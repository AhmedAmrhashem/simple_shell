#include "shell.h"

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
