%option noyywrap
%{
#include <ctype.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "calc.tab.h"
#include "calc.h"
%}

%%

[ \t]+  ; // ignora espaços

\n  { return NEWLINE;}

[0-9]+\.[0-9]+ {
  yylval.NUM = strtof(yytext, NULL);

  return NUM;
}

[0-9]+ {
  yylval.NUM = strtof(yytext, NULL);

  return NUM;
}

"=="      {return EQUAL;}
"<="      {return LESS_EQUAL;}
">="      {return GREATER_EQUAL;}
"!="      {return NOT_EQUAL;}
"<"       {return LESS;}
">"       {return GREATER;}

";"       {return END;}

(?i:int)   { return INT; }
(?i:float)  { return FLOAT; }
(?i:bool)   { return BOOL; }

(?i:read)  { return READ; }
(?i:write) { return WRITE; }

(?i:and)    { return AND; }
(?i:or)     { return OR; }
(?i:not)    { return NOT; }
(?i:true)   { return TRUEbool; }
(?i:false)  { return FALSEbool; }

"+"		{return PLUS;}
"-"		{return MINUS;}
"*"		{return MULTIPLY;}
"/"		{return DIVIDE;}
"="		{return ASSIGN;}

(?i:exit)		{return QUIT;}
(?i:quit)		{return QUIT;}
(?i:if)    {return IF;}
(?i:then)  {return THEN;}
(?i:else)  {return ELSE;}

"{"        {return OPEN_BRACKETS;}
"}"        {return CLOSE_BRACKETS;}
"("        {return OPEN_PARENTHESIS;}
")"        {return CLOSE_PARENTHESIS;}

[a-zA-Z_][a-zA-Z0-9_]* {
  yylval.ID = strdup(yytext);
  return ID;
} 

. {
  printf("Caractere inesperado: %s\n", yytext);
  return yytext[0];
}

%%
