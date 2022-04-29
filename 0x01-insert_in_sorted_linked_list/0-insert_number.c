#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - Function to insert a node
 * @head: pointer to next node
 * @number: number to add to new node
 * Return: 0
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node = NULL;
	listint_t *current_node = NULL;

	if (!head)
		return (NULL);
	new_node = malloc(sizeof(listint_t));
	if (!new_node)
		return (NULL);
	current_node = *head;
	new_node->n = number;

	if (current_node)
	{
		if (current_node->n > number)
		{
			new_node->next = prev_node;
			*head = new_node;
			return (new_node);
		}
		while (current_node->next)
		{
			if (current_node->next->n > number)
			{
				new_node->next = current_node->next;
				current_node->next = new_node;
				return (new_node);
			}
			current_node = current_node->next;
		}
		new_node->next = NULL;
		current_node->next = new_node;
		return (new_node);
	}
	new_node->next = NULL;
	*head = new_node;
	return (new_node);
}
