#include "shell.h"

/**
 * _strlen - lenght of string
 * @s: char pointer
 * Return: lenght
 */
int _strlen(char *s)
{
	int i = 0;

	for (i = 0; *s != '\0'; i++)
		s++;

	return (i);
}

/**
 * _strconcat - concantes 2 strings
 * @str1: pointer char to be concatinated
 * @str2: pointer char
 * Return: appended strings
 */
char *_strconcat(char *str1, char *str2)
{
	int l1 = _strlen(str1), l2 = _strlen(str2), i = 0;
	char *new = malloc((l1 + l2) * sizeof(char));

	if (!new)
		return (NULL);

	for (i = 0; i < l1; i++)
		new[i] = str1[i];

	for (i = 0; i < l2; i++)
		new[i + l1] = str2[i];

	return (new);
}

/**
 * _strdup - string dublicate
 * @str: string
 * Return: string pointer
 */
char *_strdup(char *str)
{
	char *arr;
	unsigned int i = 0, count = 0;

	if (str == NULL)
		return (NULL);

	while (str[count] != '\0')
		count++;
	arr = malloc(sizeof(char) * (count + 1));

	if (arr == NULL)
		return (NULL);

	while (str[i] != '\0')
	{
		arr[i] = str[i];
		i++;
	}
	return (arr);
}

/**
 * _realloc - chnages the size of the pointer from old size to new
 * @ptr: pointer to change size
 * @old_size: old size of pointer
 * @new_size: new size of pointer
 * Return: void
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new;
	char *old;

	unsigned int i;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	new = malloc(new_size);
	old = ptr;
	if (new == NULL)
		return (NULL);

	if (new_size > old_size)
	{
		for (i = 0; i < old_size; i++)
			new[i] = old[i];
		free(ptr);
	for (i = old_size; i < new_size; i++)
		new[i] = '\0';
	}
	if (new_size < old_size)
	{
		for (i = 0; i < new_size; i++)
			new[i] = old[i];
		free(ptr);
	}
	return (new);
}

/**
 * string_split - spliting the string into individual tokens
 * @str: string to be tokenized
 * Return: char double pointer
 */
char **string_split(char *str)
{
	char *token, **tokens;
	int i = 0;

	token = strtok(str, TOK_DELIM);
	while (token)
	{
		i++;
		tokens = _realloc(tokens, (i) * sizeof(char *), (i + 2) * sizeof(char *));
		if (tokens == NULL)
		{
			perror(_getenv("_"));
			exit(EXIT_FAILURE);
		}
		tokens[i - 1] = token;
		token = strtok(NULL, " \t\n");
		}

	return (tokens);
}
