#include "simple_shell.h"
/**
 * change_dir - changes directory
 * @arr: double pointer to array of cmd inputs
 * @env: double pointer to the environment variables
 * Return: 0 for success, -1 for failure
 */
int change_dir(char **arr, char **env)
{
char cw_dir[1024];
char *dir_new;
if (arr[1] == NULL)
{
char *home_dir = get_env("HOME", env);
if (home_dir == NULL)
{
write(STDERR_FILENO, "cd: No HOME environment variable.\n", 33);
return (-1);
}
if (chdir(home_dir) == -1)
{
perror(arr[0]);
free(home_dir);
return (-1);
}
free(home_dir);
}
else
{
getcwd(cw_dir, sizeof(cw_dir));
dir_new = str_concat(cw_dir, "/");
if (dir_new == NULL)
return (-1);
char *new_path = str_concat(dir_new, arr[1]);
free(dir_new);
if (new_path == NULL)
return (-1);
if (chdir(new_path) == -1)
{
perror(arr[0]);
write(STDERR_FILENO, "cd: Cannot change directory.\n", 29);
free(new_path);
return (-1);
}
free(new_path);
}
return (0);
}
