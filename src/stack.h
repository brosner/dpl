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

#ifndef _STACK_H
#define _STACK_H

typedef struct _StackElement {

	void					*data;
	struct _StackElement	*next;

} StackElement;

typedef struct _Stack {
	
	int				size;
	StackElement	*head;
	StackElement	*tail;

} Stack;

extern void stackInit(Stack *stack);
extern void stackDestroy(Stack *stack);

extern int stackPush(Stack *stack, void *data, int size);
extern int stackPop(Stack *stack, void **data);

#define stackPeek(stack) ((stack)->head == NULL ? NULL : (stack)->head->data)
#define stackSize(stack) (stack)->size

#endif
