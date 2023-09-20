#include "shell.h"

/**
 * main - entry point
 * @argc: the amount of arguments used
 * @argv: pointer to a pointer that takes input
 * Return: return 0 (EXIT_SUCCESS)
 */
int main(int argc __attribute__((unused)), char **argv)
{
	int prompt = 0;
	char **lineargs = NULL;
	int status = 1;
	char *pathline = NULL;
	size_t buff = 0;

	while (status)
	{
		if (isatty(STDIN_FILENO))
		{
			_puts("#cisfun$ ");
		}

		prompt = getline(&pathline, &buff, stdin);

		if (prompt == EOF)
		{
			free(pathline);
			exit(EXIT_SUCCESS);
		}
		lineargs = string_split(pathline);

		status = shell_execute(lineargs);
		if (status == 2)
		{
			_puts((char *)argv[0]);
			_puts(": ");
			_puts("1");
			_puts(": ");
			_puts(lineargs[0]);
			_puts(": ");
			_puts("not found\n");
			status = 1;
		}
		free(lineargs);
	}
	free(pathline);
	return (EXIT_SUCCESS);
}

/**
 * End_of_File - handle end of file
 * @args: arguements
 * Return: 0
 */
int End_of_File(char **args)
{
	(void)args;
	return (0);
}
