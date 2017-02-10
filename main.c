#include <stdio.h>
#include <stdlib.h>

#include "single.linked.list.h"


void t_single_list_print( t_single_list *list )
{
    int i;
    t_single_list_page *tmp;
    tmp=list->page;
    list->page = list->head;
    printf("-----------------------------------------\n");
    while(list->page != list->tail ) {
        printf("(h: 0x%x t: 0x%x p: 0x%x -> 0x%x )\n", (int)list->head, (int)list->tail, (int)list->page, (int)list->page->next );
        t_single_list_move_next(list);
    }
    printf("-----------------------------------------\n");
    list->page = tmp;
}
void t_single_list_test_case( t_single_list *list )
{
    int i,j;
    char *test = "Hello World";
    char c;

    //toss 500 random insert and remove functions
    for(j=0;j<=50000;j++) {
        i = rand() % 12;

        //printf("-> %i %i\n", i,  j);
        //t_single_list_print(list);
        switch(i) {
            case 1:
                t_single_list_add_head(list);
                break;
            case 2:
                t_single_list_add_tail(list);
                break;
            case 3:
                c= t_single_list_remove_head(list);
                break;
            case 4:
                c = t_single_list_remove_tail(list);
                break;
            case 5:
                c = t_single_list_remove_next(list);
                break;
            case 6:
                t_single_list_insert_next(list);
                break;
            case 7:
                list->page = list->tail;
                break;
            case 8:
                list->page = list->head;
                break;
            case 9:
                c = t_single_list_move_next(list);
                break;

        }
        //printf("%s\n", c ? "FAIL" : "SUCCESS" );
    }
}


int main(void)
{
    int ret;
    t_single_list *t;

    t = t_single_list_create();

    t_single_list_test_case(t);

    t_single_list_destroy(t);

}
