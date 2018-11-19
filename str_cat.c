#include "sash.h"

char *str_cat(char *dest, char *src)
{
	int destlen, srclen;

	for (destlen = 0; dest[destlen] != '\0'; destlen++)
		;

	for (srclen = 0; src[srclen] != '\0'; srclen++)
		dest[destlen + srclen] = src[srclen];

	return (dest);
}
