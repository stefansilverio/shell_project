#include "sash.h"

/**
 * _env - Builtin that prints the current environment
 *
 * Return: Always 1
 */
int _env(void)
{
	int key = 0;
	int val_cnt = 0;
	char c = '\n';

	while (environ[key] != NULL)
	{
		val_cnt = 0;
		while (environ[key][val_cnt] != '\0')
			val_cnt++;
		write(1, environ[key], val_cnt);
		write(1, &c, 1);
		key++;
	}
	return (1);
}
