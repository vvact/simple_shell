#include "sshell.h"

/**
 * token_free - frees the tokens
 * @tkn_array: double pointer to tokens for freeing
 */

void token_free(char **tkn_array)
{
	int index = 0;

	while (tkn_array[index] != NULL)
	{
		free(tkn_array[index]);
		index++;
	}
	free(tkn_array[index]);
}
