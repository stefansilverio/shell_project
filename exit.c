#include "sash.h"

int exit_sash(char **tokenarr)
{
	(void)**tokenarr;
	write(1, "I'm leaving...connection closed\n", 32);
	return (0);
}
