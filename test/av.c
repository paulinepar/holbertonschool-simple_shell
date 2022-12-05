#include <stdio.h>
#include <stdarg.h>

int main(int ac, char **av)
{
	char **p = av;

	while (*p != NULL)
	{
		printf("%s\n", *p);
		p++;
	}
	return (0);
}
