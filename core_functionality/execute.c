#include "sash.h"

/**
 * _execute - execute each argument stored in tokenarr
 * @dir: The command passed to the program
 * @tokenarr: array of char pointers to each argument passed
 * @env: The environment to execute the program in
 *
 * Return: Always 0
 */
int _execute(char *dir, char **tokenarr, char **env) /* execute command */
{
	int status;
	pid_t pid_id, wpid;

	pid_id = fork(); /* create child process */
	if (pid_id == 0) /* if child process is created execute */
	{
		if (execve(dir, tokenarr, env) == -1)
			perror("./sash: 1");/* tell error is from our program */
		exit(EXIT_FAILURE); /* tell our program failed */
	}
	else if (pid_id < 0)/* couldn't create child process */
		perror("./sash: 1");
	else /* parent process get pid of child - will land here */
	{
		do {
			wpid = waitpid(pid_id, &status, WUNTRACED);
			if (wpid == -1)
				exit(EXIT_FAILURE);
				} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (0);
}
