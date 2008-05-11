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
#include "functions.h"

int registerFunctions(functionEntry *functions) {
	functionEntry *ptr = functions;
	dplVal function;

	while(ptr->functionName) {
		function.type = IS_INTERNAL_FUNCTION;
		function.value.function = ptr->function;

		if(!function.value.function) {
			return FAILURE;
		}

		if(dplHashAddElement(&_global(fst), ptr->functionName, strlen(ptr->functionName) + 1, &function, sizeof(dplVal)) == FAILURE) {
			return FAILURE;
		}

		ptr++;
	}

	return SUCCESS;
}

void getArgument(dplVal *result, dplVal *args, unsigned int i) {
	dplVal *arg;

	if(dplHashIndexFind(args->value.ht, i, (void **) &arg) == FAILURE) {
		/* change to dplError later */
		fprintf(stderr, "could not get argument\n");
	}
	else {
		*result = *arg;
		dplValCopy(result);
	}
}

void getOneArgument(dplVal *result, dplVal *args) {
	/* validate number of args */
	if(getNumArguments < 1) {
		dplError(DPL_WARNINGL, "missing argument");
		return;
	}

	/* fetch argument */
	getArgument(result, args, 0);
}

void callInternalFunction(dplVal *returnValue, dplVal *name, dplVal *args) {
	dplVal *function;

	if(dplHashFind(&_global(fst), STR_VALUE(name), STR_LEN(name) + 1, (void **) &function) == FAILURE) {
		dplError(DPL_WARNINGL, "call to undefined function: %s", STR_VALUE(name));
	}
	else {
		function->value.function(returnValue, args);
	}
}

void passArgument(dplVal *result, dplVal *arg, int init) {
	static int argCount = 0;

	if(init == 1) {
		result->value.ht = (HashTable *) malloc(sizeof(HashTable));
		if(dplHashInit(result->value.ht, 20, NULL) == FAILURE) {
			dplError(DPL_CORE, "arg hash tbl failed init");
		}
	}

	if(dplHashAddIndexElement(result->value.ht, argCount, arg, sizeof(dplVal)) == FAILURE) {
		dplError(DPL_CORE, "failed adding arguments");
	}

	argCount++;
}
