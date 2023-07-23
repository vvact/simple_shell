#include "sshell.h"

/**
 * atois - converts ASCII to integer
 * @s: pointer to the string to be converted
 * Return: integer
 */
int atois(char *s)
{
	int index, length = 0;
	int tenth = 1;
	unsigned int integer_value = 0;
	int is_negative = 0;
	int negative_sign_count = 0;
	int positive_sign_count = 0;

	while (s[length] != '\0')
	{
		if (s[length] > '9' || s[length] < '0')
			return (-1);
		length++;
	}
	while ((s[index] > '9' || s[index] < '0') && s[index] != '\0')
	{
		if (s[index] == '-')
			negative_sign_count++;
		if (s[index] == '+')
			positive_sign_count++;
		index++;
	}
	if (s[index] == '\0')
		return (0);
	if ((negative_sign_count % 2) != 0)
		is_negative = 1;
	tenth = tens_point(index, s);
	while (s[index] >= '0' && s[index] <= '9')
	{
		integer_value += ((s[index] - '0') * tenth);
		tenth /= 10;
		index++;
	}
	if (is_negative == 1)
		integer_value *= -1;

	return ((int)integer_value);
}
