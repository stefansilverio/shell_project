#include "sash.h"

/**
 * _execute - execute each argument stored in tokenarr
 *
 * @tokenarr: array of char pointers
 *
 * Return: Exit status
 */
int _execute(char **tokenarr) /* execute command with args */
{
	int status;
	pid_t pid_id, wpid;

	pid_id = fork(); /* create child process */
	if (pid_id == 0) /* if child process is created execute */
	{
		if (execve(tokenarr[0], tokenarr, NULL) == -1)
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
