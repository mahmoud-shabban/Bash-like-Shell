#include "shell.h"

/**
 * get_new_argv - slice the original argv to be passed to exeve
 * @argc: the original argc
 * @argv:  the cmd args passed
 * Return: new argv vector
 */

char **get_new_argv(int argc, char *const argv[])
{
	char **new_argv;
	int i, j, c = 0;

	new_argv = malloc(sizeof(char *) * argc);
	new_argv[0] = malloc(sizeof(char) * 30);
	if (!new_argv[0])
		return (NULL);

	strcpy(new_argv[0], argv[1]);

	for (i = 1; i < (argc - 1) ; i++)
	{
		new_argv[i] = malloc(sizeof(char) * 10);
		if (new_argv[i] == NULL)
		{
			printf("i is: %d\n", i);
			c = 1;
			break;
		}

		strcpy(new_argv[i], argv[i + 1]);
	}

	if (c)
	{
		for (j = 0; j < i; j++)
		{
			free(new_argv[j]);
		}
		return (NULL);
	}

	new_argv[i] = NULL;
	return (new_argv);
}





/**
 * _strcat - concat dest + / + src
 * @dest: first string
 * @src: second string
 * Return: new concated string
 */


char *_strcat(char *dest, char *src)
{
	int l1, l2;
	char *new;

	l1 = strlen(dest);
	l2 = strlen(src);

	new = malloc(sizeof(char) * (l1 + l2 + 2));

	if (!new)
		exit(EXIT_FAILURE);

	strcpy(new, dest);
	strcat(new, "/");
	strcat(new, src);

	return (new);
}





/**
 * _strcat - concat dest + / + src
 * @dest: first string
 * @src: second string
 * Return: new concated string
 */


char *search_path(char *file)
{
	char *path, *tok, *tmp_str, *full_file_path;
	int i, s_stat;
	struct stat sb;


	path = getenv("PATH");

	for (i = 0, tmp_str = path; ; i++, tmp_str = NULL) 
	{
		tok = strtok(tmp_str, ":");

		if (tok == NULL)
			return (NULL);
		full_file_path = _strcat(tok, file);
		s_stat = stat(full_file_path, &sb);
		
		if (s_stat == 0)
			return (full_file_path);
	}

}
