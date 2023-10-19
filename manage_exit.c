#include "shell.h"
/**
 * exit_cmd -handles the exit command
 * @usr_tkns: an array of user tokens
 * @cmd_line: input command line
 * Return: nothing
 */
void exit_cmd(char **usr_tkns, char *cmd_line)
{
	int status = 0;

	if (usr_tkns[1])
	{
		status = my_atoi(usr_tkns[1]);
		if (status == 0)
		{
			my_puts("exit: illegal number: ");
			my_puts(usr_tkns[1]);
			my_puts("\n");
		}
	}

	free_tkns(usr_tkns);
	free(cmd_line);

	exit(status);
}
