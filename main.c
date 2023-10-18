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
 * main -shells entry point
 * Return: 0 when succesful
 */
int main(void)
{
	char *line = NULL, **usr_tkns = NULL;
	int wrd_len = 0, execcmd = 0;
	size_t size_line = 0;
	ssize_t line_len = 0;

	while (line_len >= 0)
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

		wrd_len = inpt_cnt(line);
		if (line[0] != '\n' && wrd_len > 0)
		{
			usr_tkns = tokenize(line, "\t", wrd_len);
			execcmd = executeBuiltInCom(usr_tkns, line);
			if (!execcmd)
			{
				usr_tkns[0] = locate(usr_tkns[0]);
				if (usr_tkns[0] && access(usr_tkns[0], X_OK) == 0)
					execute(usr_tkns[0], usr_tkns);
				else
					perror("./hsh");
			}

			free_tkns(usr_tkns);
		}
	}

	free(line);
	return (0);
}
