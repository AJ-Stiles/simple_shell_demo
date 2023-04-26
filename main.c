#include "shell.h"

/**
 * main - Simple Shell entry point
 *
 * Return: Always 0
 */
int main(void)
{
	char *command = NULL;
	size_t command_len = 0;
	ssize_t chars_read;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

		chars_read = getline(&command, &command_len, stdin);
		if (chars_read == -1)
			break;

		if (my_strcmp(command, "exit\n") == 0)
			exit_shell();

		if (execute_command(command) == -1)
			perror("Error executing command");

		free(command);
		command = NULL;
		command_len = 0;
	}

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);

	free(command);
	return (0);
}

