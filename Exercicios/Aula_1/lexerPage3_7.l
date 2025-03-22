/* Definições */
%{
    #include <stdio.h>
    #include <math.h>
    #include <string.h>

    // Função para criptografar o texto usando a Cifra de César
    void cifra_cesar(char* texto) {
        for (int i = 0; i < strlen(texto); i++) {
            int deslocamento = 3;
            char c = texto[i];

            if (c >= 'A' && c <= 'Z') {
                putchar((c - 'A' + deslocamento) % 26 + 'A');
            }
            else if (c >= 'a' && c <= 'z') {
                putchar((c - 'a' + deslocamento) % 26 + 'a');
            }
        }
    }
%}
/* Estados */

%s criptografar

/* Regras */
%%

"<CRIPTO>" { BEGIN criptografar; printf("<CRIPTO>");}
<criptografar>"</CRIPTO>"  { BEGIN INITIAL; printf("</CRIPTO>"); }
<criptografar>[^(<\/CRIPTO>)]*    { cifra_cesar(yytext); }

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
