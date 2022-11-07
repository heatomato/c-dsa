/*
 * deque.c
 *
 *  Created on: Nov 6, 2022
 *      Author: israel
 */

#include <stdio.h>

#define SIZE 5

typedef struct {
	int items[SIZE];
	int front;
	int rear;
} DEQUE;

DEQUE deque;
DEQUE *dp = &deque;

void initDeque(DEQUE *dp) {
	dp->front = -1;
	dp->rear = -1;
}

static int isFull(DEQUE *dp) {
	if ((dp->rear - dp->front) == SIZE || (dp->rear == dp->front-1))
		return 1;
	else
		return 0;
}

static int isEmpty(DEQUE *dp) {
	if ((dp->front == -1) && (dp->rear == -1))
		return 1;
	else
		return 0;
}

static void addFront(DEQUE *dp, int element) {
	if (isFull(dp)) {
		printf("Deque Full\n");
	} else {
		if (dp->front < 1) {
			dp->front = SIZE - 1;
		} else {
			dp->front--;
		}

		dp->items[dp->front] = element;
		printf("Inserted Front [%i]:%i\n", dp->front, element);
	}
}

static void removeFront(DEQUE *dp) {
	if (isEmpty(dp)) {
		printf("Deque empty\n");
	} else {
		printf("Removed Front [%i]:%i\n", dp->front, dp->items[dp->front]);
		if (dp->front == dp->rear) {
			// Only one element set to empty
			initDeque(dp);
		} else if (dp->front == SIZE - 1) {
			// Front at the end make front 0 again
			dp->front = 0;
		} else {
			dp->front = dp->front + 1;
		}
	}
}


static void addRear(DEQUE *dp, int element) {
	if (isFull(dp)) {
		printf("Deque Full\n");
		dp->rear = 0;
	} else {
		dp->rear++;
		dp->items[dp->rear] = element;
		printf("Inserted Rear[%i]:%i\n", dp->rear, element);
	}
}

static void removeRear(DEQUE *dp) {
	if (isEmpty(dp)) {
		printf("Deque empty\n");
	} else {
		printf("Removed Rear [%i]:%i\n", dp->rear, dp->items[dp->rear]);
		if (dp->front == dp->rear) {
			// Only one element set to empty
			initDeque(dp);
		} else  {
			dp->rear = dp->rear - 1;
		}
	}
}

void printDeque(DEQUE *dp) {
	if (isEmpty(dp)) {
		printf("Deque empty\n");
	} else {
		for (int i = dp->front; i != dp->rear; i = (i + 1) % SIZE ) {
			if (dp->front > -1)
				printf("[%i]:%i\n", i, dp->items[i]);
		}
		printf("[%i]:%i\n", dp->rear, dp->items[dp->rear]);
	}
}

void dequeTask() {
	printf("Deque Task\n");

	initDeque(dp);
	addRear(dp, 10);
	addRear(dp, 11);
	removeRear(dp);
	printDeque(dp);
	addFront(dp, 12);
	addFront(dp, 13);
	addFront(dp, 14);
	printDeque(dp);
	addRear(dp, 16);
	addFront(dp, 17);
	removeFront(dp);
	printDeque(dp);

}
