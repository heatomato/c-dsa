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
#include "./LinkedList/linked.h"
#include "./HashMap/hash.h"
#include "./Heap/heap.h"

enum DATA_STRUCTURES {
	STACK,
	QUEUE,
	DEQUE,
	LINKED_LIST,
	HASH_MAP,
	HEAP,
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
		case LINKED_LIST:
			linkedTask();
			break;
		case HASH_MAP:
			hashTask();
			break;
		case HEAP:
			heapTask();
			break;
		default:
			printf("None selected, bye..\n");
			break;
	}


	return 0;
}
