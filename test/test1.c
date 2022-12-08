#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

/**
 * getpath - function
 * @argv: is an array of all argument passed
 * Description: it get the absolute path of a function
 * Return: the path of a function
 */

char *getpath(char **argv)
{
	char *path;
	struct stat st;

	path = getenv("PATH");
	strcat(path, "/");
	strcat(path, argv[0]);

	printf("%s\n", path);
	if (stat(path, &st) != 0)
		exit(1);
	return (path);
}

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
	int i;

	i = 0;

	token = strtok(bufCommand, " \n");
	while (token != NULL)
	{
		argv[i] = token;
		token = strtok(NULL, " \n");
		i++;
	}
	argv[i] = NULL;

	if (argv[0][0] != '/' && argv[0][0] != '.')
		argv[0] = getpath(argv);
	return (argv);
}

/**
 * execute_funk - a function
 * @argv: it is the return value of function token_creator
 * @argenv: is the current environment
 * Description: a function that forks and execite
 * Return: i still dont know
 */
void execute_funk(char **argv, char **argenv)
{
	pid_t child;

	child = fork();
	if (child == -1)
	{
		perror("Error:");
		exit(1);
	}

	if (child == 0)
	{

		execve(argv[0], argv, argenv);
		/**
		 * i added this part in order to printout
		 * error messages and exit the process
		 */
		perror("sorry");
		exit(1);
	}

	else
	{
		/**
		 * i removed the sleeping time because
		 * it was annoying Ca m’a SOULE’ :D
		 */
		wait(NULL);
	}
}
/**
 * main - function
 * @argc: the number of argument passed => argc is not used
 * @argv: an array of all the argument passed
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
		if (strcmp(buffer, "exit\n") == 0)
		{
			printf("%s", buffer);
			break;
		}
		if (strcmp(buffer, "\n") != 0)
			execute_funk(token_creator(buffer, argv), envp);
	}
	free(buffer);
	free(argv);
	return (0);
}
