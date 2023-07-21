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
#endif
