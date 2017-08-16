#include<bits/stdc++.h>
#ifndef FILES_H_INCLUDED
#define FILES_H_INCLUDED

using namespace  std;

void view_individual_result(string input_string);




void view_individual_result(string input_string)
{
    FILE *single_result;

    char file_name[1000];
    char ch;

    strcpy(file_name,input_string.c_str());

    if((single_result=fopen(file_name,"r"))==NULL)
       {
           printf("The file does not exist!!!\n");
           exit(1);
       }
    while(fscanf(single_result,"%c",&ch)!=EOF)
        {
            printf("%c",ch);
        }
    fclose(single_result);
}

#endif // FILES_H_INCLUDED
