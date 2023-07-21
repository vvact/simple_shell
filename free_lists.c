#include "sshell.h"

/**
 * list_free - frees linked lists
 * @h: head of linked list
 * Return: nothing
 */
void list_free(path_t *h)
{
	path_t *nxtnod;

	while (h != NULL)
	{
		nxtnod = h->next;
		free(h->directory);
		free(h);
		h = nxtnod;
	}
}
