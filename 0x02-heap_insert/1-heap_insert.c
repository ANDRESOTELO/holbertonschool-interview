#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"


/**
 * test - Find parent node.
 * @root: root
 * Return: Node to parent.
 */

heap_t *test(heap_t **root)
{
	heap_t *node = NULL;
	heap_t *array[100];
	int front = 0;
	int reer = 0;


	array[reer] = *root;
	while (2021)
	{
		node = array[front];
		front++;
		if (!node->left)
		{
			front = reer = 0;
			return (node);
		}
		else if (!node->right)
		{
			front = reer = 0;
			return (node);
		}
		else
		{
			reer = reer + 1;
			array[reer] = node->left;
			reer = reer + 1;
			array[reer] = node->right;
		}
	}
}


/**
 * swapFuntion - Function to swap Node.
 * @myNode: A pointer to the first node 
 * Return: No returns
 */

void swapFuntion(heap_t **node)
{
	int temp;
	heap_t *move_node;

	for (move_node = *node; move_node->parent; move_node = move_node->parent)
		if (move_node->n > move_node->parent->n)
		{
			temp = move_node->parent->n;
			move_node->parent->n = move_node->n;
			move_node->n = temp;
			*node = move_node->parent;
		}
}


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
	heap_t *new = NULL;
	heap_t *parent = NULL;

	if (*root == NULL)
	{
		*root = binary_tree_node(*root, value);
		return (*root);
	}
	parent = testx(root);
	new = binary_tree_node(parent, value);
	if (!parent->left)
		parent->left = new;
	else
		parent->right = new;

	if (new->n > parent->n)
		swapFuntion(&new);
	return (new);
}