#ifndef __SASH__
#define __SASH__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/types.h>

typedef struct builtins
{
	char *cmd;
	int (*func)();
} builtin_t;

typedef struct blocks_s
{
	char *memory;
	char *num;
	struct blocks_s *next;
} blocks_s;

typedef struct blocks_d
{
	char **memory;
	char *num;
	struct blocks_d *next;
} blocks_d;

extern char **environ;

/* essential functions for shell */
char *read_line();
char **split_line(char *line, char **av);
int _execute(char *dir, char **tokenarr, char **env);
char **tokenize_path(char *path);
char *find_dir(char **buf_dir, char *command);
char *get_path(char **env);

/* builtins */
int run_builtin(char **tokenarr);
int _env(void);
int _chdir(char **commands);
int exit_sash();

/* non-interactive/interactive modes */
int enter_nonsash(int ac, char **av, char **env);
int enter_sash(int ac, char **av, char **env);

void sighandler();

/*string manipulation functions */
int doubleptr_len(char **buf_dir, int dir_idx);
int str_len(char *command);
char *str_cat(char *dest, char *src);
char *str_str(char *haystack, char *needle);
int str_cmp(char *s1, char *s2);
char str_chr(char *s, char c);

/* linked list functions */
blocks_s *build_list_s(blocks_s *head, char *memory, char *num);
blocks_d *build_list_d(blocks_d *head, char **memory, char *num);
void frees_s(blocks_s *head);
void frees_d(blocks_d *head);

#endif
