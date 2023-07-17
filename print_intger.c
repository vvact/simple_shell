#include "sshell.h"

/**
 * _printint - prints an intger
 * @number: num to change to string
 * Return: no. of characters on the standard output
 */

char *_printint(int number)
{
int tenth = 1;
int tkn = 0;
int tenthint = number;
char *intger;

intger = malloc(34);
if (intger == NULL)
return (NULL);
if (number == 0)
{
intger[tkn] = 0 + '0';
return (intger);
}
number = number / 10;
while (tenth != 0)
{
intger[tkn] = (tenthint / tenth) + '0';
tenthint = tenthint % tenth;
tenth /= 10;
tkn++;
}
intger[tkn] = '\0';
return (intger);
}
