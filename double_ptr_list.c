#include "sash.h"

blocks_d *build_list_d(blocks_d *head, char** memory, char *num)
{
	blocks_d *new_node;

	new_node = malloc(sizeof(blocks_d)); /* allocate space for new node */

	new_node->memory = memory;
	new_node->num = num;
	new_node->next = NULL;

	if (head == NULL)
	{
		head = new_node;
		printf("%s\n", num);
/*		printf("%p\n", new_node->(*memory));*/
	}
	else
		while (head != NULL)
		{
			head = new_node->next;
			printf("%s\n", new_node->num);
/*			printf("%p\n", new_node->(*memory)); */
		}

	return (new_node); /* return ptr to start */
}
