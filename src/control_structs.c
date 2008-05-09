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
#include "control_structs.h"
#include "stack.h"
#include "operators.h"

void csIfStart(dplVal *expr) {
	/* push current state on to css stack */
	stackPush(&_global(css),&_global(execute),sizeof(int));

	/* should this if execute? */
	if(_global(execute)) {
		/* test the expression */
		if(dplValExprTrue(expr) == TRUE) {
			_global(execute) = TRUE;
		}
		else {
			_global(execute) = FALSE;
		}
	}
	else {
		_global(execute) = FALSE;
	}
}

void csIfEnd() {
	int *execFlag;

	/* restore last state and jump back */
	stackPop(&_global(css),(void **) &execFlag);
	_global(execute) = *execFlag;
}

void csElseStart() {
	if(_global(execute) == TRUE) _global(execute) = FALSE;
	else _global(execute) = TRUE;
}
