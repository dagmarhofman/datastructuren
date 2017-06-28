#include "single_linked_list.h"

/*
    implement a stack over a single linked list.
*/

struct _stack {
    unsigned long sp;
    unsigned long size;
    t_single_linked_list *list;
};

typedef struct _stack t_stack;
