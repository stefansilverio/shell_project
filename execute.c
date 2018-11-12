#include "sash.h"

int _execute(char **tokenarr) /* execute command with args */
{
	int status;
	pid_t pid_id, wpid;

	pid_id = fork(); /* create child process */
	if (pid_id == 0) /* if child process is created execute */
	{
		if (execve(tokenarr[0], tokenarr, NULL) == -1)
			perror("sash");/* tell error is from our program */
		exit(EXIT_FAILURE); /* tell our program failed */
	}
	else if (pid_id < 0)/* couldn't create child process */
		perror("sash");
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
