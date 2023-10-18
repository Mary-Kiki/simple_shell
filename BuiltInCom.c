#include "shell.h"
/**
 * executeBuiltInCom -execute a built in command if it exists
 * @usr_tkns: an array of user tokens
 * @cmd_line: input command line
 * Return: 1 if there is a built in command 0 of not
 */
int executeBuiltInCom(char **usr_tkns, char *cmd_line)
{
	int e = 0;
	char *CountBuiltinCmds[] = { "exit", "cd", "env", NULL };

	while (CountBuiltinCmds[e])
	{
		if (str_cmp(usr_tkns[0], CountBuiltinCmds[e]) == 0)
		{
			switch (e)
			{
				case 0:
					exit_cmd(usr_tkns, cmd_line);
					break;
				case 1:
					chdir(usr_tkns[1]);
					return (1);
				case 2:
					env_prnt();
					return (1);
				default:
					break;
			}
		}
	e++;
	}
	return (0);
}
