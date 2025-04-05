#include "calc.h"

symrec *sym_table = nullptr;

symrec *putsym(const char name) {
    symrec *res = (symrec *)malloc(sizeof(symrec));
    res->name = name;
    res->value = 0;
    res->next = sym_table;
    sym_table = res;
    return res;
}

symrec *getsym(const char name) {
    for (symrec *ptr = sym_table; ptr != nullptr; ptr = ptr->next) {
        if (ptr->name == name) {
            return ptr;
        }
    }
    return nullptr;
}