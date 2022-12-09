#include "shell.h"
/**
 * exit_funk - function
 * @buffer: argument1
 * @argument: argument2
 * Description: a function that exit
 * Return: void
 */
int exit_funk(char *buffer, char **argument)
{
	exit(2);
	free(buffer);
	free(argument);
}

/**
 * print_env - function
 * @envp: environment
 * Description: a function that prints the current environment
 * Return: 1
 */
int print_env(char **envp)
{
	int i;

	i = 0;

	if (envp != NULL)
	{
		for (i = 0; envp[i]; i++)
			printf("%s\n", envp[i]);
	}
	return (1);
}
/**
 * main - function
 * @argc: the number of argument passed => argc is not used
 * @argv: an arriay of all the argument passed
 * @envp: the current environment
 * Description: it will keep accepting input from buffer
 * Return: 0 upon sucess
 */
int main(int argc, char **argv, char **envp)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	char **argument = NULL;
	(void)argc, (void)argv;
	argument = calloc(sizeof(char *), 1024);
	if (argument == NULL)
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
		else if (strcmp(buffer, "env\n") == 0)
			print_env(envp);
		else
		token_creator(buffer, argument);
		if (argument[0] != NULL)
		{
			execute_funk(argument, envp);
			if (strcmp(buffer, "exit\n") == 0)
				break;
			exit_funk(buffer, argument);
			free(argument[0]);
			argument[0] = NULL;
		}

	}
	free(buffer);
	free(argument);
	return (0);
}
