#include "sash.h"

char *str_str(char *haystack, char *needle)
{
	while (*haystack)
	{
		char *htest = haystack;
		char *ntest = needle;

		while (*haystack && *ntest && *haystack == *ntest)
		{
			haystack++;
			ntest++;
		}
		if (!*ntest)
			return (htest);

		haystack = htest + 1;
	}
	return (NULL);
}
