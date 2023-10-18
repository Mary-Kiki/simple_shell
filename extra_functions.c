#include "shell.h"
/**
 * my_atoi - convertes a string to an integer
 * @ptr: the pointer to convert
 * Return: an int
 */
int my_atoi(char *ptr)
{
	int sign = 1, enc_dig = 0, psn = 0;
	unsigned int ab = 0;

	while (ptr[psn])
	{
		if (ptr[psn] == '-')
			sign *= -1;

		while (ptr[psn] >= '0' && ptr[psn] <= '9')
		{
			enc_dig = 1;
			ab = (ab * 10) + (ptr[psn] - '0');
			psn++;
		}

		if (enc_dig == 1)
			break;

		psn++;
	}

	ab *= sign;
	return (ab);
}
/**
 * myputchar -writes the character c to stdout
 * @c: the character to print
 * Return: 1 when successful or -1
 */
int myputchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * my_puts -prints a string
 * @str: string to be printed
 * Return: nothing
 */
void my_puts(char *str)
{
	while (*str)
	{
		myputchar(*str);
		str++;
	}

	myputchar('\n');
}

/**
 * cmp_str -compares first n bytes of str1 and str2
 * @str1: first string
 * @str2: string two
 * @len: limit bytes of comparison
 * Return: int value
 */
int cmp_str(const char *str1, const char *str2, size_t len)
{
	unsigned int psn = 0;
	int diff = 0;

	while (psn < len)
	{
		if (str1[psn] == str2[psn])
		{
			psn++;
			continue;
		}
		else
		{
			diff = str1[psn] - str2[psn];
			break;
		}

		psn++;
	}

	return (diff);
}
