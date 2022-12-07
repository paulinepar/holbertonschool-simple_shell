#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include "shell.h"
/**
 * token_creator - function
 * @bufCommand: command from buffer to be analyzed
 * @argv: is an array of all argument passed
 * Description: it parses strings from user input
 * Return: array of pointers
 */
char **token_creator(char *bufCommand, char **argv)
{
	char *token = NULL;
	char *cmd = NULL;
	int i;

	i = 0;

	token = strtok(bufCommand, "\n ");
	if (token == NULL)
		return (NULL);
	while (token != NULL)
	{
		argv[i] = token;
		token = strtok(NULL, " \n");
		i++;
	}
	bufCommand = argv[0];

	cmd = getpath(&bufCommand);
	argv[0] = cmd == NULL ? strdup(argv[0]) : cmd;
	return (argv);
}

