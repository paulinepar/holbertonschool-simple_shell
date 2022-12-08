#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

char *getpath(char **bufCommand);
char **token_creator(char *bufCommand, char **argv);
void execute_funk(char **argv, char **argenv);
#endif

