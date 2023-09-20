#include "shell.h"

/**
 * buitin_env - printd the current envroment
 * @argv: used only to relate to other builtin functions
 * Return: void
 */ 
void buitin_env(char **argv __attribute__((unused)))
{
	int i = 0;

	while (environ[i])
	{
		_puts(environ[i]);
		_puts("\n");
		i++;
	}
}

/**
 * builtin_exit - exiting the shell
 * @argv: user input to be freed
 * Return: void
 */
void builtin_exit(char **argv)
{
	int i = 0;

	for (i = 0; argv[i]; i++)
		free(argv[i]);
	free(argv);
	exit(0);
}

/**
 * builtin_func - checks for a buiting command
 * @argv: user input
 * Return: function pointer for desired command
 */
void (*builtin_func(char **argv))(char **argv)
{
	built arr[] = {
		{"exit", builtin_exit},
		{"env", buitin_env},
		{"cd", builtin_cd},
		{NULL, NULL}
	};
	int i = 0, j = 0;

	for (i = 0; arr[i].command; i++)
	{
		for (j = 0; arr[i].command[j]; j++)
		{
			if (arr[i].command[j] != argv[0][j])
				break;
		}
		if (argv[0][j] == '\0')
			return (arr[i].f);
		j = 0;
	}
	return (NULL);
}

/**
 * builtin_cd - changes directory
 * @argv: user input
 * Return: void
 */
void builtin_cd(char **argv)
{
	char *old_dir;

	if (!argv[1])
	{
		perror(_getenv("_"));
		return;
	}

	old_dir = getcwd(NULL, 0);

	if (!old_dir)
	{
		perror(_getenv("_"));
		return;
	}

	if (chdir(argv[1]) == -1)
	{
		perror(_getenv("_"));
		return;
	}
	free(old_dir);
}
