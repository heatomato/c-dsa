#include <stdio.h>
#include <math.h>

void printArray(int array[], int size) {
	printf("[");
	for (int i = 0; i < size; i++) {
		printf(" %i", array[i]);
	}
	printf(" ]\n");
}

void bubbleSort(int array[], int size) {
	// Loop to access each array element
	for (int k = 0; k < size; k++) {
		printf("%i =  \n", k);

		int swapped = 0;

		// Loop to compare array elements
		for (int i = 0; i < size - k; i++) {
			printf("%i %i\n", i, array[i]);

			// Swapping
			if (array[i] > array[i + 1]) {

				int temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;

				swapped = 1;
			}
		}

		if (swapped == 0) {
			break;
		}
	}

}

void swapAux(int *from, int *to) {
	int temp = *from;
	*from = *to;
	*to = temp;
}

void selectionSort(int array[], int size) {
	// Repeat size times
	for (int k = 0; k < size; k++) {

		int minIndex = k;

		// Mark the minimum index on the array but start with one less
		for (int i = k; i < size; i++) {

			if (array[i] < array[minIndex])
				minIndex = i;
		}

		// Put min value in min index
		swapAux(&array[minIndex], &array[k]);

	}
}

void insertionSort(int array[], int size) {
	// Iterate over all the array except the first element
	for (int k = 1; k < size; k++) {

		// Compare elements with the left until found a smaller
		int key = array[k];
		int prevIndex = k - 1;

		while (key < array[prevIndex] && prevIndex >= 0) {
			array[prevIndex + 1] = array[prevIndex];
			--prevIndex;
		}

		// Change index
		array[prevIndex + 1] = key;
	}
}

void merge(int arr[], int p, int q, int r) {

	// Create two sides
	int n1 = q-p+1;
	int n2 = r-q;

	int L[n1], M[n2];

	// Filp the left side
	for (int i = 0; i < n1; i++) {
		L[i] = arr[p + i];
	}

	// Fill the right side
	for (int i = 0; i < n2; i++) {
		M[i] = arr[q + 1 + i];
	}

	// Mantain current index of subarrays and main array
	int i, j, k;
	i = 0;
	j = 0;
	k = p;

	// Pick larger amount elements L and M and place them in correct position
	while (i < n1 && j < n2) {
		if (L[i] <= M[j]) {
			arr[k] = L[i];
			i++;
		} else {
			arr[k] = M[j];
			j++;
		}
		k++;
	}

	// Pick un the remaining elements
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = M[j];
		j++;
		k++;
	}

}

void mergeSort(int array[], int l, int r) {
	if (l < r) {
		// Divide array in two
		int m = 1 + (r + 1)/2;

		mergeSort(array, l, m);
		mergeSort(array, m+1, r);

		// Merge sorted sub arrays
		merge(array, l, m, r);
	}
}

int partition(int array[], int low, int high) {
	// Select the rightmost element as pivot
	int pivot = array[high];

	// Pointer for greater element
	int i = (low - 1);

	// Traverse each element of the array
	for (int j = low; j < high; j++) {
		if (array[j] <= pivot) {
			i++;

			swapAux(&array[i], &array[j]);
		}
	}

	// Swap the pivot element with the greater element at i
	swapAux(&array[i + 1], &array[high]);

	return (i + 1);
}

void quickSort(int array[], int low, int high) {
	if (low < high) {
		// Find pivot element such that smaller on the left,
		int pivot = partition(array, low, high);

		// Recursive call on the left
		quickSort(array, low, pivot - 1);

		// Recursive call on the right
		quickSort(array, pivot + 1, high);
	}
}

int partition2(int *array, int left, int right) {
    // Select the pivot as the mean
    int pivot = floor((right + left )/2);
    printf("pivot:%i\n", pivot);

    int l = left-1;
    int r = right+1;

    while(l < r) {
        do {
            l++;
        }while (array[l] < pivot);

        do {
            r--;
        }while (array[r] > pivot);

        // Swap the elements at hte left and right indices
        int temp = array[r];
        array[r] = array[l];
        array[l] = temp;
    }

    return r;

}

void quickSort2(int *array, int left, int right) {
    if (left < right) {

     int pivot = partition2(array, left, right);

     // Repeat the quicksort to both sides of pivot
     quickSort2(array, left, pivot);
     quickSort2(array, pivot + 1, right);
    }
}


void countingSort(int array[], int size) {
	int output[10];

	// find largest element of array
	int max = array[0];
	for (int i = 0; i < size; i++) {
		if (array[i] > max)
			max = array[i];
	}

	// Initialize count array
	int count[10];
	for (int i = 0; i < size; i++) {
		count[array[i]]++;
	}

	// Store cumulative count of each array
	for (int i = 0; i <= max; i++) {
		count[i] += count[i - 1];
	}

	// Find the index of each element of the original array in count array,
	for (int i = size-1; i >= 0; i--) {
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	// Copy stored elements into original array
	for (int i = 0; i < size; i++) {
		array[i] = output[i];
	}
}

int getMax(int array[], int size) {
	int max = array[0];
	for (int i = 1; i < size; i++) {
		if (array[i] > max)
			max = array[i];
	}
	return max;
}

void radixSort(int array[], int size) {
	// Get maximum element
	int max = getMax(array, size);

	// Apply counting sort to sort elements based on place value
	for (int place = 1; max / place > 0; place *= 10) {
		countingSort(array, size);
		// THis is incomplete

	}
}

void bucketSort(int array[], int size) {
}

void heapify(int arr[], int n, int i) {
	// Find the largest among root, left child and right child
	int largest = i;
	int left = 2*i + 1;
	int right = 2*i + 2;

	printf("heapify: %i, %i, %i\n", largest, left, right );

	if (left < n && arr[left] > arr[largest])
		largest = left;

	if (right < n && arr[right] > arr[largest])
		largest = right;

	printf("heapify: %i, %i, %i\n", largest, left, right);
	// Swap and contiue heapifying if root is not largest
	if (largest != i) {
		swapAux(&arr[i], &arr[largest]);
		heapify(arr, n, largest);
	}
}

void heapSort(int array[], int size) {
	// Build max heap
	// For every root element heapify
	for (int i = size/2 - 1; i >= 0; i--)
		heapify(array, size, i);

	// Heap Sort
	for (int i = size - 1; i >= 0; i--) {
		swapAux(&array[0], &array[i]);
		heapify(array, i, 0);
	}
}

void sortTask() {

	int input[] = {-2, 45, 0, 11, -9};

	//bubbleSort(input, 5);

	//selectionSort(input, 5);

	//insertionSort(input, 5);

	//mergeSort(input,  0, 4);

	quickSort2(input, 0, 5);
	printArray(input, 5);

	//printArray(input, 5);

	///int array[] = {4, 2, 2, 8, 3, 3, 1};

	//countingSort(array, 7);

	//printArray(array, 7);

	//int array[] = {1, 12, 9, 5, 6, 10};
	//printArray(array, 6);


	//heapSort(array, 6);
	//printArray(array, 6);



}


