#include "shell.h"
/**
 * execute -Executes a command
 * @usr_tkns: user tokens
 * Return: nothing
 */
void execute(char **usr_tkns)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Fork error");
		exit(EXIT_FAILURE);
	}

	if (child_pid == 0)
	{
		if (execve(usr_tkns[0], usr_tkns, NULL) == -1)
		{
			perror("Execution error");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);
	}
}
