#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

binary_search_tree *init() {
    return NULL;
}

binary_search_tree *create_node(int key, binary_search_tree *right, binary_search_tree *left) {
    binary_search_tree *new_node = (binary_search_tree *) malloc(sizeof(binary_search_tree));

    new_node->key = key;
    new_node->right_subtree = right;
    new_node->left_subtree = left;

    return new_node;
}

binary_search_tree *add(int key, binary_search_tree *tree) {

    if (!tree) {
        return create_node(key, NULL, NULL);
    }

    if (key < tree->key) {
        tree->left_subtree = add(key, tree->left_subtree);
        return tree;
    }

    if (key > tree->key) {
        tree->right_subtree = add(key, tree->right_subtree);
        return tree;
    }
}

void show_in_order(binary_search_tree *tree) {

    if (!tree)
        return;

    show_in_order(tree->left_subtree);
    printf("%d ", tree->key);
    show_in_order(tree->right_subtree);
}

int search(int key, binary_search_tree *tree) {
    return (search_node(key, tree) != NULL ? FOUND : NOT_FOUND);
}

binary_search_tree *search_node(int key, binary_search_tree *tree) {
    binary_search_tree *aux = NULL;

    if (tree != NULL) {

        if (key == tree->key) {
            return tree;
        } else {
            if (key > tree->key)
                return search_node(key, tree->right_subtree);

            if (key < tree->key)
                return search_node(key, tree->left_subtree);
        }
    }

    return aux;
}

binary_search_tree *remove_node(int key, binary_search_tree *tree) {

    if (!tree)
        return NULL;

    if (tree->key > key) {
        tree->left_subtree = remove_node(key, tree->left_subtree);
        return tree;

    }
    if (tree->key < key) {
        tree->right_subtree = remove_node(key, tree->right_subtree);
        return tree;
    }

    if (!tree->right_subtree || !tree->left_subtree) {

        binary_search_tree *aux = (!tree->left_subtree) ? tree->right_subtree : tree->left_subtree;
        free(tree);

        return aux;
    }

    binary_search_tree *parent = tree;
    binary_search_tree *it = tree->left_subtree;

    while (it->right_subtree) {
        parent = it;
        it = it->right_subtree;
    }

    tree->key = it->key;

    if (parent == tree) {
        parent->left_subtree = it->left_subtree;
    } else {
        parent->right_subtree = it->left_subtree;
    }

    free(it);

    return tree;
}