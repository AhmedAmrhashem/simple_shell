#include "shell.h"

/**
 * _strlen - get the legth of string
 * @s: string pointer
 * Return: length of string
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;
	return (len);
}

/**
 * _strncmp - comparing 2 string with n starting chars
 * @s1: string pointer 1
 * @s2: string pointer 2
 * @n: length to be compared
 * Return: diffrence in length
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
 * @s1: string 1
 * @s2: string 2
 * Return: diffrence between 2 strings
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
	int buf_size = 0, i = 0;
	char **token = NULL, *tokens;

	while (str[buf_size])
	{
		buf_size++;
	}
	token = malloc(buf_size * sizeof(char *));
	if (!token)
	{
		perror("lsh");
		exit(EXIT_FAILURE);
	}
	tokens = strtok(str, TOK_DELIM);
	while (tokens != NULL)
	{
		token[i] = tokens;
		i++;
		if (!token)
		{
			perror("lsh");
			exit(EXIT_FAILURE);
		}
		tokens = strtok(NULL, TOK_DELIM);
	}
	token[i] = NULL;
	return (token);
}
