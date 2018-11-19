#include "sash.h"

void frees_s(blocks_s *head)
{
	blocks_s *tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp->memory);
		free(tmp);
	}
}
