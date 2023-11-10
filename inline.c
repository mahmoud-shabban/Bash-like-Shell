
#include "shell.h"

/**
 * handel_inline - handle piped values or inline commands 
 * @argv - the cmd args passed
 * Return: the absolute value of int
 */

int handel_inline(char *argv[])
{
	int wstatus = 0, pid;
	char *new_argv[] = { NULL };
	char *new_envp[] = { NULL };
	

	/* fork the current process to create the child */
	pid = fork();
	if (pid == 0)
	{
		/* this the child */
		execve(argv[1], new_argv, new_envp);
		printf("%s: No such file or directory\n", argv[0]);
	} else if (pid > 0)
	{
		/* this is the parent and pid is child pid */
		wait(&wstatus);
	} else
	{
		/* faild to fork */
		exit(EXIT_FAILURE);
	}

	return (0);

}

