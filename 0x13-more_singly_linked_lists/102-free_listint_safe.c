#include "lists.h"

/**
 * free_listint_safe - frees a listint_t list.
 * @head: pointer to the first node in the linked list
 * Return: the size of the list that was free’d
 */
size_t free_listint_safe(listint_t **head)
{
	size_t node = 0;
	int diff;
	listint_t *temp;

	if (!head || !*head)
		return (0);

	while (*head)
	{
		diff = *head - (*head)->next;
		if (diff > 0)
		{
			temp = (*head)->next;
			free(*head);
			*head = temp;
			node++;
		}
		else
		{
			free(*head);
			*head = NULL;
			node++;
			break;
		}
	}

	*head = NULL;

	return (node);
}

