#include "sshell.h"

/**
 * exit_shell - Handle the exit command in the shell program.
 * @args: An array of command inputs.
 * @original_input: The original input from the user.
 * @input_with_newline: User's input with newline truncated.
 * @command_count: The number of commands entered.
 * Return: 0 (success), exit code for the shell program.
 */
int shell_exit(char **args, char *original_input,
		char *input_with_newline, int command_count)
{
int exit_code, invalid_command_len = 0;
char *exit_arg_str;

/*Check if "exit" command is called without any arguments*/
if (args[1] == NULL)
{
free_everything(original_input, input_with_newline, args);
exit_code = 2; /*Arbitrary exit code 2*/
exit(exit_code);
}
else
{
/*Convert the argument after "exit" to an integer*/
exit_code = atois(args[1]);

/*If the conversion fails (returns -1), print an error message*/
if (exit_code == -1)
{
/*Get the string representation of the command count*/
exit_arg_str = _printint(command_count);

/*Print error message to stderr*/
write(STDERR_FILENO, args[0], str_len(args[0]));
write(STDERR_FILENO, exit_arg_str, str_len(exit_arg_str));
write(STDERR_FILENO, ": exit: cmd not found!: ", 24);

/*Find the length of the invalid command argument*/
while (args[1][invalid_command_len] != '\0')
invalid_command_len++;

/*Print the invalid command argument*/
write(STDOUT_FILENO, args[1], invalid_command_len);
write(STDOUT_FILENO, "\n", 1);
return (0); /*Return 0, which may indicate success or an error*/
}
free_everything(original_input, input_with_newline, args);
_exit(exit_code);
}
}

