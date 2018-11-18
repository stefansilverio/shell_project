#include "sash.h"

int enter_nonsash(int ac, char **av, char **env)
{
	char *line = NULL, *path = NULL, *dir = NULL;
	char **commands = NULL, **dirs = NULL;
	int status = 1;
	struct stat buffer;
	char *prev = NULL, *buff = NULL;

	(void)ac;

	prev = getcwd(buff, 0);
	
	while (status)
	{
		line = read_line();
		if (line == NULL)
			continue;
		commands = split_line(line, av);
		status = run_builtin(commands);
		if (status == -1)
		{
			if (!str_chr(commands[0], '/'))
			{
				if (stat(commands[0], &buffer) != 0)
				{
					chdir("/home/vagrant");
					path = get_path(env);
					dirs = tokenize_path(path);
					dir = find_dir(dirs, commands[0]);
					commands[0] = dir;
					chdir(prev);
				}
			}
			_execute(commands[0], commands, env);
		}
		free(commands);
		free(line);
	}
	return (0);
}
