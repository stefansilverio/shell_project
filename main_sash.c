#include "sash.h"

/**
 * main - Checks which mode to open sash in (interactive/noninteractive)
 * @ac: Number of arguments passed to standard input
 * @av: 2D array of arguments passed to standard input
 * @env: The environment of the program
 *
 * Return: Always 0
 */
int main(int ac, char **av, char **env)
{
	if (isatty(STDIN_FILENO))
		enter_sash(ac, av, env);
	else
		enter_nonsash(ac, av, env);
	return (0);
}
