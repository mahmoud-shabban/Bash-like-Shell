#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#define _GNU_SOURCE

#include <unistd.h>

int handel_inline(char *argv[]);
int handel_pipe(char *argv[]);
int prompt(char *argv[]);

#endif
