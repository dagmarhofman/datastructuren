/*
    Datastructures and algorithms api.
    Example os all common used datastructures and algorithms.

    my implementation of the single linked lists, comes
    with a stack of pointers per node.

*/

#define SUCCESS 0
#define FAIL -1
#define TRUE 1
#define FALSE 0

typedef struct single_list_page_attr
{
    void *data;
    unsigned int size;
} t_single_list_page_attr;


typedef struct single_list_page
{
    t_single_list_page_attr *attr;
    struct single_list_page *next;

} t_single_list_page;

typedef struct single_list {
    t_single_list_page *page;
    t_single_list_page *head;
    t_single_list_page *tail;
//    bool is_circular; later issue
} t_single_list;

//prototypes

t_single_list *t_single_list_create(void);
t_single_list_page *t_single_list_page_create(void);
void t_single_list_page_destroy(t_single_list_page *page);
void t_single_list_destroy( t_single_list *list);
void t_single_list_add_head( t_single_list *list );
void t_single_list_add_tail( t_single_list *list);
void t_single_list_insert_next( t_single_list *list);
int t_single_list_get_size( t_single_list *list );
char t_single_list_remove_head( t_single_list *list );
char t_single_list_remove_next( t_single_list *list);
char t_single_list_remove_tail( t_single_list *list);
char t_single_list_move_next( t_single_list *list );
/*
int t_single_list_page_create_data( t_single_list_page *page, void *data, int size );
int t_single_list_page_resize_data( t_single_list_page *page, void *data, int size);
void t_single_list_page_destroy_data( t_single_list_page *page );
*/
