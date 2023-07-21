#include "sshell.h"

/**
 * atois - Converts ASCII to an integer
 * @input_str: Pointer to the string to be converted
 * Return: Integer value of the converted string, or -1 on error
 */
int atois(char *input_str)
{
int currentIndex = 0;
int tenthMultiplier = 1;
int result = 0;
int isNegative = 0;
/*Step 1: Skip leading whitespace characters*/
while (input_str[currentIndex] == ' ')
currentIndex++;
/*Step 2: Check for a sign (+ or -)*/
if (input_str[currentIndex] == '-')
{
isNegative = 1;
currentIndex++;
}
else if (input_str[currentIndex] == '+')
{
currentIndex++;
}
/*Step 3: Convert the ASCII representation to an integer*/
while (input_str[currentIndex] >= '0' && input_str[currentIndex] <= '9')
{
int digit = input_str[currentIndex] - '0';
/*Step 4: Check for integer overflow before updating the result*/
if (result > INT_MAX / 10 ||
		(result == INT_MAX / 10 && digit > INT_MAX % 10))
{
/*Overflow occurred*/
return (isNegative ? INT_MIN : INT_MAX);
}
result = result * 10 + digit;
currentIndex++;
}
/*Step 5: Apply the sign if the number is negative*/
if (isNegative)
result *= -1;
return (result);
}

