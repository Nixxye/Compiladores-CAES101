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

\n  { 
    printf("Token: NEWLINE\n"); 
    return NEWLINE;
}

[0-9]+\.[0-9]+ {
  yylval.NUM = strtof(yytext, NULL);
  printf("Token: NUM (%s)\n", yytext); 
  return NUM;
}

[0-9]+ {
  yylval.NUM = strtof(yytext, NULL);
  printf("Token: NUM (%s)\n", yytext); 
  return NUM;
}

"=="      { 
  printf("Token: EQUAL\n"); 
  return EQUAL;
}

"<="      { 
  printf("Token: LESS_EQUAL\n"); 
  return LESS_EQUAL;
}

">="      { 
  printf("Token: GREATER_EQUAL\n"); 
  return GREATER_EQUAL;
}

"!="      { 
  printf("Token: NOT_EQUAL\n"); 
  return NOT_EQUAL;
}

"<"       { 
  printf("Token: LESS\n"); 
  return LESS;
}

">"       { 
  printf("Token: GREATER\n"); 
  return GREATER;
}

";"       { 
  printf("Token: END\n"); 
  return END;
}

(?i:int)   { 
  printf("Token: INT\n"); 
  return INT; 
}

(?i:float)  { 
  printf("Token: FLOAT\n"); 
  return FLOAT; 
}

(?i:bool)   { 
  printf("Token: BOOL\n"); 
  return BOOL; 
}

(?i:read)  { 
  printf("Token: READ\n"); 
  return READ; 
}

(?i:write) { 
  printf("Token: WRITE\n"); 
  return WRITE; 
}

(?i:and)    { 
  printf("Token: AND\n"); 
  return AND; 
}

(?i:or)     { 
  printf("Token: OR\n"); 
  return OR; 
}

(?i:not)    { 
  printf("Token: NOT\n"); 
  return NOT; 
}

(?i:true)   { 
  printf("Token: TRUEbool\n"); 
  return TRUEbool; 
}

(?i:false)  { 
  printf("Token: FALSEbool\n"); 
  return FALSEbool; 
}

"+"		{ 
  printf("Token: PLUS\n"); 
  return PLUS;
}

"-"		{ 
  printf("Token: MINUS\n"); 
  return MINUS;
}

"*"		{ 
  printf("Token: MULTIPLY\n"); 
  return MULTIPLY;
}

"/"		{ 
  printf("Token: DIVIDE\n"); 
  return DIVIDE;
}

"="		{ 
  printf("Token: ASSIGN\n"); 
  return ASSIGN;
}

(?i:exit)		{ 
  printf("Token: QUIT\n"); 
  return QUIT; 
}

(?i:quit)		{ 
  printf("Token: QUIT\n"); 
  return QUIT; 
}

(?i:if)    { 
  printf("Token: IF\n"); 
  return IF; 
}

(?i:then)  { 
  printf("Token: THEN\n"); 
  return THEN; 
}

(?i:else)  { 
  printf("Token: ELSE\n"); 
  return ELSE; 
}

"{"        { 
  printf("Token: OPEN_BRACKETS\n"); 
  return OPEN_BRACKETS; 
}

"}"        { 
  printf("Token: CLOSE_BRACKETS\n"); 
  return CLOSE_BRACKETS; 
}

"("        { 
  printf("Token: OPEN_PARENTHESIS\n"); 
  return OPEN_PARENTHESIS; 
}

")"        { 
  printf("Token: CLOSE_PARENTHESIS\n"); 
  return CLOSE_PARENTHESIS; 
}

[a-zA-Z_][a-zA-Z0-9_]* {
  yylval.ID = strdup(yytext);
  printf("Token: ID (%s)\n", yytext); 
  return ID;
} 

. {
  printf("Caractere inesperado: %s\n", yytext);
  return yytext[0];
}

%%
