#include "sshell.h"

/**
 * str_dup - duplciates string
 * @s: string to duplicate
 * Return: pointer to the duplicated string
 */
char *string_duplicate(char *s)
{
int index = 0;
int length = 0;
char *str;

if (s == NULL)
return (NULL);

while (*(s + index) != '\0')
{
length++;
index++;
}

index = 0;
str = malloc(sizeof(char) * (length + 1));

if (str == NULL)
return (NULL);

while (*(s + index) != '\0')
{
*(str + index) = *(s + index);
index++;
}

*(str + index) = '\0';

return (str);
}
