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
      printf("*****Add Item*****");
      gets(i.name);
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
      FILE *file1;
      printf("Item has been Added");
}
char view()
{
   printf("Item no.\tItem name\tItem price\n");
   char name[10];
   int q=0;
   do
   {
   sprintf(name, "%d.txt", q);
   FILE *file1;
   file1 = fopen(name, "r");
   char c;
   while((c=getc(file1))!=EOF)
   putchar(c);
   q++;
   }
   while(q<=10000);
}
char search()
{
   char q[10], name[10];
        system("cls");
        printf("          Enter Item no::::");
        scanf("%s", &q);
        sprintf(name, "%s.txt", &q);
        FILE *file1;
        file1 = fopen(name, "r");
        char c;
        while((c=getc(file1))!=EOF)
        putchar(c);
        fclose(file1);
}
char del()
{
 system("cls");
        char q[10], name[10], *dlt;
        system("cls");
        printf("            Enter Item no to Delete::::");
        scanf("%s", &q);
        sprintf(name, "%s.txt", &q);
        dlt=fopen(name, "w");
        remove(dlt);
        printf("            Item deleted!!!!");
}
char edit()
{
  struct Item i;
  printf("            *****Edit Item*****\n\n\n");
gets(i.item_no);
printf("            Enter Item no::::");
gets(i.item_no);
printf("            Enter Item name:");
gets(i.name);
printf("            Enter Price:");
gets(i.price);
char name[10];
sprintf(name, "%s.txt", &i.item_no);
FILE *file1;
file1 = fopen(name, "w");
fprintf(file1, "%s  -   %s  -  %s\t\n",i.item_no,i.name,i.price);
}
char logout()
{
    printf("Loggin out......................");
}
int Mainmenu()
{
  printf("***************Main Menu***************\n\n");
  printf("***************************************\n");
  printf("**          1.Add Items              **\n");
  printf("**          2.View Item's list       **\n");
  printf("**          3.Search Items           **\n");
  printf("**          4.Delete Items           **\n");
  printf("**          5.Edit Items             **\n");
  printf("**          6.log out                **");
  printf("\n***************************************");
  printf("\n\n\n\n          Choice Your Option::::");
  int q;
  char c;
  scanf("%d",&q);
  if(q==1)
  {
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
            Mainmenu();
        }
  }
  else if(q==2)
  {
      system("cls");
      printf("*****View*****\n");
      view();
      getch();
  }
  else if(q==3)
  {
      system("cls");
      printf("*****Search*****\n");
      char i;
      do{
      search();
      printf("\nYou want to search more?? (Y/N)\n");
      printf("Y=Continue   N=Main menu\n");
      scanf("%s",&i);
        }
      while(i == 'Y');
        if(i == 'N')
        {
            system("cls");
            Mainmenu();
        }
  }
  else if(q==4)
  {
      system("cls");
      printf("*****Delete*****\n");
      char f;
      do{
      del();
      printf("\nYou want to delete more Item?? (Y/N)\n");
      printf("Y=Continue   N=Main menu\n");
      scanf("%s",&f);
        }
      while(f == 'Y');
        if(f == 'N')
        {
            system("cls");
            Mainmenu();
        }
  }
  else if(q==5)
  {
      system("cls");
      printf("*****Edit*****\n");
      char g;
      do{
      edit();
      printf("\nYou want to edit more Item?? (Y/N)\n");
      printf("Y=Continue   N=Main menu\n");
      scanf("%s",&g);
        }
      while(g == 'Y');
        if(g == 'N')
        {
            system("cls");
            Mainmenu();
        }
  }
  else if(q==6)
  {
      system("cls");
      logout();
      getch();
  }
  else
  {
      printf("          Invalid Choice");
  }
  return q;
}
int main()
{
  printf("                    Shop Management\n");
  printf("                    By  Team BAhEFuz\n\n");
   int i;
   int x;
   printf("\n\n\n\n");
   printf("*******************************************\n\n");
   printf("      Enter Your Password::::");
   /*for(i=0;i<5;i++)
   {
   getch();
   printf("*");
   */
   scanf("%d",&x);
   printf("\n\n");
   printf("*******************************************");
   if( x==123)
    {
        {
        fflush(stdin);
        printf("\nLogging in.........");
        }
        system("cls");
        Mainmenu();
    }
   else
    {
      printf("\n          Invalid Password \n");
      printf("              Try Again");
    }
}
