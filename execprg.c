#include "shell.h"
/**
 * execprg -executes commands
 * @argv: argument vector
 * Return: 0 when succesful
 */
int execprg(char **argv)
{
	char *cmd, *real_cmd;
	pid_t pid;
	int status;
	static char *cur_dir;

	cmd = argv[0];
	if (strcmp(cmd, "exit") == 0)
	{
		exit(0);
	}
	else if (strcmp(cmd, "pwd") == 0)
	{
		printf("%s/n", getcwd(cur_dir, 1024));
	}
	else
	{
		real_cmd = locate(cmd);
		pid = fork();
		if (pid == -1)
		{
			perror("Error: ");
		}
		else if (pid == 0)
		{
			if (execv(real_cmd, argv) == -1)
			{
				perror("Error: ");
				return (1);
			}
		}
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("Error: ");
			return (1);
		}

		free(real_cmd);
	}
	return (0);
}

