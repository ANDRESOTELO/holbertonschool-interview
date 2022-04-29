#include "lists.h"

/**
 *add_node - Function to insert a node
 *@head: pointer to next node
 *@number: number to add to new node
 *Return: The number of nodes
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node = NULL;
    listint_t *current_node = NULL;

    /* If head doesn´t exists */
    if (!head)
        return (NULL);

    /* Allocate memory to new node */
	new_node = malloc(sizeof(listint_t));

    /* Check if new node allocate memory success */
	if (!new_node)
		return (NULL);

    /* Assign head to current node */
    current_node = *head;

    /* Assign number to the variable in the new node */
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
