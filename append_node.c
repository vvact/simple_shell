#include "sshel.h"
/**
 * append_directories - Append path directories from a path variable
 * @path_variable: Pointer to the path variable
 * @path_list: Pointer to the path_t list
 *
 * Return: Pointer to the new list
 */
path_t *append_directories(char *path_variable, path_t *path_list)
{
if (path_variable == NULL || *path_variable == '\0')
return (path_list);
path_t *head = path_list;
path_t *tail = path_list;
int start = 0, end = 0;
while (path_variable[end] != '\0')
{
if (path_variable[end] == ':')
{
int dir_len = end - start;
path_t *new_node = malloc(sizeof(path_t));
if (new_node == NULL)
{
free_directory_list(head);
return (NULL);
}
new_node->directory = malloc(dir_len + 2);
if (new_node->directory == NULL)
{
free(new_node);
free_directory_list(head);
return (NULL);
}
strncpy(new_node->directory, path_variable + start, dir_len);
new_node->directory[dir_len] = '/';
new_node->directory[dir_len + 1] = '\0';
new_node->next = NULL;
if (tail == NULL)
head = new_node;
else
tail->next = new_node;
tail = new_node;
start = ++end;
}
else
{
end++;
}
}
return (head);
}

/**
 * free_directory_list - Frees the linked list of directories
 * @path_list: Pointer to the path_t list
 */
void free_directory_list(path_t *path_list)
{
while (path_list != NULL)
{
path_t *temp = path_list;
path_list = path_list->next;
free(temp->directory);
free(temp);
}
}

