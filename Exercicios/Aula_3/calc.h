#include <stdlib.h>
#include <string.h>

struct symrec {
    char name;
    double value;
    symrec *next;
};

extern symrec *sym_table;

symrec *putsym(const char name);
symrec *getsym(const char name);