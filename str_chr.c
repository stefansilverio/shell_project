#include "sash.h"

char *str_chr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (c == '\0')
		return (s);
	else if (*s != c)
		return (0);
	return (s);
}
