#include "shell.h"

#define MAX_COMMAND 10

void myprompt(char **av, char **env)
{
	char *string = NULL;
	int a, b, status;
	size_t n = 0;
	ssize_t num_char;
	char *argv[MAX_COMMAND];
	pid_t child_pid;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("agut$");

		num_char = getline(&string, &n, stdin);
		if (num_char == -1)
		{
			free(string);
			exit(EXIT_FAILURE);
		}
		a = 0;
		while (string[1])
		{
			if (string[1] == '\n')
				string[1] = 0;
			a++;
		}

		b = 0;
		argv[b] = strtok(string, " ");
		while (argv[b])
			argv[++b] = strtok(NULL, " ");

		child_pid = fork();
		if (child_pid == -1)
		{
			free(string);
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, env) == -1)
				printf("%s: no such filr or directory\n", av[0]);
		}
		else
			wait(&status);
	}
}

