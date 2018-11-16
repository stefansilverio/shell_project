#include "sash.h"

int _chdir(char **commands)
{
	int status = 0;

	printf("%s\n", commands[1]);
	status = chdir(commands[1]);
	if (status == -1)
		perror("cd");
	return (status);
}
