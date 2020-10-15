#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
void pushA(int);
void pushB(int);
int popA();
int popB();
void enqueue();
void dequeue();
void display();
void create();
int stack1[300], stack2[300];
int top1 = -1, top2 = -1;
int c = 0;
void main()
{
int a;
clrscr();
printf("\n1.ENQUEUE");
printf("\n2.DEQUEUE");
printf("\n3.DISPLAY");
printf("\n4.EXIT");
printf("\n");
create();
while (1)
{
printf("\ngive choice : ");
scanf("%d", &a);
switch (a)
{
case 1:
enqueue();
break;
case 2:
dequeue();
break;
case 3:
display();
break;
case 4:
exit(0);
default:
printf("\nInvalid Choice\n");
}
}
}
void create()
{
top1=top2=-1;
}
void push1(int e)
{
stack1[++top1] = e;
}
int pop1()
{
return(stack1[top1--]);
}
void push2(int e)
{
stack2[++top2] = e;
}
int pop2()
{
return(stack2[top2--]);
}
void enqueue()
{
int d, i;
printf("Enter the data : ");
scanf("%d", &d);
push1(d);
c++;
}
void dequeue()
{
int i;
for (i = 0;i <= c;i++)
{
push2(pop1());
}
pop2();
c--;
for (i = 0;i <= c;i++)
{
push1(pop2());
}
}
void display()
{
int i;
if(top1 == -1)
{
printf("\nEMPTY QUEUE\n");
}
else
{
printf("\nQUEUE ELEMENTS : ");
for (i = 0;i <= top1;i++)
{
printf(" %d ", stack1[i]);
}
printf("\n");
}
}