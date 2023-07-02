#include "dll.h"
#include <stdlib.h>
#include <stdio.h>

int delete_item(dll_t *dll, void* data) {
    if (!dll->head) return 1;

    dll_node_t *node = dll->head;
    dll_node_t *prev_node = NULL;

    while (node != NULL) {
        void* node_data = node->data;
        if (node_data == data) {
            if (prev_node == NULL) {    
                dll->head = node->right;
            } else {            
                prev_node->right = node->right;
                if (node->right != NULL) {
                    node->right->left = prev_node;
                }
            }

            free(node);
            return 0;
        }

        prev_node = node;
        node = node->right;
    }

    return 1;
}

int is_dll_empty(dll_t *dll) {
    return !dll->head ? 1 : 0;
}

void* search(dll_t *dll, void *data) {
    if (!dll || !dll->head) return NULL;

    dll_node_t *head = dll->head;
    void* head_data = NULL;


    while(head) {
        head_data = head->data;
        printf("head data: %d, key: %d\n", head_data, data);
        if (dll->key_match(head_data, data) == 0) {
            return head->data;
        }
        
        head = head->right;
    }

    return NULL;
}

int sorted_add(dll_t *dll, void *data) {
    if(!dll)
        return -1;

    /*if DLL is empty*/
    if(!dll->head){
        add_data(dll, data);
        return 0;
    }

    dll_node_t *data_node = calloc(1, sizeof(dll_node_t));
    data_node->data = data;
    data_node->left = NULL;
    data_node->right = NULL;

    /* if there is only one node in DLL*/
    if(dll->head && !dll->head->right){                
        if(dll->compare_key(dll->head->data, data) == -1){
            dll->head->right = data_node;
            data_node->left = dll->head;
        }
        else{
            dll->head->left = data_node;
            data_node->right = dll->head;
            dll->head = data_node;
        }
        return 0;
    }

    /*if More than one node in DLL*/
    if(dll->compare_key(data, dll->head->data) == -1){
        data_node->right = dll->head;
        dll->head->left = data_node;
        dll->head = data_node;
        return 0;
    }

    dll_node_t *prev = NULL,
               *curr = NULL;

    curr = dll->head;

    while(curr){
        if(dll->compare_key(data, curr->data) != -1){
            prev = curr;
            curr = curr->right;
            continue;
        }

        prev->right = data_node;
        data_node->left = prev;
        data_node->right = curr;
        curr->left = data_node;
        return 0;
    }

    /*Add in the end*/
    prev->right = data_node;
    data_node->left = prev;
    return 0;
}