#include "lists.h"

/**
 * free_listint_safe - prints the elements of a linked list of structures
 * @head: the pointer to the pointer to the first element of the list
 * Return: the number of nodes
 */
size_t free_listint_safe(listint_t **head)
{
	int pdiff, count;
	listint_t *temp;

	if (head == NULL || *head == NULL)
		return (0);
	for (count = 0; *head; count++)
	{
		pdiff = *head - (*head)->next;
		if (pdiff > 0)
		{
			temp = *head;
			*head = (*head)->next;
			free(temp);
		}
		else
		{
			free(*head);
			count++;
			break;
		}
	}
	*head = NULL;
	return (count);
}
