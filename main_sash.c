#include "sash.h"

int main(int ac, char **av, char **env)
{
	if (isatty(STDIN_FILENO))
		enter_sash(ac, av, env);
	else
		enter_nonsash(ac, av, env);
	return (0);
}
