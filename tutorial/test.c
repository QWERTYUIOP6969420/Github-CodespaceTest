#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    if(argc > 2 || argc == 1)
    {
        printf("Usage: ./test string\n");
        return 1;
    }
    if(strcmp(argv[1], "CAT") == 0)
    {
        printf("Meow\n");
    } 
    else if(strcmp(argv[1], "DOG") == 0)
    {
        printf("Woof\n");
    }
}