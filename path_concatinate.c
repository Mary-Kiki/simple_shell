#include "shell.h"
/**
 * pth_conc -concatenate a program and a path name
 * @namepath: path name to be oncatenated with the program name
 * @prgname: program name to be placed in the path name
 * Return: program name to be concaenated with the path name
 */
char *pth_conc(char *namepath, char *prgname)
{
	int prg_len = 0, pth_len = 0, new_size = 0;

	prg_len = len_str(prgname);
	pth_len = len_str(namepath);
	new_size = sizeof(char) * (pth_len + prg_len + 2);
	namepath = my_realloc(namepath, (pth_len + 1), new_size);
	if (!namepath)
		return (NULL);

	conc_str(namepath, "/");
	conc_str(namepath, prgname);

	return (namepath);
}
