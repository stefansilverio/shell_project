#include "sash.h"

int main(int ac, char **av)
{
	if (isatty(STDIN_FILENO))
		enter_sash(ac, av);
	else
		enter_nonsash(ac, av);
	return (0);
}
