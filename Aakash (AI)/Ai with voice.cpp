/*
Program Name: Aakash (The AI)
Details: Its an Artificial Intelligence That can Talk with you.
Solved By: Liverwort
Date: 18.6.2016
*/


#include <string.h>
#include<cstdlib>
#include <stdio.h>

int main()
{
   int i=0,j,k,f=-1;
   char str[1000];
   char str2[10][100];
   char *token;

   char vc[][2][1000]={
                       "HI", "Hi!",
                       "Hi", "Hi!",
                       "hi", "Hi!",
                       "aakash", "Hmm!",
                       "Aakash", "Hmm!",
                       "AAKASH", "Hmm!",
                       "Name", "Aakash",
                       "name", "Aakash",
                       "NAME", "Aakash",
                       "roza", "Hmm! Tui?",
                       "Roza", "Hmm! Tui?",
                       "kemon", "Vlo!",
                       "kmn", "Vlo!",
                       "Kmn", "Vlo!",
                       "Ammur","Khaleda Amin",
                       "ammu", "Khaleda Amin",
                       "Ammu","Khaleda Amin",
                       "ammur", "Khaleda Amin",
                       "Abbur", "Al-Amin",
                       "abbur", "Al-Amin",
                       "Abbu", "Al-Amin",
                       "abbu", "Al-Amin",
                       "Atika", "Pocha",
                       "atika", "Pocha",
                       "pocha", "Hm Atika Pocha",
                       "Pocha", "Hm Atika Pocha",
                       "Kaium", "Poralekha kore na!",
                       "kaium", "Poralekha kore na!",
                       "Nusrat", "Or shoshur bari",
                       "nusrat", "Or Shoshur bari",
                       "Bappy", "Abroad",
                       "bappy", "Abroad",


                     };

   gets(str);

   token = strtok(str, " ");

   while( token != NULL )
   {
      strcpy(str2[i], token);

      token = strtok(NULL, " ");

      i++;
   }

   j=i;

   for(i=0; i<j; i++)
   {
       for(k=0; k<32; k++)
        {
            if(!strcmp(str2[i], vc[k][0]))
            {
                printf("%s\n", vc[k][1]);
                f=1;
                break;
            }
        }

        if(f==1)
            break;
   }

   if(f==-1)
    printf("Ki koili, Bujhlam na!\n");

   main();

   return(0);
}





