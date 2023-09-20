#include "shell.h"

/**
 * main - entry point to shell
 * Return: 0 in success
 */
int main(void)
{
	char *buffer = NULL;
	size_t len = 0;
	int tmp = 0, i = 0;
	path_l *head;
	char *val, **argv, *path_name;
	void (*func)(char **);

	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
	signal(SIGTSTP, handle_sigstp);
	while (tmp != EOF)
	{
		_puts("$ ");
		tmp = getline(&buffer, &len, stdin);
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
			{
				execute_p(argv);
			}
			else if(path_name)
			{
				argv[0] = path_name;
				execute_p(argv);
				free(argv[0]);
			}
		}
		else
		{
			continue;
		}
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
