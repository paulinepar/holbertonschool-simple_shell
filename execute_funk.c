#include "shell.h"
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
		/**
		 * momo: i changed this because it created trailing statements errors
		 * if (!(execve(argv[0], argv, argenv)));
		 */
		execve(argv[0], argv, argenv);
		/**
		 * i added this part in order to printout
		 * error messages and exit the process
		 */

		if (argv[0][0] != '/' && argv[0][0] != '.')
			perror(argv[0]);
		else
			perror(argv[0]);
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
