#include "shell.h"

/**
 * _getenv - getting the address of desired name in env
 * @name: string to be searched for
 * Return: address of desired path or variable
 */
char *_getenv(const char *name)
{

	int i = 0, j = 0, k = 0;
	int len = _strlen((char *)name);
	char **env = environ;

	char *str = malloc(sizeof(char) * 150);

	if (!str)
	{
		return (NULL);
	}
	if (!name)
	{
		free(str);
		return (NULL);
	}
	while (env[i][j] != '\0')
	{
		if (_strncmp(env[i], (char *)name, len) != 0)
		{
			i++;
		}
		else
		{
			if (env[i][len] == '=')
			{
				while (env[i][len + j] != '\0')
				{
					str[k] = (env[i][len + j + 1]);
					k++;
					j++;
				}
				return ((char *)str);
			}
		}
	}
	free(str);
	return (NULL);
}

/**
 * execute_p - used to execute files in argv
 * @argv: double pointer to excutable
 * Return: void
 */
void execute_p(char **argv)
{
	pid_t id;
	int status;

	id = fork();
	if (id == -1)
	{
		perror("lsh");
	}

	if (id == 0)
	{
		if (execve(argv[0], argv, environ) == -1)
			perror("lsh");
		exit(EXIT_FAILURE);
	}
	else
	{
		do {
			waitpid(id, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}

/**
 * add_node_end - adding node at end of list
 * @head: pointer to pointer to the head
 * @str: string  of struct
 * Return: new node
 */

path_l *add_node_end(path_l **head, char *str)
{
	path_l *new, *end;

	new = malloc(sizeof(path_l));
	if (!new)
		return (NULL);

	new->direction = str;
	new->next = NULL;
	if (!(*head))
	{
		*head = new;
		return (*head);
	}

	end = *head;

	while (end->next)
	{
		end = end->next;
	}

	end->next = new;
	return (*head);
}

/**
 * link_path - linking all dir in a linked list
 * @dir: path direstion or directory name
 * Return: the linked list
 */
path_l *link_path(char *dir)
{
	path_l *h = NULL;
	char *tmp = _strdup(dir);
	char *token = strtok(tmp, ":");

	while (token)
	{
		h = add_node_end(&h, token);
		token = strtok(NULL, ":");
	}
	return (h);
}

/**
 * _which - checks for a filename if found or not
 * @h: head of linked list
 * @file_command: command entered by user
 * Return: string of full path or NULL
 */
char *_which(path_l *h, char *file_command)
{
	struct stat st;
	char *str = NULL;
	path_l *tmp = h;

	if (stat(file_command, &st) == 0)
		return (file_command);
	while (tmp)
	{
		str = _strconcat(tmp->direction, "/");
		str = _strconcat(str, file_command);
		if (stat(str, &st) == 0)
		{
			return (str);
		}

		free(str);
		tmp = tmp->next;
	}
	return (NULL);
}
