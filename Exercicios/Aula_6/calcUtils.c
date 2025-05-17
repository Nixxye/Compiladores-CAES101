#include "calc.h"

// Definições das tabelas globais
Symbol *symbolTable[TABLE_SIZE] = {0};
IntValue *intTable[TABLE_SIZE] = {0};
FloatValue *floatTable[TABLE_SIZE] = {0};
BoolValue *boolTable[TABLE_SIZE] = {0};

// Função de hash simples
unsigned int hash(const char *str) {
    unsigned int hash = 0;
    while (*str) {
        hash = (hash * 31) + *str++;
    }
    return hash % TABLE_SIZE;
}

// Adiciona símbolo e gera alocação LLVM
void add_symbol(const char *name, VarType type, FILE *llvm_out) {
    unsigned int index = hash(name);
    Symbol *symbol = symbolTable[index];
    while (symbol) {
        if (strcmp(symbol->name, name) == 0) {
            if (symbol->type != type) {
                fprintf(stderr, "Erro: Variável '%s' já existe com tipo diferente!\n", name);
                exit(EXIT_FAILURE);
            }
            return;
        }
        symbol = symbol->next;
    }
    Symbol *newSymbol = malloc(sizeof(Symbol));
    if (!newSymbol) { perror("malloc failed"); exit(EXIT_FAILURE); }
    newSymbol->name = strdup(name);
    if (!newSymbol->name) { perror("strdup failed"); exit(EXIT_FAILURE); }

    newSymbol->type = type;
    newSymbol->next = symbolTable[index];
    symbolTable[index] = newSymbol;

    // Geração LLVM: aloca a variável
    switch (type) {
        case INT_VAR:
            fprintf(llvm_out, "  %%%s = alloca i32\n", name);
            break;
        case FLOAT_VAR:
            fprintf(llvm_out, "  %%%s = alloca float\n", name);
            break;
        case BOOL_VAR:
            fprintf(llvm_out, "  %%%s = alloca i1\n", name);
            break;
        default:
            break;
    }
}

void set_int_value(const char *name, int value, FILE *llvm_out) {
    unsigned int index = hash(name);
    IntValue *val = intTable[index];
    while (val) {
        if (strcmp(val->name, name) == 0) {
            val->value = value;
            goto emit;
        }
        val = val->next;
    }
    IntValue *newValue = malloc(sizeof(IntValue));
    newValue->name = strdup(name);
    newValue->value = value;
    newValue->next = intTable[index];
    intTable[index] = newValue;

emit:
    fprintf(llvm_out, "  store i32 %d, i32* %%%s\n", value, name);
}

void set_float_value(const char *name, float value, FILE *llvm_out) {
    unsigned int index = hash(name);
    FloatValue *val = floatTable[index];
    while (val) {
        if (strcmp(val->name, name) == 0) {
            val->value = value;
            goto emit;
        }
        val = val->next;
    }
    FloatValue *newValue = malloc(sizeof(FloatValue));
    newValue->name = strdup(name);
    newValue->value = value;
    newValue->next = floatTable[index];
    floatTable[index] = newValue;

emit:
    fprintf(llvm_out, "  store float %f, float* %%%s\n", value, name);
}

void set_bool_value(const char *name, int value, FILE *llvm_out) {
    unsigned int index = hash(name);
    BoolValue *val = boolTable[index];
    while (val) {
        if (strcmp(val->name, name) == 0) {
            val->value = value;
            goto emit;
        }
        val = val->next;
    }
    BoolValue *newValue = malloc(sizeof(BoolValue));
    newValue->name = strdup(name);
    newValue->value = value;
    newValue->next = boolTable[index];
    boolTable[index] = newValue;

emit:
    fprintf(llvm_out, "  store i1 %d, i1* %%%s\n", value, name);
}

// Recupera tipo da variável
VarType get_variable_type(const char *name) {
    unsigned int index = hash(name);
    Symbol *symbol = symbolTable[index];
    while (symbol) {
        if (strcmp(symbol->name, name) == 0) {
            return symbol->type;
        }
        symbol = symbol->next;
    }
    fprintf(stderr, "Erro: Variável '%s' não encontrada na tabela de símbolos!\n", name);
    exit(EXIT_FAILURE);
}

void free_llvm_val(llvm_val *val) {
    if (!val) return;
    if (val->name) free(val->name);
    free(val);
}