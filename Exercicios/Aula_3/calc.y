%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calc.h"

extern int yylex();
extern int yyparse();
extern FILE* yyin;

void yyerror(const char* s);
%}

%union {
	int ival;
	float fval;
	char sval;
}


%token<ival> INT
%token<fval> FLOAT
%token<sval> VARIABLE
%token PLUS MINUS MULTIPLY DIVIDE ASSIGN
%token NEWLINE QUIT


%type<ival> expression

%start calculation

%%

calculation:
	   | calculation line
;

line: NEWLINE
    | expression NEWLINE { printf("\tResult: %i\n", $1); }
    | QUIT NEWLINE { printf("bye!\n"); exit(0); }
;


expression:       FLOAT            { $$ = $1; }
	| INT              { $$ = $1; }
	| VARIABLE         { $$ = $1->value.var; }
	| expression expression PLUS    { $$ = $1 + $2; }
	| expression expression MINUS   { $$ = $1 - $2; }
	| expression expression MULTIPLY     { $$ = $1 * $2; }
	| expression expression DIVIDE     { $$ = $1 / $2; }
	| VARIABLE ASSIGN expression { $$ = $3; $1->value.var = $3; }
;

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
