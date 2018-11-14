#include "sash.h"


char **tokenize_path(char *path)
{
	char *token;
	char *delim = ":";
	char **buf_dir = NULL;
	int idx = 0;
	int count = 0;

	while(path[idx])
	{
		if (path[idx] == delim)
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
char *find_dir(char **buf_dir, char *command)
{
	char *buffer = NULL /* store dir and concatenated str */
	int chr_cnt =  0; /* chrs in path dir */
	int cmd_len = 0; /* len of command usr enters */
	int buf_size = 0; /* space you need allocated */
	int curr_dir = 0; /* position in buf_dir */
	int b_idx = 0; /* position in b_index */
	int status;

	while (buf_dir[dir_idx] != NULL)
	{
		cmd_len = 0;
		chr_cnt = 0;
		buf_idx = 0;

		while (buf_dir[curr_dir] + chr_cnt != '\0')
			chr_cnt++; /* get length of next dir */

		while (command[cmd_len] != '\0')
			cmd_len++; /* len of tokenarr[0] */

		buf_size = cmd_len + chr_cnt;

		buffer = malloc((sizeof(char)) * (buf_size));

		cmd_len = 0;
		chr_cnt = 0;

		while (buf_dir[buf_dir] + chr_cnt != '\0')
		{
			buffer[b_idx] = buf_dir[curr_dir] + chr_cnt;
			chr_cnt++; /* get length of next dir */
		}

		while (command[cmd_len] != '\0')
		{
			buffer[b_idx] = command[cmd_len];
			cmd_len++; /* len of tokenarr[0] */
		}

		if (stat(buffer) == 0)
			return (buffer);
	}
	return (0);
}
