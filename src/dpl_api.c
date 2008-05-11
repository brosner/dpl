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

#include "dpl.h"
#include <string.h>

char *empty_string = "";
char *undefined_string = "\0";

void valueCopy(dplVal *to, dplVal *from) {
	if(from->isArray == TRUE) {
		arrayValueCopy(to, from);
	}
	else {
		to->type = from->type;

		switch(from->type) {
			case IS_INT:
				to->value.ival = INT_VALUE(from);
			break;
			case IS_DOUBLE:
				to->value.dval = DOUBLE_VALUE(from);
			break;
			case IS_BOOL:
				to->value.boolval = BOOL_VALUE(from);
			break;
			case IS_STRING:
				to->value.str.val = strdup(STR_VALUE(from));
				to->value.str.len = STR_LEN(from);
			break;
			case IS_FILE:
				FILE_PATH(to) = strdup(FILE_PATH(from));
				FILE_HANDLE(to) = FILE_HANDLE(from);
				FILE_SIZE(to) = FILE_SIZE(from);
				FILE_DATA(to) = FILE_DATA(from);
			break;
		}
	}
}

void arrayValueCopy(dplVal *to, dplVal *from) {
#ifdef DEBUG
	if(from == NULL) {
		printf("from is null\n");
		return;
	}
#endif
	dplVal tmp;
	to->type = from->type;
	to->isArray = TRUE;

	if(dplHashCopy(&(to->value.array.elements), from->value.array.elements, DPLVAL_COPY, &tmp, sizeof(dplVal)) == FAILURE) {
		dplError(DPL_CORE, "hash copied failed");
	}
}

/* temp for printing values with print */
void valuePrint(dplVal *value) {
	if(value->isNull == TRUE) {
		printf("<null>\n");
	}
	else if(value->isArray == TRUE) {
		arrayValuePrint(value,NULL);
	}
	else {
		switch(value->type) {
			case IS_INT:
				printf("%d\n",INT_VALUE(value));
			break;
			case IS_DOUBLE:
				printf("%f\n",DOUBLE_VALUE(value));
			break;
			case IS_BOOL:
				if(BOOL_VALUE(value) == TRUE) {
					printf("<bool:true>\n");
				}
				else {
					printf("<bool:false>\n");
				}
			break;
			case IS_STRING:
				printf("%s\n",STR_VALUE(value));
			break;
			case IS_FILE:
				if(value->value.file.print_context == TRUE) {
					printf("%s",FILE_DATA(value));
				}
				else {
					printf("%s\n",FILE_PATH(value));
				}
			break;
		}
	}
}

void arrayValuePrint(dplVal *array,dplVal *element) {
	dplVal elementData;
	arrayElementFetch(&elementData,array,element,TRUE);
	valuePrint(&elementData);
}

void typePrint(dplVal *value) {
	if(value->isNull == TRUE) {
		printf("<null>\n");
	}
	else {
		switch(value->type) {
			case IS_INT:
				printf("<int>\n");
			break;
			case IS_DOUBLE:
				printf("<double>\n");
			break;
			case IS_BOOL:
				printf("<bool>\n");
			break;
			case IS_STRING:
				printf("<string>\n");
			break;
			case IS_FILE:
				printf("<file>\n");
			break;
		}
	}
}

void dplValDestroy(dplVal *v) {
	if(v->type == IS_STRING) {
		STR_FREE(STR_VALUE(v));
	}

	if(v->type == IS_FILE) {
		fclose(FILE_HANDLE(v));
		STR_FREE(FILE_DATA(v));
	}

	if(v->isArray == TRUE) {
		dplHashDestroy(v->value.array.elements);
	}
}

int dplValCopy(dplVal *result) {
	if(result->type == IS_STRING) {
		result->value.str.val = strdup(result->value.str.val);
	}
	else if(result->isArray == TRUE) {
		dplVal tmp;
		if(dplHashCopy(&(result->value.array.elements),result->value.array.elements,DPLVAL_COPY,&tmp,sizeof(dplVal)) == FAILURE) {
			dplError(DPL_CORE,"hash copy failed");
		}
	}

	return SUCCESS;
}
