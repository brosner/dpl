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

#ifndef DPL_OPERATORS
#define DPL_OPERATORS

extern void opAdd(dplVal *result, dplVal *op1, dplVal *op2);
extern void opSub(dplVal *result, dplVal *op1, dplVal *op2);
extern void opMul(dplVal *result, dplVal *op1, dplVal *op2);
extern void opDiv(dplVal *result, dplVal *op1, dplVal *op2);
extern void opPow(dplVal *result, dplVal *op1, dplVal *op2);
extern void opConcat(dplVal *result, dplVal *str1, dplVal *str2);

extern int dplValExprTrue(dplVal *expr);
extern int compareDplVal(dplVal *result, dplVal *op1, dplVal *op2);
extern void isEqualFunc(dplVal *result, dplVal *op1, dplVal *op2);
extern void isNotEqualFunc(dplVal *result, dplVal *op1, dplVal *op2);
extern void isGreaterThanFunc(dplVal *result, dplVal *op1, dplVal *op2);
extern void isLessThanFunc(dplVal *result, dplVal *op1, dplVal *op2);

#endif
