#include "sash.h"

/**
 *
 */

int run_builtin(char **tokenarr)
{
	int index = 0;
	builtin_t cmds[] = {
		{"exit", exit_sash}, {"env", _env}, {NULL, NULL}
	};

	while (cmds[index].cmd)
	{
		if (str_cmp(tokenarr[0], cmds[index].cmd) == 0)
		{
			cmds[index].func();
			return (0);
		}
		index++;
	}
	return (-1);
}
