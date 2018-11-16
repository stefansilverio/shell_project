int str_len(char *command)
{
	int cmd_len = 0;

	while (command[cmd_len] != '\0')
		cmd_len++;
	return (cmd_len);
}
