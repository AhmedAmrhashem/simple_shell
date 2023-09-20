#include "shell.h"

int shell_cd(char **args);
int shell_help(char **args);
int shell_exit(char **args);
char *built_in_name[] = {"cd", "help", "exit", "env", "^D"};
int (*search_builtin[]) (char **) = {&shell_cd, &shell_help, &shell_exit,
				     &shell_env, &lsh_eof};
/**
 * shell_num_builtins - count the amount of builtins avalibe
 * Return: return the number of builtins
 */
int shell_num_builtins(void)
{
	return (sizeof(built_in_name) / sizeof(char *));
}
/**
 * shell_cd - change directory
 * @args: array of strings with the arguments
 * Return: return 1 if success or exit if fail
 */
int shell_cd(char **args)
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
 * shell_help - display a help text of the shell
 * @args: array of strings with the arguments
 * Return: return 1 if success or exit if fail
 */
int shell_help(char **args)
{
	int i;
	*args = *args;
	_puts("Jaime Aricapa and Frank Grijalba\n");
	_puts("Type program names and arguments, and hit enter.\n");
	_puts("The following are built in:\n");
	for (i = 0; i < shell_num_builtins(); i++)
	{
		_puts(built_in_name[i]);
		_puts(" \n");
	}
	_puts("Use the man command for information on other programs.\n");
	return (1);
}
/**
 * shell_exit - exit of the shell
 * @args: array of strings with the arguments
 * Return: return 1 if success or exit if fail
 */
int shell_exit(char **args)
{
	(void)args;
	return (0);
}
/**
 * shell_env - prints the environment
 * @args: array of strings with the arguments
 * Return: return 1 if success or exit if fail
 */
int shell_env(char **args)
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
