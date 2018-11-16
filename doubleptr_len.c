#include "sash.h"

int doubleptr_len(char **buf_dir, int dir_idx)
{
	int chr_cnt = 0;

	while(buf_dir[dir_idx][chr_cnt] != '\0')
		chr_cnt++;
	return (chr_cnt);
}
