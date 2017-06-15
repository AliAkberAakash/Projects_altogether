#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE 1 /* Defines initially how many integers can be stored in array */
int current_max = INITIAL_SIZE, current_used = 0; /* For global use */
int *list = NULL;

void reallocate_list ();           /* Allocates an array of doubled size of list, copies list to the new array and deletes previously allocated memory */
void insertItem(int item); /* Pass the pointer of the list, the integer to be inserted at the end of list. */
int  deleteItem();
void clearList();
int matchingBrace(int item);

int main()
{
    list = (int *) malloc((size_t)(INITIAL_SIZE*sizeof(int))); /* Allocates array */
    if(list == NULL)
        printf("Memory allocation failed!\n");
    int item;
    while(scanf("%c", &item)!=EOF)
    {
        if(item == '(' || item == '{' || item == '[')
            insertItem(item);
        else if(item == ')' || item == '}' || item == ']')
        {
            if(list[current_used-1]==matchingBrace(item))
                    deleteItem();
            else
            {
                printf("Not Balanced\n");
                clearList();
                do
                {
                    item = getchar();
                }while(item!='\n');
                continue;
            }
        }
        if(item == '\n')
        {
            if(current_used == 0)
                printf("Balanced\n");
            else
                printf("Not Balanced\n");
            clearList();
        }
    }

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
}

int  deleteItem      ()
{
    int i;
    current_used--;
    if(current_used<=0)
    {
        current_used = 0;
        return list[0];
    }
    else
    {
        return list[current_used];
    }
}

int matchingBrace(int item)
{
    if(item==')') return '(';
    else if(item=='}') return '{';
    else if(item==']') return '[';
}

void clearList       ()
{
    current_used = 0;
}
