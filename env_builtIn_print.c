#include "shell.h"
/**
 * env_prnt -prints the environment builtin
 * Return: nothing
 */
void env_prnt(void)
{
	int v = 0;

	while (environ[v])
	{
		my_puts(environ[v]);
		v++;
	}
}
