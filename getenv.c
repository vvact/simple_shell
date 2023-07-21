#include "sshell.h"

/**
 * get_env - Search for the value of an environment variable.
 * @variable_name: The name of the environment variable to search for.
 * @env_vars: The array of environment variables.
 * Return: A pointer to the value of the environment variable.
 */
char *get_env(const char *variable_name, char **env_vars)
{
int env_index = 0;
int char_index = 0;

/*Check if the input arguments are valid*/
if (variable_name == NULL || env_vars == NULL || *env_vars == NULL)
return (NULL);

/*Iterate through the array of environment variables*/
while (env_vars[env_index] != NULL)
{
/*Compare each character of the variable*/
while (env_vars[env_index][char_index] == variable_name[char_index])
char_index++;

/*If the comparison matches up to the '=' character*/
if (env_vars[env_index][char_index] == '=')
{
char_index++; /*Move past '=' to point to the value*/
return (&(env_vars[env_index][char_index])); /*Returnpointer*/
}

/*Move to the next environment variable*/
env_index++;
char_index = 0; /*Reset the index for the next comparison*/
}

/*If the variable name is not found, print an error message*/
fprintf(stderr, "Environment variable '%s' not found!\n", variable_name);
return (NULL);
}

