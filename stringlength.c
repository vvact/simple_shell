#include "sshell.h"

/**
 * stringlength - finds length of a string
 * @str: string to use
 * Return: length of the string
 */

int stringlength(char *str)
{
int index = 0;
int length = 0;

if (str == NULL)
return (-1);
while (str[index] != '\0')
{
length = length + 1;
index++;
}
return (length);
}
