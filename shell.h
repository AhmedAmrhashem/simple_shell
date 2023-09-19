#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stddef.h>
#include <signal.h>
#include <errno.h>

#define BUFF_SIZE 1024

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
}path_l;

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
}built;

extern char **environ;

/* write_functions */
void _puts(char *str);
int _putchar(char c);

/* string_functions */
int _strlen(char *s);
char *_strdup(char *str);
char *_strconcat(char *str1, char *str2);
char **string_split(char *str);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/* execute_command */
char *_getenv(const char *name);
void execute_p(char **arv);
path_l *add_node_end(path_l **head, char *str);
path_l *link_path(char *dir);
char *_which(path_l *h, char *file_command);

/* builtin_commands */
void (*builtin_func(char **argv))(char **argv);
void builtin_exit(char **argv);
void buitin_env(char **argv __attribute__((unused)));
void builtin_cd(char **argv);

/* special_cases */
void hash_handle(char **argv);

#endif
