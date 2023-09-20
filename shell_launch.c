#include "shell.h"
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
