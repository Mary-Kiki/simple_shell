#include "shell.h"
/**
 * env_prnt -prints the environment builtin
 * Return: nothing
 */
void env_prnt(void)
{
	int v = 0, y = 0;

	while (environ[v])
	{
		y = 0;
		while (environ[v][y])
		{
			myputchar(environ[v][y]);
			y++;
		}

		if (y != 0)
			myputchar('\n');
		v++;
	}
}
