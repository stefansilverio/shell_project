#ifndef __SASH__
#define __SASH__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

char *read_line();
char **split_line(char *line);
int _execute(char **tokenarr);

#endif
