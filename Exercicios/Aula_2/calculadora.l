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
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float top;
    float capacity;
    float *items;
} Stack;

// Função para inicializar a pilha
void initStack(Stack *s) {
    s->top = -1;
    s->capacity = 10; // Capacidade inicial
    s->items = (float *)malloc(s->capacity * sizeof(float));
    if (s->items == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(EXIT_FAILURE);
    }
}

// Função para verificar se a pilha está cheia
int isFull(Stack *s) {
    return s->top == s->capacity - 1;
}

// Função para verificar se a pilha está vazia
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Função para redimensionar a pilha
void resize(Stack *s) {
    s->capacity *= 2; // Dobrar a capacidade
    s->items = (float *)realloc(s->items, s->capacity * sizeof(float));
    if (s->items == NULL) {
        printf("Erro ao realocar memória!\n");
        exit(EXIT_FAILURE);
    }
}

// Função para adicionar um elemento à pilha
void push(Stack *s, int value) {
    if (isFull(s)) {
        resize(s);
    }
    s->items[++s->top] = value;
}

// Função para remover um elemento da pilha
float pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Erro: Pilha vazia!\n");
        return -1;
    }
    return s->items[s->top--];
}

// Função para mostrar o elemento do topo
float peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Erro: Pilha vazia!\n");
        return -1;
    }
    return s->items[s->top];
}

// Função para liberar memória da pilha
void freeStack(Stack *s) {
    free(s->items);
}

int main() {
    Stack s;
    initStack(&s);

    printf("\n\nIniciando analisador:\n\n");
    yylex(); 
    freeStack(&s);
    return 0;
}

/* Encerra ao chegar no final do arquivo */
int yywrap() {
    return 1;
}