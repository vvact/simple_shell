#include "sshell.h"
/**
 * print_environment - Print environmental variables to stdout.
 * @env: Double pointer to environmental variables.
 * Return: Always 0 upon success.
 */
int print_environment(char **env)
{
int index = 0;
while (env[index] != NULL)
{
/* Calculate the length of the environmental variable*/
int variable_length = string_length(env[index]);
/* Write the environmental variable along with its value to stdout*/
write(STDOUT_FILENO, env[index], variable_length);
write(STDOUT_FILENO, "\n", 1);
index++;
}
return (0);
}
