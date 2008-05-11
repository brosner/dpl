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

#ifndef _DPL_FUNCTIONS_H
#define _DPL_FUNCTIONS_H

#define RETURN_INT(i) { \
	returnValue->type = IS_INT; \
	returnValue->value.ival = i; \
}

#define RETURN_DOUBLE(d) { \
	returnValue->type = IS_DOUBLE; \
	returnValue->value.dval = d; \
}

extern int registerFunctions(functionEntry *functions);

extern void getArgument(dplVal *result, dplVal *args, unsigned int i);
#define getNumArguments args->value.ht->numElements

extern void getOneArgument(dplVal *result, dplVal *args);

extern void callInternalFunction(dplVal *returnValue, dplVal *name, dplVal *args);
extern void passArgument(dplVal *result, dplVal *arg, int init);

#endif
