#include "sshell.h"
/**
 * handle_ctrl_c - Handles Ctrl+C signal by printing a new prompt.
 * @signal: Signal input (unused parameter).
 */
void handle_ctrl_c(int signal)
{
(void)signal; /*To suppress the "unused parameter" warning*/
write(STDOUT_FILENO, "\n$ ", 3); /*Print a new prompt after Ctrl+C*/
}

/**
 * handle_ctrl_d - Handles Ctrl+D signal.
 * @user_input: User's entry.
 * Return: 0 for success.
 */
int handle_ctrl_d(char *user_input)
{
free(user_input); /*Free the dynamically allocated memory*/
if (isatty(STDIN_FILENO) == 1)
write(STDOUT_FILENO, "\n", 1);/*Print a newline after Ctrl+D*/
return (0);
}

