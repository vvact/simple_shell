#include "sshell.h"
#define STRING_DELIM " \t\0"
/**
 * tokenize_string - Splits user input into individual tokens.
 * @user_input: The string containing the user's input.
 * Return: An array of tokens.
*/
char **tokenize_string(char *user_input)
{
int token_count = 0, i = 0, current_token_index = 0;
char **token_array, *current_token, *token_copy;
/* Check if the user_input is NULL */
if (user_input == NULL)
return (NULL);
/* Count the number of tokens in the user_input */
int i = 0;
while (user_input[i] != '\0')
{
if (user_input[i] != ' ' && (user_input[i + 1] == ' ' ||
user_input[i + 1] == '\0' || user_input[i + 1] == '\t'))
token_count++;
i++;
}
/* Allocate memory for the token_array*/
token_array = malloc(sizeof(char *) * (token_count + 1));
if (token_array == NULL)
return (NULL);
/* Tokenize the input string using strtok*/
current_token = strtok(user_input, STRING_DELIM);
while (current_token != NULL)
{
/* Duplicate the current_token and store it in token_copy*/
token_copy = str_dup(current_token);
if (token_copy == NULL)
{
/* If  free previously allocated memory and return NULL*/
free(token_array);
return (NULL);
}
/* Store the pointer in the token_array*/
token_array[current_token_index] = token_copy;
/* Move to the next token*/
current_token = strtok(NULL, STRING_DELIM);
current_token_index++;
}
/* Set the last element of the token_array to NULL as a*/
token_array[current_token_index] = NULL;
return (token_array);
}

