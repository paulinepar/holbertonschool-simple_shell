#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the environment
 *
 * Return: Always 0.
 */
int main(void)
{
	char *var = getenv("PATH");

    printf("%s\n", var);
    return (0);
}

