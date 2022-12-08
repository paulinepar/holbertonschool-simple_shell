#include "shell.h"

/**
 * getpath - function
 * @bufCommand: the input
 * Description: it get the absolute path of a function
 * Return: the path of a function
 */
char *getpath(char **bufCommand)
{
	char *path = NULL;
	char *token = NULL;
	char *env = NULL;
	struct stat st;

	path = calloc(sizeof(char), 1024);
	if (path == NULL)
		exit(0);

	env = strdup(getenv("PATH"));
	token = strtok(env, ":");
	while (token)
	{
		/**
		 * putting one of the pathes in the path
		 */
		strcpy(path, token);
		/**
		 * adding slash for creating a new path
		 */
		strcat(path, "/");
		strcat(path, bufCommand[0]);

		if (stat(path, &st) == 0)
		{
			free(env);
			bufCommand[0] = path;
			return (path);
		}
	/**
	 * else
	 *	perror(bufCommand[0]);
	 */

		token = strtok(NULL, ":");
	}

	free(path);
	free(env);
	return (NULL);
}

