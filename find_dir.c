#include "sash.h"

/**
 * tokenize_path - Break down the PATH into tokens
 * @path: The path to be tokenized
 *
 * Return: A pointer to an array of pointers to tokens
 */

char **tokenize_path(char *path)
{
	char *token;
	char *delim = ":";
	char **buf_dir = NULL;
	int idx = 0;
	int count = 0;

	while (path[idx])
	{
		if (path[idx] == *delim)
			count++;
		idx++;
	}

	buf_dir = malloc(sizeof(char *) * (count + 1));
	idx = 0;
	token = strtok(path, delim);
	while (token)
	{
		buf_dir[idx] = token;
		token = strtok(NULL, delim);
		idx++;
	}
	return (buf_dir);
}
/**
 * find_dir - check the usrs path for executable
 * @buf_dir: An array of pointers to path tokens
 * @command: The command/executable given to the shell
 *
 * Return: Pointer to command concatenated with dir containing executable
 */
char *find_dir(char **buf_dir, char *command)
{
	char *buffer = NULL; /* store dir and concatenated str */
	int chr_cnt =  0; /* chrs in path dir */
	int cmd_len = 0; /* len of command usr enters */
	int buf_size = 0; /* space you need allocated */
	int dir_idx = 0, b_idx = 0;
	struct stat buff;

	while (buf_dir[dir_idx] != NULL)
	{
		cmd_len = 0;
		chr_cnt = 0;

		while (buf_dir[dir_idx][chr_cnt] != '\0')
			chr_cnt++; /* get length of next dir */
		while (command[cmd_len] != '\0')
			cmd_len++; /* len of tokenarr[0] */
		buf_size = cmd_len + chr_cnt;
		buffer = malloc((sizeof(char)) * (buf_size));

		cmd_len = 0;
		chr_cnt = 0;

		for (b_idx = 0; buf_dir[dir_idx][chr_cnt] != '\0'; b_idx++)
		{
			buffer[b_idx] = buf_dir[dir_idx][chr_cnt];
			chr_cnt++;
		}
		buffer[b_idx] = '/';
		b_idx++;
		while (command[cmd_len] != '\0')
		{
			buffer[b_idx + cmd_len] = command[cmd_len];
			cmd_len++; /* len of tokenarr[0] */
		}
		if (stat(buffer, &buff) == 0)
			return (buffer);
	}
	return (0);
}
