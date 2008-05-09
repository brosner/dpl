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
#include "arrays.h"
#include "variables.h"

void arrayInit(dplVal *type,dplVal *name) {
	dplVal array;

	/* set array specific data and pass thru type */
	array.type = type->type;
	array.isArray = TRUE;

#ifdef DEBUG
	printf("init array (type = %d,name = %s)\n",type->type,name->value.str.val);
#endif

	/* init the variable */
	variableInit(&array,name);
}

void arrayCreate(dplVal *type,dplVal *name,dplVal *value) {
#ifdef DEBUG
	printf("creating array (type = %d,name = %s)\n",type->type,name->value.str.val);
#endif

	/* validate the value being assigned MUST BE AN ARRAY */
	if(value->isArray != TRUE ) {
		dplError(DPL_WARNINGL,"value being assigned to array must be an array");
		return;
	}
	else {
		int elementCount;
		dplVal i, *ivalue;

		/* initialize array */
		arrayInit(type,name);

		/* cache element count and set the type for i to int */
		elementCount = value->value.array.elements->numElements;
		i.type = IS_INT;

		/* assign in the values passed by the array */
		for(i.value.ival = 0; i.value.ival < elementCount; i.value.ival++) {
			/* fetch the element value from ht */
			if(dplHashIndexFind(value->value.array.elements,i.value.ival,(void **) &ivalue) == FAILURE) {
				dplError(DPL_CORE,"error extracting element %d from ht",i.value.ival);
				break;
			}

			/* assign to right index */
			arrayAssign(name,&i,ivalue);
		}
	}
}

void arrayAssign(dplVal *name,dplVal *element,dplVal *value) {
#ifdef DEBUG
	printf("assigning array (name = %s,element = %d)\n",name->value.str.val,element->value.ival);
#endif

	dplVal array;

	/* fetch the array */
	if(variableFetch(&array,name) == FAILURE) {
		dplError(DPL_WARNINGL,"array was not initialized.");
		return;
	}

#ifdef DEBUG
	printf("array check (init = %d,ce = %d)\n",array.value.array.elements->isInit,array.value.array.currentElement);
#endif

	/* check if element exists */
	if(arrayElementExists(&array,element) == TRUE) {
#ifdef DEBUG
		printf("element %d in array %s exists...updating\n",element->value.ival,name->value.str.val);
#endif
		/* perform a hash update */
		if(dplHashUpdateIndexElement(array.value.array.elements,element->value.ival,value,sizeof(dplVal)) == FAILURE) {
			dplError(DPL_CORE,"failed updating index %d in %s",element->value.ival,name->value.str.val);
			return;
		}
		else {
#ifdef DEBUG
			printf("updated array element %d successfully\n",element->value.ival);
#endif
		}
	}
	else {
#ifdef DEBUG
		printf("element %d in array %s does not exist...adding\n",element->value.ival,name->value.str.val);
#endif
		
		/* perform a hash add */
		if(dplHashAddIndexElement(array.value.array.elements,element->value.ival,value,sizeof(dplVal)) == FAILURE) {
			dplError(DPL_CORE,"failed adding index %d in %s",element->value.ival,name->value.str.val);
			return;
		}
		else {
#ifdef DEBUG
			printf("added array element %d successfully\n",element->value.ival);
#endif
		}

		/* commit the changes of the array back */
		if(dplHashUpdateElement(&_global(vst),name->value.str.val,name->value.str.len + 1,&array,sizeof(dplVal)) == FAILURE) {
			dplError(DPL_CORE,"failed udpating the array %s",name->value.str.val);
		}
		else {
#ifdef DEBUG
			printf("commited the array back successfully\n");
#endif
		}
	}

}

void passArrayValue(dplVal *result,dplVal *value,int init) {
	static int elementCount = 0;

	if(init == 1) {
		result->isArray = TRUE;
		result->value.array.elements = (HashTable *) malloc(sizeof(HashTable));

		if(dplHashInit(result->value.array.elements,20,NULL) == FAILURE) {
			dplError(DPL_CORE,"array pass hash tbl failed init");
		}
	}

	if(dplHashAddIndexElement(result->value.array.elements,elementCount,value,sizeof(dplVal)) == FAILURE) {
		dplError(DPL_CORE,"failed adding elements");
	}

	elementCount++;
}

int arrayElementExists(dplVal *array,dplVal *element) {
	dplVal *tmp;

	if(dplHashIndexFind(array->value.array.elements,element->value.ival,(void **) &tmp) == FAILURE) {
		return FALSE;
	}
	else {
		return TRUE;
	}
}

void arrayElementFetch(dplVal *result,dplVal *_array,dplVal *element) {
	dplVal array, *elementData;


	/* check to see if we need to fetch the array */
	if(_array->isArray != TRUE) {
		if(variableFetch(&array,_array) == FAILURE) {
			dplError(DPL_CORE,"failed fetching array %s in arrayElementFetch",_array->value.str.val);
			return;
		}
	}
	else {
		arrayValueCopy(&array,_array);
	}

#ifdef DEBUG
	printf("arrayElementFetch array check (init = %d,ce = %d,elements = %d)\n",array.value.array.elements->isInit,array.value.array.currentElement,array.value.array.elements->numElements);
#endif

	/* fetch the element data */
	if(dplHashIndexFind(array.value.array.elements,element->value.ival,(void **) &elementData) == FAILURE) {
		dplError(DPL_WARNINGL,"cannot fetch element %d of array %s",element->value.ival,_array->value.str.val);
		result->isNull = TRUE;
		return;
	}
	else {
#ifdef DEBUG
		printf("fetched element %d from array %s successfully\n",element->value.ival,_array->value.str.val);
#endif
	}
	
	/* result */
	if(elementData->isArray == TRUE) {
		arrayValueCopy(result,elementData);
	}
	else {
		valueCopy(result,elementData);
	}
}

void arrayElementDump(dplVal *arrayName) {
	dplVal array;

	/* fetch array */
	if(variableFetch(&array,arrayName) == FAILURE) {
		dplError(DPL_CORE,"failed fetching array");
	}

	/* preform dump - make sure a stderr redirect is ineffect to make easier reading */
	dplHashIndexDump(array.value.array.elements,FALSE);
}
