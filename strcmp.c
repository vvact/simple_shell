#include "sshell.h"

/**
 * string_compare - Compare two strings.
 * @str1: Pointer to the first string.
 * @str2: Pointer to the second string.
 * Return: If str1 < str2, (-), if str1 > str2 (+), if str1 = str2 (0).
 */
int string_compare(char *str1, char *str2)
{
while ((*str1 == *str2) && *str1 != '\0' && *str2 != '\0')
{
str1++;
str2++;
}

if ((*str1 == '\0') && (*str2 == '\0'))
return (0);
else if (*str1 > *str2)
return ((int)(*str1 - *str2));
else
return ((int)(*str1 - *str2));
}
