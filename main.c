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
	size_t bufsize = 0;

	(void)argc;
	argv = calloc(sizeof(char *), 1024);
	if (argv == NULL)
	{
		perror("Unable to allocate buffer");
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
		if (strcmp(buffer, "exit\n") == 0)
			break;
		token_creator(buffer, argv);
		if (argv[0] != NULL)
		{
			execute_funk(argv, envp);
			free(argv[0]);
		}
	}
	free(buffer);
	free(argv);
	return (0);
}
