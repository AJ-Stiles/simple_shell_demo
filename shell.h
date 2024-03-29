#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/wait.h>

#define PATH_MAX 4096
#define BUFFER_SIZE 1024

extern char **environ;

/* function declarations */
int execute_command(char *command, char *program_name);
char *find_full_path(char *command);
void print_error(char *command, char *error_message);
int exit_shell(void);
void env_shell(void);
int my_strcmp(const char *s1, const char *s2);
int my_strncmp(const char *s1, const char *s2, size_t n);
int count_arguments(char *command, char *delim);
int execute_builtin_command(char *command);
char **parse_arguments(char *command);
char *find_full_path(char *command);
void execute_child_process(char *full_path, char **args);
void wait_for_child_process(pid_t pid);
ssize_t my_getline(char **line, size_t *line_size);
void exit_shell_with_status(int exitStatus);
void execute_setenv_command(char *command);
void execute_unsetenv_command(char *command);
void execute_cd_command(char *command);
char *get_program_name(void);

#endif /* SHELL_H */

