#include "shell.h"

/**
 * main - entry point
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **av, char **env)

{
	if (ac == 1)
		myprompt(av, env);
	return (0);
}
