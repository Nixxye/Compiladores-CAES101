/*  Definições */
%{
#include <stdio.h>
#include <math.h>
%}
d [0-9]
l [a-zA-Z]
IP 0|[1-9][0-9]?|1[0-9]{2}|2[0-4][0-9]|25[0-5]
/* ------------------------------------------- */
/* Regras */
/* Ex 1: */
%%
\({d}{2}\){d}{5}-{d}{4}          printf("EX1 - Número de telefone encontrado: %s\n", yytext);
{l}{3}-{l}{d}{3}                 printf("EX2 - Placa encontrada: %s\n", yytext);
{d}{3}-{d}{2}-{d}{3}-{d}{4}-{d}  printf("EX3 - ISBN encontrado: %s\n", yytext);
{IP}\.{IP}\.{IP}\.{IP}           printf("EX4 - IPv4 encontrado: %s\n", yytext);

[\+\-]?(0|([1-9]{d}*))((\.{d}+)(E[\+\-]?({d}+))?)?    printf("T1 - Numero real encontrado: %s\n", yytext);
M?(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})  printf("T1 - Numero romano encontrado: %s\n", yytext);



.|\n   {/* Ignora qualquer caractere não reconhecido */}
%%
/* ------------------------------------------- */
/* Código */
int main () {
printf("\n\nIniciando analisador:\n\n");
yylex(); 
return 0;
}
/* Encerra ao chegar no final do arquivo */
int yywrap() {
return 1;
}