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
				_put("\n");
				free(buffer);
			}
			exit(0);
		}
		argv = string_split(buffer);
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
