#include "sash.h"

/**
 * frees_s - Frees all allocated single pointers added to linked list
 * @head: The first node of the linked list
 */

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
