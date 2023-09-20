#include "shell.h"
/**
 * _strlen - prints the length of a string
 * @s: string to print.
 * Description: this function prints the length of a string
 * section header: the header of this function is hsh.h
 * Return: string length in int
 **/
int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;
	return (len);
}
/**
 * _strncmp - this function compare two strings
 * @s1: the first string
 * @s2: the second string
 * @n: number to compare
 (* a blank line
 * Description: this function comparing two strings using the first value)?
(* section header: the header of this function is shell.h)*
* Return: return a number depends os the resul fo comparation.
*/
int _strncmp(char *s1, char *s2, int n)
{
	int i;

	if (s1 == NULL || s2 == NULL)
		return (-1);
	for (i = 0; (s1[i] != '\0' || s2[i] != '\0') && i < n; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}
/**
 * _strcmp - compares two strings
 * @s1: get a char
 * @s2: get a char
 * Return: return a integrer
 */
int _strcmp(char *s1, char *s2)
{
	while (((*s1 != '\0') && (*s2 != '\0')) && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 == *s2)
	{
		return (0);
	}
	else
	{
		return (*s1 - *s2);
	}
}

/**
 * string_split - spliting the string into individual tokens
 * @str: string to be tokenized
 * Return: char double pointer
 */
char **string_split(char *str)
{
	int buffersize = 0, position = 0;
	char **arraystr = NULL;
	char *string;

	while (str[buffersize])
	{
		buffersize++;
	}
	arraystr = malloc(buffersize * sizeof(char *));
	if (!arraystr)
	{
		perror("lsh");
		exit(EXIT_FAILURE);
	}
	string = strtok(str, TOK_DELIM);
	while (string != NULL)
	{
		arraystr[position] = string;
		position++;
		if (!arraystr)
		{
			perror("lsh");
			exit(EXIT_FAILURE);
		}
		string = strtok(NULL, TOK_DELIM);
	}
	arraystr[position] = NULL;
	return (arraystr);
}
