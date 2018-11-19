#include "sash.h"

void frees_d(blocks_d *head)
{
	char **memory = head->memory;
	blocks_d *tmp;
	int idx = 0;

	while (head)
	{
		while (memory[idx] != NULL)
		{
			free(memory[idx]);
			puts("hi");
			idx++;
		}
		tmp = head;
		head = head->next;
		free(tmp->memory);
		free(tmp);
	}
}
