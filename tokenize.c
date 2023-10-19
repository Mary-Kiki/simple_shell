#include "shell.h"
/**
 * tokenize - tokenizes input from string
 * @str: the string to tokenize
 * @del: delimiter of tokenization
 * @len: token number
 * Return: array of tokens
 */
char **tokenize(char *str, char *del, int len)
{
	char **tokens = NULL, *token = NULL, *temp = NULL;
	int t = 0;

	tokens = malloc(sizeof(char *) * (len + 1));
	if (!tokens)
		return (NULL);
	str = rm_new_line(str);
	temp = dup_str(str);
	token = strtok(temp, del);

	while (token)
	{
		tokens[t] = dup_str(token);
		token = strtok(NULL, del);
		t++;
	}
	tokens[t] = NULL;
	free(temp);
	return (tokens);
}
