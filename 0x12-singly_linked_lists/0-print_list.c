#include <stdio.h>
#include "lists.h"
/**
 * print_list: prints all element of a linked list by using list_t
 * @h: signly linked list to print
 * Return: number of node in the list
 */
size_t print_list(const list_t *h)
{
	size_t s = 0;

	while (h)
	{
		if (!h->str)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", h->len, h->str);
		h = h->next;
		s++;
	}

	return (s);
}
