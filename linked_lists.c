#include "sshell.h"

/**
 * develop_likedlist - forms an empty path based on arguments
 * @s: pointer to the formed path variable
 * Return: pointer to the path_t struct
 */

path_t *develop_likedlist(char *s)
{
	int num_nodes = 1;
	int index = 0;
	path_t *last, *head, *temp, *node;

	temp = malloc(sizeof(path_t));
	if (temp == NULL)
		return (NULL);
	head = temp;

	last = malloc(sizeof(path_t));
	if (last == NULL)
	{
		free(temp);
		return (NULL);
	}
	last->next = NULL;

	while (s[index] != '\0')
	{
		if (s[index] == ':')
			num_nodes++;
		index++;
	}

	while ((num_nodes - 2) > 0)
	{
		node = malloc(sizeof(path_t));
		if (node == NULL)
		{
			free(temp);
			free(last);
			return (NULL);
		}
		temp->next = node;
		temp = temp->next;
		num_nodes--;
	}

	temp->next = last;

	return (head);
}
