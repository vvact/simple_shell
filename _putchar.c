#include <simple_shell>

/**
 * _putchar - write character to standard output
 * @c: character to print
 * Return: 1 on success, -1 on failure
 */

int _putchar(char c)
{
return ( write(1, &c, 1));
}