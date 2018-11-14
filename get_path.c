#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

extern char **environ;

char *get_path(char **environ)
{
	int key_idx = 0;
	int b_idx = 0;
	int env_value = 0;
	char *buffer = NULL;

	buffer = malloc(sizeof(char) * (1024)); /* buffer size is arbitrary */

	if (buffer == NULL)
		exit(0);

	while ((*(environ[key_idx]) != 'P') && (*(environ[key_idx] + 3) != 'H'))
		key_idx++; /* find right key */
	while (*(environ[key_idx] + env_value) != '\0')
	{
		buffer[b_idx] = *(environ[key_idx] + env_value);
		b_idx++;
		env_value++;
	}
	return (buffer);
}