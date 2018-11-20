#include "sash.h"

void frees_d(blocks_d *head)
{
	char **memory = head->memory;
	blocks_d *tmp;
	int idx = 0;

	while (head)
	{
		while (head->memory[idx])
		{
			free(memory[idx]);
			idx++;
		}
		head++;
		tmp = head;
		head = head->next;
		free(tmp->memory);
		free(tmp);
	}
}
