#include "shell.h"

/**
 * handel_pipe - handle piped values or inline commands 
 * @argv: - the cmd args passed
 * Return: the absolute value of int
 */

int handel_pipe(char *argv[])
{
	char *line = NULL;
	size_t n = 0;
	int wstatus = 0, pid, read, s_stat;
	char **new_argv, *new_program;
	char *new_envp[] = { NULL };
	struct stat sb;

	while(1)
	{
		read = getline(&line, &n, stdin);

		if (read == -1)
			/* failed to read */
			break;
		if (read == 1)
			/* only new line char is read */
			continue;

		line[read - 1] = '\0';
		new_argv = line_to_argv(line);

		if (new_argv)
		{
			s_stat = stat(new_argv[0], &sb);
			if (s_stat != 0)
			{
				new_program = search_path(argv, new_argv[0]);
				if (!new_program)
					continue;
			} else
				new_program = new_argv[0];
		}
		/* fork the current process to create the child */
		pid = fork();
		if (pid == 0)
		{
			/* this the child */
			execve(new_program, new_argv, new_envp);
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

