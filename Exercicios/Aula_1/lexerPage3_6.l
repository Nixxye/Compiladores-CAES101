/* Definições */
%{
    #include <stdio.h>
    #include <math.h>
%}
/* Estados */

%s comment

/* Regras */
%%

"<HIDE>" { BEGIN comment; printf("<HIDE>");}
<comment>"</HIDE>"  { BEGIN INITIAL; printf("</HIDE>"); }
<comment>.    { putchar('X'); }

.|\n { putchar(yytext[0]); } /* Imprime o resto do texto */

%%
/* Código */
int main() {
    printf("\n\nIniciando analisador:\n\n");
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
