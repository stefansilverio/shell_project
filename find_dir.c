#include "sash.h"

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
	int dir_idx = 0;
	int b_idx = 0;
	struct stat buff;

	while (buf_dir[dir_idx] != NULL)
	{
		cmd_len = doubleptr_len(buf_dir, dir_idx);
		chr_cnt = str_len(command);
		buf_size = cmd_len + chr_cnt;

		buffer = malloc((sizeof(char)) * (buf_size));
		chr_cnt = 0;

		for (b_idx = 0; buf_dir[dir_idx][chr_cnt] != '\0'; b_idx++)
		{
			buffer[b_idx] = buf_dir[dir_idx][chr_cnt];
			chr_cnt++;
		}
		buffer[b_idx] = '/';
		b_idx++;
		cmd_len = 0;
		while (command[cmd_len] != '\0')
		{
			buffer[b_idx] = command[cmd_len];
			b_idx++;
			cmd_len++; /* len of tokenarr[0] */
		}
		if (stat(buffer, &buff) == 0)
			return (buffer);
		dir_idx++;
	}
	return (NULL);
}
