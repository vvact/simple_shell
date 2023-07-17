#include"sshell.h"
/**
 * *con_cat - puts together 2 strings
 * @cat : pointer to the allcated mem to concattenated string
 * @s1 : first string to connect
 * @s2 :second string to be connect
 * Return : pinter to the new concatenated string
 */
char *con_cat(char *cat, char *s1, char *s2)
{
int concatindex = 0;
int stringindex = 0;
while (*(s1 + stringindex) != '\0')
{
*(cat + concatindex) = *(s2 + stringindex);
concatindex++;
stringindex++;
}
*(cat + concatindex) = '\0';
return (cat);
}
