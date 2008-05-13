/* 
   +----------------------------------------------+
   | DPL Programming Language v1.1                |
   +----------------------------------------------+
   | The DPL langauge was developed for a school  |
   | project at ThunderRidge High School.         |
   |                                              |
   | Development of the language after its        |
   | completion is reserved to Brian Rosner.      |
   +----------------------------------------------+
   | Author: Brian Rosner <br@brosner.com>        |
   +----------------------------------------------+
*/

#include <stdio.h>

#include "dpl.h"
#include "stack.h"

void stackInit(Stack *stack) {
	stack->size = 0;
	stack->head = NULL;
	stack->tail = NULL;
}

void stackDestroy(Stack *stack) {
}

int stackPush(Stack *stack, void *data, int size) {
	StackElement *element;

	/* allocate memory for element */
	element = (StackElement *) malloc(sizeof(StackElement));

	if(element == NULL) {
		return FAILURE;
	}

	/* allocate memory for data and store it */
	element->data = (void *) malloc(size);
	memcpy(element->data, data, size);

	if(stackSize(stack) == 0) {
		stack->tail = element;
	}

	element->next = stack->head;
	stack->head = element;

	/* adjust stack size */
	stackSize(stack)++;

	return SUCCESS;
}

int stackPop(Stack *stack, void **data) {
	StackElement *element;

	/* dont allow removal from empty list */
	if(stackSize(stack) == 0) {
		return FAILURE;
	}

	*data = stack->head->data;
	element = stack->head;
	stack->head = stack->head->next;

	if(stackSize(stack) == 1) {
		stack->tail = NULL;
	}

	/* free memory */
	free(element);

	/* adjust stack size */
	stackSize(stack)--;

	return SUCCESS;
}
