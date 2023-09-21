#include "shell.h"

void print_err(char **argv, char **av);

/**
 * main - entry point
 * @argc: the amount of arguments used
 * @argv: pointer to a pointer that takes input
 * Return: return 0 (EXIT_SUCCESS)
 */
int main(int argc __attribute__((unused)), char **argv)
{
	int prompt = 0, status = 1;
	char **av = NULL, *pathline = NULL;
	size_t buffer = 0;

	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
	signal(SIGTSTP, handle_sigstp);
	while (status)
	{
		if (isatty(STDIN_FILENO))
		{
			_puts("$ ");
		}

		prompt = getline(&pathline, &buffer, stdin);

		if (prompt == EOF)
		{
			free(pathline);
			exit(EXIT_SUCCESS);
		}
		av = string_split(pathline);
		hash_handle(av);
		status = execute_p(av);
		if (status == 2)
		{
			print_err(argv, av);
			status = 1;
		}
		free(av);
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

/**
 * hash_handle - handling the # char
 * @argv: user input
 * Return: void
 */
void hash_handle(char **argv)
{
	int i = 0;

	while (argv[i])
	{
		if (argv[i][0] == '#')
		{
			while (argv[i])
			{
				argv[i] = NULL;
				free(argv[i]);
				i++;
			}
			return;
		}
		i++;
	}
}

/**
 * print_err - printing error message
 * @argv: file name
 * @av: user input
 * Return: void
 */
void print_err(char **argv, char **av)
{
	_puts((char *)argv[0]);
	_puts(": ");
	_puts("1");
	_puts(": ");
	_puts(av[0]);
	_puts(": ");
	_puts("not found\n");
}
