%code requires {
  #include "calc.h"
}

%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <math.h>
  #include "calc.h"
  extern FILE *yyin;
  int yylex(void);
  void yyerror(const char *);
  FILE *llvm_out;

  int temp_var_count = 0;
  int get_temp_var_count() {
    return temp_var_count++;
  }

  // Aloca nova string para nome temporário (ex: %t0, %t1, ...)
  char *new_temp() {
    char buffer[32];
    snprintf(buffer, sizeof(buffer), "%%t%d", get_temp_var_count());
    return strdup(buffer);  // aloca nova string para evitar sobrescrever
  }
%}

%define api.value.type union

%token <float> NUM
%token PLUS MINUS MULTIPLY DIVIDE ASSIGN IF THEN ELSE EQUAL LESS GREATER LESS_EQUAL NOT_EQUAL GREATER_EQUAL AND OR NOT OPEN_BRACKETS CLOSE_BRACKETS OPEN_PARENTHESIS CLOSE_PARENTHESIS
%token <int> TRUEbool FALSEbool
%token NEWLINE QUIT
%token INT FLOAT BOOL READ WRITE END
%token <char*> ID

%nterm <llvm_val*> expression term factor
%nterm <llvm_val*> boolean_expression

%left PLUS MINUS
%left MULTIPLY DIVIDE
%right ASSIGN
%left EQUAL LESS GREATER LESS_EQUAL GREATER_EQUAL NOT_EQUAL
%left AND OR
%right NOT

%start program

%%

program:
    lines
    | QUIT NEWLINE { 
        exit(0);
    }
;

lines:
    line
  | lines line
;

line:
    declarations NEWLINE
  | commands NEWLINE
;

declarations: 
    declaration
  | declarations declaration
;

declaration:
    INT ID END     { add_symbol($2, INT_VAR, llvm_out); }
  | FLOAT ID END   { add_symbol($2, FLOAT_VAR, llvm_out); }
  | BOOL ID END    { add_symbol($2, BOOL_VAR, llvm_out); }
;

commands:
    command
  | commands command
;

command:
    if_command
  | assignments 
  | read_command END
  | write_command END
;
block:
    { /* bloco vazio */ }
  | block_element
  | block block_element
;

block_element:
    declaration
  | command
;
read_command:
    READ OPEN_PARENTHESIS ID CLOSE_PARENTHESIS { 
        switch (get_variable_type($3)) {
            case INT_VAR: {
                int auxInt;
                printf("Enter an integer: ");
                scanf("%d", &auxInt);
                while (getchar() != '\n'); // limpar buffer
                set_int_value($3, auxInt, llvm_out);
                break;
            }
            case FLOAT_VAR: {
                float auxFloat;
                printf("Enter a float: ");
                scanf("%f", &auxFloat);
                while (getchar() != '\n'); // limpar buffer
                set_float_value($3, auxFloat, llvm_out);
                break;
            }
            case BOOL_VAR: {
                int auxBool;
                printf("Enter a boolean (0 or 1): ");
                scanf("%d", &auxBool);
                while (getchar() != '\n'); // limpar buffer
                set_bool_value($3, auxBool, llvm_out);
                break;
            }
            default:
                break;
        }
    }
;

write_command:
    WRITE OPEN_PARENTHESIS expression CLOSE_PARENTHESIS { 
        // Exemplo simples para imprimir float, adaptar para tipo
        if ($3->type == FLOAT_VAR)
            printf("%f\n", atof($3->name));
        else if ($3->type == INT_VAR)
            printf("%d\n", atoi($3->name));
        else if ($3->type == BOOL_VAR)
            printf("%d\n", atoi($3->name));
        free_llvm_val($3);
    }
;

assignments:
    assignment
;

assignment:
    ID ASSIGN expression END {
        int var_type = get_variable_type($1);
        int expr_type = $3->type;
        
        if (var_type != expr_type) {
            fprintf(stderr, "Erro de tipo na atribuição: variável '%s' do tipo %d, expressão do tipo %d\n", $1, var_type, expr_type);
            YYABORT;
        } else {
            switch (var_type) {
                case INT_VAR:
                    // Aloca um inteiro (caso não alocado antes) e armazena valor
                    fprintf(llvm_out, "store i32 %s, i32* %s\n", $3->name, $1);
                    break;
                case FLOAT_VAR:
                    fprintf(llvm_out, "store float %s, float* %s\n", $3->name, $1);
                    break;
                default:
                    fprintf(stderr, "Tipo desconhecido para variável '%s'\n", $1);
                    YYABORT;
            }
        }
        free_llvm_val($3);
    }
    | ID ASSIGN boolean_expression {
        if (get_variable_type($1) != BOOL_VAR) {
            fprintf(stderr, "Erro de tipo na atribuição: variável '%s' não é do tipo booleano\n", $1);
            YYABORT;
        } else {
            fprintf(llvm_out, "store i1 %s, i1* %s\n", $3->name, $1);
        }
    }
;

expression:
    term { $$ = $1; }
  | expression PLUS term {
        llvm_val *res = malloc(sizeof(llvm_val));
		if (($1->type != FLOAT_VAR && $1->type != INT_VAR) || ($3->type != FLOAT_VAR && $3->type != INT_VAR)) {
			fprintf(stderr, "Error: Que conta é essa?\n");
			exit(1);
		}
		if ($1->type == FLOAT_VAR || $3->type == FLOAT_VAR) {
			res->type = FLOAT_VAR; // se um dos operandos for float, o resultado é float
		}
		else {
			res->type = INT_VAR;
		}

        res->name = new_temp();

        if (res->type == INT_VAR) {
            fprintf(llvm_out, "  %s = add i32 %s, %s\n", res->name, $1->name, $3->name);
        } else if (res->type == FLOAT_VAR) {
            fprintf(llvm_out, "  %s = fadd float %s, %s\n", res->name, $1->name, $3->name);
        } else {
            // erro de tipo, tratar
        }

        free_llvm_val($1);
        free_llvm_val($3);

        $$ = res;
    }
  | expression MINUS term {
        llvm_val *res = malloc(sizeof(llvm_val));
		if (($1->type != FLOAT_VAR && $1->type != INT_VAR) || ($3->type != FLOAT_VAR && $3->type != INT_VAR)) {
			fprintf(stderr, "Error: Que conta é essa?\n");
			exit(1);
		}
		if ($1->type == FLOAT_VAR || $3->type == FLOAT_VAR) {
			res->type = FLOAT_VAR; // se um dos operandos for float, o resultado é float
		}
		else {
			res->type = INT_VAR;
		}

        res->name = new_temp();

        if (res->type == INT_VAR) {
            fprintf(llvm_out, "  %s = sub i32 %s, %s\n", res->name, $1->name, $3->name);
        } else if (res->type == FLOAT_VAR) {
            fprintf(llvm_out, "  %s = fsub float %s, %s\n", res->name, $1->name, $3->name);
        } else {
            // erro de tipo, tratar
        }

        free_llvm_val($1);
        free_llvm_val($3);

        $$ = res;
    }
;

term:
    factor { $$ = $1; }
  | term MULTIPLY factor {
        llvm_val *res = malloc(sizeof(llvm_val));
		if (($1->type != FLOAT_VAR && $1->type != INT_VAR) || ($3->type != FLOAT_VAR && $3->type != INT_VAR)) {
			fprintf(stderr, "Error: Que conta é essa?\n");
			exit(1);
		}
		if ($1->type == FLOAT_VAR || $3->type == FLOAT_VAR) {
			res->type = FLOAT_VAR; // se um dos operandos for float, o resultado é float
		}
		else {
			res->type = INT_VAR;
		}

        res->name = new_temp();

        if (res->type == INT_VAR) {
            fprintf(llvm_out, "  %s = mul i32 %s, %s\n", res->name, $1->name, $3->name);
        } else if (res->type == FLOAT_VAR) {
            fprintf(llvm_out, "  %s = fmul float %s, %s\n", res->name, $1->name, $3->name);
        } else {
            // erro de tipo, tratar
        }

        free_llvm_val($1);
        free_llvm_val($3);

        $$ = res;
    }
  | term DIVIDE factor {
        llvm_val *res = malloc(sizeof(llvm_val));
		if (($1->type != FLOAT_VAR && $1->type != INT_VAR) || ($3->type != FLOAT_VAR && $3->type != INT_VAR)) {
			fprintf(stderr, "Error: Que conta é essa?\n");
			exit(1);
		}
		if ($1->type == FLOAT_VAR || $3->type == FLOAT_VAR) {
			res->type = FLOAT_VAR; // se um dos operandos for float, o resultado é float
		}
		else {
			res->type = INT_VAR;
		}

        res->name = new_temp();

        if (res->type == INT_VAR) {
            fprintf(llvm_out, "  %s = sdiv i32 %s, %s\n", res->name, $1->name, $3->name);
        } else if (res->type == FLOAT_VAR) {
            fprintf(llvm_out, "  %s = fdiv float %s, %s\n", res->name, $1->name, $3->name);
        } else {
            // erro de tipo, tratar
        }

        free_llvm_val($1);
        free_llvm_val($3);

        $$ = res;
    }
;

factor:
    NUM {
        llvm_val *res = malloc(sizeof(llvm_val));
        res->type = FLOAT_VAR; 

        res->name = malloc(32);
        snprintf(res->name, 32, "%f", $1);

        $$ = res;
    }
  | ID {
        llvm_val *res = malloc(sizeof(llvm_val));
        res->type = get_variable_type($1);
        res->name = new_temp();

        switch (res->type) {
            case INT_VAR:
                fprintf(llvm_out, "  %s = load i32, i32* %%%s\n", res->name, $1);
                break;
            case FLOAT_VAR:
                fprintf(llvm_out, "  %s = load float, float* %%%s\n", res->name, $1);
                break;
            case BOOL_VAR:
                fprintf(llvm_out, "  %s = load i1, i1* %%%s\n", res->name, $1);
                break;
            default:
                // erro: variável não encontrada
                break;
        }

        $$ = res;
    }
  | OPEN_PARENTHESIS expression CLOSE_PARENTHESIS {
        $$ = $2;
    }
;

boolean_expression:
    TRUEbool {
        llvm_val *res = malloc(sizeof(llvm_val));
        res->type = BOOL_VAR;
        res->name = strdup("true");
        $$ = res;
    }
  | FALSEbool {
        llvm_val *res = malloc(sizeof(llvm_val));
        res->type = BOOL_VAR;
        res->name = strdup("false");
        $$ = res;
    }
  | NOT boolean_expression {
        llvm_val *res = malloc(sizeof(llvm_val));
        res->type = BOOL_VAR;
        res->name = new_temp();
        fprintf(llvm_out, "  %s = xor i1 %s, true\n", res->name, $2->name);
        free_llvm_val($2);
        $$ = res;
    }
  | expression EQUAL expression {
        llvm_val *res = malloc(sizeof(llvm_val));
        res->type = BOOL_VAR;
        res->name = new_temp();
        if ($1->type == FLOAT_VAR || $3->type == FLOAT_VAR)
            fprintf(llvm_out, "  %s = fcmp oeq float %s, %s\n", res->name, $1->name, $3->name);
        else
            fprintf(llvm_out, "  %s = icmp eq i32 %s, %s\n", res->name, $1->name, $3->name);
        free_llvm_val($1); free_llvm_val($3);
        $$ = res;
    }
  | expression NOT_EQUAL expression {
        llvm_val *res = malloc(sizeof(llvm_val));
        res->type = BOOL_VAR;
        res->name = new_temp();
        if ($1->type == FLOAT_VAR || $3->type == FLOAT_VAR)
            fprintf(llvm_out, "  %s = fcmp one float %s, %s\n", res->name, $1->name, $3->name);
        else
            fprintf(llvm_out, "  %s = icmp ne i32 %s, %s\n", res->name, $1->name, $3->name);
        free_llvm_val($1); free_llvm_val($3);
        $$ = res;
    }
  | expression LESS expression {
        llvm_val *res = malloc(sizeof(llvm_val));
        res->type = BOOL_VAR;
        res->name = new_temp();
        if ($1->type == FLOAT_VAR || $3->type == FLOAT_VAR)
            fprintf(llvm_out, "  %s = fcmp olt float %s, %s\n", res->name, $1->name, $3->name);
        else
            fprintf(llvm_out, "  %s = icmp slt i32 %s, %s\n", res->name, $1->name, $3->name);
        free_llvm_val($1); free_llvm_val($3);
        $$ = res;
    }
  | expression GREATER expression {
        llvm_val *res = malloc(sizeof(llvm_val));
        res->type = BOOL_VAR;
        res->name = new_temp();
        if ($1->type == FLOAT_VAR || $3->type == FLOAT_VAR)
            fprintf(llvm_out, "  %s = fcmp ogt float %s, %s\n", res->name, $1->name, $3->name);
        else
            fprintf(llvm_out, "  %s = icmp sgt i32 %s, %s\n", res->name, $1->name, $3->name);
        free_llvm_val($1); free_llvm_val($3);
        $$ = res;
    }
  | expression LESS_EQUAL expression {
        llvm_val *res = malloc(sizeof(llvm_val));
        res->type = BOOL_VAR;
        res->name = new_temp();
        if ($1->type == FLOAT_VAR || $3->type == FLOAT_VAR)
            fprintf(llvm_out, "  %s = fcmp ole float %s, %s\n", res->name, $1->name, $3->name);
        else
            fprintf(llvm_out, "  %s = icmp sle i32 %s, %s\n", res->name, $1->name, $3->name);
        free_llvm_val($1); free_llvm_val($3);
        $$ = res;
    }
  | expression GREATER_EQUAL expression {
        llvm_val *res = malloc(sizeof(llvm_val));
        res->type = BOOL_VAR;
        res->name = new_temp();
        if ($1->type == FLOAT_VAR || $3->type == FLOAT_VAR)
            fprintf(llvm_out, "  %s = fcmp oge float %s, %s\n", res->name, $1->name, $3->name);
        else
            fprintf(llvm_out, "  %s = icmp sge i32 %s, %s\n", res->name, $1->name, $3->name);
        free_llvm_val($1); free_llvm_val($3);
        $$ = res;
    }
  | boolean_expression AND boolean_expression {
        llvm_val *res = malloc(sizeof(llvm_val));
        res->type = BOOL_VAR;
        res->name = new_temp();
        fprintf(llvm_out, "  %s = and i1 %s, %s\n", res->name, $1->name, $3->name);
        free_llvm_val($1); free_llvm_val($3);
        $$ = res;
    }
  | boolean_expression OR boolean_expression {
        llvm_val *res = malloc(sizeof(llvm_val));
        res->type = BOOL_VAR;
        res->name = new_temp();
        fprintf(llvm_out, "  %s = or i1 %s, %s\n", res->name, $1->name, $3->name);
        free_llvm_val($1); free_llvm_val($3);
        $$ = res;
    }
;

if_command:
    IF OPEN_PARENTHESIS boolean_expression CLOSE_PARENTHESIS
    OPEN_BRACKETS block CLOSE_BRACKETS
    ELSE OPEN_BRACKETS block CLOSE_BRACKETS {
        int label_id = get_temp_var_count();

        char *then_label = malloc(32);
        char *else_label = malloc(32);
        char *end_label = malloc(32);

        snprintf(then_label, 32, "label_then_%d", label_id);
        snprintf(else_label, 32, "label_else_%d", label_id);
        snprintf(end_label, 32, "label_end_%d", label_id);

        fprintf(llvm_out, "  br i1 %s, label %%%s, label %%%s\n", $3->name, then_label, else_label);
        fprintf(llvm_out, "%s:\n", then_label);
        // Código gerado pelo bloco $6 (then)
        fprintf(llvm_out, "  br label %%%s\n", end_label);
        fprintf(llvm_out, "%s:\n", else_label);
        // Código gerado pelo bloco $10 (else)
        fprintf(llvm_out, "  br label %%%s\n", end_label);
        fprintf(llvm_out, "%s:\n", end_label);

        free_llvm_val($3);
        free(then_label);
        free(else_label);
        free(end_label);
    }
  | IF OPEN_PARENTHESIS boolean_expression CLOSE_PARENTHESIS
    OPEN_BRACKETS block CLOSE_BRACKETS {
        int label_id = get_temp_var_count();

        char *then_label = malloc(32);
        char *end_label = malloc(32);

        snprintf(then_label, 32, "label_then_%d", label_id);
        snprintf(end_label, 32, "label_end_%d", label_id);

        fprintf(llvm_out, "  br i1 %s, label %%%s, label %%%s\n", $3->name, then_label, end_label);
        fprintf(llvm_out, "%s:\n", then_label);
        // Código gerado pelo bloco $6 (then)
        fprintf(llvm_out, "  br label %%%s\n", end_label);
        fprintf(llvm_out, "%s:\n", end_label);

        free_llvm_val($3);
        free(then_label);
        free(end_label);
    }
;


%%

int main() {
    yyin = stdin;

    llvm_out = fopen("output.ll", "w");
    if (!llvm_out) {
        fprintf(stderr, "Error opening output file.\n");
        return 1;
    }

    do {
        yyparse();
    } while(!feof(yyin));

    fclose(llvm_out);

    return 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "Parse error: %s\n", s);
    exit(1);
}