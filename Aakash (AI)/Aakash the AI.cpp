/*
Program Name: Aakash (The AI)
Details: Its an Artificial Intelligence That can Talk with you.
Solved By: Liverwort
Date: 18.6.2016
*/


#include <string.h>
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
                       "aakash", "Hmm, Bolo!",
                       "Aakash", "Hmm, Bolo!",
                       "AAKASH", "Hmm, Bolo!",
                       "Name", "Aakash",
                       "name", "Aakash",
                       "NAME", "Aakash",
                       "Khaiso", "Hmm, Tmi?",
                       "khaiso", "Hmm, Tmi?",
                       "KHAISO", "Hmm, Tmi?",
                       "Khaiso?", "Hmm, Tmi?",
                       "khaiso?", "Hmm, Tmi?",
                       "hmm", "Achcha",
                       "Hmm", "Achcha",
                       "HMM", "Achcha",
                       "koro?","Tomar kotha vabi babu",
                       "Koro?","Tomar kotha vabi babu",
                       "KORO?","Tomar kotha vabi babu",
                       "boshcho?","Hm boshchi to",
                       "porte", "Hm boshchi to",
                       "Porte", "Hm boshchi to",
                       "Poro", "Achcha Babu",
                       "poro", "Achcha Babu",
                       "kissi", "Ummmmmmmmmaaaaaahhh :*",
                       "Kissi", "Ummmmmmmmmaaaaaahhh :*",
                       "hug", "Hugging u tttttiiiiigggghhhhttttllllyyyy!!! ^_^",
                       "Hug", "Hugging u tttttiiiiigggghhhhttttllllyyyy!!! ^_^",
                       "love", "I love you more :*",
                       "Love", "I love you more :*",
                     };

   gets(str);

   token = strtok(str," ");

   while( token != NULL )
   {
      strcpy(str2[i], token);

      token = strtok(NULL, " ");

      i++;
   }

   j=i;

   for(i=0; i<j; i++)
   {
       for(k=0; k<31; k++)
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
    printf("Ki bolla, Bujhlam na!\n");

   main();

   return(0);
}
