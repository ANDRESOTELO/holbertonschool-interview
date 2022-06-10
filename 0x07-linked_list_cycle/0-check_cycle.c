#include "lists.h"

/**
* check_cycle -  Linked list cycle
*
* @list: pointer to linked list
*
* Return: 0 if there is no cycle or 1 if there is a cycle
*/

int check_cycle(listint_t *list)
{
	listint_t *f = list;
	listint_t *s = list;

	while (s && f && f->next)
	{
		s = s->next;
		f = f->next->next;

		if (s == f)
		{
			return (1);
		}
	}
	return (0);
}