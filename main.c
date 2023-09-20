#include "shell.h"

/**
 * main - entry point to shell
 * @argc: input count
 * @av: file name
 * Return: 0 in success
 */
int main(int argc __attribute__((unused)), char **av)
{
	char *buffer =  NULL;
	size_t len = 0;
	int tmp = 0, i = 0;
	path_l *head = NULL;
	char **argv;

	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
	signal(SIGTSTP, handle_sigstp);
	while (tmp != EOF)
	{
		if (isatty(STDIN_FILENO))
			_puts("$ ");
		tmp = getline(&buffer, &len, stdin);
		if (tmp == -1)
		{
			if (isatty(STDIN_FILENO))
			{
				_puts("\n");
				free(buffer);
			}
			exit(0);
		}
		argv = string_split(buffer);
		hash_handle(argv);
		launch(argv, head, av);
	}
	free(buffer);
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
	free_list(head);
	return (0);
}

/**
 * hash_handle - ignoring any string that starts with #
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
 * free_list - frees a linked list
 * @head: start node
 * Return: void
 */
void free_list(path_l *head)
{
	path_l *remove = head;

	while (head)
	{
		remove = head->next;
		free(head->direction);
		free(head);
		head = remove;
	}
}

/**
 * error_message - error message to be printed
 * @argv: user input
 * @av: file name
 * Return: void
 */
void error_message(char **argv, char **av)
{
	_puts((char *)av[0]);
	_puts(": ");
	_puts("1");
	_puts(": ");
	_puts(argv[0]);
	_puts(": ");
	_puts("not found\n");
}

/**
 * launch - condition series to execute
 * @argv: user input
 * @head: head of linked list
 * @av: file name
 * Return: void
 */
void launch(char **argv, path_l *head, char **av)
{
	char *val, *path_name;
	void (*func)(char **);

	if (argv && argv[0])
	{
		val = _getenv("PATH");
		head = link_path(val);
		path_name = _which(head, argv[0]);
		func = builtin_func(argv);
		if (func)
		{
			func(argv);
		}
		else if (!path_name)
		{
			error_message(argv, av);
		}
		else if (path_name)
		{
			argv[0] = path_name;
			execute_p(argv);
			free(argv[0]);
		}
	}
	else
	{
		return;
	}
}
