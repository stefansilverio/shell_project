#include "sash.h"
/**
 * enter_sash - the driver function for our sash shell
 * @ac: Count of arguments passed to standard input
 * @av: 2D array of arguments passed to standard input
 * @env: The environment to run the program in
 *
 * Return: Always 0
 */

int enter_sash(int ac, char **av, char **env)
{
	char *line = NULL, *path = NULL, *dir = NULL;
	char **commands = NULL, **dirs = NULL;
	blocks_s *head_s = NULL, *first_node_s = NULL;
	blocks_d *head_d = NULL, *first_node_d = NULL;
	int status = 1;
	struct stat buffer;
	(void) ac;

	signal(SIGINT, sighandler);  /* Ignores Ctrl+C signal to quit shell */

	while (status)
	{
		write(STDOUT_FILENO, "$ ", 2); /* Write command prompt to stdout */
		line = read_line(); /* Stores command written in line */
		if (line == NULL)
			continue;
		commands = split_line(line, av);
		head_d = build_list_d(head_d, commands);
		first_node_d = head_d;
		status = run_builtin(commands);
		if (status == -1)
		{
			if (stat(commands[0], &buffer) != 0)
			{
				path = get_path(env);
				head_s = build_list_s(head_s, path);
				first_node_s = head_s;
				dirs = tokenize_path(path);
				head_d = build_list_d(head_d, dirs);
				dir = find_dir(dirs, commands[0]);
				head_s = build_list_s(head_s, dir);
				commands[0] = dir;
			}
			_execute(commands[0], commands, env);
		}
	}
	frees_s(first_node_s);
	frees_d(first_node_d);
	return (0);
}

/**
 * sighandler - Tells the program what to do with Ctrl-C signal
 * @sig_num: The signal number to give to the program
 */

void sighandler(int sig_num)
{
	(void)sig_num;
	write(1, "\n", 1);
	write(1, "$ ", 2);
}
