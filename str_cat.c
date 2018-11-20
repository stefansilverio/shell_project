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
	int destlen, srclen;

	for (destlen = 0; dest[destlen] != '\0'; destlen++)
		;

	for (srclen = 0; src[srclen] != '\0'; srclen++)
		dest[destlen + srclen] = src[srclen];

	return (dest);
}
