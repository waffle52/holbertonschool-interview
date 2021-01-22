#include "lists.h"

/**
 * is_palindrome - check if linked list is palindrome
 * @head: head of linked list to check
 * Return: 1 (is palindrome) 0 (is not palindrome)
 */
int is_palindrome(listint_t **head)
{
	listint_t *slow = *head, *fast = *head, *prev = *head;
	listint_t *second, *mid = NULL;
	int num = 1;

	if (fast && fast->next)
	{
		while (fast && fast->next)
		{
			fast = fast->next->next;
			prev = slow;
			slow = slow->next;
		}

		if (fast)
		{
			mid = slow;
			slow = slow->next;
		}

		second = slow;
		prev->next = NULL;
		reverse(&second);
		num = compare(*head, second);
		reverse(&second);

		if (mid)
		{
			prev->next = mid;
			mid->next = second;
		}
		else
			prev->next = second;
	}

	return (num);
}

/**
 * reverse - reverse a listint_t list
 * @head: pointer to pointer of first node of listint_t list
 */
void reverse(listint_t **head)
{
	listint_t *prev = NULL;
	listint_t *current = *head, *next;

	while (current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head = prev;
}

/**
 * compare - check if 2 lists are the same
 * @head1: pointer to first list
 * @head2: pointer to second list
 * Return: (1) if they're the same (0) false
 */
int compare(listint_t *head1, listint_t *head2)
{
	listint_t *first = head1;
	listint_t *second = head2;

	while (first && second)
	{
		if (first->n != second->n)
			return (0);
		first = first->next;
		second = second->next;
	}

	if (!first && !second)
		return (1);
	return (0);
}
