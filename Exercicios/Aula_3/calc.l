%option noyywrap

%{
#include <stdio.h>

#define YY_DECL int yylex()

#include "calc.tab.h"

%}

%%

[ \t]	; // ignore all whitespace
[0-9]+\.[0-9]+ 	{yylval.fval = atof(yytext); return FLOAT;}
[0-9]+		{yylval.ival = atoi(yytext); return INT;}
\n		{return NEWLINE;}
"+"		{return PLUS;}
"-"		{return MINUS;}
"*"		{return MULTIPLY;}
"/"		{return DIVIDE;}
"="		{return ASSIGN;}
[a-z]   {yylval.sval = atoi(yytext); return VARIABLE;} // variáveis são letras mínusculas
"exit"		{return QUIT;}
"quit"		{return QUIT;}

%%
