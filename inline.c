
#include "shell.h"

/**
 * handel_inline - handle piped values or inline commands 
 * @argv - the cmd args passed
 * Return: the absolute value of int
 */

int handel_inline(int argc, char *argv[])
{
	int wstatus = 0, pid;
	char **new_argv;
	char *new_envp[] = { NULL };
	

	/* fork the current process to create the child */
	pid = fork();
	if (pid == 0)
	{
		/* this the child */
		new_argv = get_new_argv(argc, argv);
		if (new_argv == NULL)
		{
			perror(argv[0]);
			exit(EXIT_FAILURE);
		}

		execve(argv[1], new_argv, new_envp);
		perror(argv[0]);
		exit(EXIT_FAILURE);

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

