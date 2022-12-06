#ifndef SHELL_H
#define SHELL_H
char *getpath(char **argv);
char **token_creator(char *bufCommand, char **argv);
void execute_funk(char **argv, char **argenv);
#endif

