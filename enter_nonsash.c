#include "sash.h"

int enter_nonsash(int ac, char **av, char **env)
{
	char *line = NULL, *path = NULL, *dir = NULL;
	char **commands = NULL, **dirs = NULL;
	blocks_s *head_s = NULL, *first_node_s = NULL;
	blocks_d *head_d = NULL, *first_node_d = NULL;
	int status = 1;
	struct stat buffer;
	char *prev = NULL, *buff = NULL;

	(void)ac;

	prev = getcwd(buff, 1024);

	while (status)
	{
		line = read_line();
		if (line == NULL)
			continue;
		commands = split_line(line, av);
		head_d = build_list_d(head_d, commands);
		first_node_d = head_d;
		status = run_builtin(commands);
		if (status == -1)
		{
			path = get_path(env);
			head_s = build_list_s(head_s, path);
			first_node_s = head_s;
			if (!str_str(path, prev))
			{
				chdir("/home/vagrant");
				if (stat(commands[0], &buffer) != 0)
				{
					dirs = tokenize_path(path);
					head_d = build_list_d(head_d, dirs);
					dir = find_dir(dirs, commands[0]);
					head_s = build_list_s(head_s, dir);
					commands[0] = dir;
				}
				chdir(prev);
			}
			_execute(commands[0], commands, env);
		}
		frees_d(first_node_d);
		frees_s(first_node_s);
	}
	return (0);
}
