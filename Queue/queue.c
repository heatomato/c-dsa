#include <stdio.h>

#define SIZE 10

typedef struct {
	int items[SIZE];
	int front;
	int rear;

}QUEUE;

QUEUE queue;
QUEUE *qp = &queue;


// Create Queue
static void createQueue(QUEUE *qp) {
	qp->front = -1;
	qp->rear = -1;
}

// Check for full
static int isFull(QUEUE *qp) {
	if ((qp->front == qp->rear + 1) || (qp->front == 0 && qp->rear == SIZE - 1)) {
		printf("Queue is full\n");
		return 1;
	} else {
		return 0;
	}
}

// Check for emtpy
static int isEmpty(QUEUE *qp) {
	if (qp->front == -1 )
		return 1;
	else
		return 0;
}


// Enqueue
void enqueue(QUEUE *qp, int element) {
	if (isFull(qp)) {
		printf("Queue Already Full\n");
	} else {
		if (qp->front == -1)
			qp->front = 0;

		qp->rear = (qp->rear +1) % SIZE;
		qp->items[qp->rear] = element;
		printf("Element inserted: %i\n", element);
	}
}

// Dequeue
void dequeue(QUEUE *qp) {
	if (isEmpty(qp)) {
		printf("Queue Empty\n");
	} else {
		printf("Dequeued: %i\n", qp->items[qp->front]);
		// In case that this was the last element
		if (qp->front == qp->rear) {
			// Reset the queue
			qp->front = -1;
			qp->rear = -1;
		} else {
			qp->front = (qp->front + 1) % SIZE;
		}

	}
}


// Print queue
void printQueue(QUEUE *qp) {
	if (isEmpty(qp)) {
		printf("Queue empty\n");
	}  else {
		printf("Queue Front-Rear:%i-%i\n", qp->front, qp->rear);
		for (int i = qp->front; i != qp->rear; i = (i + 1) % SIZE) {
			printf("[%i]:%i\n", i, qp->items[i]);
		}
		// Print the last element on the queue (when front == rear)
		printf("[%i]:%i\n", qp->rear, qp->items[qp->rear]);
	}


}

void queueTask () {
	printf("Hello Queue\n");

	createQueue(qp);

	enqueue(qp, 14);
	enqueue(qp, 45);
	enqueue(qp, 34);
	enqueue(qp, 66);
	enqueue(qp, 33);

	printQueue(qp);

	dequeue(qp);
	dequeue(qp);
	printQueue(qp);
}
