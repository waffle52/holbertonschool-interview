#include "binary_trees.h"

/**
 * heap_insert - entry
 * @root: root of binary tree
 * @value: Value to insert into tree
 * Description: creates a new node and inserts into a new node while
 * Respecting Max Binary Heap Ordering
 * Return: new node created
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new, *push;
	int tmp;

	if (!root)
		return (NULL);

	if (!*root)
	{
		new = binary_tree_node(*root, value);
		*root = new;
		return (new);
	}

	push = insert(*root);
	new = binary_tree_node(push, value);
	if (push->left == NULL)
		push->left = new;
	else
		push->right = new;

	while (new->parent && new->n > new->parent->n)
	{
		tmp = new->parent->n;
		new->parent->n = new->n;
		new->n = tmp;
		new = new->parent;
	}

	return (new);
}

/**
 * insert - insert node
 * @root: root of binary tree
 *
 * Return: pointer to inserted node
 */

heap_t *insert(heap_t *root)
{
	heap_t *heap[50];
	heap_t *insert = root;
	int start = 0, end = 0;

	while (insert && insert->left && insert->right)
	{
		heap[start] = insert->left;
		start += 1;
		if (start >= 49)
			start = 0;
		heap[start] = insert->right;
		start += 1;
		if (start >= 49)
			start = 0;
		insert = heap[end];
		end += 1;
		if (end >= 49)
			end = 0;
	}

	return (insert);
}
