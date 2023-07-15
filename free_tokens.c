#include "sshell.h"
/**
 * tkn_free - frees the already used tokens
 * @token_array : double pointer to the tokens for freeing
 */

void tkn_free(char **token_array)
{
int tkn = 0;
while ( token_array[tkn] != NULL)
{
free(token_array[tkn]);
tkn++;
}
free(token_array[tkn]);
}
