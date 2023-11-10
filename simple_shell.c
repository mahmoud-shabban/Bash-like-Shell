#include "shell.h"



/**
 *  main - the main function for the shell
 * @argc: the number of cmd args
 * @argv: the array of the arguments
 * Return: nothing
 */

int main (int argc, char *argv[])
{

	int tty;


	tty = isatty(fileno(stdin));

	if (!tty)
	{
		handel_pipe(argv);
	} else if (argc > 1)
	{
		handel_inline(argv);
	} else
	{
		prompt(argv);
	}

	return (0);
}
