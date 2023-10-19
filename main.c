#include "shell.h"
/**
 * sig_hndlr -handles the signals
 * @sig_id: identifies the signal to be handles
 * Return: nothing
 */
void sig_hndlr(int sig_id)
{
	if (sig_id == SIGINT)
		write(STDOUT_FILENO, "\n($) ", 5);
}
/**
 * mbali_nhlapo -cleans up the code
 * @line: string of char
 * @usr_tkns: user tokens
 * Return: nothing
 */
void mbali_nhlapo(char *line, char **usr_tkns)
{
	int a;

	if (line)
	{
		free(line);
	}
	if (usr_tkns)
	{
		for (a = 0; usr_tkns[a] != NULL; a++)
		{
			free(usr_tkns[a]);
		}
		free(usr_tkns);
	}
	my_puts("Exiting shell");
}
/**
 * main -shells entry point
 * Return: 0 when succesful
 */
int main(void)
{
	char *line = NULL;
	size_t size_line = 0;
	ssize_t line_len = 0;

	while (1)
	{
		signal(SIGINT, sig_hndlr);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);
		line_len = getline(&line, &size_line, stdin);
		if (line_len == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}
		input_sesame(line);
	}
	mbali_nhlapo(line, NULL);
	return (0);
}
/**
 * input_sesame -processes the input
 * @line: string being processed
 * Return:nothing
 */
void input_sesame(char *line)
{
	int wrd_len = inpt_cnt(line);

	if (line[0] != '\n' && wrd_len > 0)
	{
		char **usr_tkns = tokenize(line, "\t", wrd_len);
		int execcmd = executeBuiltInCom(usr_tkns, line);

		if (!execcmd)
		{
			usr_tkns[0] = locate(usr_tkns[0]);

			if (usr_tkns[0] && access(usr_tkns[0], X_OK) == 0)
			{
				execute(usr_tkns);
			} else
			{
				perror("Command not found");
			}
		}
		mbali_nhlapo(NULL, usr_tkns);
	}
}
