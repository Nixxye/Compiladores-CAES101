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
%token <symrec*> VAR FUN /* Symbol table pointer: variable/function. */
%token PLUS MINUS MULTIPLY DIVIDE ASSIGN IF THEN ELSE EQUAL AND OR NOT 
%token <int> TRUEbool FALSEbool
%token NEWLINE QUIT
%nterm <float> expression
%nterm <int> boolean


%start calculation

%%

calculation:
	   | calculation line
;

line:
	NEWLINE
	| expression NEWLINE
	| expression QUIT { printf("\tResult: %f\n", $1); exit(0); }
	| QUIT NEWLINE { printf("bye!\n"); exit(0); }
;

expression:
	NUM                  { $$ = $1; }
	| VAR                { $$ = $1->value.var; }
	| VAR ASSIGN expression        { $$ = $3; $1->value.var = $3; }
	| expression expression PLUS       { $$ = $1 + $2;  }
	| expression expression MINUS        { $$ = $1 - $2;  }
	| expression expression MULTIPLY       { $$ = $1 * $2; }
	| expression expression DIVIDE       { $$ = $1 / $2;  }
;

boolean:
	TRUEbool              { $$ = 1; }
	| FALSEbool           { $$ = 0; }
    | expression EQUAL expression { $$ = $1 == $3; }
;
if_command:
	IF '(' boolean ')' '{' expression '}' { if($3){$6}}
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
