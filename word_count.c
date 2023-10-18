#include "shell.h"
/**
 * inpt_cnt -counts words typed by user
 * @str: string where the typed words are located
 * Return: number of words found in the string
 */
int inpt_cnt(char *str)
{
	int c = 0, wc = 0, inword = 0;

	while (str[c])
	{
		if (str[c] == ' ' || str[c] == '\n' || str[c] == '\t')
			inword = 0;
		else if (inword == 0)
		{
			inword = 1;
			wc++;
		}

		c++;
	}

	return (wc);
}
