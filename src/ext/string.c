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
#include <string.h>

#include "dpl.h"
#include "functions.h"
#include "string.h"

functionEntry stringFunctions[] = {
	{"strlen",		dpl_strlen},
	{NULL,			NULL}
};

int stringInit() {
	return registerFunctions(stringFunctions);
}

void dpl_strlen(INTERNAL_FUNCTION_PARAMS) {
	/* validate arguments */
	if(getNumArguments < 1) {
		dplError(DPL_WARNINGL, "argument 1 to strlen is missing");
		return;
	}

	/* fetch the argument */
	dplVal str;
	getArgument(&str, args,0);

	/* validate the type */
	if(str.type != IS_STRING) {
		dplError(DPL_WARNINGL, "invalid data type in argument 1 to strlen");
	}

	RETURN_INT(str.value.str.len);
}
