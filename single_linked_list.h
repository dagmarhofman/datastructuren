

//hold max of 4GB of data
struct _single_linked_list_page
{
    unsigned long size;
    void *data;
    struct _single_linked_list_page *next;
};


//container for pages
struct _single_linked_list
{
    struct _single_linked_list_page *head;
    struct _single_linked_list_page *tail;
    struct _single_linked_list_page *page;
};

typedef struct _single_linked_list_page t_single_linked_list_page;
typedef struct _single_linked_list t_single_linked_list;

