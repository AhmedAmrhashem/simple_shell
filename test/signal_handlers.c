#include "shell.h"

/**
 * handle_sigint - Signal handler for SIGINT (Ctrl+C)
 * @sig: Signal number
 * Return: Nothing
 */
void handle_sigint(int sig)
{
	(void) sig;
	_putchar('\n');
	prompt();
}

/**
 * handle_sigquit - Signal handler for SIGQUIT (Ctrl+\)
 * @sig: Signal number
 * Return: Nothing
 */
void handle_sigquit(int sig)
{
	(void) sig;
	_puterror("Quit (core dumped)\n");
	exit(EXIT_SUCCESS);
}

/**
 * handle_sigstp - Signal handler for SIGTSTP (Ctrl+Z)
 * @sig: Signal number
 * Return: Nothing
 */
void handle_sigstp(int sig)
{
	(void) sig;
	_puts("\n");
	prompt();
}
/**
 * prompt - starting point of terminal.
 * Return: void.
 */
void prompt(void)
{
	_puts("$ ");
	fflush(stdout);
}

/**
 * _puterror - printing the error message
 * @err: The error message to print
 * Return: void
 */
void _puterror(char *err)
{
	size_t len;
	ssize_t num_written;

	len = _strlen(err);
	num_written = write(STDERR_FILENO, err, len);
	if (num_written == -1)
	{
		perror("write");
	}
}
