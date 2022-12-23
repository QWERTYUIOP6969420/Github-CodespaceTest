#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    size_t size_of_list = 5;
    int *dataset = calloc(size_of_list, sizeof(int));
    dataset[1] = 5;
    dataset[0] = 3;
    dataset[2] = 7;
    for(int i = 0; i < size_of_list; i++)
    {
        printf("%d\n", dataset[i]);
    }
}
 