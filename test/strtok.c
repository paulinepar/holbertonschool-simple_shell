#include <stdio.h>
#include <string.h>

int main()
{
	char str[] = "Hello baby guess who's back ?!";
	char str2[] = "Hello baby guess who's back ?!";
	const char *sep = " ";
	char *token;
	int i = 0;

	token = strtok(str, sep);
	while (token != 0)
	{
		printf("%s\n", token);
		token = strtok(0, sep);
	}
	printf("-------------------->\n");

	while (str2[i] != '\0')
	{
		if (str2[i] == ' ')
			printf("\n");
		else
			printf("%c", str2[i]);
		i++;
	}
	return (0);
}
