/*
 * linked.c
 *
 *  Created on: Nov 7, 2022
 *      Author: israel
 */


#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct NODE {
	int value;
	struct NODE *next;
}NODE;

NODE *list = NULL;

void insertAtFront(int element) {
	// Allocate memory or a node n is temporary just to initialize
	NODE *n = malloc(sizeof(NODE));

	if (n != NULL) {

		if (list == NULL) {
			// First node to get added
			// Insert data
			n->value = element;
			n->next = NULL;

			// Reorganize previous nodes
			list = n;

		} else {
			// Another node added
			n->value = element;
			n->next = list;
			list = n;
		}

	} else {
		free(list->next);
		free(list);
	}
}

void insertAtRear( int element) {

	// Allocate mem for new node


	// Insert data



	// Reorganize previous nodes

}

void deleteNode(int element) {

	for (NODE  *tmpNode = list; tmpNode != NULL; tmpNode = tmpNode->next) {

		if (tmpNode->next->value == element) {

			NODE *start = list;

			// Jump next node
			list = tmpNode;
			list->next = list->next->next;

			//Return list pointer to start;
			list = start;

			// Exit

			printf("Node Deleted:%i\n",  element);
			break;

		}
	}
}

void printList() {

	// Traverse the linked list

	for (NODE *tmp = list; tmp != NULL; tmp = tmp->next) {
		printf("-->%i", tmp->value);
	}

	puts("\n");
}

void freeList() {
	while (list != NULL) {
		NODE *tmp = list->next;
		// Free first node
		free(list);
		list = tmp;
	}
}

void linkedTask() {

	//insertAtFront(1);
	//insertAtFront(2);
	//insertAtFront(3);

	// Bulk insertion
	for(int i = 0; i < 100; i++) {
		insertAtFront(i);
	}

	printList();
	deleteNode(90);
	printList();
	freeList();

}
