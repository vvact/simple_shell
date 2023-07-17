#include "sshell.h"
/**
 * calculate_tenth - Calculate the initial value of 'tenth'.
 * @start_index: The index from which to start the calculation.
 * @s: The string containing numeric characters.
 * Return: The calculated value of 'tenth'.
 */
static int calculate_tenth(int start_index, char *s);
/**
 * atois - converts ASCII to integer
 * @str: pointer to the string to be converted
 * Return: The integer result of the conversion, or 0 if invalid input.
 */
int atois(char *str)
{
int index = 0;
int tenth = 1;
int result = 0;
int is_negative = 0;
/* Check if the input string is empty */
if (str[0] == '\0')
return (0);
/* Check for leading '+' or '-' signs */
while (str[index] == '-' || str[index] == '+')
{
if (str[index] == '-')
is_negative = !is_negative; /* Toggle the is_negative flag */
index++;
}
/* Convert the string to an integer */
tenth = calculate_tenth(index, str);
while (str[index] >= '0' && str[index] <= '9')
{
result = result * 10 + (str[index] - '0');
index++;
}
/* Apply the negative sign if necessary */
if (is_negative)
result = -result;
return (result);
}
/**
 * calculate_tenth - Calculate the initial value of 'tenth'.
 * @start_index: The index from which to start the calculation.
 * @s: The string containing numeric characters.
 * Return: The calculated value of 'tenth'.
*/
static int calculate_tenth(int start_index, char *s)
{
int numeric_length = 0;
int tenth = 1;
/* Calculate the length of the numeric part of the string */
while (s[start_index + numeric_length] >= '0'
		&& s[start_index + numeric_length] <= '9')
{
numeric_length++;
}
/* Calculate the initial value of 'tenth'*/
for (int i = 0; i < numeric_length - 1; i++)
{
tenth *= 10;
}
return (tenth);
}

