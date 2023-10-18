#include "shell.h"
/**
 * dup_str -duplicates a string
 * @str: string to be duplicated
 * Return: string duplicated
 */
char *dup_str(char *str)
{
	int index = 0, len = 1;
	char *strdup;

	if (str == NULL)
		return (NULL);

	len = len_str(str);
	strdup = malloc((sizeof(char) * len) + 1);
	if (strdup == NULL)
		return (NULL);

	while (index < len)
	{
		strdup[index] = str[index];
		index++;
	}

	strdup[index] = '\0';
	return (strdup);
}

/**
 * len_str -counts the length of a string
 * @strcnt: string counts
 * Return: length of string
 */
int len_str(const char *strcnt)
{
	int c = 0;

	while (strcnt[c])
		c++;

	return (c);
}

/**
 * cmp_str -compares two strings
 * @s1: first string
 * @s2: second string
 * Return: int value
 */
int str_cmp(char *s1, char *s2)
{
	int len_s1 = 0, len_s2 = 0, psn = 0, diff = 0, limt = 0;

	len_s1 = len_str(s1);
	len_s2 = len_str(s2);

	if (len_s1 <= len_s2)
		limt = len_s1;
	else
		limt = len_s2;
	while (psn <= limt)
	{
		if (s1[psn] == s2[psn])
		{
			psn++;
			continue;
		}
		else
		{
			diff = s1[psn] == s2[psn];
			break;
		}

		psn++;
	}

	return (diff);
}
/**
 * conc_str -concatenates two strings
 * @destn: destination of a string
 * @source: the source of string
 * Return: pointer to string destination
 */
char *conc_str(char *destn, char *source)
{
	int dest_len = 0, n = 0;

	while (destn[dest_len])
		dest_len++;
	for (n = 0; source[n] != '\0'; n++)
	{
		destn[dest_len] = source[n];
		dest_len++;
	}

	destn[dest_len] = '\0';
	return (destn);
}

