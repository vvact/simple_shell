#include "simple_shell.h"
/**
 * append_directories_to_list - Append path directories to.
 * @path_var: Pointer to the path variable string.
 * @list_head: Pointer to the head of the path_t list.
 * Return: Pointer to the updated head of the linked list.
 */
path_t *append_directories_to_list(char *path_var, path_t *list_head)
{
char *directory;
path_t *current_node, *head;
int i = 0, dir_len = 0, start = 0, end = 0;
if (path_var == NULL || list_head == NULL)
return (NULL);
head = list_head;
current_node = head;
while (current_node != NULL)
{
if (path_var[end] == ':' || path_var[end] == '\0')
{
if (path_var[end] != '\0')
end++;
dir_len = end - start;
directory = malloc(sizeof(char) * (dir_len + 2));
if (directory == NULL)
return (NULL);
for (i = 0; i < dir_len; i++)
directory[i] = path_var[start + i];
directory[i++] = '/';
directory[i] = '\0';
start = end;
current_node->dir = directory;
current_node = current_node->next;
}
else
{
end++;
}
}
return (head);
}
