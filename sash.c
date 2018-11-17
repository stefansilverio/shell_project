#include "sash.h"

/**
 * main - the driver function for our sash shell
 *
 * Return: Always 0
 */

int main(int ac, char *av[])
{
	char *line = NULL, *path = NULL, *dir = NULL;
	char **commands = NULL, **dirs = NULL;
	int status = 1, flag = 0, av_idx = 0, cmd_idx = 0;
	struct stat buffer;

	signal(SIGINT, SIG_IGN);  /* Ignores Ctrl+C signal to quit shell */

	while (status != 5)
	{
		write(STDOUT_FILENO, "$ ", 2); /* Write command prompt to stdout */
		flag = 0;
		if (ac > 1)
		{
			flag = 1;
			commands = malloc(sizeof(*commands) * (ac + 1));
			av_idx = ac;
			commands[av_idx] = NULL;
			av_idx = 1;
			while (ac != 1)
			{
				commands[cmd_idx] = av[av_idx];
				av_idx++;
				cmd_idx++;
				ac--;
			}
/*		printf("%s\n", commands[1]); */
		}
		if (!flag)
		{
			line = read_line(); /* Stores command written in line */
			commands = split_line(line);
		}
/*		printf("%s\n", commands[0]); */
		status = run_builtin(commands);
		if (status == -1)
		{
			if (stat(commands[0], &buffer) != 0)
			{
				path = get_path(environ);
/*				if (path == NULL)
				{
					perror("Memory fail");
					continue;
					}*/
				dirs = tokenize_path(path);
				dir = find_dir(dirs, commands[0]);
				commands[0] = dir;
			}
			_execute(commands);
		}
		free(commands);
		free(line);
	}
	return (0);
}
