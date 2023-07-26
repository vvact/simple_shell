#include "simple_shell.h"

/**
 * _env - handles environmental variables
 * @envp: double pointer to environmental variables
 * Return: 0 (success)
 */

int _env(char **envp)
{
int index = 0;
int str_length = 0;
while (envp[index] != NULL)
{
str_length = str_len(envp[index]);
write(STDOUT_FILENO, envp[index], str_length);
write(STDOUT_FILENO, "\n", 1);
index++;
}
return (0);
}
