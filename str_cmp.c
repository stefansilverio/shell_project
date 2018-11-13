#include "sash.h"

/**
 * str_cmp - Compares two strings
 * @s1: The first string to be compared
 * @s2: The second string to be compared
 *
 * Return: 0 if strings are a match, otherwise the difference
 */

int str_cmp(char *s1, char *s2)
{
	int index;

	for (index = 0 ; s1[index] == s2[index]; index++)
	{
		if (s1[index] == '\0')
			return (0);
	}
	return (s1[index] - s2[index]);
}
