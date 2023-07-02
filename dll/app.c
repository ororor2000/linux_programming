#include "dll.h"
#include <stdio.h>

static int match_int(void *data, void *key) {
    int *number = (int*) data;
    int *key_num = (int*) key;

    printf("number: %d, key_num: %d\n", number, key_num);

    if (number == key_num) {
        printf("equal\n");
        return 0;
    }
    printf("not equal\n");
    return 1;
}

static int compare_int(void *a, void *b) {
    int *a_int = (int*)a;
    int *b_int = (int*)b;

    if (a_int == b_int) return 0;

    if (a_int > b_int) {
        return -1;
    } else {
        return 1;
    }
}

int main(int argc, char **argv) {
    dll_t *dll;
    dll_node_t *node;

    dll = create_new_dll();
    register_match_key_cb(dll, match_int);
    register_compare_key_cb(dll, compare_int);

    sorted_add(dll, 1);
    sorted_add(dll, 9);
    sorted_add(dll, 3);
    sorted_add(dll, 6);

    node = dll->head;

    while (node != NULL) {
        printf("item: %d\n", (node->data));
        node = node->right;
    }
    printf("\n\n\n");

    // delete_item(dll, dll->head->right->right->data);

    // int *n = (int*)search(dll, (void*)8);

    // if (n) {
    //     printf("found 3 in ,,list: %d\n", n);
    // } else {
    //     printf("could not find 3\n");
    // }
    

    // node = dll->head;

    // while (node != NULL) {
    //     printf("item: %d\n", (node->data));
    //     node = node->right;    
    // }
    
    free_dll(dll);
    
    return 0;
}