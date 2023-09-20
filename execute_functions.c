#include "shell.h"

/**
 * shell_execute - execute the comands inserted from input by user
 * @args: array of strings with the arguments
 * Return: return 1 if success or 0 if exit is called
 */
int shell_execute(char **args)
{
	int i = 0, c = 0, flag = 0;
	struct stat st;
	char *path = NULL, *pathcat = NULL;
	char **environs = NULL;
	char *builtin_str[] = {"cd", "exit", "env", "^D"};

	int (*builtin_func[]) (char **) = {&shell_cd, &shell_exit,
					   &shell_env, &End_of_File};
	if (args[0] == NULL)
		return (1);
	for (i = 0; i < (int)(sizeof(builtin_str) / sizeof(char *)); i++)
	{
		if (_strcmp(args[0], builtin_str[i]) == 0)
			return ((*builtin_func[i])(args));
	}
	if (args[0][0] == '/')
	{
		return (shell_launch(args, flag));
	}
	path = _getenv("PATH");
	environs = string_split(path);
	for (i = 0; environs[i]; i++)
	{
		pathcat = str_concat(environs[i], "/");
		pathcat = str_concat(pathcat, args[0]);
		c = stat(pathcat, &st);
		if (c == 0)
		{
			args[0] = pathcat;
			free(path);
			free(environs);
			flag = 1;
			return (shell_launch(args, flag));
		}
		free(pathcat);
	}
	free(path);
	free(environs);
	return (2);
}

/**
 * _getenv - getting the address of desired name in env
 * @name: string to be searched for
 * Return: address of desired path or variable
 */
char *_getenv(const char *name)
{
	int i = 0, j = 0, k = 0;
	int len = _strlen((char *)name);
	char **env = environ;

	char *str = malloc(sizeof(char) * 150);

	if (!str)
	{
		return (NULL);
	}
	if (!name)
	{
		free(str);
		return (NULL);
	}
	while (env[i][j] != '\0')
	{
		if (_strncmp(env[i], (char *)name, len) != 0)
		{
			i++;
		}
		else
		{
			if (env[i][len] == '=')
			{
				while (env[i][len + j] != '\0')
				{
					str[k] = (env[i][len + j + 1]);
					k++;
					j++;
				}
				return ((char *)str);
			}
		}
	}

	free(str);
	return (NULL);
}

/**
 * shell_launch - execute a binary file with commands and returns value
 * @args: array of strings with the arguments
 * @flag: is a number for (iterar) in a if;
 * Return: return 1 if success or exit if fails
 */
int shell_launch(char **args, int flag)
{
	pid_t pid;
	int status;
	pid_t wpid;

	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			free(args[0]);
			perror("lsh");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("lsh");
	}
	else
	{
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		wpid = 0;
	}
	if (flag == 0)
		return (1);
	if (flag == 1)
		free(args[0]);
	if (wpid == 0)
	{
		wpid = 1;
		return (wpid);
	}
	else
		return (1);
}
