#ifndef __dll__
#define __dll__

struct dll_node_;
struct dll_;


/* single dobule linked list node */
typedef struct dll_node_ {
    void *data;
    struct dll_node_ *left;
    struct dll_node_ *right;
} dll_node_t;

/* struct cotaining the head node of the double linked list */
typedef struct dll_
{
    dll_node_t *head;
    int (*key_match)(void*, void*);
    int (*compare_key)(void*, void*);
} dll_t;

#define DLL_T_STRUCT_SIZE sizeof(dll_t)
#define DLL_NODE_T_STRUCT_SIZE sizeof(dll_node_t)

/* function returning a pointer to a new double linked list */
dll_t *create_new_dll(void);

/* function for adding a new element to the double linked lits 'dll' */
int add_data(dll_t *dll, void *data);

int sorted_add(dll_t *dll, void* data);

/* delete item by data*/
int delete_item(dll_t *dll, void* data);

/* checks if the double link list is empty*/
int is_dll_empty(dll_t *dll);

/* freeing up all memeory used by dll_t */
int free_dll(dll_t *dll);

void register_match_key_cb(dll_t *dll, int (*key_match)(void*, void*));

void register_compare_key_cb(dll_t *dll, int (*compare_key)(void*, void*));

void* search(dll_t *dll, void *data);

#endif