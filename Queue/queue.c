#include <stdio.h>
#define MAX_SIZE 200
typedef struct
{
	int items[MAX_SIZE];
	int front;
	int rear;
}queue;

void createQueue(queue* q) 
{
	q->front = -1;
	q->rear = -1;
};
int isFull(queue* q) 
{
	return q->rear == MAX_SIZE - 1;
};
int isEmpty(queue* q) 
{
	return q->front == q->rear;
};
void enqueue(queue* q, int data)
{
	if (isFull(q)) return;

	q->items[++q->rear] = data;
};
int dequeue(queue* q)
{
	if (isEmpty(q)) return;

	return q->items[++q->front];
};





void main()
{
	queue q;
	createQueue(&q);
	enqueue(&q, 30);
	enqueue(&q, 40);
	int a = dequeue(&q);
	int b = dequeue(&q);
	printf("%d %d\n", a, b);
	printf("%d %d\n", isEmpty(&q),isFull(&q));



};