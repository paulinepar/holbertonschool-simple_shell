#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include "shell.h"

/**
 * getpath - function
 * @argv: is an array of all argument passed
 * Description: it get the absolute path of a function
 * Return: the path of a function
 */

char *getpath(char **argv)
{
	char *path = NULL;
	struct stat st;

	path = malloc(sizeof(char) * 1024);
	if (path == NULL)
		free(path);
	strcpy(path, "/bin/");
	strcat(path, argv[0]);

	if (stat(path, &st) != 0)
		return (argv[0]);
	return (path);
}

