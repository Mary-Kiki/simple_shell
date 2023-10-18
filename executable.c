#include "shell.h"
/**
 * execute -Executes a command
 * @cmd_name: command to be executed
 * @flags: options or flags for the command
 * Return: 0 for success or -1 for failure
 */
int execute(const char *cmd_name, char **flags)
{
	pid_t child;
	int status;

	switch (child = fork())
	{
		case -1:
			perror("fork failed");
			return (-1);
		case 0:
			execve(cmd_name, flags, environ);
			break;
		default:
			do {
				waitpid(child, &status, WUNTRACED);
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (0);
}
