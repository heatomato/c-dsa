/*
 * heap.c
 *
 *  Created on: Nov 12, 2022
 *      Author: israel
 */


#include <stdio.h>

#define HEAP_SIZE 10

int heapArray[HEAP_SIZE];
int size = 0;

static void swap(int *nodeA, int *nodeB) {
	int temp = *nodeB;
	*nodeB = *nodeA;
	*nodeA = temp;
}

static void heapify(int *array, int size, int place) {
	if (size == 1) {
		printf("Single element in the heap\n");
	} else {
		int largest = place;
		int childLeft = 2*place + 1;
		int childRigth = 2*place + 2;
		// Valid place's node and ChildLeft > Parent
		if (childLeft < size && array[childLeft] > array[largest] ) {
			largest = childLeft;
		}

		// Valid place's node and Child Right > Parent
		if (childRigth < size && array[childRigth] > array[largest]) {
			largest = childRigth;
		}


		// Swap noded and test heap again
		if (largest != place) {
			swap(&array[place], &array[largest]);
			heapify(array, size, largest);
		}
	}
}

static void insert(int *array, int value) {
	if (size == 0) {
		// First Node Inserted
		array[0] = value;
		size += 1;
	} else {
		array[size] = value;
		size += 1;

		// Traverse from end to front every not root node
		for (int i = size/2 - 1; i >= 0; i-- ) {
			// Reorder in a heapify fashion
			heapify(array, size, i);
		}
	}
}

static void printNode(int *array, int node) {

	int left = 2 * node + 1;
	int rigth = 2 * node + 2;
	printf("  %i  \n", array[node]);
	printf(" / \\ \n");
	printf("%i   %i\n", array[left], array[rigth]);


}

static void printHeap(int *array, int size) {
	for (int i= 0; i < size; i++) {
		printf("%d ", array[i]);

	}
	printf("\n");
	printf("***************\n");
}



void heapTask() {

	printf("Init Heap Task\n");

	insert(heapArray, 3);
	insert(heapArray, 9);
	insert(heapArray, 2);
	insert(heapArray, 1);
	insert(heapArray, 4);
	insert(heapArray, 5);



	printHeap(heapArray, 6);

	printNode(heapArray, 0);

	printHeap(heapArray, 6);


}
