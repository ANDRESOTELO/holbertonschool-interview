#include "lists.h"
#include <stdlib.h>

/**
 *add_node - Function to insert a node
 *@head: pointer to next node
 *@number: number to add to new node
 *Return: The number of nodes
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node = NULL;
    listint_t *prev_node = NULL;
    listint_t *next_node = NULL;

    /* Allocate memory to new node */
	new_node = malloc(sizeof(listint_t));

    /* Check if new node allocate memory success */
	if (new_node)
    {
        /* Assign number to the variable in the new node */
        new_node->n = number;

        if (head)
        {
            /* Assign head to the previous node */
            prev_node = *head;

            if (!prev_node)
            {
                new_node->next_node = prev_node;
                *head = new_node;
                return (new_node);
            }

            next_node = prev_node->next_node;
            if (prev_node->n > number)
            {
                new_node->next_node = prev_node;
                *head = new_node;
                return (new_node);
            }
            while (next_node && next_node->n < number)
            {
                prev_node = prev_node->next_node;
                next_node = next_node->next_node;
            }
            prev_node->next_node = new_node;
            new->next_node = next_node;
        }
        return (new_node);
    }
    else
    {
        return (NULL);
    }
}
