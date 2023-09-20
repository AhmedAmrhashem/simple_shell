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

/**
 * assign_lineptr - Reassigns the lineptr variable for _getline.
 * @lineptr: A buffer to store an input string.
 * @n: The size of lineptr.
 * @buffer: The string to assign to lineptr.
 * @b: The size of buffer.
 */
void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t b)
{
	if (*lineptr == NULL)
	{
		if (b > 120)
			*n = b;
		else
			*n = 120;
		*lineptr = buffer;
	}
	else if (*n < b)
	{
		if (b > 120)
			*n = b;
		else
			*n = 120;
		*lineptr = buffer;
	}
	else
	{
		_strcpy(*lineptr, buffer);
		free(buffer);
	}
}

int lsh_eof(char **args);
/**
 * lsh_eof - handle end of file
 * @args: arguements
 * Return: 0
 */
int lsh_eof(char **args)
{
	(void)args;
	return (0);
}

/**
 * _strcpy - Copies the string pointed to by src, including the
 *           terminating null byte, to the buffer pointed by des.
 * @dest: Pointer to the destination of copied string.
 * @src: Pointer to the src of the source string.
 * Return: Pointer to dest.
 */
char *_strcpy(char *dest, const char *src)
{
	size_t i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];

	dest[i] = '\0';
	return (dest);
}
