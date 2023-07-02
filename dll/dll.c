#include "dll.h"
#include <stdlib.h>
#include <memory.h>

dll_t *create_new_dll(void) {
    dll_t *dll = calloc(0, DLL_T_STRUCT_SIZE);
    dll->head = NULL;    

    return dll;
}

int add_data(dll_t *dll, void *data) {
    /* validating data */
    if (!dll || !data) return 1;
    

    /* alocating new node and assiging data to it*/
    dll_node_t *new_node = calloc(0, DLL_NODE_T_STRUCT_SIZE);
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    /* if head is NULL, assign it new_node as head*/
    if (!dll->head) {       
        dll->head = new_node;
        return 0;
    }

    /* saving a pointer to the head of  the list*/
    dll_node_t *old_head = dll->head;

    /* setting new node to the the right of old_head */
    new_node->right = old_head;
    old_head->left = new_node;

    /*setting head at the start of the list*/
    dll->head = new_node;

    return 0;
}

int free_dll(dll_t *dll) {
    dll_node_t *node = dll->head;

    while(node != NULL) {
        dll_node_t *prev = node;
        node = node->right;

        free(prev);        
    }

    free(dll);

    return 0;
}

void register_match_key_cb(dll_t *dll, int (*key_match)(void*, void*)) {
    dll->key_match = key_match;
}

void register_compare_key_cb(dll_t *dll, int (*compare_key)(void*, void*)) {
    dll->compare_key = compare_key;
}