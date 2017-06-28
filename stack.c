#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    t_stack_pop and t_stack_peek, returns copy of data.
*/

//takes the size of a stack page
t_stack *t_stack_create(unsigned long size)
{
    t_stack *t;
    
    t = (t_stack *)malloc(sizeof(t_stack));

    t->list = (t_single_linked_list *) t_single_linked_list_create();
    t->size = size;
    t->sp = 0;

    return t;
}

void t_stack_destroy(t_stack *t)
{
    t_single_linked_list_destroy(t->list);
    free(t);

    return;
}

int t_stack_push( t_stack *s, void *data )
{
    s->sp++;
    t_single_linked_list_add_tail(s->list);
    t_single_linked_list_page_attach_data(s->list->tail, data, s->size );
}

void *t_stack_pop( t_stack *s )
{
    void *data;
    data = malloc( s->size );
    memcpy(data, s->list->tail->data, s->size );
    t_single_linked_list_page_detach_data(s->list->tail);
    t_single_linked_list_remove_tail(s->list);
    s->sp--;
    return data;
}

void *t_stack_peek( t_stack *s )
{
    void *data;

    data = malloc( s->size );

    if(s->size >= s->list->tail->size ) {
	fprintf(stderr, "page size is greater than stack page size. truncating\n" );
        memcpy(data, s->list->tail->data, s->size );
    } else {
	memcpy(data, s->list->tail->data, s->list->tail->size );
    }

    return data;
}

