#include <unistd.h>
#include <stdio.h>

int execute_executables(char **tokenarr) /* execute command with args */
{
	int status = 0;
	pid_t pid_id, wpid;
	pid_id = fork(); /* create child process */
	if (pid_id == 0) /* if child process is created execute */
	{
		if (execve(buf_line[0], buf_line, environ) == -1)
			perror("sash");/* tell error is from our program */
		exit(EXIT_FAILURE); /* tell our program failed */
	}
	else if (pid_id < 0)/* couldn't create child process */
		perror("sash");
	else /* parent process get pid of child - will land here */
	{
		do {
			wpid = waitpid(pid_id, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (0);
}
