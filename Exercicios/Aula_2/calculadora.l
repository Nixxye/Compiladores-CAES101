/*  Definições */
%option noyywrap

%{
    // ByGPT
    #include <stdio.h>
    #include <math.h>
    #include <stdlib.h>

    typedef struct {
        int top;
        int capacity;
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
    void push(Stack *s, float value) {
        if (isFull(s)) {
            resize(s);
        }
        s->items[++s->top] = value;
    }

    // Função para remover um elemento da pilha
    float pop(Stack *s) {
        if (isEmpty(s)) {
            printf("Erro: Pilha vazia - pop!\n");
            return -1;
        }
        return s->items[s->top--];
    }

    // Função para mostrar o elemento do topo
    float peek(Stack *s) {
        if (isEmpty(s)) {
            printf("Erro: Pilha vazia - peek!\n");
            return -1;
        }
        return s->items[s->top];
    }

    // Função para liberar memória da pilha
    void freeStack(Stack *s) {
        free(s->items);
    }
    Stack s;

%}
FLOAT [0-9]+(\.[0-9]+)?
OP [\+\-\*\/]
/* ------------------------------------------- */
/* Regras */

%%
{FLOAT} { push(&s, atof(yytext)); }
{OP} {
    float y = pop(&s);
    float x = pop(&s);
    float result;

    switch(yytext[0]) {
        case '+':
            result = x + y;
            break;
        case '-':
            result = x - y;
            break;
        case '*':
            result = x * y;
            break;
        case '/':
            result = x / y;
            break;
    }
    printf("%f %s %f = %f\n", x, yytext, y, result);
    push(&s, result);
}
.|\n|\r   {/* Ignora qualquer caractere não reconhecido */}
%%
/* ------------------------------------------- */
/* Código */


int main() {
    initStack(&s);

    printf("\n\nIniciando analisador:\n\n");
    yylex(); 
    printf("Resultado: %f\n", peek(&s));
    freeStack(&s);
    return 0;
}
