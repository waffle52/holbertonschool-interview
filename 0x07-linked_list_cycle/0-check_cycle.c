#include "lists.h"

/**
 * check_cycle - entry
 * @list: linked list to check cycle for
 *
 * Return: 1 (cycle) 0 (no cycle)
 */
int check_cycle(listint_t *list)
{
	listint_t *slow, *fast;

	if (list)
	{
		slow = list;
		fast = list->next;

		while (slow && fast && fast->next)
		{
			if (slow == fast)
				return (1);
			slow = slow->next;
			fast = fast->next->next;
		}
	}
	return (0);
}
