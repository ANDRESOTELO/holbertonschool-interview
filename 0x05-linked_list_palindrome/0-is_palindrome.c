#include "lists.h"

/**
 * is_palindrome - function in C that checks if a singly linked list is a palindrome.
 * @head: Head single linked list.
 *
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome.
 */
int is_palindrome(listint_t **head)
{
	int i = 0;
	int len = 0;
	int *array;
	listint_t *temp = NULL;

	if (*head)
	{
		temp = *head;
		while (temp)
		{
			temp = temp->next;
			len++;
		}
		array = malloc(len * sizeof(int));
		temp = *head;
		for (i = len - 1; i >= 0; i--)
		{
			array[i] = temp->n;
			temp = temp->next;
		}
		temp = *head;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] != temp->n)
			{
				free(array);
				return (0);
			}
			temp = temp->next;
		}
		free(array);
	}
	return (1);
}
