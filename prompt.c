#include "shell.h"


/**
 * prompt - open shell prompt 
 * @argv - the array of passed commands
 * Return: p in case of sucess
 */

int prompt (char *argv[])
{

	char *line = NULL;
	int wstatus = 0, pid, read;
	size_t n = 0;
	char *new_argv[] = { NULL };
	char *new_envp[] = { NULL };

	while (1)
	{
		printf("($) ");
		read = getline(&line, &n, stdin);

		if (read == -1)
		{
			/* EOF (CTR + d ) is reached */
			printf("\n");
			break;
		}

		if (read == 1)
			/* when user press Enter */
			continue;

		line[read - 1] = '\0';

		/* fork the current process to create the child */
		pid = fork();
		if (pid == 0)
		{
			/* this the child */
			execve(line, new_argv, new_envp);
			perror(argv[0]);
			free(line);
			exit(EXIT_FAILURE);
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
	}

	free(line);
	return (0);
}
