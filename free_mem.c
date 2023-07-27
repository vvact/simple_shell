#include "simple_shell.h"

/**
 * free_mem - frees all var used
 * @l: user input
 * @new_l: user input without newline
 * @array: double pointer to argument array
 */

void free_mem(char *l, char *new_l, char **array)
{
tkn_free(array);
free(l);
free(new_l);
free(array);
}
