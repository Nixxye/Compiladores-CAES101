/* Definições */
%{
    #include <stdio.h>
    #include <math.h>
    #include <string.h>
%}
/* Estados */

/* Regras */
%%
[,:;\.] printf("DELIMITADOR ");
(<=|>=|<|>|=|<>|=<|=>) printf("OPERADOR_RELACIONAL ");
[\*-\+\/]|(SQR|SQRT|SIN|COS|TAN) printf("OPERADOR_ARITMETICO ");
(Begin|End|For|Do|If|Then|Else|Elseif|Endif|While|Repeat|Until) printf("PALAVRA_RESERVADA ");
(Integer|Real|Float|Double|Char|String|Boolean) printf("TIPO_DADO ");
_[a-zA-Z]+ printf("FUNCAO ");
\$[a-zA-Z]+ printf("VARIAVEL ");
\".*\" printf("TEXTO ");
-?[0-9]+ printf("NUMERO ");
[a-zA-Z]+ printf("NOME ");
#.*# printf("COMENTARIO ");
\n printf("\n");
(" "|\n|\t) printf("%s", yytext);  /*Imprime o resto do texto */
\r 
. printf("INVALIDO "); 




%%
/* Erro em: [^\ \t\n] { printf("INVALIDO (%s)", yytext); } */
/* Código */
int main() {
    printf("\n\nIniciando analisador:\n\n");
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
