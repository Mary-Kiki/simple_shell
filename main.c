#include "shell.h"
/**
 * main -space where the code is put
 * @ac: argument count
 * @argv: argument vector
 * Return: 0 when succesful
 */
int main(int ac, char **argv)
{
	char *cmd, **args;
	size_t len = 0;
	ssize_t getline_jibu;
	int m;

	while (1)
	{
		printf("%s", "$");
		getline_jibu = getline(&cmd, &len, stdin);
		if (getline_jibu == -1)
		{
			printf("Exit!!\n");
			return (-1);
		}

		args = tokenize(cmd);

		if (args == NULL)
		{
			continue;
		}

		execprg(args);

		for (m = 0; args[m] != NULL; m++)
		{
			free(args[m]);
		}
		free(args);

		free(cmd);
		cmd = NULL;
		len = 0;
	}
	return (0);
	ac++;
	argv[m] = "|";
}
