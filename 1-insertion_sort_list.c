#include "sort.h"

/**
 * switch_nodes - Switch two nodes in a listint_t doubly-linked list.
 * @h: A pointer to the head of the doubly-linked list.
 * @f_n: A pointer to the First node to switch.
 * @s_n: The Second node to switch.
 * Return: Void.
 */
void switch_nodes(listint_t **h, listint_t **f_n, listint_t *s_n)
{
	(*f_n)->next = s_n->next;
	if (s_n->next != NULL)
		s_n->next->prev = *f_n;
	s_n->prev = (*f_n)->prev;
	s_n->next = *f_n;
	if ((*f_n)->prev != NULL)
		(*f_n)->prev->next = s_n;
	else
		*h = s_n;
	(*f_n)->prev = s_n;
	*f_n = s_n->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *Description: Prints the list after each swap.
 * Return: Void.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr_n, *insert, *next_n;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (curr_n = (*list)->next; curr_n != NULL; curr_n = next_n)
	{
		next_n = curr_n->next;
		insert = curr_n->prev;
		while (insert != NULL && curr_n->n < insert->n)
		{
			switch_nodes(list, &insert, curr_n);
			print_list((const listint_t *)*list);
		}
	}
}
