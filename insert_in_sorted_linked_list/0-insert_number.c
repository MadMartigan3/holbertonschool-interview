#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - inserst a node in a sorted linked list
 * @head: pointer to pointer of first node of listint_t list
 * @number: integer to be included in new node
 * Return: address of the new element or NULL if it fails
 */

listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new;
    listint_t *current;

    current = *head;

    new = malloc(sizeof(listint_t));
    if (new == NULL)
        return (NULL);

    new->n = number;
    new->next = NULL;

    if (*head == NULL || (*head)->n >= new->n)
    {
        new->next = *head;
        *head = new;
    }
    else
    {
        while (current-> next != NULL && current->next->n < new->n)
            current = current->next;
        new->next = current->next;
        current->next = new;
    }


    return (new);

}
