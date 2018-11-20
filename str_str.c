#include "sash.h"

/**
 * str_str - Finds a substring in a string
 * @haystack: The string to be searched
 * @needle: The substring to find
 *
 * Return: Pointer to the substring if found, NULL if not found
 */
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
