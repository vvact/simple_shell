#include "sshell.h"
#define STRING_DELIM " \t\0"

/**
 * str_tkn - divides user input int tokens
 * @l: user's input
 * Return: array of tokens
 */
char **strtkn(char *l)
{
	int index = 0;
	int tkn_index = 0;
	char **token_array;
	char *tkn, *tkncpy;

	if (l == NULL)
		return (NULL);
	while (*(l + index) != '\0')
	{
		if (l[index] != ' ' && (l[index + 1] == ' ' || l[index + 1] == '\0'
					|| l[index + 1] == '\t'))
			tkn_index++;
		index++;
	}

	index = 0;
	token_array = malloc(sizeof(char *) * (tkn_index + 1));
	if (token_array == NULL)
		return (NULL);
	tkn = strtok(l, STRING_DELIM);
	while (tkn != NULL)
	{
		tkncpy = str_dup(tkn);
		if (tkncpy == NULL)
		{
			free(token_array);
			return (NULL);
		}
		*(token_array + index) = tkncpy;
		tkn = strtok(NULL, STRING_DELIM);
		index++;
	}
	*(token_array + index) = NULL;
	return (token_array);
}
