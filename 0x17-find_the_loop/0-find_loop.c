#include "lists.h"
#include <stdio.h>

/**
 * find_listint_loop - Find the memory address
 * of starting node
 * @head: Pointer to the head
 * Return: The address of the node or NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *ab, *cd;

	if (!head)
		return (NULL);

	ab = cd = head;

	while (cd && ab && ab->next)
	{
		cd = cd->next;
		ab = (ab->next)->next;

		if (ab == cd)
		{
			cd = head;
			while (cd && ab)
			{
				if (cd == ab)
					return (cd);

				cd = cd->next;
				ab = ab->next;
			}
		}
	}
	return (NULL);
}
