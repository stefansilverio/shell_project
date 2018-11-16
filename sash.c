#include "sash.h"

/**
 * main - the driver function for our sash shell
 *
 * Return: Always 0
 */

int main(void)
{
	char *line = NULL, *path = NULL, *dir = NULL;
	char **commands = NULL, **dirs = NULL;
	int status = 1;
	struct stat buffer;

	(void) *dir;

	signal(SIGINT, SIG_IGN);  /* Ignores Ctrl+C signal to quit shell */

	while (status)
	{
		write(STDOUT_FILENO, "$ ", 2); /* Write command prompt to stdout */
		line = read_line(); /* Stores command written in line */
		if (line == NULL)
		{
			free(line);
			continue;
		}
		commands = split_line(line);
		status = run_builtin(commands);
		if (status != -1) /* If a builtin is found, run it */
		{
			free(commands);
			free(line);
		}
		else if (status == -1) /* If a builtin is not found, search the PATH */
		{
			if (stat(commands[0], &buffer) != 0) 
			{
				path = get_path(environ);
				if (path == NULL)
				{
					perror("Memory fail");
					continue;
				}
				dirs = tokenize_path(path);
/*				dir = find_dir(dirs, commands[0]); 
				commands[0] = dir;*/
				free(path);
				free(dirs);
			}
			_execute(commands);
			free(commands);
			free(line);
		}
	}
	return (0);
}
