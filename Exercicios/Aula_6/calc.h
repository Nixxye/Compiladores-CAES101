#ifndef CALC_H
#define CALC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

typedef enum {
    INT_VAR,
    FLOAT_VAR,
    CHAR_VAR,
    STRING_VAR,
    BOOL_VAR
} VarType;

typedef struct Symbol {
    char *name;
    VarType type;
    struct Symbol *next;
} Symbol;

typedef struct IntValue {
    char *name;
    int value;
    struct IntValue *next;
} IntValue;

typedef struct FloatValue {
    char *name;
    float value;
    struct FloatValue *next;
} FloatValue;

typedef struct BoolValue {
    char *name;
    int value;
    struct BoolValue *next;
} BoolValue;

typedef struct {
    char *name;
    int type;
} llvm_val;
// Tabelas globais - só devem ser **definidas** em um .c
extern Symbol *symbolTable[TABLE_SIZE];
extern IntValue *intTable[TABLE_SIZE];
extern FloatValue *floatTable[TABLE_SIZE];
extern BoolValue *boolTable[TABLE_SIZE];

// Funções utilitárias
unsigned int hash(const char *str);
void add_symbol(const char *name, VarType type, FILE *llvm_out);
void set_int_value(const char *name, int value, FILE *llvm_out);
void set_float_value(const char *name, float value, FILE *llvm_out);
void set_bool_value(const char *name, int value, FILE *llvm_out);
VarType get_variable_type(const char *name);
void free_llvm_val(llvm_val *val);

#endif // CALC_H
