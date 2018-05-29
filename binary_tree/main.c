#include "tree.h"
#include <stdio.h>

#define INSERT 'I'
#define REMOVE 'R'
#define SHOW 'M'
#define SEARCH 'B'


int main() {
    int operations, i, key;
    char operation;

    binary_search_tree *tree = init();

    scanf("%d", &operations);

    for (i = 0; i < operations; i++) {
        scanf("\n%c %d", &operation, &key);

        switch (operation) {
            case INSERT:
                tree = add(key, tree);
                break;
            case REMOVE:
                tree = remove_node(key, tree);
                break;
            case SHOW:
                show_in_order(tree);
                printf("\n");
                break;
            case SEARCH:
                search(key, tree) == FOUND ? printf("S\n") : printf("N\n");
                break;
        }
    }

    return 0;
}
