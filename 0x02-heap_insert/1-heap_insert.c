#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

heap_t *parent = NULL;

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 *
 * @root: Double pointer to the root node of the Heap
 * @value: Value to store in the node to be inserted
 *
 * Return: a pointer to the inserted node, or NULL on failure
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *node = *root;

	if (root != NULL)
	{
		if (node == NULL)
		{
			node = binary_tree_node(parent, value);
			if (*root == NULL)
				*root = node;
			return (node);
		}
		if (node->left != NULL && node->right == NULL)
		{
			parent = node;
			heap_insert(&node->right, value);
		}
		else
		{
			parent = node;
			heap_insert(&node->left, value);
		}
	}
	return (NULL);
}