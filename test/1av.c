#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *buffer;
    size_t bufsize = 32;

    buffer = (char *)malloc(bufsize * sizeof(char));
    if( buffer == NULL)
    {
		free(buffer);
        exit(1);
    }

    printf("$ ");
    getline(&buffer,&bufsize,stdin);
    printf("%s",buffer);

    return(0);
}
