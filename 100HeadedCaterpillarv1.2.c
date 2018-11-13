//22/4/2014 1:45am
#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
char t,a[2001];
int i,size,s[500],key,flag=0;
const int z=50;
void item()
{
    while(a[key]!=32) key=rand()%1919;
    a[key]=2;
}
    void map()
{
    for(i=81;i<1919;i++) a[i]=32;
    for(i=0;i<30;i++) a[89+(rand()%1830)]=176;
    a[2000]='\0';
    a[0]=201;
    for(i=1;i<79;i++){a[i]=205;a[i+1920]=205;}
    a[79]=187;
    for(i=1;i<24;i++){a[80*i]=186;a[80*i+79]=186;}
    a[1920]=200;
    a[1999]=7;
    a[1957]='S';
    a[1958]='C';
    a[1959]='O';
    a[1960]='R';
    a[1961]='E';
    a[1962]=':';
    a[1963]=48;
    a[1964]=48;
    a[1999]='\0';
    srand(time(NULL));
    item();
}
void reverse()
{
    for(i=0;i<=size;i++) s[499-size+i]=s[i];
    for(i=0;i<=size;i++) s[i]=s[499-i];
}
void left()
{
    while(!kbhit())
    {
     for(i=0;i<=size;i++) a[s[i]]=1;
     printf("%s",a);
     Sleep(z);
     system("cls");
     if(a[s[size]-1]==2) {size++;s[size]=s[size-1]-1;a[1964]++;if(a[1964]==58){a[1963]++;a[1964]-=10;}if(a[1963]==58){t=0;flag=1;return;}item();}
     else {a[s[0]]=32;
     for(i=0;i<size;i++) s[i]=s[i+1];
     s[size]--;
     if((s[size])%80==0)s[size]+=78;
     if(a[s[size]]!=32&&a[s[size]]!=2){t=0;return;}}
    }
    t=getch();
    if(t!='a'&&t!='d'&&t!='s'&&t!='w') left();
}
void right()
{
    while(!kbhit())
    {
     for(i=0;i<=size;i++) a[s[i]]=1;
     printf("%s",a);
     Sleep(z);
     system("cls");
     if(a[s[size]+1]==2) {size++;s[size]=s[size-1]+1;a[1964]++;if(a[1964]==58){a[1963]++;a[1964]-=10;}if(a[1963]==58){t=0;flag=1;return;}item();}
     else {a[s[0]]=32;
     for(i=0;i<size;i++) s[i]=s[i+1];
     s[size]++;
     if((s[size]+1)%80==0)s[size]-=78;
     if(a[s[size]]!=32&&a[s[size]]!=2){t=0;return;}}
    }
    t=getch();
    if(t!='a'&&t!='d'&&t!='s'&&t!='w') right();
}
void down()
{
    while(!kbhit())
    {
     for(i=0;i<=size;i++) a[s[i]]=1;
     printf("%s",a);
     Sleep(z);
     system("cls");
     if(a[s[size]+1]==205) {ungetch(0);return;}
     if(a[s[size]+80]==2) {size++;s[size]=s[size-1]+80;a[1964]++;if(a[1964]==58){a[1963]++;a[1964]-=10;}if(a[1963]==58){t=0;flag=1;return;}item();}
     else{a[s[0]]=32;
     for(i=0;i<size;i++) s[i]=s[i+1];
     s[size]+=80;
     if(s[size]>1920)s[size]-=1840;
     if(a[s[size]]!=32&&a[s[size]]!=2){t=0;return;}}
    }
    t=getch();
    if(t!='a'&&t!='d'&&t!='s'&&t!='w') down();
}
void up()
{
    while(!kbhit())
    {
     for(i=0;i<=size;i++) a[s[i]]=1;
     printf("%s",a);
     Sleep(z);
     system("cls");
     if(a[s[size]-80]==2) {size++;s[size]=s[size-1]-80;a[1964]++;if(a[1964]==58){a[1963]++;a[1964]-=10;}if(a[1963]==58){t=0;flag=1;return;}item();}
     else{a[s[0]]=32;
     for(i=0;i<size;i++) s[i]=s[i+1];
     s[size]-=80;
     if(s[size]<80)s[size]+=1840;
     if(a[s[size]]!=32&&a[s[size]]!=2){t=0;return;}}
    }
    t=getch();
    if(t!='a'&&t!='d'&&t!='s'&&t!='w') up();
}
main()
{
    system("COLOR F2");//color
    printf("\t\t\t ***100 HEADED CATERPILLAR***\n\n\t  Your have to collect the scattered heads %c of the caterpillar\n\n"
                 "\t\t\t     The Classic Snake Game\n\n\n\t\t\t\t   Controls: \n\n\t\t\t   w:up\t\t\ts:down\n\n\t\t\t   a:left\t\td:right"
                 "\n\n\n\t\t      Avoid collision with the obstacle %c",2,176);
        Sleep(6000);
        printf("\n\n\n\n\n\n\n\t\t\t\t  Lets start ");
        Sleep(500);
        printf("%c",1);
        Sleep(500);
        printf("%c",1);
        Sleep(500);
        printf("%c",1);
        Sleep(500);
        system("cls");
    do
    {
        system("cls");
        map();
        t='d';//initialize
        s[0]=81,s[1]=82;
        size=1;key=0;
        do
        {
            switch (t)
            {
                case 'a':
                    left();
                    if(t=='d') {if(s[0]!=s[1]-1) reverse();
                    else t='a';}
                    break;
                case 'd':
                    right();
                    if(t=='a') {if(s[0]!=s[1]+1) reverse();
                    else t='d';}
                    break;
                case 'w':
                    up();
                    if(t=='s') {if(s[0]!=s[1]-80) reverse();
                    else t='w';}
                    break;
                case 's':
                    down();
                    if(t=='w') {if(s[0]!=s[1]+80) reverse();
                    else t='s';}
                    break;
            }
        }while(t);
        if(flag==1)
            {flag=0;printf("Congratulations!!!You won!!You deserve a hug!!!\nSCORE:100");}
        else printf("BOOOOOO!!!!!You lose!!!\nSCORE:%c%c",a[1963],a[1964]);
        printf("\nPlay Again???(y/n):");
        fflush(stdin);
        t=getch();
        }while(t=='y');
    }
