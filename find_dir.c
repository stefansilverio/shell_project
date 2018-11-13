#include "sash.h"


char **tokenize_path(char *path, char **tokenarr)
{
	char *token;
	char *delim = ":";
	char **buf_dir = NULL;
	int idx = 0;
	int count = 0;

	while(path[idx])
	{
		if (path[idx] = ":")
			count++;
		idx++;
	}

	buf_dir = malloc(sizeof(char *) * (count + 1));
	idx = 0;
	token = strtok(path, delim);
	while (path)
	{
		buf_dir[idx] = token;
		token = strtok(NULL, delim);
		idx++;
	}
	return (buf_dir);
}
/**
 * find_dir - check the usrs path for executable
  * Return: the dir where the executable is stored
 */
char *find_dir(char **buf_dir)
{
	char *command = tokenarr[0]; /* usrs command */
	int chr_cnt =  0; /* chrs in path dir */
	int cmd_len = 0;
	int buf_size = 0;
	int buf_idx = 0; /* current key */
	int buf_dir = 0;
	int status;

	while (buff_dir[dir_idx] != NULL)
	{
		cmd_len = 0;
		chr_cnt = 0;
		buf_idx = 0;
		while (command[cmd_len] != '\0')
			cmd_len++; /* len of tokenarr[0] */

		while (*(buf_dir[buf_idx] + chr_cnt) != '\0')
			chr_cnt++; /* get length of next dir */

		buf_size = cmd_len + chr_cnt;

		buffer = malloc((sizeof(char)) * (buf_size));

		while (chr_cnt > 0)
			buffer[buf_idx] = buf_dir[
				buf_idx++;
