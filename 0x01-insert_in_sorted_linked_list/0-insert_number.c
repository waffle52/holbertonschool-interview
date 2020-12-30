#include "lists.h"

/**
 * insert_node - insert node by number value
 *
 * @head: head of the list
 * @number: Number of new node to insert
 * Description: inserts a number into a sorted singly linked list
 * Return: Return: the address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *temp = *head;

	if (head == NULL)
		return (add_nodeint_end(head, number));

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = number;
	new->next = NULL;

	while (temp && temp->next)
	{
		if (temp->n < number && number < temp->next->n)
		{

			new->next = temp->next;
			temp->next = new;
			return (new);
		}
		temp = temp->next;
	}
	temp->next = new;

	return (new);
}
