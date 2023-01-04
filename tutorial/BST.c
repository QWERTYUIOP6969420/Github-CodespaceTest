#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode;

int *divideArray(int *array, int array_size);
void assignNodeValue(int val, TreeNode *node_to_assign);
void createLeftNode(int val, TreeNode *tree_to_add);
void createRightNode(int val, TreeNode *tree_to_add);
void printBinaryTree(TreeNode *tree);
void arrayToTree(int *array, int index, TreeNode *tree_to_make, int array_size);

int main()
{
    int dataset[] = {305, 170, 1057, 230, 21, 1, 0};
    struct TreeNode *binary_search_tree = malloc(sizeof(TreeNode));
    struct TreeNode **Pbinary_search_tree = &binary_search_tree;
    struct TreeNode *binary_search_tree_copy = *Pbinary_search_tree;
    assignNodeValue(dataset[0], binary_search_tree_copy);
    // createLeftNode(27, binary_search_tree_copy);
    // createRightNode(35, binary_search_tree_copy);
    // binary_search_tree_copy = binary_search_tree_copy->left;
    // createLeftNode(5, binary_search_tree_copy);
    arrayToTree(dataset, 1, binary_search_tree_copy, sizeof(dataset)/sizeof(dataset[0]));
    printBinaryTree(binary_search_tree);
}

void createLeftNode(int val, TreeNode *tree_to_add)
{
    tree_to_add->left = malloc(sizeof(TreeNode));
    tree_to_add->left->data = val;
}

void createRightNode(int val, TreeNode *tree_to_add)
{
    tree_to_add->right = malloc(sizeof(TreeNode));
    tree_to_add->right->data = val;
}

void printBinaryTree(TreeNode *tree)
{
    if(tree != NULL)
    {
        printf("Main: %d\n", tree->data);
        if(tree->left != NULL && tree->right != NULL)
        {
            printf("Left: %d\nRight: %d\n", tree->left->data, tree->right->data);
            printBinaryTree(tree->left);
            printBinaryTree(tree->right);
        } 
        else if(tree->left == NULL && tree->right == NULL)
        {
            printf("End of side\n");
        }
        else if(tree->left == NULL)
        {
            printf("Right: %d\n", tree->right->data);
            printBinaryTree(tree->right);
        } 
        else if(tree->right == NULL)
        {
            printf("Left: %d\n", tree->left->data);
            printBinaryTree(tree->left);
        } 
    }
}

void assignNodeValue(int val, TreeNode *node_to_assign)
{
    node_to_assign->data = val;
}

void arrayToTree(int *array, int index, TreeNode *tree_to_make, int array_size)
{
    int *array_indexes = divideArray(array, array_size);
    if(index < array_size - 1)
    {
        createLeftNode(array[index], tree_to_make);
        index++;
        createRightNode(array[index], tree_to_make);
        arrayToTree(array, index + 1, tree_to_make->left, array_size);
        arrayToTree(array, index + 3, tree_to_make->right, array_size);
    }
}

int *divideArray(int *array, int array_size)
{
    int y = 0;
    int *return_array = calloc(y + 1, sizeof(int));
    for(int i = 0; i < array_size; i++)
    {
        if(i == pow(2, y))
        {
            y++;
            return_array = calloc(1, sizeof(int));
            return_array[i] = i;
        }
    }
}











/*Pseudocode for creating a Tree
1. Find indexes that separate array into length of the powers of 2 
2. Use those indexes to separate layers by powers of two and inset grousp of two into the tree
*/