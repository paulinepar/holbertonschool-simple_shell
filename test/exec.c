#include <unistd.h>
#include <stdio.h>

int main(void)
{
	char *argv[] = {"/bin/ls", "-l", NULL};
	char *env[] = {NULL};

	if (execve(argv[0], argv, env) == -1)
		perror("Error:");

	return (0);
}
