#include "lists.h"

/**
 * free_list - Counts the number of unique nodes
 * in a looped listint_t linked list.
 * @head: A pointer to the head of the listint_t to check.
 * Return: If the list is not looped - 0.
 */
size_t free_list(const listint_t *head)
{
	const listint_t *new, *temp;
	size_t nodes = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	new = head->next;
	temp = (head->next)->next;

	while (temp)
	{
		if (new == temp)
		{
			new = head;
			while (new != temp)
			{
				nodes++;
				new = new->next;
				temp = temp->next;
			}

			new = new->next;
			while (new != temp)
			{
				nodes++;
				new = new->next;
			}

			return (nodes);
		}

		new = new->next;
		temp = (temp->next)->next;
	}

	return (0);
}

/**
 * print_listint_safe - Prints a listint_t list safely.
 * @head: A pointer to the head of the listint_t list.
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nodes, index = 0;

	nodes = free_list(head);

	if (nodes == 0)
	{
		for (; head != NULL; nodes++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}

	else
	{
		for (index = 0; index < nodes; index++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}

		printf("-> [%p] %d\n", (void *)head, head->n);
	}

	return (nodes);
}

