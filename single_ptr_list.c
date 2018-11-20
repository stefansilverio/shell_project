#include "sash.h"

/**
 * build_list_s - Build a linked list of all single pointers allocated
 * @head: The first node of the linked list
 * @memory: The pointer to store for future freeing
 *
 * Return: A pointer to the first node of the linked list
 */

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
