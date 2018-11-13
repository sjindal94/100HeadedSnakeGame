//10/4/2014 11:38 pm//combine the for direction functions//
#include<iostream>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
using namespace std;
char t,a[2001];
int i,size=1,j=0,s[500],key;
const int z=50;
void item()
{
    key=0;
    srand( time( NULL ) );
    while(a[key]!=' ')
    {
        key=(80*(1+rand()%23))+(rand()%78)+1;
    }
    a[key]=2;
}
    void map()
{
    for(i=0;i<2000;i++) a[i]=' ';a[2000]='\0';
    a[0]=201;
    t=205;
    for(i=1;i<79;i++){a[i]=t;a[i+1920]=t;}
    t=187;a[79]=t;
    t=186;
    for(i=1;i<24;i++){a[80*i]=t;a[80*i+79]=t;}
    t=200;
    a[1920]=t;
    a[1985]='S';
    a[1986]='C';
    a[1987]='O';
    a[1988]='R';
    a[1989]='E';
    a[1990]=':';
    a[1991]=48;
    a[1992]=48;
    a[1999]='\0';
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
     cout<<a;
     Sleep(z);
     system("cls");
     if(a[s[size]-1]==2) {size++;s[size]=s[size-1]-1;a[1992]++;if(a[1992]==58){a[1991]++;a[1992]-=10;}item();}
     else {a[s[0]]=' ';
     for(i=0;i<size;i++) s[i]=s[i+1];
     s[size]--;
     if((s[size])%80==0)s[size]+=78;
     if(a[s[size]]!=' '&&a[s[size]]!=2){t=0;return;}}
    }
    t=getch();
    if(t!='a'&&t!='d'&&t!='s'&&t!='w') left();
}
void right()
{
    while(!kbhit())
    {
     for(i=0;i<=size;i++) a[s[i]]=1;
     cout<<a;
     Sleep(z);
     system("cls");
     if(a[s[size]+1]==30) {ungetch(0);return;}
     if(a[s[size]+1]==186) cout<<222;
     if(a[s[size]+1]==2) {size++;s[size]=s[size-1]+1;a[1992]++;if(a[1992]==58){a[1991]++;a[1992]-=10;}item();}
     else {a[s[0]]=' ';
     for(i=0;i<size;i++) s[i]=s[i+1];
     s[size]++;
     if((s[size]+1)%80==0)s[size]-=78;
     if(a[s[size]]!=' '&&a[s[size]]!=2){t=0;return;}}
    }
    t=getch();
    if(t!='a'&&t!='d'&&t!='s'&&t!='w') right();
}
void down()
{
    while(!kbhit())
    {
     for(i=0;i<=size;i++) a[s[i]]=1;
     cout<<a;
     Sleep(z);
     system("cls");
     if(a[s[size]+1]==205) {ungetch(0);return;}
     if(a[s[size]+80]==2) {size++;s[size]=s[size-1]+80;a[1992]++;if(a[1992]==58){a[1991]++;a[1992]-=10;}item();}
     else{a[s[0]]=' ';
     for(i=0;i<size;i++) s[i]=s[i+1];
     s[size]+=80;
     if(s[size]>1920)s[size]-=1840;
     if(a[s[size]]!=' '&&a[s[size]]!=2){t=0;return;}}
    }
    t=getch();
    if(t!='a'&&t!='d'&&t!='s'&&t!='w') down();
}
void up()
{
    while(!kbhit())
    {
     for(i=0;i<=size;i++) a[s[i]]=1;
     cout<<a;
     Sleep(z);
     system("cls");
     if(a[s[size]-80]==2) {size++;s[size]=s[size-1]-80;a[1992]++;if(a[1992]==58){a[1991]++;a[1992]-=10;}item();}
     else{a[s[0]]=' ';
     for(i=0;i<size;i++) s[i]=s[i+1];
     s[size]-=80;
     if(s[size]<80)s[size]+=1840;
     if(a[s[size]]!=' '&&a[s[size]]!=2){t=0;return;}}
    }
    t=getch();
    if(t!='a'&&t!='d'&&t!='s'&&t!='w') up();
}
main()
{
    map();
    t='d';//initialize
    s[0]=81,s[1]=82;
    system("COLOR F2");//color
    cout<<"\t\t\t ***100 HEADED CATERPILLAR***\n\n Your have to collect the scattered heads of the caterpillar avoiding obstacles\n\n"
          <<"\t\t\t    The Classic Snake Game";
    Sleep(5000);
    system("cls");
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t  Lets start ";
    Sleep(500);
    cout<<char(1);
    Sleep(500);
    cout<<char(1);
    Sleep(500);
    cout<<char(1);
    Sleep(500);
    system("cls");
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
    cout<<"BOOOOOO!!!!!You lose!!!\nSCORE:"<<a[1991]<<a[1992];
}

