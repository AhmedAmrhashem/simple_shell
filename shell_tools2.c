#include "shell.h"
/**
 * str_concat - concatenate two or more strings
 *@s1: string
 *@s2: string
 * Return: the concetenated string
 */
char *str_concat(char *s1, char *s2)
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
 *_puts - prints a string
 *
 *@str: pointer that will store the string's location
 *
 *Return: nothing
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
 * _realloc - reallocates a memory block
 * @ptr: pointer to the memory previously allocated
 * @old_size: is the size, in bytes, of the allocated space
 * @new_size: new size, in bytes of the new memory block
 * Return: pointer to the new memory block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i;
	char *ptr_cp, *r;

	if (new_size == old_size)
		return (ptr);
	if (!ptr)
		return (malloc(new_size));
	if (!new_size && ptr)
	{
		free(ptr);
		return (0);
	}
	ptr_cp = ptr;
	r = malloc(new_size);
	if (!r)
		return (0);
	for (i = 0; i < old_size; i++)
		r[i] = ptr_cp[i];
	free(ptr);
	return ((void *)r);
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
