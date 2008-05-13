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

#ifndef _DPL_VARIABLES_H
#define _DPL_VARIABLES_H

extern void variableInit(dplVal *type, dplVal *varName);
extern void variableAssign(dplVal *varName, dplVal *value);
extern void variableCreate(dplVal *type, dplVal *varName, dplVal *value);

extern int variableFetch(dplVal *result, dplVal *varName);

#endif
