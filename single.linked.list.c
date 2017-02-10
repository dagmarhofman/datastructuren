/*
    Single linked list and circular single linked list implementation.

*/
#include <stdio.h>
#include <stdlib.h>

#include "single.linked.list.h"

//construct one page
t_single_list_page *t_single_list_page_create(void)
{
    t_single_list_page *page;
    page = (t_single_list_page *) malloc( sizeof(t_single_list_page) );

    if( page == NULL ) {
        fprintf(stderr, "Could not allocate memory. exiting.\n");
        exit(1);
    }
/*
    page->attr->data = NULL;
    page->attr->size = -1;
*/
    return page;
}

//destruct single page
void t_single_list_page_destroy(t_single_list_page *page)
{

  //  t_single_list_page_destroy_data(page);
    //free(page);
    return;
}

//construct the list itself
t_single_list *t_single_list_create(void)
{
    t_single_list *retval;
    retval = (t_single_list *) malloc( sizeof( t_single_list ));

    if( retval == NULL ) {
        fprintf(stderr, "Could not allocate memory. exiting.\n");
        exit(1);
    }

    retval->page = NULL;
    retval->head = NULL;
    retval->tail = NULL;


    return retval;
}

//destruct the whole list
void t_single_list_destroy(t_single_list *list)
{
    while(t_single_list_get_size(list) > 0)
        t_single_list_remove_tail(list);
    free(list);
    return;
}

//add head to list.
//page keeps pointing
void t_single_list_add_head(t_single_list *list)
{
    t_single_list_page *node = t_single_list_page_create();

    if (list->head == NULL)  {
        list->page = node;
        list->tail = node;
        list->head = node;
    } else  {
        node->next = list->head;
        list->head = node;
    }
    return;
}

//add tail to list.
//page keeps pointing
void t_single_list_add_tail(t_single_list *list)
{
    t_single_list_page *node = t_single_list_page_create();

    if (list->head == NULL)  {
        list->page = node;
        list->tail = node;
        list->head = node;
    } else  {
        list->tail->next = node;
        list->tail = node;
    }
    return;
}
// insert page into list.
void t_single_list_insert_next(t_single_list *list)
{
    t_single_list_page *node;
    t_single_list_page *p;
    node = t_single_list_page_create();

    if( t_single_list_get_size(list) == 0) {
        list->head = node;
        list->tail = node;
        list->page = node;
    }
    else if( t_single_list_get_size(list) == 1 ) {
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
char t_single_list_remove_next(t_single_list *list)
{
    t_single_list_page *tmp;

    if( t_single_list_get_size(list) <= 1 )
        return FAIL;

    if( list->page->next == NULL )
        return FAIL;

    if(list->page->next == list->tail)
        return t_single_list_remove_tail(list);

    tmp = list->page->next;
    list->page->next = list->page->next->next;
    t_single_list_page_destroy(tmp);
    return SUCCESS;
}


//remove tail.
char t_single_list_remove_tail(t_single_list *list )
{
    int list_size;

    t_single_list_page *tmp = list->tail;

    list_size = t_single_list_get_size(list);

    if( list_size == 0 )
        return FAIL;
    else if ( list_size == 1 ) {
        list->tail = NULL;
        list->head = NULL;
        list->page = NULL;
    } else {
        list->page = list->head;
        while(list->page->next->next != NULL)
            list->page = list->page->next;
        tmp = list->page->next;
        list->tail = list->page;
        list->page->next = NULL;
    }

    t_single_list_page_destroy( tmp);
    return SUCCESS;
}

//moves not further than the tail
char t_single_list_move_next( t_single_list *list )
{
    if(list->head == NULL )
        return FAIL;
    if(list->page->next == NULL)
        return FAIL;

    list->page = list->page->next;
    return SUCCESS;
}

//remove head
char t_single_list_remove_head(t_single_list *list)
{
    t_single_list_page *tmp;

    int list_size;

    list_size = t_single_list_get_size(list);
    tmp = list->head;

    if(list_size == 0)
        return FAIL;
    else if( list_size == 1) {
        list->head = NULL;
        list->tail = NULL;
        list->page = NULL;
     } else {
        //not to wire the page pointer at the removed head.
        if( list->page == list->head )
            list->page = list->head->next;
        list->head = list->head->next;
    }
    t_single_list_page_destroy(tmp);
    return SUCCESS;
}

//get the size of the list in nodes.
int t_single_list_get_size(t_single_list *list)
{
    int retval=0;

    t_single_list_page *p;

    p = list->head;
    while( p != NULL ) {
	retval++;
        p = p->next;
    }
    return retval;
}
/*
int t_single_list_page_create_data( t_single_list_page *page, void *data, int size )
{
    data = malloc( size );
    if( data == NULL ) {
        fprintf(stderr, "Could not allocate memory. exiting.");
        exit(1);
    }

    page->attr->data = data;
    page->attr->size = size;

    return size;
}


void t_single_list_page_destroy_data( t_single_list_page *page )
{
    free(page->attr->data);
    page->attr->size = -1;
    page->attr->data = NULL;
    return;
}

int t_single_list_page_resize_data( t_single_list_page *page, void *data, int size)
{
    void *new_data;
    new_data = realloc(data, size);

    if( new_data == NULL ) {
        fprintf(stderr, "Could not allocate memory. exiting.");
        exit(1);
    }
    page->attr->data = new_data;
    page->attr->size = size;
    return size;
}
*/
//get_mem_size of linked list??
//for proper algorithmics, what key do we fetch from the page and how and why?
//page frames?
