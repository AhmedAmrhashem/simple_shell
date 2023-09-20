#include "shell.h"
#define SHELL_TOK_DELIM " :\t\r\n\a"
/**
 * shell_split_line - splits the line in tokens
 * @line: get the line from the user input
 * Return: Return an array of strings of args to execute
 */
char **shell_split_line(char *line)
{
	int buffersize = 0, position = 0;
	char **arraystr = 0;
	char *str;

	while (line[buffersize])
	{
		buffersize++;
	}
	arraystr = malloc(buffersize * sizeof(char *));
	if (!arraystr)
	{
		perror("lsh");
		exit(EXIT_FAILURE);
	}
	str = strtok(line, SHELL_TOK_DELIM);
	while (str != NULL)
	{
		arraystr[position] = str;
		position++;
		if (!arraystr)
		{
			perror("lsh");
			exit(EXIT_FAILURE);
		}
		str = strtok(NULL, SHELL_TOK_DELIM);
	}
	arraystr[position] = NULL;
	return (arraystr);
}
