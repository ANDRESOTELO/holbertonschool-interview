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
	listint_t *new_node = NULL, *current = NULL;

	if (head == NULL)
			return (NULL);

	current = *head;

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = number;

	if (current != NULL)
	{
		while (current->next != NULL)
		{
			if (number < current->next->n)
			{
				new_node->next = current->next;
				current->next = new_node;
				return (new_node);
			}
			current = current->next;
		}
		new_node->next = NULL;
		current->next = new_node;
		return (new_node);
	}
	new_node->next = NULL;
	*head = new_node;
	return (new_node);
}
