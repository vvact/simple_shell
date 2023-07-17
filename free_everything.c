#include "sshell.h"

/**
 * free_everything - frees all the variable sused
 * @1: user input
 * @new_1: user input withoiut the newline
 * @arr: double pointer to the array of arguments
 */

void free_everything(char *1, char *new_1,char **arr)
{
token_free(arr);
free(1);
free(new_1);
free(arr);
}
