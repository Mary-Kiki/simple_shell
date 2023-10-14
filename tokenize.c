#include "shell.h"
/**
 * tokenize - tokenizes input from string
 * @input: command
 * Return: char
 */
char **tokenize(char *input)
{
	const char *DLMTR = " \t\r\n\a";
	char *cpy, *tkn, **args;
	int arg_cnt, c;

	cpy = strdup(input);

	if (cpy == NULL)
	{
		perror("Error: ");
		return (NULL);
	}

	arg_cnt = 0;
	tkn = strtok(NULL, DLMTR);

	while (tkn != NULL)
	{
		arg_cnt++;
		tkn = strtok(NULL, DLMTR);
	}
	args = calloc(arg_cnt + 1, sizeof(char *));

	if (args == NULL)
	{
		perror("Error: ");
		free(cpy);
		return (NULL);
	}
	c = 0;
	tkn = strtok(input, DLMTR);
	while (tkn != NULL)
	{
		args[c++] = strdup(tkn);
		tkn = strtok(NULL, DLMTR);
	}
	args[c] = NULL;
	free(cpy);

	return (args);
}

