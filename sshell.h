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

/**
 * struct paths - structure for PATH variables
 * @dir: directory to search
 * @next: pointer to the next node
 */

typedef struct paths
{
	char *directory;
	struct paths *next;
} path_t;
int atois(char *input_str);
path_t *append_directories(char *path_variable, path_t *path_list);
void free_directory_list(path_t *path_list);
int change_directory(char **args, char **env_vars);
void handle_ctrl_c(int signal);
int handle_ctrl_d(char *user_input);
int print_environment(char **env);
int _env(char **env);
void tkn_free(char **token_array);
int inbuilts(char **arr, char **env, char *l, char *new_l, int cmd_num);
void list_free(path_t *h);
char *pathhand(char *s, char **env);
void printprompt(void);
char *rea_lloc(char *d);

#endif
