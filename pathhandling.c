#include "sshell.h"

/**
 * pathhand - loops through path var and concats cmd
 * @s: pointer to path var
 * @env: double pointer to env var
 * Return: pointer to concat s
 */

char *pathhand(char *s, char **env)
{
	char *full_path, *path_var;
	path_t *path_list, *temp_list;
	struct stat file_stat;

	if (s == NULL || env == NULL || *env == NULL)
		return (NULL);

	path_var = get_env("PATH", env);
	if (path_var == NULL)
	{
		write(STDERR_FILENO, "No path available", 17);
		_exit(0);
	}

	path_list = develop_likedlist(path_var);
	if (path_list == NULL)
	{
		write(STDERR_FILENO, "faulty path", 11);
		_exit(0);
	}

	path_list = appendnode(path_var, path_list);
	temp_list = path_list;

	while (temp_list != NULL)
	{
		if (path_var[0] == ':')
			full_path = str_concat("./", s);
		else
			full_path = str_concat(temp_list->dir, s);

		if (full_path == NULL)
			return (NULL);

		if (stat(full_path, &file_stat) == 0 && 
				access(full_path, X_OK) == 0)
		{
			list_free(path_list);
			return (full_path);
		}

		temp_list = temp_list->next;
		free(full_path);
	}

	list_free(path_list);
	return (NULL);
}

