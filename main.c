#include "shell.h"

/**
 * main - entry point to shell
 * Return: 0 in success
 */

int main(void)
{
	char *buffer = NULL, **argv, *path_name;
	ssize_t len = 0;
	path_l *head;
	char *val, *val2;
	void (*func)(char **);

	while (len != EOF)
	{
		_puts("$ ");
		getline(&buffer, &len, stdin);
		if (len == -1)
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
				execute_p(argv);
			else if(path_name)
			{
				argv[0] = path_name;
				execute_p(argv);
				free(argv[0]);
			}
		}
		else
			continue;

	}
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
