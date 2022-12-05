#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
	char *buffer;
	size_t bufsize = 32;
	const char *sep = " ";
	char *token[32];
	int i = 1;
	pid_t pid;
	int status;

	while (!feof(stdin))
	{
		printf("#let's-go!!!$ ");
		getline(&buffer, &bufsize, stdin);

		token[0] = strtok(buffer, sep);
		while (token[i] != 0)
		{
			token[i] = strtok(NULL, sep);
			i++;
		}


		printf("je veux me pendre!");


		pid = fork();
		if (pid == -1)
		{
			perror("Error:");
			return (1);
		}

		if (pid == 0)
		{
			printf("ou me noyer");
			execve(buffer, token, NULL);
		}
		else
		{
			sleep(3);
			wait(&status);
		}
		free(buffer);
	}
	return (0);
}
