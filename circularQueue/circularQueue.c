#include <stdio.h>
#define MAX_SIZE 200

typedef struct
{
	int items[MAX_SIZE];
	int front;
	int rear;
}circularQueue;

void createCirularQueue(circularQueue* q)
{
	q->front = 0;
	q->rear = 0;
};
int isFull(circularQueue* q) 
{
	return q->front == (q->rear+1)%MAX_SIZE;
};
int isEmpty(circularQueue* q) 
{
	return q->front == q->rear;
};
void enqueue(circularQueue* q, int data) 
{
	if (isFull(q)) return;

	q->items[(q->rear+1)%MAX_SIZE] = data;
	q->rear = (q->rear +1) % MAX_SIZE;

};
int dequeue(circularQueue* q) 
{
	if (isEmpty(q)) return;
	int temp = q->items[(q->front + 1) % MAX_SIZE];
	q->front = (q->front+1) % MAX_SIZE;
	return temp;
};



void main()
{
	circularQueue q;
	createCirularQueue(&q);

	printf("%d\n", isEmpty(&q));
	enqueue(&q, 10);
	printf("%d\n", isEmpty(&q));
	enqueue(&q, 20);
	printf("%d\n", isFull(&q));
	enqueue(&q, 30);
	printf("%d\n", isFull(&q));
	printf("%d\n",dequeue(&q));
	printf("%d\n", dequeue(&q));
	printf("%d\n", dequeue(&q));
	printf("%d\n", isEmpty(&q));
	// enqueue(&q, 10);
	// enqueue(&q, 20);
	// enqueue(&q, 30);
	// printf("%d\n", dequeue(&q));
	// enqueue(&q, 10);
}