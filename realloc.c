#include "simple_shell.h"

/**
 * rea_lloc - memory reallocation for char
 * @v: pointer to an array of strings
 * Return: pointer to the reallocated mem
 */
char *rea_lloc(char *v)
{
int index = 0;
char *new_pointer;

if (v == NULL)
return (NULL);
while (*(v + index) != '\n')
index++;
new_pointer = malloc(sizeof(char) * index + 1);
if (new_pointer == NULL)
return (NULL);
index = 0;
while (*(v + index) != '\n')
{
*(new_pointer + index) = *(v + index);
index++;
}
*(new_pointer + index) = '\0';
return (new_pointer);
}
