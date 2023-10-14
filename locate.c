#include "shell.h"
/**
 * locate -finds the location from the path
 * @cmnd: command that has been input
 * Return: NULL or the path
 */
char *locate(char *cmnd)
{
	char *path, *path_env, *path_cmd, *dir;
	size_t len;

	path_env = getenv("PATH");
	if (path_env == NULL)
	{
		return (NULL);
	}
	path = strdup(path_env);

	if (path == NULL)
	{
		return (NULL);
	}
	dir = strtok(path, ":");
	while (dir != NULL)
	{
		len = strlen(dir) + 1 + strlen(cmnd) + 1;
		path_cmd = malloc(len);
		if (path_cmd == NULL)
		{
			free(path);
			return (NULL);
		}
		snprintf(path_cmd, len, "%s/%s", dir, cmnd);
		if (access(path_cmd, X_OK) == 0)
		{
			free(path);
			return (path_cmd);
		}
		free(path_cmd);
		dir = strtok(NULL, ":");
	}
	free(path);
	return (NULL);
}
