#include "shell.h"
int lsh_eof(char **args);
/**
 * lsh_eof - handle end of file
 * @args: arguements
 * Return: 0
 */
int lsh_eof(char **args)
{
	(void)args;
	return (0);
}
/**
 * prompt - prints '$' and waits for a user's input
 */
void prompt(void)
{
	char *prompt = {"{^_^} "};
	char *buffer = getcwd(NULL, 0);

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, prompt, _strlen(prompt));
	}
	free(buffer);
}
