
#include <stdio.h>

int queue[100];
int front = -1;
int rear = -1;
int size = -1;
int isempty()
{
return size<0;
}
int isfull()
{
return size == 100;
}
void enqueue(int value)
{
if(size<100)
{
if(size<0)
{
queue[0] = value;
front = rear = 0;
size = 1;
}
else if(rear == 100-1)
{
queue[0] = value;
rear = 0;
size++;
}
else
{
queue[rear+1] = value;
rear++;
size++;
}
}
else
{
printf("Queue is full\n");
}
}
int dequeue()
{
if(size<0)
{
printf("Queue is empty\n");
}
else
{
size--;
front++;
}
return size==100;
}
int Front()
{
return queue[front];
}
void display()
{
int i;
if(rear>=front)
{
for(i=front;i<=rear;i++)
{
printf("%d\n",queue[i]);
}
}
else
{
for(i=front;i<100;i++)
{
printf("%d\n",queue[i]);
}
for(i=0;i<=rear;i++)
{
printf("%d\n",queue[i]);
}
}
}

int main()
{
clrscr();
enqueue(1);
enqueue(11);
enqueue(111);
display();
dequeue();
printf("After dequeue\n");
display();
enqueue(2);
enqueue(22);
enqueue(222);
dequeue();
enqueue(3);
enqueue(33);
enqueue(333);
display();
printf("After enqueue\n");
getch();
return 0;
}