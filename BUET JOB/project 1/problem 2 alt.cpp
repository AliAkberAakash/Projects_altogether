#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define initial_size 10000

int* a=(int*) malloc(sizeof(int)*initial_size);

int pos=0;

void Insert(int x);
void Delete();
void clearList();
int match(int x);

int main()
{
    int item,i;
    char s[10000];

    start:

    gets(s);

    for(i=0; i<=strlen(s); i++)
    {
        item=s[i];

        if(item == '(' || item == '{' || item == '[')
            Insert(item);
        else if(item == ')' || item == '}' || item == ']')
        {
                if(a[pos-1]==match(item))
                    Delete();
                else
                {
                    printf("Not Balanced\n");
                    clearList();
                    break;
                }
        }

        if(item == '\0')
        {
            if(pos == 0)
                printf("Balanced\n");
            else
                printf("Not Balanced\n");
            clearList();
        }

    }

    goto start;

    return 0;
}

void Insert      (int item)
{
    a[pos] = item;
    pos++;
}

int match(int item)
{
    if(item==')') return '(';
    else if(item=='}') return '{';
    else if(item==']') return '[';
}

void  Delete      ()
{
    int i;
    pos--;
    if(pos<=0)
        pos = 0;
}

void clearList()
{
    pos = 0;
}
