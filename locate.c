#include "shell.h"
/**
 * locate -finds if command is in the system
 * @cmd_name: command that is being located
 * Return: NULL upon failure or the path name of command
 */
char *locate(char *cmd_name)
{
	char *env_pth = NULL, **pth_tkns = NULL;
	int f = 0, del_num = 0;

	if (cmd_name)
	{
		struct stat f_info;

		if (stat(cmd_name, &f_info) != 0 && cmd_name[0] != '/')
		{
			env_pth = loc_env("PATH");
			del_num = del_cnt(env_pth, ":") + 1;
			pth_tkns = tokenize(env_pth, ":", del_num);

		while (pth_tkns[f])
		{
			pth_tkns[f] = pth_conc(pth_tkns[f], cmd_name);

			if (stat(pth_tkns[f], &f_info) == 0)
			{
				free(cmd_name);
				cmd_name = dup_str(pth_tkns[f]);
				free_loc_env(env_pth);
				free_tkns(pth_tkns);
				return (cmd_name);
			}

			f++;
		}

		free_loc_env(env_pth);
		free_tkns(pth_tkns);
		}
	}
	return (NULL);
}
