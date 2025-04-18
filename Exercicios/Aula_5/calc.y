%code requires {
  typedef struct symrec symrec;
}

%{
  #include <stdio.h>  /* For printf, etc. */
  #include <math.h>   /* For pow, used in the grammar. */
  #include "calc.h"   /* Contains definition of 'symrec'. */
  extern FILE *yyin;  /* Input file. */
  int yylex (void);
  void yyerror (char const *);
%}


%define api.value.type union /* Generate YYSTYPE from these types: */
%token <float>  NUM    /* Double precision number. */
%token PLUS MINUS MULTIPLY DIVIDE ASSIGN IF THEN ELSE EQUAL LESS GREATER LESS_EQUAL NOT_EQUAL GREATER_EQUAL AND OR NOT OPEN_BRACKETS CLOSE_BRACKETS OPEN_PARENTHESIS CLOSE_PARENTHESIS
%token <int> TRUEbool FALSEbool
%token NEWLINE QUIT
%token INT FLOAT BOOL READ WRITE END
%token <char*> ID
%nterm <float> expression if_command assignments read_command assignment term factor
%nterm <int> boolean_expression


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
	INT ID END { add_symbol($2, INT_VAR); }
	| FLOAT ID END { add_symbol($2, FLOAT_VAR); }
	| BOOL ID END { add_symbol($2, BOOL_VAR); }
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

read_command:
	READ OPEN_PARENTHESIS ID CLOSE_PARENTHESIS { 
		//scanf???
	}
;

write_command:
	WRITE OPEN_PARENTHESIS expression CLOSE_PARENTHESIS { 
		printf("%f\n", $3); 
	}
;

assignments:
	assignment

assignment:
	ID ASSIGN expression END { 
		switch (get_variable_type($1)) {
			case INT_VAR: 
				set_int_value($1, $3);
			break;
			case FLOAT_VAR: 
				set_float_value($1, $3);
			break;
			case BOOL_VAR: 
				set_bool_value($1, $3);
			break;
			default:
				// variable not found
				break;
		} }


expression:
    term
    | expression PLUS term      { $$ = $1 + $3; }
    | expression MINUS term     { $$ = $1 - $3; }
;

term:
    factor
    | term MULTIPLY factor      { $$ = $1 * $3; }
    | term DIVIDE factor        { $$ = $1 / $3; }
;

factor:
    NUM
	| ID { 
		switch (get_variable_type($1)) {
			case INT_VAR: 
				$$ = get_int_value($1);
			break;
			case FLOAT_VAR: 
				$$ = get_float_value($1);
			break;
			default:
				// variable not found
				break;
		}
	}
    | OPEN_PARENTHESIS expression CLOSE_PARENTHESIS { $$ = $2; }
;


boolean_expression:
	TRUEbool              { $$ = 1; }
	| FALSEbool           { $$ = 0; }
	| NOT boolean_expression { $$ = !$2; }
    | expression EQUAL expression { $$ = $1 == $3; }
	| expression LESS_EQUAL expression { $$ = $1 <= $3; }
	| expression GREATER_EQUAL expression { $$ = $1 >= $3; }
	| expression NOT_EQUAL expression { $$ = $1 != $3; }
	| expression LESS expression { $$ = $1 < $3; }
	| expression GREATER expression { $$ = $1 > $3; }
	| expression OR expression { $$ = $1 || $3; }
	| expression AND expression { $$ = $1 && $3; }
	| expression { $$ = $1; }
;


if_command:
	IF OPEN_PARENTHESIS boolean_expression CLOSE_PARENTHESIS 
	OPEN_BRACKETS assignments CLOSE_BRACKETS
	ELSE OPEN_BRACKETS expression CLOSE_BRACKETS { if ($3) { $$ = $6; } else { $$ = $10; } } 
	| IF OPEN_PARENTHESIS boolean_expression CLOSE_PARENTHESIS
	OPEN_BRACKETS assignments CLOSE_BRACKETS { if ($3) { $$ = $6; } }
;
/* End of grammar. */
%%

int main() {
	yyin = stdin;

	do {
		yyparse();
	} while(!feof(yyin));

	return 0;
}

void yyerror(const char* s) {
	fprintf(stderr, "Parse error: %s\n", s);
	exit(1);
}
