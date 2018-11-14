#ifndef __SASH__
#define __SASH__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

typedef struct builtins
{
	char *cmd;
	int (*func)();
} builtin_t;

extern char **environ;

char *read_line();
char **split_line(char *line);
int _execute(char **tokenarr);
int exit_sash(char **tokenarr);
int str_cmp(char *s1, char *s2);
int run_builtin(char **tokenarr);
char **tokenize_path(char *path);
char *find_dir(char **buf_dir, char *command);
char *get_path(char **environ);

#endif
