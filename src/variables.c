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
#include "variables.h"

void variableInit(dplVal *type,dplVal *varName) {
	dplVal tmp;

	if(variableFetch(&tmp,varName) == SUCCESS) {
		dplError(DPL_WARNINGL,"variable %s is already declared.",STR_VALUE(varName));
		return;
	}

	dplVal var;
	var.type = type->type;

	/* set value to null or false if boolean */
	if(type->type == IS_BOOL) {
		var.value.boolval = FALSE;
		var.isNull = FALSE;
	}
	else {
		var.isNull = TRUE;
	}

	/* array actions */
	if(type->isArray == TRUE) {
		var.isArray = TRUE;

		/* set internal pointer to first element */
		var.value.array.currentElement = 0;
		var.value.array.nextIndex = 0;

		/* allocate memory for array elements  if you can only use one element check here for how much to allocate */
		var.value.array.elements = (HashTable *) malloc(sizeof(HashTable));

#ifdef DEBUG
		printf("init the array elements ht\n");
#endif

		/* initialize array ht */
		if(dplHashInit(var.value.array.elements,50,DPLVAL_DESTROY) == FAILURE) {
			dplError(DPL_CORE,"unable to init array hash table");
		}
	}
	else {
		/* set specific type to default init values */
		switch(type->type) {
			case IS_STRING:
				var.value.str.val = "\0";
				var.value.str.len = 0;
			break;
			case IS_FILE:
				var.value.file.handle = NULL;
				var.value.file.data = NULL;
			break;
		}
	}

	/* add to vst */
	if(dplHashAddElement(&_global(vst),STR_VALUE(varName),STR_LEN(varName) + 1,&var,sizeof(dplVal)) == FAILURE) {
		dplError(DPL_CORE,"cannot add %s to vst.",STR_VALUE(varName));
	}
}

void variableAssign(dplVal *varName,dplVal *value) {
	dplVal tmp;

	if(variableFetch(&tmp,varName) == FAILURE) {
		dplError(DPL_WARNINGL,"assignment to undefined variable %s",STR_VALUE(varName));
		return;
	}

	dplVal var;
	var.type = value->type;
	var.isNull = FALSE;

	/* handle special assignments */
	if(var.type == IS_FILE && tmp.type == IS_STRING) {
		var.value.str.val = FILE_DATA(value);
		var.value.str.len = strlen(FILE_DATA(value));
	}
	else {
		if(var.type != tmp.type) {
			dplError(DPL_WARNINGL,"assignment of incompatible types");
			return;
		}

		switch(var.type) {
			case IS_INT:
				var.value.ival = INT_VALUE(value);
			break;
			case IS_DOUBLE:
				var.value.dval = DOUBLE_VALUE(value);
			break;
			case IS_BOOL:
				var.value.boolval = BOOL_VALUE(value);
			break;
			case IS_STRING:
				var.value.str.val = STR_VALUE(value);
				var.value.str.len = STR_LEN(value);
			break;
			case IS_FILE:
				var.value.file.path = strdup(FILE_PATH(value));
				var.value.file.handle = value->value.file.handle;
			break;
		}
	}

	if(dplHashUpdateElement(&_global(vst),STR_VALUE(varName),STR_LEN(varName) + 1,&var,sizeof(dplVal)) == FAILURE) {
		dplError(DPL_CORE,"unable to update value of %s",STR_VALUE(varName));
		return;
	}
}

void variableCreate(dplVal *type,dplVal *varName,dplVal *value) {
	variableInit(type,varName);
	variableAssign(varName,value);
}

int variableFetch(dplVal *result,dplVal *varName) {
	dplVal *data;

	//printf("fetching %s\n",varName->value.str.val);

	if(dplHashFind(&_global(vst),STR_VALUE(varName),STR_LEN(varName) + 1,(void **) &data) == SUCCESS) {
		*result = *data;
		return dplValCopy(result);
	}
	else {
		return FAILURE;
	}
}
