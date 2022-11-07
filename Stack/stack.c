#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 20

typedef struct {
	int items[STACK_SIZE];
	int top;
}STACK;

STACK stack;
STACK *sp = &stack;

// Creation
void createEmptyStack(STACK *sp) {
	sp->top = -1;
}

// Check full
static int isFull(STACK *sp) {
	if (sp->top == STACK_SIZE -1)
		return 1;
	else
		return 0;
}

// Check Empty
static int isEmpty(STACK *sp) {
	if (sp->top == -1)
		return 1;
	else
		return 0;
}

// Pushing elements into the stack
void push(STACK *sp, int newItem) {
	if (isFull(sp)) {
		printf("Stack full\n");
	} else {
		sp->top++;
		sp->items[sp->top] = newItem;
	}
}

// Popping elements out of the stack
void pop(STACK *sp) {
	if (isEmpty(sp)) {
		printf("Stack empty\n");
	} else {
		printf("Item popped: %i\n", sp->items[sp->top]);
		sp->top--;
	}
}

// Print Stack
void printStack(STACK *sp) {
	for (int i = 0; i <= sp->top; i++ ) {
		printf("[%i]:%i\n", i, sp->items[i]);
	}
}

int stackTask () {
	printf("Hello Stack\n");
	printf("For array based implementation of a stack push and pop O(1)\n");

	createEmptyStack(sp);

	push(sp,10);
	push(sp,9);
	push(sp,8);
	printStack(sp);
	pop(sp);
	printStack(sp);

	return 0;
}
