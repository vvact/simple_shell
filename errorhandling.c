#include "simple_shell.h"

/**
 * error_hand - handles errors
 * @argv: argument vectors
 * @array: pointer to token array from user input
 * @cmdnum: number of cmd inputs
 * @l: user line input
 * @new_l: user input lacking '\n' character
 */
void error_hand(char **argv, char **array, int cmdnum, char *l, char *new_l)
{
char *v;

v = _printint(cmdnum);
write(STDERR_FILENO, argv[0], str_len(argv[0]));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, v, str_len(v));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, array[0], str_len(array[0]));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, "not found\n", 10);
free(v);
free_everything(l, new_l, array);
exit(0);
}
