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
%token PLUS MINUS MULTIPLY DIVIDE ASSIGN IF THEN ELSE EQUAL LESS GREATER LESS_EQUAL NOT_EQUAL GREATER_EQUAL AND OR NOT OPEN_BRACKETS CLOSE_BRACKETS OPEN_PARENTHESIS CLOSE_PARENTHESIS
%token <int> TRUEbool FALSEbool
%token NEWLINE QUIT
%nterm <float> expression if_command
%nterm <int> boolean


%start calculation

%%

calculation:
	   | calculation line
;

line:
	NEWLINE
	| expression NEWLINE { printf("\tResult: %f\n", $1); }
	| expression QUIT { printf("\tResult: %f\n", $1); exit(0); }
	| boolean NEWLINE { printf("\tResult: %d\n", $1); }
	| if_command NEWLINE { printf("\tResult: %f\n", $1); }
	| QUIT NEWLINE { printf("bye!\n"); exit(0); }
;

expression:
	NUM                  { $$ = $1; }
	| VAR                { $$ = $1->value.var; }
	| VAR ASSIGN expression        { $$ = $3; $1->value.var = $3; }
	| VAR ASSIGN boolean        { $$ = $3; $1->value.var = $3; }
	| OPEN_PARENTHESIS expression CLOSE_PARENTHESIS { $$ = $2; }
	| expression PLUS expression       { $$ = $1 + $3;  }
	| expression MINUS expression       { $$ = $1 - $3;  }
	| expression MULTIPLY expression      { $$ = $1 * $3; }
	| expression DIVIDE expression       { $$ = $1 / $3;  }
;

boolean:
	TRUEbool              { $$ = 1; }
	| FALSEbool           { $$ = 0; }
	| NOT boolean { $$ = !$2; }
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
	IF OPEN_PARENTHESIS boolean CLOSE_PARENTHESIS 
	OPEN_BRACKETS expression CLOSE_BRACKETS
	ELSE OPEN_BRACKETS expression CLOSE_BRACKETS {if ($3) { $$ = $6; } else { $$ = $10; } } 
	| IF OPEN_PARENTHESIS boolean CLOSE_PARENTHESIS
	OPEN_BRACKETS expression CLOSE_BRACKETS {if ($3) { $$ = $6; } }
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
