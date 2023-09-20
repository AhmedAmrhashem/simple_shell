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
	char *path = NULL, *pathcat1 = NULL, *pathcat2 = NULL;
	char **environs = NULL;
	char *builtin_str[] = {"cd", "help", "exit", "env", "^D"};

	int (*builtin_func[]) (char **) = {&shell_cd, &shell_help, &shell_exit,
					   &shell_env, &lsh_eof};
	if (args[0] == NULL)
		return (1);
	for (i = 0; i < shell_num_builtins(); i++)
	{
		if (_strcmp(args[0], builtin_str[i]) == 0)
			return ((*builtin_func[i])(args));
	}
	if (args[0][0] == '/')
	{
		return (shell_launch(args, flag));
	}
	path = _getenv("PATH");
	environs = shell_split_line(path);
	for (i = 0; environs[i]; i++)
	{
		pathcat1 = str_concat(environs[i], "/");
		pathcat2 = str_concat(pathcat1, args[0]);
		free(pathcat1);
		c = stat(pathcat2, &st);
		if (c == 0)
		{
			args[0] = pathcat2;
			free(path);
			free(environs);
			flag = 1;
			return (shell_launch(args, flag));
		}
		free(pathcat2);
	}
	free(path);
	free(environs);
	return (2);
}
