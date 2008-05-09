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

#ifndef _DPL_API_H
#define _DPL_API_H

#define INT_VALUE(var)		(var)->value.ival
#define DOUBLE_VALUE(var)	(var)->value.dval
#define BOOL_VALUE(var)		(var)->value.boolval

#define STR_VALUE(var)		(var)->value.str.val
#define STR_LEN(var)		(var)->value.str.len

#define FILE_PATH(var)		(var)->value.file.path
#define FILE_HANDLE(var)	(var)->value.file.handle
#define FILE_SIZE(var)		(var)->value.file.size
#define FILE_LINES(var)		(var)->value.file.lines
#define FILE_DATA(var)		(var)->value.file.data

#define DPLVAL_DESTROY	(void (*)(void *)) dplValDestroy
#define DPLVAL_COPY		(void (*)(void *)) dplValCopy

extern void valueCopy(dplVal *to,dplVal *from);
extern void arrayValueCopy(dplVal *to,dplVal *from);
extern void valuePrint(dplVal *value);
extern void arrayValuePrint(dplVal *array,dplVal *element);
extern void typePrint(dplVal *value);

extern void dplValDestroy(dplVal *);
extern int dplValCopy(dplVal *);

#endif
