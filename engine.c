#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
	while (1)
	{

		write(STDIN_FILENO, "", 1);

		char *sash_read(void) /* read line from stdin to buffer */
		{
			char *line = NULL;
			size_t bufsize = 0;
			int status = 0;

			status = getline(&line, &bufsize, stdin);
			if (status == -1)
				return (-1);

			return (line); /* return array of ptrs to lines of output */
		}

		char parse_line(char **line) /* return array of parsed args */
		{
			char *buf_line = NULL;
			int idx = 0;

			buf_line = malloc(sizeof(char) * 500); /* create buffer */
			while (strtok(*line, " ") != NULL)
			{
				buf_line[idx] = strtok(*line, " ");
				idx++;
			}
			return (&buf_line);
		}
		char execute_executables(char **buf_line) /* execute command with args */
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
			return (1);
		}
	}
	free(line); /* free buffer getline created */
	free(buf_line); /* free buffer of parsed args */
	return (0);
}
