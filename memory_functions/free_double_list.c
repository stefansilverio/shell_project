#include "sash.h"

/**
 * frees_d - free all double ptrs
 * @head: next node in list
 * Return: Nothing
 */
void frees_d(blocks_d *head)
{
	char **memory = head->memory;
	blocks_d *tmp;
	int idx = 0;

	(void)**memory;

	while (head)
	{
		while (memory[idx])
		{
			free(memory[idx]);
			idx++;
		}
		tmp = head;
		head = head->next;
		free(tmp->memory);
		free(tmp);
	}
}
