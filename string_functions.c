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
char *_strconcat(char *s1, char *s2)
{
	char *array = NULL;
	int i = 0, l1 = 0, l2 = 0;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	while (s1[l1] != '\0')
	{
		l1++;
	}
	while (s2[l2] != '\0')
	{
		l2++;
	}
	array = malloc(sizeof(*array) * (l1 + l2 + 1));
	if (array == NULL)
		return (NULL);
	while (*s1)
	{
		array[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		array[i] = *s2;
		i++;
		s2++;
	}
	array[i] = '\0';
	return (array);
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
	int buffersize = 0, position = 0;
	char **arraystr = 0;
	char *strg;

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
	strg = strtok(str, TOK_DELIM);
	while (strg != NULL)
	{
		arraystr[position] = strg;
		position++;
		if (!arraystr)
		{
			perror("lsh");
			exit(EXIT_FAILURE);
		}
		strg = strtok(NULL, TOK_DELIM);
	}
	arraystr[position] = NULL;
	return (arraystr);
}
