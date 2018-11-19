#include "sash.h"


char *get_path(char **env)
{
	int key_idx = 0, b_idx = 0, env_value = 5, cwd_idx = 0;
	char *buffer = NULL, *curr = NULL, *buff = NULL;

	curr = getcwd(buff, 0);
	buffer = malloc(sizeof(char) * (1024)); /* buffer size is arbitrary */
	if (buffer == NULL)
		return (NULL);
	while ((*(env[key_idx]) != 'P') && (*(env[key_idx] + 3) != 'H'))
		key_idx++;
	if (*(env[key_idx] + env_value) == ':')
	{
		env_value = env_value + 1;
		str_cat(buffer, curr);
	}
	while (*(env[key_idx] + env_value) != '\0')
	{
		if (*(env[key_idx] + env_value) == ':')
		{
			if (*(env[key_idx] + (env_value + 1)) == ':')
			{
				env_value = env_value + 2;
				buffer--;
				str_cat(buffer, curr);
			}
		}
		b_idx = str_len(buffer);
		buffer[b_idx] = *(env[key_idx] + env_value);
		b_idx++;
		env_value++;
	}
	if (*(env[key_idx] + (env_value - 1)) == ':')
	{
		b_idx = b_idx - 2;
		for (cwd_idx = 0; curr[cwd_idx] != '\0'; cwd_idx++)
		{
			buffer[b_idx] = curr[cwd_idx];
			b_idx++;
		}
	}
	return (buffer);
}
