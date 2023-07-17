#include "sshell.h"

/**
 * _env - deals with environmental variables
 * @env : double pointer to the environmental variable
 * Return: Always 0 upon success
 */

int _env(char **env)
{
int tkn = 0;
int length = 0;
while (env[tkn] != NULL)
{
length = string_length(env[tkn]);
write(STDOUT_FILENO,env[tkn],length);
write(STDOUT_FILENO,"\n", 1);
tkn++;
}
return (0);
}
