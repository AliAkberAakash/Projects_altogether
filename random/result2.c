#include<stdio.h>
#include<conio.h>
#include<string.h>

struct std
{
    char name[10];
    char xm_nm[10];
    int roll;
    char sec[2];

    struct result
    {
        float marks;
        float final_grade;
        char grade;
    };

};

int main()
{

    struct std stdnt[100];
    struct result res[15];
    float total=0;
    char (*s[7])[50]={"Bangla","English","Math","Physics","Chemistry","Biology","ICT"};
    int i, n;
    char repeat;
    printf("Enter the number of students:\n\n");
    scanf("%d",&n);

    for(i=0; i<n;i++)
    {
        printf("Enter student name:\n");
        scanf("%s", &stdnt[i].name);
        printf("Enter level\n");
        scanf("%s", &stdnt[i].xm_nm);
        printf("Enter the Roll:\n");
        scanf("%d", &stdnt[i].roll);
        printf("Enter the section:\n");
        scanf("%s", &stdnt[i].sec);

        printf("Enter the result:\n\n");

        for(i=0; i<7; i++)
        {
            printf("%s:",*s[i]);
            scanf("%f", &res[i].marks);
            total+=res[i].marks;
        }
    }

    printf("==============================RESULT==================================\n\n");

    for(i=0; i<n; i++)
    {
        printf("Name:%s\t\t\tRoll:%d\nLevel:%s\t\t\tSec:%s\n\n\n", stdnt[i].name,stdnt[i].roll, stdnt[i].xm_nm, stdnt[i].sec);
        printf("======================================================================\n\n");
        printf("Subject\t\t\tMarks\t\tGrade point\t\tGrade\n");
        printf("======================================================================\n\n");
        for(i=0;i<7; i++)
        {
            for(i=0; i<7;i++)
            {
            printf("%9s:\t\t%.2f",*s[i], res[i].marks);
            if(res[i].marks>=80) printf("\t\t5.00\t\t\tA+\n");
            else if(res[i].marks>=70) printf("\t\t4.00\t\t\tA\n");
            else if(res[i].marks>=60) printf("\t\t3.50\t\t\tA-\n");
            else if(res[i].marks>=50) printf("\t\t3.00\t\t\tB\n");
            else if(res[i].marks>=40) printf("\t\t2.00\t\t\tC\n");
            else if(res[i].marks>=33) printf("\t\t1.00\t\t\tD\n");
            else printf("\t\t0.00\t\t\tF\n");
            }
            printf("======================================================================\n\n");
            printf("\t   Total marks=%.2f\n", total);
            printf("======================================================================\n\n");
        }
    }
    printf("Exit? (y/n)");
    scanf("%c", &repeat);
    if(repeat=='y')
        main();
    else
        return 0;
}
