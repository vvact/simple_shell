#include "simple_shell.h"

/**
 * inbuilts - checks if cmd entered exists
 * @array: double Pointer to array of cmds to execute
 * @env: the environment va
 * @l: entry from user
 * @new_l: entry from user without \n
 * @cmd_num: counts no of cmd args
 * Return: 0 if cmd exists. 1 when absent
 */
int inbuilts(char **array, char **env, char *l, char *new_l, int cmd_num)
{
if (array == NULL || *array == NULL)
return (1);
if (env == NULL || *env == NULL)
return (1);
if (str_cmp((array[0]), "exit") == 0)
return (exit_shell(array, l, new_l, cmd_num));
else if (str_cmp((array[0]), "cd") == 0)
return (change_dir(array, env));
else if (str_cmp((array[0]), "env") == 0)
return (_env(env));
else
return (1);
}
