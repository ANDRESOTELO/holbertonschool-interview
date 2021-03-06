#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
} binary_tree_t;

/*Max binary heap*/
typedef struct binary_tree_s heap_t;

/*Print function*/
void binary_tree_print(const binary_tree_t *);

/*New Node*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

/* Swap Function */
void swapFuntion(heap_t **node);

/* Heap Insert */
heap_t *heap_insert(heap_t **root, int value);
heap_t *test(heap_t **root);

#endif /* _BINARY_TREES_H_ */