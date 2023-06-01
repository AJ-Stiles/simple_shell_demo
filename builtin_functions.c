#include "shell.h"

void execute_setenv_command(char *command)
{
    char *variable;
    char *value;

    /* Extract the variable and value arguments from the command */
    variable = strtok(command + 7, " ");
    value = strtok(NULL, "\n");

    /* Check if both variable and value are provided */
    if (variable == NULL || value == NULL)
    {
        fprintf(stderr, "Invalid setenv command syntax\n");
        return;
    }

    /* Set the environment variable using setenv */
    if (setenv(variable, value, 1) == -1)
    {
        perror("setenv");
        return;
    }
}

void execute_unsetenv_command(char *command)
{
    char *variable;

    /* Extract the variable argument from the command */
    variable = strtok(command + 9, "\n");

    /* Check if variable is provided */
    if (variable == NULL)
    {
        fprintf(stderr, "Invalid unsetenv command syntax\n");
        return;
    }

    /* Unset the environment variable using unsetenv */
    if (unsetenv(variable) == -1)
    {
        perror("unsetenv");
        return;
    }
}

void execute_cd_command(char *command)
{
    char *directory;
    char cwd[PATH_MAX];

    /* Extract the directory argument from the command */
    directory = strtok(command + 3, "\n");

    /* If no directory is provided, set it to the value of $HOME */
    if (directory == NULL)
    {
        directory = getenv("HOME");
        if (directory == NULL)
        {
            fprintf(stderr, "cd: $HOME not set\n");
            return;
        }
    }

    /* Change directory using chdir */
    if (chdir(directory) == -1)
    {
        perror("cd");
        return;
    }

    /* Update the PWD environment variable */
    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        setenv("PWD", cwd, 1);
    }
    else
    {
        perror("getcwd");
    }
}
