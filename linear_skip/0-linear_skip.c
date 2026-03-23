#include <stdio.h>
#include <stdlib.h>
#include "search.h"


/**
 * linear_skip - Searches for a value in a skiplist
 *
 * @head: Pointer to the head of the skiplist to search in
 * @value: Value to search for
 *
 * Return: Pointer on the first node where value is located, or NULL
 */
skiplist_t *linear_skip(skiplist_t *head, int value)
{
	skiplist_t *search, *express;

	if (head == NULL)
		return (NULL);

	express = head;
	search = head;

	while (express->express != NULL)
	{
		search = express;
		express = express->express;
		printf("Value checked at index [%lu] = [%d]\n", express->index, express->n);
		if (express->n >= value)
			break;
		if (express->express == NULL)
		{
			search = express;
			while (express->next != NULL)
			{
				express = express->next;
			}
		}
	}
	printf("Value found between indexes [%lu] and [%lu]\n",
		search->index, express->index);

	while (search->next != NULL && search->index != express->index)
	{
		printf("Value checked at index [%lu] = [%d]\n", search->index, search->n);
		if (search->n == value)
			break;
		search = search->next;
	}
	if (search->next == NULL)
		printf("Value checked at index [%lu] = [%d]\n", search->index, search->n);
	if (search->n == value)
		return (search);

	return (NULL);
}
