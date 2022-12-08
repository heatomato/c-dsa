/*
 * queue.h
 *
 *  Created on: Nov 6, 2022
 *      Author: israel
 */

#ifndef QUEUE_QUEUE_H_
#define QUEUE_QUEUE_H_

#define SIZE 10

typedef struct {
	int items[SIZE];
	int front;
	int rear;
}QUEUE;


void queueTask(void);

void createQueue(QUEUE *qp);
void enqueue(QUEUE *qp, int element);
int dequeue(QUEUE *qp);
int isFull(QUEUE *qp);
int isEmpty(QUEUE *qp);
void printQueue(QUEUE *qp);

#endif /* QUEUE_QUEUE_H_ */
