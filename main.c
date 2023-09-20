#include "shell.h"

/**
 * main - main function
 * @argc: get a count of arguments
 * @argv: get a array of arguments
 * Return: return EXIT_SUCCESS
 */
int main(int argc, char **argv)
{
	/* Run command loop. */
	(void)argc;
	shell_loop(argv);
	/* Perform any shutdown/cleanup. */
	return (EXIT_SUCCESS);
}
