#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stddef.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

static int calculate_tenth(int start_index, char *s);
int print_environment(char **env);
void error_hand(char **argv, char **arr, int cmdnum, char *l, char *new_l);
void free_everything(char *1, char *new_1,char **arr);
void tkn_free(char **token_array);
char *_printint(int number);
int _putchar(char c);
char *con_cat(char *cat, char *s1, char *s2);
char **tokenize_string(char *user_input);
int main(int ac, char **av, char **env);
int change_directory(char **args, char **env_vars);
#endif
