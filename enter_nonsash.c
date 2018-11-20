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
	char *blk0 = "blk0", *blk1 = "blk1", *blk2 = "blk2", *blk3 = "blk3", *blk4 = "blk4";
	(void)ac;
	(void)**av;
	(void)*blk0;
	prev = getcwd(buff, 1024);

	while (status)
	{
		line = read_line();
		if (line == NULL)
			continue;
		commands = split_line(line, av);
		head_d = build_list_d(head_d, commands, blk1);
		first_node_d = head_d;
		status = run_builtin(commands);
		if (status == -1)
		{
			path = get_path(env);
			head_s = build_list_s(head_s, path, blk2);
			first_node_s = head_s;
			if (!str_str(path, prev))
			{
				chdir("/home/vagrant");
				if (stat(commands[0], &buffer) != 0)
				{
					dirs = tokenize_path(path);
					head_d = build_list_d(head_d, dirs, blk3);
					dir = find_dir(dirs, commands[0]);
					head_s = build_list_s(head_s, dir, blk4);
					commands[0] = dir;
				}
				chdir(prev);
			}
			_execute(commands[0], commands, env);
		}
		frees_s(first_node_s);
		frees_d(first_node_d);
	}
	return (0);
}
