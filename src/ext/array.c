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
#include <stdlib.h>

#include "dpl.h"
#include "functions.h"
#include "arrays.h"

#include "array.h"

functionEntry arrayFunctions[] = {
	{"printFirstElement",			dpl_printFirstElement},
	{NULL,							NULL}
};

int arrayExtInit() {
	return registerFunctions(arrayFunctions);
}

void dpl_printFirstElement(INTERNAL_FUNCTION_PARAMS) {
	dplVal array;
	getOneArgument(&array, args);

	/* verify array only */
	if(array.isArray != TRUE) {
		dplError(DPL_WARNINGL, "argument to printFirstElement is not an array");
		return;
	}

	/* create variables */
	dplVal e; e.type = IS_INT; e.value.ival = 0;
	dplVal elementData;

	/* get the first element */
	arrayElementFetch(&elementData, &array, &e);

	/* return value */
	RETURN_INT(elementData.value.ival);
}
