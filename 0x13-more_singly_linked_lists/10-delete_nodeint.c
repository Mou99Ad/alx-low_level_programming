#include <stdlib.h>
#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes the node at a given position in a linked list.
 * @head: Pointer to the pointer of the head node.
 * @index: Index of the node to be deleted.
 * 
 * Return: 1 if it succeeded, -1 if it failed.
*/

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current, *temp;
	unsigned int i;

	if (!head || !*head)
		return (-1);

	if (index == 0)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
		return (1);
	}

	current = *head;
	for (i = 0; current && i < index - 1; i++)
		current = current->next;

	if (!current || !current->next)
		return (-1);

	temp = current->next;
	current->next = temp->next;
	free(temp);

	return (1);
}
