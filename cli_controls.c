#include "simple_shell.h"

/**
 * handle_ctrl_c - Handles Ctrl+C signal
 * @signal_num: Signal number input
 */
void handle_ctrl_c(int signal_num)
{
(void)signal_num;
write(STDOUT_FILENO, "\n$ ", 3);
}

/**
 * handle_ctrl_d - Handles Ctrl+D signal
 * @user_input: User's input
 * Return: 0 for success
 */
int handle_ctrl_d(char *user_input)
{
free(user_input);
if (isatty(STDIN_FILENO) == 1)
write(STDOUT_FILENO, "\n", 1);
return (0);
}
