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
