#include "sash.h"

/**
 * run_builtin - Finds the right builtin to run
 * @tokenarr: The builtin command passed to the shell
 *
 * Return: Upon success, return value of executed builtin, otherwise -1
 */
int run_builtin(char **tokenarr)
{
	int index = 0;
	builtin_t cmds[] = {
		{"exit", exit_sash}, {"env", _env}, {"cd", _chdir}, {NULL, NULL}
	};

	while (cmds[index].cmd)
	{
		if (str_cmp(tokenarr[0], cmds[index].cmd) == 0)
		{
			if (cmds[2].cmd[1] == 'd')
				return (cmds[index].func(tokenarr));
			return (cmds[index].func());
		}
		index++;
	}
	return (-1);
}
