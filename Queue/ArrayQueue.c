#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1
#define MAX 5

struct QUEUE
{
    int array[MAX];
    int front;
    int rear;
};
typedef struct QUEUE Queue;

Queue *initQueue();
void enqueue(Queue *queue, int data);
int dequeue(Queue *queue);
void display(Queue *queue);

int main()
{
    Queue *queue = initQueue();

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    printf("Dequeued element: %d\n", dequeue(queue));
    printf("Dequeued element: %d\n", dequeue(queue));
    printf("Dequeued element: %d\n", dequeue(queue));

    display(queue);

    return 0;
}

Queue *initQueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;

    return queue;
}

void enqueue(Queue *queue, int data)
{
    if (queue->front == -1)
        queue->front++;

    queue->rear++;
    queue->array[queue->rear] = data;
}

int dequeue(Queue *queue)
{
    int item;

    item = queue->array[queue->front];
    queue->front++;
    return item;
}

void display(Queue *queue)
{
    int i;

    printf("\nFront at %d", queue->front);
    printf("\nRear at %d\n", queue->rear);

    for (i = 0; i < MAX; i++)
        printf("%d\t", queue->array[i]);
}