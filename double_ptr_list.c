#include "sash.h"

/**
 * doubleptr_len - Counts the number of characters of each string in a 2D array
 * @buf_dir: The 2D array to be counted
 * @dir_idx: The index of the current string in the 2D array
 *
 * Return: The character count of the string
 */
blocks_d *build_list_d(blocks_d *head, char** memory)
{
	blocks_d *new_node;

	new_node = malloc(sizeof(blocks_d)); /* allocate space for new node */

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
