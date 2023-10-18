#include "shell.h"
/**
 * free_loc_env -frees the environment variable
 * @env_pth: environmental variable being freed
 * Return: nothing
 */
void free_loc_env(char *env_pth)
{
	int e;

	for (e = 4; e >= 0; e--)
		env_pth--;

	free(env_pth);
}

/**
 * free_tkns -frees tokens
 * @tkns: tokens being freed
 * Return: nothing
 */
void free_tkns(char **tkns)
{
	if (tkns)
	{
		while (*tkns)
			free(*tkns++);
	}
}
