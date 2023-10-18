#include "shell.h"
/**
 * loc_env -gets an environmental variable
 * @var_name: variable to find in the environmental system
 * Return: content of environmental variable
 */
char *loc_env(const char *var_name)
{
	int e = 0;
	char *env_var = NULL;

	while (environ[e])
	{
		if (cmp_str(var_name, environ[e], len_str(var_name)) == 0)
		{
			env_var = dup_str(environ[e]);
			while (*env_var != '=')
				env_var++;

			++env_var;
			return (env_var);
		}
		e++;
	}

	return (NULL);
}
