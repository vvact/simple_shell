#include "sshell.h"
/**
 * change_directory - Changes the current working directory
 * @args: Double pointer to an array of command inputs
 * @env_vars: Double pointer to the environment variables
 *
 * Return: 0 for success, 1 for failure
 */
int change_directory(char **args, char **env_vars)
{
int cwd_len = 0;
char current_working_dir[1024];
char *new_dir_path;
/*Check if a target directory is provided*/
if (args[1] == NULL)
{
/*Change to the root directory if no argument is provided*/
const char *root_dir = get_env("ROOT", env_vars);
if (root_dir == NULL || chdir(root_dir) == -1)
{
perror(args[0]);
write(STDERR_FILENO, "cd: cannot cd to root\n", 22);
return (1);
}
}
else
{
/*Get the current working directory*/
if (getcwd(current_working_dir, sizeof(current_working_dir)) == NULL)
{
perror("getcwd");
return (1);
}
while (current_working_dir[cwd_len] != '\0')
cwd_len++;
current_working_dir[cwd_len++] = '/';
current_working_dir[cwd_len] = '\0';
new_dir_path = str_concat(current_working_dir, args[1]);
if (new_dir_path == NULL)
return (1);
if (chdir(new_dir_path) == -1)
{
perror(args[0]);
write(STDERR_FILENO, "Directory not found\n", 20);
free(new_dir_path);
return (1);
}
free(new_dir_path);
}
return (0);
}

