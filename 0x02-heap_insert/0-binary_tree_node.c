#include "binary_trees.h"
/**
 * binary_tree_node - Create a binary tree node
 * @parent: Pointer to the parent node of the node to Create
 * @value: Value to put in the new node
 * Return: Pointer to the new node or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node = NULL;

    /*Allocate memory for the new node*/
    new_node = (binary_tree_t *)malloc(sizeof(binary_tree_t));

    if (new_node == NULL)
    {
        return (NULL);
    }

    /*Set the value of the node*/
    new_node->n = value;
    /*Set the parent of the node*/
    new_node->parent = parent;

    new_node->left = NULL;
    new_node->right = NULL;

    return (new_node);
}
