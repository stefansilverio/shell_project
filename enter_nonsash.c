#include "sash.h"

int enter_nonsash(int ac, char **av)
{
	char *line = NULL, *path = NULL, *dir = NULL;
	char **commands = NULL, **dirs = NULL;
	int status = 1;
	struct stat buffer;

	(void)ac;
	(void)**av;
	while (status)
	{
		line = read_line();
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
		free(commands);
		free(line);
	}
	return (0);
}
