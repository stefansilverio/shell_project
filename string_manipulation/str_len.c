#include "sash.h"

/**
 * str_len - Counts the length of a string
 * @command: The string to be counted
 *
 * Return: The length of the counted string
 */
int str_len(char *command)
{
	int cmd_len = 0;

	while (command[cmd_len] != '\0')
		cmd_len++;
	return (cmd_len);
}
