#include "sshell.h"

/**
 * rea_lloc - memory reallocation for char
 * @d: pointer to an array of strings
 * Return: pointer to the reallocated mem
 */

char *rea_lloc(char *d)
{
	int length = 0;
	char *new_pointer;

	if (d == NULL)
		return (NULL);

	while (d[length] != '\n')
		length++;

	new_pointer = malloc(sizeof(char) * (length + 1));
	if (new_pointer == NULL)
		return (NULL);

	for (int i = 0; i < length; i++)
		new_pointer[i] = d[i];

	new_pointer[length] = '\0';
	return (new_pointer);
}
