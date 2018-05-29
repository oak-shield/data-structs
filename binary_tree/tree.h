#define FOUND 1
#define NOT_FOUND 0

typedef struct Node_Binary_Search_Tree
{
    int key;
    struct Node_Binary_Search_Tree* left_subtree;
    struct Node_Binary_Search_Tree* right_subtree;

} binary_search_tree;

binary_search_tree* init();

binary_search_tree* create_node(int key, binary_search_tree *right, binary_search_tree *left);
binary_search_tree* add(int key, binary_search_tree* tree);

void show_in_order(binary_search_tree* tree);

int search(int key, binary_search_tree* tree);
binary_search_tree *search_node(int key, binary_search_tree *tree);

binary_search_tree *remove_node(int key, binary_search_tree *tree);
