#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE 1 /* Defines initially how many integers can be stored in array */
int current_max = INITIAL_SIZE, current_used = 0; /* For global use */
int *list = NULL;

void reallocate_list ();           /* Allocates an array of doubled size of list, copies list to the new array and deletes previously allocated memory */
void insertItem      (int item); /* Pass the pointer of the list, the integer to be inserted at the end of list. */
void  deleteItem      (int item);
int  findItem      (int item);


int main()
{
    list = (int *) malloc((size_t)(INITIAL_SIZE*sizeof(int))); /* Allocates array */
    if(list == NULL)
        printf("Memory allocation failed!\n");
    int item, exit_program = 0;
    char  operation_type, ignore;


    do
    {
        scanf("%c",&operation_type);
        switch(operation_type)
        {
        case 'T':
            exit_program = 1;
            break;
        case 'I':
            scanf(" %d%c", &item, &ignore);
            insertItem(item);
            break;
        case 'D':
            scanf(" %d%c", &item, &ignore);
            deleteItem(item);
            break;
        case 'F':
            scanf("%d", &item);
            findItem(item);
            break;
        default:
            break;
        }
    }
    while(exit_program == 0);

    return 0;
}

void reallocate_list ()
{
    int *newlist = NULL, i;
    newlist = (int *) malloc((size_t)(2*current_max*sizeof(int)));
    if(newlist == NULL)
        printf("Memory allocation failed!\n");
    else
        current_max *= 2;
    for(i = 0; i <current_used; i++)
        newlist[i]=list[i];
    free(list);
    list = newlist;
}
void insertItem(int item)
{
    int i, position;
    if(current_used==current_max)
        reallocate_list();
    for(i=0; i<current_used; i++)
        if(list[i]>item) break;
    if(current_used==0 || i==current_used) list[i] = item;
    else
    {
        position = i;
        for(i=current_used; i>position; i--)
        {
            list[i] = list[i-1];
        }
        list[position] = item;
    }
    current_used++;
    for(i=0; i<current_used; i++)
        printf("%d ", list[i]);
    printf("\n");
}


void deleteItem(int item)
{
    int i, position = -1;
    for(i=0; i<current_used; i++)
    {
        if(list[i] == item)
        {
            position = i;
            break;
        }
    }
    if(position==-1)
    {
        printf("Element not Found\n");
    }
    else
    {
        for(i=position; i<current_used-1; i++)
            list[i] = list[i+1];
        current_used--;
        for(i=0; i<current_used; i++)
            printf("%d ", list[i]);
        printf("\n");
    }
}

int findItem(int item)
{
    int i, position = -1;
    for(i=0; i<current_used; i++)
    {
        if(list[i] == item)
        {
            position = i;
            break;
        }
    }
    if(position==-1)
    {
        printf("not found\n");
        return -1;
    }
    else
    {
        printf("Found at position %d\n", position);
        return position;
    }
}
