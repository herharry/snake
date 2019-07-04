#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<process.h>
int intersect();
void check();
void check1();
void food();
void move();
int a[50][2],fpos[1][2];
int len=4,count=0,flag=0;
char ch='d';

void init()
{
   for(int i=0;i<50;++i)
   {
      a[i][0]=-1;
      a[i][1]=-1;
   }
}
int intersect()
{
  int i=1;
  if(ch=='w')
  {
    for(i=1;i<=len;++i)
     if(a[i][0]==a[0][0] && a[i][1]==a[0][1]-1)
      break;
  }
  else if(ch=='a')
       {
	 for(i=1;i<=len;++i)
	 if(a[i][0]==a[0][0]-1 && a[i][1]==a[0][1])
	   break;
	}

	else  if(ch=='s')
	      {
		for(i=1;i<=len;++i)
		if(a[i][0]==a[0][0] && a[i][1]==a[0][1]+1)
		 break;
	      }
	       else  if(ch=='d')
		     {
			for(i=1;i<=len;++i)
			     if(a[i][0]==a[0][0]+1  && a[i][1]==a[0][1])
				break;
		      }
 //					     gotoxy(0,0);
 // cout<<i<<' '<<len<<endl;
 // delay(200);
  if(i==len+1)
    return 1;
  else
    return 0;


}
void disp()
{
  if(ch=='w')
   if(intersect()==1)
       a[0][1]--;
   else
   {
     cout<<"lost";delay(2000);
     exit(0);
   }
  if(ch=='a')
   if(intersect()==1)
      a[0][0]--;
    else
   {
     cout<<"lost";delay(2000);
     exit(0);
   }
  if(ch=='s')
    if(intersect()==1)
      a[0][1]++;
     else
   {
     cout<<"lost";delay(100);
     exit(0);
   }
  if(ch=='d')
    if(intersect()==1)
      a[0][0]++;
   else
   {
     cout<<"lost";delay(2000);
     exit(0);
   }
  move();
  check();
 flag=0;
 clrscr();
 food();
 gotoxy(fpos[0][0],fpos[0][1]);
 cout<<"*";



 int i=0;


 do{
     gotoxy(a[i][0],a[i][1]);
     cout<<'O';
     i++;
   }while(a[i][0]!=-1);
}


void move()
{
   for(int i=len;i>0;--i)
   {
     a[i][0]=a[i-1][0];
     a[i][1]=a[i-1][1];
    // cout<<a[i][0]<<' '<<a[i][1]<<endl;

   }
}


void food()
{do
{
srand(time(0));
fpos[0][0]=random(60)+10;
fpos[0][1]=random(15)+10;

for(int i=0;i<=len;++i)
   {if(a[i][0]!=fpos[0][0] && a[i][1]!=fpos[0][1])
      count++;
   }
  }while(count<len);
}

void check()
{
  if(a[0][0]==fpos[0][0] && a[0][1]==fpos[0][1])
     ++len;

}

void main()
{
 init();
 clrscr();
 char temp=ch,dir;
 int n=0;
 a[0][0]=10;
 a[0][1]=20;

 for(int i=1;i<=len;++i)
 {
   a[i][0]=a[i-1][0]-1;
   a[i][1]=a[i-1][1];
    }
  while(temp!=13)
 {
  if(kbhit()==0)
  {
    disp();
    delay(100);
  }
  else
  {
    if(temp=='w' || temp=='s')
      dir='v';
    else
      dir='h';
    ch=getch();
    if(ch=='w' || ch=='s' || ch=='a' || ch=='d' || ch==13)
    {
    if(dir=='v' && (ch=='w'  || ch=='s'))
      ch=temp;
    else if(dir=='h' && (ch=='a' || ch=='d'))
	   ch=temp;
	 else
	    temp=ch;
    }
    else
      ch=temp;
  }


  n++;


 }
}