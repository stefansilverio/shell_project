#include "sash.h"


char *get_path(char **env)
{
	int key_idx = 0;
	int b_idx = 0;
	int env_value = 0;
	char *buffer = NULL;

	buffer = malloc(sizeof(char) * (1024)); /* buffer size is arbitrary */
	if (buffer == NULL)
		return (NULL);

	while ((*(env[key_idx]) != 'P') && (*(env[key_idx] + 3) != 'H'))
		key_idx++; /* find right key */
	while (*(env[key_idx] + env_value) != '\0')
	{
		buffer[b_idx] = *(env[key_idx] + env_value);
		b_idx++;
		env_value++;
	}
	return (buffer);
}
