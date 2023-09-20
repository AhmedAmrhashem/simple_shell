#include "shell.h"

/**
 * _putchar - printing a char
 * @c: char to be printed
 * Return: 1 on success or -1 on failure
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - printd a string 
 * @str: char pointer
 * Return: void
 */ 
void _puts(char *str)
{
	int i = 0;
	
	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
}
