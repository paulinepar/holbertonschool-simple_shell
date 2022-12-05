#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * token_creator - function
 * @bufCommand: command from buffer to be analyzed
 * @argv: is an array of all argument passed
 * Description: it parses strings from user input
 * Return: array of pointers
 */

char **token_creator(char *bufCommand, char **argv)
{
	/**
	 * argument is of type char * : because it will
	 * take the buffer and the buffer is of this type
	 * Note: I changed the type of argv “look below” from
	 * char* argv[] to char **argv because
	 * i couldnot return argv at the end of function
	 * after doing so, (changing the type) i had an
	 * error: "argv may be used unitialized"
	 * so i searched in the internet and i saw it was set to NULL
	 * =>i set it to NULL
	 * then upon compiling i recieved an error of segmentation fault
	 * so i concluded that i cant access the array of pointer and when comparing -
	 * i saw that i havent allocated a space for my new array
	 * so i used malloc to solve the issue
	 */
	char *token = NULL;
	int i;

	i = 0;

	token = strtok(bufCommand, " \n");
	while (token != NULL)
	{
		argv[i] = token;
		/*printf("%s\n", argv[1]) to check for problem;*/
		/**
		 * Note: we have one last problem :D
		 * all works well except for /bin/ls -l
		 * /bin/ls works by itself
		 * but i lost access to my second pointer in
		 * the array **argv
		 * because when i executed "printf("%s\n", argv[1]);"
		 * i got segmentation fault
		 * assignment for today allow access to argv[i];
		 */
		token = strtok(NULL, " \n");
		i++;
	}
	argv[i] = NULL;
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
