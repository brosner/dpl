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

#ifndef _DPL_ARRAYS_H
#define _DPL_ARRAYS_H

extern void arrayInit(dplVal *type,dplVal *name);
extern void arrayCreate(dplVal *type,dplVal *name,dplVal *value);
extern void arrayAssign(dplVal *name,dplVal *element,dplVal *value);

extern void passArrayValue(dplVal *result,dplVal *value,int init);

extern int arrayElementExists(dplVal *array,dplVal *element);
extern void arrayElementFetch(dplVal *result,dplVal *_array,dplVal *element);

extern void arrayElementDump(dplVal *arrayName);

#endif
