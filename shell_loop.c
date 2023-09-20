#include "shell.h"
/**
 * shell_loop - make a infinite loop forever
 * @args: array of strings with arguments
 * Return: return void
 */
void shell_loop(char **args)
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

		lineargs = shell_split_line(line);

		status = shell_execute(lineargs);
		if (status == 2)
		{
			_puts((char *)args[0]);
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
}
