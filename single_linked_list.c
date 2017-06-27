#include "single_linked_list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

t_single_linked_list *t_single_linked_list_create( void )
{
    t_single_linked_list *t;
    t = (t_single_linked_list *)malloc(sizeof(t_single_linked_list));
    if( t == NULL ) {
	fprintf(stderr,"Could not create list. Exiting.\n");
	exit(0);
    }
    t->head = NULL;
    t->tail = NULL;
    t->page = NULL;

    return t;
}

t_single_linked_list_page *t_single_linked_list_page_create( void )
{
    t_single_linked_list_page *p;
    p = (t_single_linked_list_page *)malloc(sizeof(t_single_linked_list_page));
    if( p == NULL ) {
	fprintf(stderr,"Could not create list. Exiting.\n");
	exit(0);
    }

    p->size = 0;
    p->next = NULL;
    return p;
}

void t_single_linked_list_add_tail( t_single_linked_list *t )
{
    t_single_linked_list_page *p;
    t_single_linked_list_page *tmp;
    p = t_single_linked_list_page_create();
    if( p == NULL) {
	fprintf(stderr,"Could not create page. Exiting.\n");
	exit(0);
    }

    if (t->head == NULL)  {
        t->page = p;
        t->tail = p;
        t->head = p;
    } else  {
        t->tail->next = p;
        t->tail = p;
    }

    return;
}


void t_single_linked_list_add_head( t_single_linked_list *t )
{
    t_single_linked_list_page *p;
    t_single_linked_list_page *tmp;

    p = t_single_linked_list_page_create();

    if( p == NULL) {
	fprintf(stderr, "Could not create page. Exiting.\n");
	exit(0);
    }

    if (t->head == NULL)  {
        t->page = p;
        t->tail = p;
        t->head = p;
    } else  {
        p->next = t->head;
        t->head = p;
    }
    return;
}

int t_single_linked_list_get_size(t_single_linked_list *l)
{
    int retval=0;

    t_single_linked_list_page *p;

    p = l->head;
    while( p != NULL ) {
	retval++;
        p = p->next;
    }
    return retval;
}

void t_single_linked_list_page_destroy(t_single_linked_list_page *p )
{
    free( p->data );
    free( p );
    return;
}



char t_single_linked_list_remove_head( t_single_linked_list *t )
{
    t_single_linked_list_page *tmp;

    int list_size;

    list_size = t_single_linked_list_get_size(t);
    tmp = t->head;

    if(list_size == 0)
        return 0;
    else if( list_size == 1) {
        t->head = NULL;
        t->tail = NULL;
        t->page = NULL;
     } else {
        //not to wire the page pointer at the removed head.
        if( t->page == t->head )
            t->page = t->head->next;
        t->head = t->head->next;
    }
    t_single_linked_list_page_destroy(tmp);
    return 1;

}

char t_single_linked_list_remove_tail( t_single_linked_list *t )
{
   int list_size;

    t_single_linked_list_page *tmp = t->tail;

    list_size = t_single_linked_list_get_size(t);

    if( list_size == 0 )
        return 0;
    else if ( list_size == 1 ) {
        t->tail = NULL;
        t->head = NULL;
        t->page = NULL;
    } else {
        t->page = t->head;
        while(t->page->next->next != NULL)
            t->page = t->page->next;
        tmp = t->page->next;
        t->tail = t->page;
        t->page->next = NULL;
    }

    t_single_linked_list_page_destroy( tmp);
    return 1;
}

void t_single_linked_list_destroy(t_single_linked_list *t )
{
    while( t_single_linked_list_get_size(t) > 0 )
	t_single_linked_list_remove_tail(t);
    free( t );
    return;
}

// insert page into list.
void t_single_linked_list_insert_next(t_single_linked_list *list)
{
    t_single_linked_list_page *node;
    t_single_linked_list_page *p;
    node = t_single_linked_list_page_create();

    if( t_single_linked_list_get_size(list) == 0) {
        list->head = node;
        list->tail = node;
        list->page = node;
    }
    else if( t_single_linked_list_get_size(list) == 1 ) {
        list->tail->next = node;
        list->tail = node;
    } else {
        if(list->page->next == NULL) {
            list->page->next = node;
            list->tail = list->page->next;
        } else {
            node->next = list->page->next;
            list->page->next = node;
        }
    }
    return;
}

//remove_next
char t_single_linked_list_remove_next(t_single_linked_list *list)
{
    t_single_linked_list_page *tmp;

    if( t_single_linked_list_get_size(list) <= 1 )
        return 0;

    if( list->page->next == NULL )
        return 0;

    if(list->page->next == list->tail)
        return t_single_linked_list_remove_tail(list);

    tmp = list->page->next;
    list->page->next = list->page->next->next;
    t_single_linked_list_page_destroy(tmp);
    return 1;
}

void t_single_linked_list_page_attach_data(t_single_linked_list_page *p, void *data, unsigned long len )
{
    p->size = len;
    p->data = malloc( len );
    memcpy(p->data, data, len );
    return;
}

void t_single_linked_list_page_detach_data(t_single_linked_list_page *p )
{
    free(p->data);
    p->size = 0;
    return;
}
