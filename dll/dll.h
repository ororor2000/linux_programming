#ifndef __dll__
#define __dll__

/* single dobule linked list node */
typedef struct dll_node_ {
    void *data;
    struct dll_node *left;
    struct dll_node *right;
} dll_node_t;

/* struct cotaining the head node of the double linked list */
typedef struct dll_
{
    struct dll_node_t *head;    
    
} dll_t;

#define DLL_T_STRUCT_SIZE sizeof(dll_t)
#define DLL_NODE_T_STRUCT_SIZE sizeof(dll_node_t)

/* function returning a pointer to a new double linked list */
dll_t *create_new_dll(void);

/* function for adding a new element to the double linked lits 'dll' */
int add_data(dll_t *dll, void *data);

int free_dll(dll_t *dll);

#endif