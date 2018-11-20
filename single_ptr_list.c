#include "sash.h"

blocks_s *build_list_s(blocks_s *head, char *memory)
{
	blocks_s *new_node;

	new_node = malloc(sizeof(blocks_s)); /* allocate space for new node */

	new_node->memory = memory;
	new_node->next = NULL;

	if (head == NULL)
		head = new_node;
	else
		while (head != NULL)
		{
			head = new_node->next;
		}

	return (new_node); /* return ptr to start */
}
