

//hold max of 4GB of data
struct _double_linked_list_page
{
    unsigned long size;
    void *data;
    struct _double_linked_list_page *next;
    struct _double_linked_list_page *prev;
};


//container for pages
struct _double_linked_list
{
    struct _double_linked_list_page *head;
    struct _double_linked_list_page *tail;
    struct _double_linked_list_page *page;
};

typedef struct _double_linked_list_page t_double_linked_list_page;
typedef struct _double_linked_list t_double_linked_list;

