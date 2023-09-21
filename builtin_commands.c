#include "shell.h"

char *commands[] = {"cd", "exit", "env", "^D"};
int (*search_builtin[]) (char **) = {&builtin_cd, &builtin_exit,
	&builtin_env, &End_of_File};

/**
 * builtin_cd - change directory
 * @args: array of strings with the arguments
 * Return: return 1 if success or exit if fail
 */
int builtin_cd(char **args)
{
	if (args[1] == NULL)
	{
		perror("expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("lsh");
		}
	}
	return (1);
}

/**
 * builtin_exit - exit of the shell
 * @args: array of strings with the arguments
 * Return: return 1 if success or exit if fail
 */
int builtin_exit(char **args)
{
	(void)args;
	return (0);
}

/**
 * builtin__env - prints the environment
 * @args: array of strings with the arguments
 * Return: return 1 if success or exit if fail
 */
int builtin_env(char **args)
{
	char **env = environ;
	unsigned int i, length;
	(void)args;

	i = 0;
	while (env[i])
	{
		length = _strlen(env[i]);
		write(STDOUT_FILENO, env[i], length);
		write(STDOUT_FILENO, "\n", 1);
		++i;
	}
	return (1);
}
