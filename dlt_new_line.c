#include "shell.h"
/**
 * rm_new_line -removes a new line character from string
 * @str: string in question
 * Return: the string without a new line
 */
char *rm_new_line(char *str)
{
	int r = 0;

	while (str[r])
	{
		if (str[r] == '\n')
			str[r] = '\0';
		r++;
	}

	return (str);
}
