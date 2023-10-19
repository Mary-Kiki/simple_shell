#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>

extern char **environ;

char *conc_str(char *destn, char *source);
int len_str(const char *strcnt);
int str_cmp(const char *s1, const char *s2);
int cmp_str(const char *s1, const char *s2, size_t len);
char *dup_str(char *str);
int my_atoi(char *ptr);
int myputchar(char c);
void my_puts(char *str);
void *my_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int inpt_cnt(char *str);
int del_cnt(char *str, char *del);
char *rm_new_line(char *str);
void sig_hndlr(int sig_id);
void env_prnt(void);
void exit_cmd(char **usr_tkns, char *cmd_line);
int executeBuiltInCom(char **usr_tkns, char *cmd_line);
void free_loc_env(char *env_pth);
void free_tkns(char **tkns);
char *loc_env(const char *var_name);
char **tokenize(char *str, char *del, int len);
char *locate(char *cmd_name);
char *pth_conc(char *namepath, char *prgname);
void mbali_nhlapo(char *line, char **usr_tkns);
void input_sesame(char *line);
void execute(char **usr_tkns);
#endif /* SHELL_H */
