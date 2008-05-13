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
#include "operators.h"

void opAdd(dplVal *result, dplVal *op1, dplVal *op2) {
	if(!(op1->type & IS_NUMBER)) {
		dplError(DPL_WARNINGL, "cannot add a non number");
		return;
	}

	if((op1->type == IS_DOUBLE) || (op2->type == IS_DOUBLE)) {
		result->type = IS_DOUBLE;
		result->value.dval = (op1->type == IS_DOUBLE) ? op1->value.dval : op1->value.ival;
		result->value.dval += (op2->type == IS_DOUBLE) ? op2->value.dval : op2->value.ival;
	}
	else {
		result->type = IS_INT;
		result->value.ival = op1->value.ival + op2->value.ival;
	}
}

void opSub(dplVal *result, dplVal *op1, dplVal *op2) {
	if(!(op1->type & IS_NUMBER)) {
		dplError(DPL_WARNINGL, "cannot subtract a non number");
		return;
	}

	result->type = IS_INT;
	result->value.ival = op1->value.ival - op2->value.ival;
}

void opMul(dplVal *result, dplVal *op1, dplVal *op2) {
	if(!(op1->type & IS_NUMBER)) {
		dplError(DPL_WARNINGL, "cannot multiply a non number");
		return;
	}

	result->type = IS_INT;
	result->value.ival = op1->value.ival * op2->value.ival;
}

void opDiv(dplVal *result, dplVal *op1, dplVal *op2) {
	if(!(op1->type & IS_NUMBER)) {
		dplError(DPL_WARNINGL,"cannot divide a non number");
		return;
	}

	if(op2->value.ival == 0) {
		dplError(DPL_WARNINGL,"cannot divide by 0");
		return;
	}

	result->type = IS_INT;
	result->value.ival = op1->value.ival / op2->value.ival;
}

void opPow(dplVal *result, dplVal *op1, dplVal *op2) {
	if(!(op1->type & IS_NUMBER)) {
		dplError(DPL_WARNINGL, "cannot power up a non number");
		return;
	}

	int i;
	INT_VALUE(result) = 0;

	result->type = IS_INT;

	for(i = 0; i < (INT_VALUE(op2) - 1); i++) {
		INT_VALUE(result) += INT_VALUE(op1) * INT_VALUE(op1);
	}
}

void opConcat(dplVal *result, dplVal *str1, dplVal *str2) {
	/* sanity check */
	if(str1->type != IS_STRING || str2->type != IS_STRING) {
		dplError(DPL_WARNINGL, "cannot concat a non-string.");
		return;
	}

	result->type = IS_STRING;
	result->value.str.len = str1->value.str.len + str2->value.str.len;

	/* concat op */
	strncat(result->value.str.val, str2->value.str.val, str2->value.str.len);
}

int dplValExprTrue(dplVal *expr) {
	/* convert expr to a boolean value */
	switch(expr->type) {
		case IS_INT:
			if(expr->value.ival <= 0) return FALSE;
			else return TRUE;
		case IS_DOUBLE:
			if(expr->value.dval <= 0.0) return FALSE;
			else return TRUE;
		break;
		case IS_BOOL:
			if(expr->value.boolval == FALSE) return FALSE;
			else return TRUE;
		break;
	}

	return FALSE;
}

int compareDplVal(dplVal *result, dplVal *op1, dplVal *op2) {
	result->type = IS_BOOL;

	if(op1->type == IS_INT && op2->type == IS_INT) {
		if((op1->value.ival - op2->value.ival) == 0) {
			result->value.boolval = TRUE;
		}
		else {
			result->value.boolval = FALSE;
		}
	}
	else if(op1->type == IS_DOUBLE && op2->type == IS_DOUBLE) {
		if((op1->value.dval - op2->value.dval) == 0) {
			result->value.boolval = TRUE;
		}
		else {
			result->value.boolval = FALSE;
		}
	}
	else if(op1->type == IS_BOOL && op2->type == IS_BOOL) {
		if(op1->value.boolval == FALSE) {
			result->value.boolval = TRUE;
		}
		else {
			result->value.boolval = FALSE;
		}
	}
	else if(op1->type == IS_STRING && op2->type == IS_STRING) {
		if(strcmp(op1->value.str.val, op2->value.str.val) == 0) {
			result->value.boolval = TRUE;
		}
		else {
			result->value.boolval = FALSE;
		}
	}
	else {
		dplError(DPL_WARNINGL, "comparsion types are not compatible");
	}

	/*if((op1->type & IS_NOT_BOOL) && op2->type == IS_NULL) {
		printf("here\n");
	}*/
}

void isEqualFunc(dplVal *result, dplVal *op1, dplVal *op2) {
	compareDplVal(result, op1, op2);
}

void isNotEqualFunc(dplVal *result, dplVal *op1, dplVal *op2) {
	compareDplVal(result, op1, op2);

	if(result->value.boolval == FALSE) {
		result->value.boolval = TRUE;
	}
	else {
		result->value.boolval = FALSE;
	}
}

void isGreaterThanFunc(dplVal *result, dplVal *op1, dplVal *op2) {
	result->type = IS_BOOL;

	if(op1->type == IS_INT && op2->type == IS_INT) {
		if(op1->value.ival > op2->value.ival) {
			BOOL_VALUE(result) = TRUE;
		}
		else {
			BOOL_VALUE(result) = FALSE;
		}
	}
}

void isLessThanFunc(dplVal *result, dplVal *op1, dplVal *op2) {
	result->type = IS_BOOL;

	if(op1->type == IS_INT && op2->type == IS_INT) {
		if(op1->value.ival < op2->value.ival) {
			BOOL_VALUE(result) = TRUE;
		}
		else {
			BOOL_VALUE(result) = FALSE;
		}
	}
}
