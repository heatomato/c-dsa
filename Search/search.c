/*
 * search.c
 *
 *  Created on: Dec 18, 2022
 *      Author: featomato
 */

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
	return *((int *)a) - *((int *)b);
}

int binarySearch(int *array, int value, int left, int right) {
	int index = -1;
	if (right >= left) {
		int mid = left + (right-left)/2;

		// If found at mid, then return it
		if (array[mid] == value) {
			index = mid;
			return index;
		} else if (value < array[mid]) {
			// Search in the left side
			return binarySearch(array, value, left, mid-1);
		} else {
			// Search in the right side
			return binarySearch(array, value, mid+1, right);
		}
	}

	return index;
}


int binarySearchIterative(int *array, int value, int left, int right) {
	// Repeat until the pointers meet each other
	while (left < right) {

		int mid = left + ((right - left)/2);
		printf("%i %i %i\n", left, mid, right);

		if (array[mid] == value) {
			// We just find the desired number, return the index
			return mid;
		} else if (array[mid] < value) {
			// Searched value exist only on the right of the array
			right = mid + 1;
		} else {
			// Searched value exist only on the left of the array
			left = mid - 1;
		}

	}
	// nothing found return invalid index
	return -1;
}

void searchTask() {

	  int array[] = {3, 4, 5, 6, 7, 8, 9};
	  int n = sizeof(array) / sizeof(array[0]);
	  int x = 9;
	  printf("Starting binary search\n");

	  //int result = binarySearch(array, x, 0, n - 1);
	  // QSEARCH RETURNS THE ELEMENT NOT THE INDEX
	  int  *result = (int *) bsearch(&x, array, n, sizeof(int), &compare);
	  //int result = (void *) ((index - (void *)array)/n);

	  if (*result == -1) {
		  printf("Value not found\n");
	  } else {
		  //printf("Value located %i index\n", array[result]);
	  }

}
