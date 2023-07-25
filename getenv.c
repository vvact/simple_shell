#include "sshell.h"

/**
 * get_env - searches for env variables
 * @variable_name: pointer to the var name
 * @env_list: double pointer to env var
 * Return: ptr to the env var
 */
char *get_env(const char *variable_name, char **env_list)
{
int env_index = 0;
int char_index = 0;

if (variable_name == NULL || env_list == NULL || *env_list == NULL)
return (NULL);

while (env_list[env_index] != NULL)
{
while (env_list[env_index][char_index] == variable_name[char_index])
char_index++;

if (env_list[env_index][char_index] == '=')
{
char_index++;
return (&(env_list[env_index][char_index]));
}

char_index = 0;
env_index++;
}

write(STDOUT_FILENO, "env var not found!", 18);
return (NULL);
}

