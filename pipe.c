#include "shell.h"

/**
 * handel_pipe - handle piped values or inline commands 
 * @argv - the cmd args passed
 * Return: the absolute value of int
 */

int handel_pipe(char *argv[])
{
	char *line = NULL;
	size_t n = 0;
	int wstatus = 0, pid, read;
	char *new_argv[] = { NULL };
	char *new_envp[] = { NULL };
	
	read = getline(&line, &n, stdin);

	line[read - 1] = '\0';

	/* fork the current process to create the child */
	pid = fork();
	if (pid == 0)
	{
		/* this the child */
		execve(line, new_argv, new_envp);
		printf("%s: No such file or directory\n", argv[0]);
	} else if (pid > 0)
	{
		/* this is the parent and pid is child pid */
		wait(&wstatus);
	} else
	{
		/* faild to fork */
		free(line);
		exit(EXIT_FAILURE);
	}

	free(line);

	return (0);

}

