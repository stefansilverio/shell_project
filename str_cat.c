#include "sash.h"

/**
 * str_cat - Concatenates two strings together
 * @dest: The string to be appended
 * @src: The string to append to dest
 *
 * Return: A pointer to the concatenated string
 */
char *str_cat(char *dest, char *src)
{
	int str1, str2, size, idx = 0, idx2;
	char *buf = NULL;

	str1 = str_len(src);
	str2 = str_len(dest);
	size = str1 + str2;
	buf = malloc(sizeof(char) * size);
	while (str1--)
	{
		buf[idx] = src[idx];
		idx++;
	}
	idx2 = idx;
	while (str2--)
	{
		buf[idx2] = dest[idx];
		idx2++;
	}
	return (buf);
}
