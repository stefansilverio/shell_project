#include "sash.h"

/**
 * _chdir - Changes the directory
 * @commands: The directory to change to. If no dir is given, chdir to home
 *
 * Return: Always 1
 */
int _chdir(char **commands)
{
	int status = 0;
	char *directory = NULL;

	if (!commands[1] || *commands[1] == '~')
	{
		if (chdir("/home/vagrant") == 0)
			getcwd(directory, sizeof(directory));
		return (1);
	}
	else if (*commands[1] == '-' && !commands[1][1])
	{
		write(STDIN_FILENO, "/home/vagrant\n", 15);
		if (chdir("/home/vagrant") == 0)
			getcwd(directory, sizeof(directory));
		return (1);
	}
	else
	{
		status = chdir(commands[1]);
		if (status == -1)
			perror("cd");
		return (1);
	}
}
