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

"+"		{return PLUS;}
"-"		{return MINUS;}
"*"		{return MULTIPLY;}
"/"		{return DIVIDE;}
"="		{return ASSIGN;}

"exit"		{return QUIT;}
"quit"		{return QUIT;}
"if/i"    {return IF;}
"then/i"  {return THEN;}
"else/i"  {return ELSE;}

"=="      {return EQUAL;}
"and/i"   {return AND;}
"or/i"    {return OR;}
"not/i"   {return NOT;}
"true"    {return TRUEbool;}
"false"   {return FALSEbool;}

[a-zA-Z_][a-zA-Z0-9_]* {
  static ptrdiff_t bufsize = 0;
  static char *symbuf = 0;
  ptrdiff_t i = 0;

  // Copia nome do identificador
  while (yytext[i]) {
    if (bufsize <= i) {
      bufsize = 2 * bufsize + 40;
      symbuf = realloc(symbuf, bufsize);
    }
    symbuf[i] = yytext[i];
    i++;
  }
  symbuf[i] = '\0';

  symrec* s = getsym(symbuf);
  if (!s) s = putsym(symbuf, VAR);

  yylval.VAR = s;
  return s->type;
}

.

%%
