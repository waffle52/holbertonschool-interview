#include "lists.h"

/**
 * is_palindrome - check if linked list is palindrome
 * @head: head of linked list to check
 * Return: 1 (is palindrome) 0 (is not palindrome)
 */
int is_palindrome(listint_t **head)
{
	int list[1000];
	int i = 0;
	int num = 0;
	listint_t *node;

	if (head == NULL)
		return (0);
	if (*head == NULL)
		return (1);
	if ((*head)->next == NULL)
		return (1);

	node = *head;
	while (node != NULL)
	{
		list[num] = node->n;
		node = node->next;
		num++;
	}

	for (i = 0; i < (num / 2); i++)
	{
		if (list[i] != list[num - i - 1])
			return (0);
	}

	return (1);
}
