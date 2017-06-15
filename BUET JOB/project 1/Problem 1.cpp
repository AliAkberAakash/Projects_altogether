#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE 1 /* Defines initially how many integers can be stored in array */
int current_max = INITIAL_SIZE, current_used = 0; /* For global use */
int *list = NULL;

void reallocate_list ();           /* Allocates an array of doubled size of list, copies list to the new array and deletes previously allocated memory */
void insertItem      (int item); /* Pass the pointer of the list, the integer to be inserted at the end of list. */
void insertItemAtPos (int item, int position); /* Pass the pointer of the list, the integer to be inserted at the end of list. */
int  deleteItem      ();
int  deleteFirstItem (int item);
int  deleteLastItem  (int item);
void clearList       ();
int  searchItem      (int item);


int main()
{
    list = (int *) malloc((size_t)(INITIAL_SIZE*sizeof(int))); /* Allocates array */
    if(list == NULL)
        printf("Memory allocation failed!\n");
    int item, position, exit_program = 0;
    char operation_type, secondary_operation_type, ignore;


    do
    {
        scanf("%c",&operation_type);
        switch(operation_type)
        {
        case 'T':
            exit_program = 1;
            break;
        case 'I':
            position = -1;
            scanf(" %d%c", &item, &ignore);
            if(ignore==' ')
                scanf("%d%c", &position, &ignore);
            if(position == -1)
                insertItem(item);
            else
                insertItemAtPos(item, position);
            break;
        case 'D':
            scanf("%c",&ignore);
            if(ignore == '\n')
                deleteItem();
            else if(ignore == ' ')
            {
                scanf("%c%d%c", &secondary_operation_type, &item, &ignore);
                if(secondary_operation_type == 'F')
                    deleteFirstItem(item);
                else if(secondary_operation_type == 'L')
                    deleteLastItem(item);
            }
            break;
        case 'S':
            scanf("%d", &item);
            searchItem(item);
            break;
        case 'C':
            clearList();
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
void insertItem      (int item)
{
    int i;
    if(current_used==current_max)
        reallocate_list();
    list[current_used] = item;
    current_used++;
    for(i=0; i<current_used; i++)
        printf("%d ", list[i]);
    printf("\n");
}
void insertItemAtPos (int item, int position)
{
    int i;
    if(current_used == current_max)
        reallocate_list();
    for(i=current_used; i>position; i--)
        list[i] = list[i-1];
    list[position] = item;
    current_used++;
    for(i=0; i<current_used; i++)
        printf("%d ", list[i]);
    printf("\n");
}
int  deleteItem      ()
{
    int i;
    current_used--;
    if(current_used<=0)
    {
        printf("Empty List\n");
        current_used = 0;
        return list[0];
    }
    else
    {
        for(i=0; i<current_used; i++)
            printf("%d ", list[i]);
        printf("\n");
        return list[current_used];
    }
}
int  deleteFirstItem (int item)
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
        return -1;
    }
    else
    {
        for(i=position; i<current_used-1; i++)
            list[i] = list[i+1];
        current_used--;
        for(i=0; i<current_used; i++)
            printf("%d ", list[i]);
        printf("\n");
        return item;
    }
}
int  deleteLastItem  (int item)
{
    int i, position = -1;
    for(i=current_used-1; i>=0; i--)
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
        return -1;
    }
    else
    {
        for(i=position; i<current_used-1; i++)
            list[i] = list[i+1];
        current_used--;
        for(i=0; i<current_used; i++)
            printf("%d ", list[i]);
        printf("\n");
        return item;
    }
}
void clearList       ()
{
    current_used = 0;
    printf("Clear Completed\n");
}
int  searchItem      (int item)
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
        printf("Not Found\n");
        return -1;
    }
    else
    {
        printf("Found at position %d\n", position);
        return position;
    }
}
