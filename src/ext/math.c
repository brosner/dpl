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
#include <math.h>

#include "dpl.h"
#include "functions.h"

#include "math.h"

functionEntry mathFunctions[] = {
	{"abs",			dpl_abs},
	{"acos",		dpl_acos},
	{"cos",			dpl_cos},
	{"sin",			dpl_sin},
	{"tan",			dpl_tan},
	{"deg2rad",		dpl_deg2rad},
	{NULL,			NULL}
};

int mathInit() {
	return registerFunctions(mathFunctions);
}

void dpl_abs(INTERNAL_FUNCTION_PARAMS) {
	dplVal number;
	getOneArgument(&number,args);

	/* verify int only */
	if(number.type != IS_INT) {
		dplError(DPL_WARNINGL,"argument to abs is not an int");
		return;
	}

	RETURN_INT(abs(number.value.ival));
}

void dpl_acos(INTERNAL_FUNCTION_PARAMS) {
	dplVal number;
	getOneArgument(&number,args);

	/* verify double only */
	if(number.type != IS_DOUBLE) {
		dplError(DPL_WARNINGL,"argument to acos is not a double");
		return;
	}

	RETURN_DOUBLE(acos(number.value.dval));
}

void dpl_cos(INTERNAL_FUNCTION_PARAMS) {
	dplVal number;
	getOneArgument(&number,args);

	/* verify double only */
	if(number.type != IS_DOUBLE) {
		dplError(DPL_WARNINGL,"argument to cos is not a double");
		return;
	}

	RETURN_DOUBLE(cos(number.value.dval));
}

void dpl_sin(INTERNAL_FUNCTION_PARAMS) {
	dplVal number;
	getOneArgument(&number,args);

	/* verify double only */
	if(number.type != IS_DOUBLE) {
		dplError(DPL_WARNINGL,"argument to sin is not a double");
		return;
	}

	RETURN_DOUBLE(sin(number.value.dval));
}

void dpl_tan(INTERNAL_FUNCTION_PARAMS) {
	dplVal number;
	getOneArgument(&number,args);

	/* verify double only */
	if(number.type != IS_DOUBLE) {
		dplError(DPL_WARNINGL,"argument to tan is not a double");
		return;
	}

	RETURN_DOUBLE(tan(number.value.dval));
}

void dpl_deg2rad(INTERNAL_FUNCTION_PARAMS) {
	dplVal number;
	getOneArgument(&number,args);

	/* verify int only */
	if(number.type != IS_INT) {
		dplError(DPL_WARNINGL,"argument to deg2rad is not an int");
		return;
	}

	double num, answer;

	num = (double) number.value.ival;
	answer = num * (M_PI * 180);

	RETURN_DOUBLE(answer);
}
