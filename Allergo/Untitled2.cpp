int main()

{

char b,e;

printf("Input The Character\n");

scanf("%c", &b);

getch();

if(islower(b)>0)

{

printf("It's A Lowercase Alphabet\nNow do you want to Change this alphabet to uppercase?");

}

else

{

printf("It's an uppercase alphabet\nNow do you want to Change this alphabet to lowercase?");

}

printf("Then Give me your Answer, y/n\n");

scanf("%c",&e);

if(e=='y';||e=='Y')

{

if(islower(b)>0)

putchar(toupper(b));

else

putchar(tolower(b));

}

else

{

printf("GOODBYE THEN.");

}

getch();

return 0;

}
