#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"
/**
 * main - function
 * @argc: the number of argument passed => argc is not used
 * @argv: an arriay of all the argument passed
 * @envp: the current environment
 *
 * Description: it will keep accepting input from buffer
 * Return: 0 upon sucess
 */
int main(int argc, char **argv, char **envp)
{
	char *buffer = NULL;
	size_t bufsize = 1024;

	(void)argc;
	argv = malloc(sizeof(char *) * 1024);
	if (argv == NULL)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}
	buffer = malloc(bufsize * sizeof(char));
	if (buffer == NULL)
	{
		perror("Unable to allocate buffer");
		free(buffer);
		free(argv);
		exit(1);
	}
	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");
		getline(&buffer, &bufsize, stdin);
		if (feof(stdin))
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			break;
		}
		if (strcmp(buffer, "exit\n") == 0 ||
				(strlen(buffer) == 2 && buffer[0] == ' '))
				{
			break;
		}
		if (strcmp(buffer, "\n") != 0)
			execute_funk(token_creator(buffer, argv), envp);
		}
	free(buffer);
	free(argv);
	return (0);
}
