#ifndef SHELL_BASIC_H
#define SHELL_BASIC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>

#define TOK_DELIM " :\t\r\n\a"

extern char **environ;

/**
 * struct path - linked list to path directories
 * @direction: evergy possible path directories
 * @next: next node
 * Description: linked list for path direction
 */
typedef struct path
{
	char *direction;
	struct path *next;
} path_l;

/**
 * struct builtin_commands - struct for builtin commands
 * @command: name of the command
 * @f: function pointer of the command
 * Description: making a strcut to realate all of the builtin commands
 */
typedef struct builtin_commands
{
	char *command;
	void (*f)(char **);
} built;

/*  File prototypes  */
char **string_split(char *str);
int execution_start(char **args, int flag);
int execute_p(char **args);
void hash_handle(char **argv);

/* Functions for Built-in commands */
int builtin_cd(char **args);
int builtin_help(char **args);
int builtin_exit(char **args);
int builtin_env(char **environ);
int End_of_File(char **args);

/* Environment variables and Function´s */
char *_getenv(const char *name);
void handle_signal(int m);

/* signal handlers */
void handle_sigint(int sig);
void handle_sigquit(int sig);
void handle_sigstp(int sig);
void prompt(void);
void _puterror(char *err);

/* Functions for strings */
int _strlen(char *string);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, int n);
char *str_concat(char *s1, char *s2);
int _putchar(char c);
void _puts(char *str);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

#endif
