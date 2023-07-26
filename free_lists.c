#include "simple_shell.h"

/**
 * list_free - all the linked lists are freed.
 * @h: head of linked list start
 * Return: nothing to be returned
 */
void list_free(path_t *h)
{
	path_t *nex_tnode;

	while (h != NULL)
	{
		nex_tnode = h->next;
		free(h->dir);
		free(h);
		h = nex_tnode;
	}
}
