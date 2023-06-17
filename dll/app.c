#include "dll.h"
#include <stdio.h>

int main(int argc, char **argv) {
    dll_t *dll;
    dll_node_t *node;

    dll = create_new_dll();

    add_data(dll, (void*)1);
    add_data(dll, (void*)2);
    add_data(dll, (void*)3);
    add_data(dll, (void*)6);

    node = dll->head;

    while (node != NULL) {
        printf("item: %d\n", (int)node->data);
        node = node->right;
    }

    free_dll(dll);

    return 0;
}