/*
 * main.c
 *
 *  Created on: Nov 6, 2022
 *      Author: israel
 */

#include <stdio.h>
#include "./Queue/queue.h"
#include "./Stack/stack.h"
#include "./Deque/deque.h"

enum DATA_STRUCTURES {
	STACK,
	QUEUE,
	DEQUE,
};

int main () {

	int input;
	printf("Select Algorithm or Data Structure\n");
	scanf("%d", &input);

	switch(input) {
		case STACK:
			stackTask();
			break;
		case QUEUE:
			queueTask();
			break;
		case DEQUE:
			dequeTask();
			break;
		default:
			printf("None selected, bye..\n");
			break;
	}


	return 0;
}
