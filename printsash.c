#include "sash.h"

/**
 * main - the driver function for our sash shell
 *
 * Return: Always 0
 */

int main(void)
{
	char *line = NULL, *path = NULL, *dir = NULL;
	char **commands = NULL, **dirs = NULL;
	int status = 1;
	int index = 0;
	struct stat buffer;

	signal(SIGINT, SIG_IGN);  /* Ignores Ctrl+C signal to quit shell */

	while (status)
	{
		write(STDOUT_FILENO, "$ ", 2); /* Write command prompt to stdout */
		line = read_line(); /* Stores command written in line */
		printf("line after read_line: %s\n", line);
		if (line == NULL)
		{
			free(line);
			continue;
		}
		commands = split_line(line);
		for (index = 0; commands[index] != NULL; index++)
			printf("Commands after split_line at index %d is %s\n", index, commands[index]);
		status = run_builtin(commands);
		printf("Status after builtin searched: %d\n", status);
		if (status != -1) /* If a builtin is found, run it */
		{
			printf("Status after builtin is run: %d\n", status);
			for (index = 0; commands[index] != NULL; index++)
				printf("Commands after builtin is run and before freeing at index %d is %s\n", index, commands[index]);
			free(commands);
			printf("Line after builtin is run and before freeing is %s\n", line);
			free(line);
		}
		else if (status == -1) /* If a builtin is not found, search the PATH */
		{
			printf("Status is %d after a builtin is not found and the path is searched\n", status);
			printf("Before executing & stat, commands[0] is %s\n", commands[0]);
			if (stat(commands[0], &buffer) != 0) 
			{
				path = get_path(environ);
				printf("Path after get_path is run: %s\n", path);
				if (path == NULL)
				{
					perror("Memory fail");
					continue;
				}
				dirs = tokenize_path(path);
				for (index = 0; dirs[index] != NULL; index++)
					printf("Dirs after tokenize_path at index %d is %s\n", index, dirs[index]);
				dir = find_dir(dirs, commands[0]); 
				printf("Dir after find_dir is run: %s, Commands[0] is: %s\n", dir, commands[0]);
				commands[0] = dir;
				printf("Commands[0] after assignment to dir is: %s\n", commands[0]);
				printf("Path after get_path, tokenize_path, and find_dir are run and before freeing: %s\n", path);
				for (index = 0; dirs[index] != NULL; index++)
					printf("Dirs at index %d after get_path, tokenize_path, and find_dir are run and before freeing: %s\n", index, dirs[index]);
/*				free(dirs);*/
/*				free(path);*/
			}
			for (index = 0; commands[index] != NULL; index++)
				printf("Commands at index %d after everything is run and before they are executed: %s\n", index, commands[index]);
			_execute(commands);
			for (index = 0; commands[index] != NULL; index++)
				printf("Commands at index %d after everything is run/executed and before they are freed: %s\n", index, commands[index]);
/*			free(dirs);*/
/*			free(path);*/
			free(commands);
			printf("Line after everything is run and before it is freed: %s\n", line);
			free(line);
		}
	}
	return (0);
}
