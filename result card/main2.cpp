#include<stdio.h>
#include<string.h>

struct result
{
    char name[10000];
    int roll;
    char course[6][50]={
        "CSE-111",
        "CSE-112",
        "CSE-113",
        "CSE-114",
        "CSE-115",
        "CSE-116"
    };
    float marks[6], total=0;
}stdnt[100];

int main()
{
    int i,j,n;
    FILE *f1=NULL;
    char filename[100];

    printf("Enter the number of students: \n");
    scanf("%d", &n);
    getchar();

    for(i=0; i<n; i++)
    {
       printf("Enter file name:\n");
       gets(filename);
       strcat(filename,".txt");
       printf("%s\n",filename);
       f1=fopen(filename,"a");

       printf("Enter student name:\n");
       gets(stdnt[i].name);
       fprintf(f1,"Name:%s\n",stdnt[i].name);

       printf("Enter student roll:\n");
       scanf("%d", &stdnt[i].roll);
       getchar();
       fprintf(f1,"Roll: %d\n",stdnt[i].roll);

       printf("Enter students' marks:\n");

       for(j=0; j<6; j++)
       {
           printf("%s: ", stdnt[i].course[j]);
           scanf("%f", &stdnt[i].marks[j]);
           getchar();

           stdnt[i].total+=stdnt[i].marks[j];

           fprintf(f1,"%s: %4.2f\n",stdnt[i].course[j], stdnt[i].marks[j]);
       }

       printf("%2.2f\n", stdnt[i].total);
       fprintf(f1,"Total: %4.2f\n",stdnt[i].total);

       fclose(f1);
    }
}

