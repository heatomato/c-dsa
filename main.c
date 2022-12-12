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
#include "./Tree/tree.h"
#include "./Graph/graph.h"
#include "./Strings/ustring.h"

enum DATA_STRUCTURES {
	STACK,
	QUEUE_TASK,
	DEQUE,
	LINKED_LIST,
	HASH_MAP,
	HEAP,
	STRING,
	TREE,
	GRAPH,
	SORTING
};



int main () {

	int input;
	printf("Select Algorithm or Data Structure\n");
	scanf("%d", &input);

	switch(input) {
		case STACK:
			stackTask();
			break;
		case QUEUE_TASK:
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
		case STRING:
			stringTask();
			break;
		case TREE:
			treeTask();
			break;
		case GRAPH:
			graphTask();
			break;
		case SORTING:
			sortTask();
			break;

		default:
			printf("None selected, bye..\n");
			break;
	}


	return 0;
}
