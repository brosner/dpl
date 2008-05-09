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

#ifndef _DPL_MATH_H
#define _DPL_MATH_H

extern int mathInit();

extern void dpl_abs(INTERNAL_FUNCTION_PARAMS);
extern void dpl_acos(INTERNAL_FUNCTION_PARAMS);
extern void dpl_cos(INTERNAL_FUNCTION_PARAMS);
extern void dpl_sin(INTERNAL_FUNCTION_PARAMS);
extern void dpl_tan(INTERNAL_FUNCTION_PARAMS);

extern void dpl_deg2rad(INTERNAL_FUNCTION_PARAMS);

#endif
