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
	char *path = NULL;
	struct stat st;

	path = malloc(sizeof(char)* (strlen(path)));
	if (path == NULL)
		free(path);
	strcpy(path, "/bin/");
	strcat(path, argv[0]);

	if (stat(path, &st) != 0)
	{

		printf("7\n");
		/*free(path);*/
		/*printf("%s: command not found\n", argv[0]);*/
		return (argv[0]);
	}

	printf("8\n");
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

	token = strtok(bufCommand, " \t\r\n");

	while (token != NULL)
	{
		if (strlen(token) > 0)
		{
			argv[i] = token;
			i++;
		}
		token = strtok(NULL, " \t\r\n");
	}
	argv[i] = NULL;

	printf("4.1\n");
	if (argv[0][0] != '/' && argv[0][0] != '.')
	{		
		printf("5\n");
		argv[0] = getpath(argv);
		printf("6\n");
	}

	/*free(token);*/
	printf("7\n");
	/*free(bufCommand);*/
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
		/*free(argv);
		free(argenv);*/
		exit(1);
	}

	if (child == 0)
	{

		printf("9\n");
		if (!(execve(argv[0], argv, argenv)));
		/**
		 * i added this part in order to printout
		 * error messages and exit the process
		 */
		if (argv[0][0] != '/' && argv[0][0] != '.')
		{

			printf("10\n");
			printf("%s: command not found\n", argv[0]);
		}
		else
		{
			printf("11\n");
			perror(argv[0]);
		}

		printf("12\n");
		/*free(argv);
		free(argenv);*/
		exit(1);
	}

	else
	{
		printf("13\n");
		/**
		 * i removed the sleeping time because
		 * it was annoying Ca m’a SOULE’ :D
		 */
		wait(NULL);
	}
	free(argv);
	/*free(argenv);*/
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
	size_t bufsize = 0;

	(void)argc;
	/*argv = malloc(sizeof(char *) * (strlen(*argv)));
	if (argv == NULL)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}*/
	buffer = malloc(bufsize * sizeof(char));
	if (buffer == NULL)
	{
		perror("Unable to allocate buffer");
		free(argv);
		exit(1);
	}
	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");
		getline(&buffer, &bufsize, stdin);

		printf("1\n");
		if (feof(stdin))
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			break;
		}
		if (strcmp(buffer, "exit\n") == 0)
		{
			printf("2\n");
			break;
		}
		if (strcmp(buffer, "\n") != 0)
		{

			printf("3\n");
			execute_funk(token_creator(buffer, argv), envp);
			printf("4\n");
		}
	}
	free(buffer);
	printf("espace\n");
	return (0);
}
