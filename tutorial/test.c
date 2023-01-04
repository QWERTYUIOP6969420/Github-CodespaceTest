#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int *return_array = NULL;
    for(int i = 0; i < 5; i++)
    {
        return_array = calloc(1, sizeof(int));
    }
    int i = 0;
    while(i < 5)
    {
        printf("%d\n", return_array[i]);
        i++;
    }
    printf("%d", i);
}