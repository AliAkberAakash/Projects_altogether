#include<stdio.h>
#include<string.h>

struct result
{
    char name[10000];
    int roll;
    struct subjects
    {
        char course[10000];
        int marks;
    }sub[5];
};

int main()
{
    int i,j,n;
    FILE *f1=NULL;
    char filename[100];
    struct result stdnt[100];

    printf("Enter the number of students: \n");
    scanf("%d", &n);
    getchar();

    for(i=0; i<n; i++)
    {
       printf("Enter file name:\n");
       gets(filename);
       strcat(filename,".txt");
       printf("%s\n",filename);
       //f1=fopen(filename,"w");

       printf("Enter student name:\n");
       //gets(stdnt[i].name);
       //fprintf(f1,"%d",stdnt[i].name);

      // fclose(f1);
    }
}
