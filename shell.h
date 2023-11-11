#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#define _GNU_SOURCE

#include <unistd.h>

int handel_inline(int argc, char *argv[]);
int handel_pipe(char *argv[]);
int prompt(char *argv[]);
char **get_new_argv(int argc, char *const argv[]);
char *_strcat(char *dest, char *src);
char *search_path(char *file);


#endif
