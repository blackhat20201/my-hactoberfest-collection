#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#define FULL 10
struct node
{
int data;
struct node *next;
};
typedef struct node n;
struct queue
{
int count;
n *front;
n *rear;
};
typedef struct queue queue;
void initialize(queue *q)
{
q->count = 0;
q->front = NULL;
q->rear = NULL;
}
int empty(queue *q)
{
return (q->rear == NULL);
}
void enqueue(queue *q, int value)
{
if (q->count < FULL)
{
n *tmp;
tmp = malloc(sizeof(n));
tmp->data = value;
tmp->next = NULL;
if(!empty(q))
{
q->rear->next = tmp;
q->rear = tmp;
}
else
{
q->front = q->rear = tmp;
}
q->count++;
}
else
{
printf("List is full\n");
}
}

int dequeue(queue *q)
{
n *tmp;
int n = q->front->data;
tmp = q->front;
q->front = q->front->next;
q->count--;
free(tmp);
return(n);
}
void display(n*head)
{
if(head == NULL)
{
printf("THIS NODE IS NULL\n");
}
else
{
printf("%d\n", head -> data);
display(head->next);
}
}
int main()
{
queue *q;
clrscr();
q = malloc(sizeof(queue));
initialize(q);
enqueue(q,2);
enqueue(q,22);
enqueue(q,222);

printf("queue before dequeue\n");
display(q->front);
dequeue(q);
printf("queue after dequeue\n\n");
display(q->front);
getch();
return 0;
}