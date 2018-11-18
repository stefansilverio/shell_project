#include "sash.h"
#include <signal.h>
/**
 * main - the driver function for our sash shell
 *
 * Return: Always 0
 */

int enter_sash(int ac, char **av)
{
	char *line = NULL, *path = NULL, *dir = NULL;
	char **commands = NULL, **dirs = NULL;
	int status = 1;
	struct stat buffer;

	(void) **av;
	(void) ac;

	signal(SIGINT, sighandler);  /* Ignores Ctrl+C signal to quit shell */

	while (status)
	{
		write(STDOUT_FILENO, "$ ", 2); /* Write command prompt to stdout */
		line = read_line(); /* Stores command written in line */
		if (line == NULL)
			continue;
		commands = split_line(line);
		status = run_builtin(commands);
		if (status == -1)
		{
			if (stat(commands[0], &buffer) != 0)
			{
				path = get_path(environ);
				dirs = tokenize_path(path);
				dir = find_dir(dirs, commands[0]);
				commands[0] = dir;
			}
			_execute(commands);
		}
	}
	return (0);
}

void sighandler()
{
	write(1, "\n", 1);
	write(1, "$ ", 2);
}
