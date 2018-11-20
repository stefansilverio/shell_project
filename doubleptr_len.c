#include "sash.h"

/**
 * doubleptr_len - Counts the number of characters of each string in a 2D array
 * @buf_dir: The 2D array to be counted
 * @dir_idx: The index of the current string in the 2D array
 *
 * Return: The character count of the string
 */

int doubleptr_len(char **buf_dir, int dir_idx)
{
	int chr_cnt = 0;

	while (buf_dir[dir_idx][chr_cnt] != '\0')
		chr_cnt++;
	return (chr_cnt);
}
