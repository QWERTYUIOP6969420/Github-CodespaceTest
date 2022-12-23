#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *createNode(int val);
void deleteNode(int val, Node *list_to_copy, int list_length);
Node *sortList(Node *list_to_sort, int list_length);
int *quickSort(int *array, int low, int high);
int partition(int *array, int low, int high);

int main()
{ 
    int dataset[] = {305, 170, 1057, 230, 21, 1};
    struct Node *linked_list = malloc(sizeof(Node));
    struct Node **Plinked_list = &linked_list;
    linked_list->next = malloc(sizeof(Node));
    int i = 0;
    int list_length = 0;
    struct Node *linked_list_copy = *Plinked_list;
    while(i < (sizeof(dataset)/sizeof(int))){
        linked_list_copy = createNode(dataset[i]);
        linked_list_copy = linked_list_copy->next;
        i++;
    }
    deleteNode(21, linked_list, sizeof(dataset)/sizeof(int));
    //sortList(linked_list, sizeof(dataset)/sizeof(int));
    while(linked_list->next != NULL)
    {
        printf("%d\n", linked_list->data);
        linked_list = linked_list->next;
    }
    
}

Node *createNode(int val)
{
    struct Node *newNode = malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = malloc(sizeof(Node));
    return newNode;
}

void deleteNode(int val, Node *list_to_copy, int list_length)
{
    if(list_to_copy->data != val && list_to_copy != NULL)
    {
        list_to_copy = list_to_copy->next;
        deleteNode(val, list_to_copy, list_length);
    } 
    else if(list_to_copy->data == val){
        list_to_copy->data = list_to_copy->next->data;
        list_to_copy->next = list_to_copy->next->next;
    }
}

Node *sortList(Node *list_to_sort, int list_length)
{
    struct Node **Plist_to_sort = &list_to_sort;
    struct Node *list_to_sort_copy = *Plist_to_sort;
    int *dataset = calloc(list_length, sizeof(int));
    int y = 0;
    while(list_to_sort_copy->next != NULL){
        dataset[y] = list_to_sort_copy->data;
        list_to_sort_copy = list_to_sort_copy->next;
        y++;
    }
    dataset = quickSort(dataset, 0, list_length - 1);
    struct Node *list_to_sort_copy2 = *Plist_to_sort;
    for(int i = 0; i < list_length; i++)
    {
        list_to_sort_copy2->data = dataset[i];
        list_to_sort_copy2 = list_to_sort_copy2->next;
    }
    return list_to_sort;
}

int *quickSort(int *array, int low, int high)
{
    if(low < high)
    {   
        int partition_index = partition(array, low, high);
        quickSort(array, partition_index + 1, high);
        quickSort(array, low, partition_index - 1);
    }
    return array;
}

int partition(int *array, int low, int high)
{
    int pivot = array[high];
    int i = low - 1;
    for(int j = low; j < high; j++)
    {
        if(array[j] < pivot)
        {
            i++;
            int x = array[j];
            array[j] = array[i];
            array[i] = x;
        }
    }
    int y = array[i + 1];
    array[i + 1] = array[high];
    array[high] = y;
    return i + 1;
}