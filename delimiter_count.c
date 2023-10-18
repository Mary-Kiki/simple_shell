#include "shell.h"
/**
 * del_cnt -counts delimiters in a string
 * @str: location where the delimiters will be stored
 * @del: delimeters that will be found
 * Return: number of delimeters
 */
int del_cnt(char *str, char *del)
{
	int c = 0, d = 0, wc = 0;

	while (del[c])
	{
		d = 0;
		while (str[d])
		{
			if (str[d] == del[c])
				wc++;
			d++;
		}
		c++;
	}

	return (wc);
}
