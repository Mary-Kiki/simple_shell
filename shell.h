#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int ac, char **argv);
char **tokenize(char *input);
int execprg(char **argv);
char *locate(char *cmnd);
#endif
