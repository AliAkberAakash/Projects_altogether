#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

struct Item
    {
        char item_no[50];
        char name[50];
        char price[50];
    }i;
char add()
{
      struct Item i;
      printf("*****Add Item*****\n");
      printf("\nEnter Item's name::::");
      gets(i.name);
      printf("Enter Item's no.::::");
      gets(i.item_no);
      printf("Enter Price::::");
      gets(i.price);
      char name[10];
      sprintf(name, "%s.txt", &i.item_no);
      FILE *file2;
      file2 = fopen(name, "a");
      fprintf(file2, "%s  -   %s  -  %s\t\n",i.item_no,i.name,i.price);
      printf("Item has been Added");
}

int main()
{
    char c;
      system("cls");
      do{
      add();
      printf("\nYou want to add more?? (Y/N)\n");
      printf("Y=Continue   N=Main menu\n");
      scanf("%s",&c);
        }
      while(c == 'Y');
        if(c == 'N')
        {
           system("cls");
           printf("                   \n***END***");
        }
  }
