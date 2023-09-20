#include "shell.h"

/**
 * main - main function
 * @argc: get a count of arguments
 * @argv: get a array of arguments
 * Return: return EXIT_SUCCESS
 */
int main(int argc __attribute__((unused)), char **argv)
{
	int promptline = 0;
	char **lineargs = NULL;
	int status = 1;
	char *line = NULL;
	size_t buffersize = 0;

	while (status)
	{
		if (isatty(STDIN_FILENO))
		{
			_puts("#cisfun$ ");
		}

		promptline = getline(&line, &buffersize, stdin);

		if (promptline == EOF)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}

		lineargs = string_split(line);

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
	free(line);

	return (EXIT_SUCCESS);
}
