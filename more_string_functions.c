#include "shell.h"
/**
 * str_concat - concatenate two strs
 * @s1: string pointer 1
 * @s2: string pointer 2
 * Return: char pointer
 */
char *str_concat(char *s1, char *s2)
{
	char *arr = NULL;
	int i = 0, len1 = 0, len2 = 0;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	while (s1[len1] != '\0')
	{
		len1++;
	}
	while (s2[len2] != '\0')
	{
		len2++;
	}
	arr = malloc(sizeof(*arr) * (len1 + len2 + 1));
	if (arr == NULL)
		return (NULL);
	while (*s1)
	{
		arr[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		arr[i] = *s2;
		i++;
		s2++;
	}
	arr[i] = '\0';
	return (arr);
}
/**
 * _puts - prints a string
 * @str: string to be printed
 * Return: void
 */
void _puts(char *str)
{
	while (*str != 0)
	{
		_putchar(*str);
		str++;
	}
}
/**
 * _realloc - reallocates a memory space
 * @ptr: pointer to old memory
 * @old_size: the old size
 * @new_size: new memory to be allocated
 * Return: newly allocated memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i;
	char *tmp, *t;

	if (new_size == old_size)
		return (ptr);
	if (!ptr)
		return (malloc(new_size));
	if (!new_size && ptr)
	{
		free(ptr);
		return (0);
	}
	tmp = ptr;
	t = malloc(new_size);
	if (!t)
		return (0);
	for (i = 0; i < old_size; i++)
		t[i] = tmp[i];
	free(ptr);
	return ((void *)t);
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1 or -1 in failure
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
