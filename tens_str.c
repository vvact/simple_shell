#include "sshell.h"

/**
 * tenspoint- finds mult factor of tens
 * @start_index: counter of where the no begins in str
 * @number_str: pointer to the string
 * Return: tens multiplier
 */

int tenspoint(int start_index, char *number_str)
{
double tens_multiplier = 1;

while (number_str[start_index] >= '0' && number_str[start_index] <= '9')
{
tens_multiplier *= 10;
start_index++;
}

tens_multiplier /= 10;

return ((int)tens_multiplier);
}
