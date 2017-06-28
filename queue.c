#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//takes the size of a stack page
t_queue *t_queue_create(unsigned long size)
{
    t_queue *q;
    
    q = (t_queue *)malloc(sizeof(t_queue));

    q->list = (t_single_linked_list *) t_single_linked_list_create();
    q->size = size;
    q->sp = 0;

    return q;
}

void t_queue_destroy(t_queue *q)
{
    t_single_linked_list_destroy( q->list );
    free(q);

    return;
}

int t_queue_enqueue( t_queue *q, void *data )
{
    q->sp++;
    t_single_linked_list_add_tail(q->list);
    t_single_linked_list_page_attach_data(q->list->tail, data, q->size );
}

void *t_queue_dequeue( t_queue *q )
{
    void *data;
    data = malloc( q->size );
    memcpy(data, q->list->head->data, q->size );
    t_single_linked_list_remove_head(q->list);
    q->sp--;
    return data;
}

void *t_queue_peek( t_queue *q )
{
    void *data;

    data = malloc( q->size );

    if(q->size >= q->list->head->size ) {
	fprintf(stderr, "page size is greater than queue page size. truncating\n" );
        memcpy(data, q->list->head->data, q->size );
    } else {
	memcpy(data, q->list->head->data, q->list->head->size );
    }

    return data;
}

