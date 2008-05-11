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

#ifndef _DPL_H
#define _DPL_H

typedef struct _dplVal dplVal;

#include <stdio.h>
#include <stdlib.h>

#include "dpl_api.h"
#include "hash.h"
#include "stack.h"

#define INTERNAL_FUNCTION_PARAMS	dplVal *returnValue,dplVal *args
#define INTERNAL_METHOD_PARAMS		dplVal *returnValue,dplVal *args

#define SUCCESS 0
#define FAILURE -1

#undef TRUE
#undef FALSE
#define TRUE 1
#define FALSE 0

#define _global(s) s

extern char *dplSourceFileName;
extern FILE *dplSourceFileHandle;
extern int dplSourceLineNo;

extern void dplLoadModule(dplVal *);
extern void dplError(int, const char *, ...);

typedef union _dplValue {
	
	long int ival;
	double dval;

	int boolval;

	struct {
		char *val;
		int len;
	} str;

	struct {
		char *path;
		FILE *handle;
		long size;
		int lines;
		char *data;
		int print_context;
	} file;

	struct {
		int currentElement;
		int nextIndex;
		HashTable *elements;
	} array;

	/* internal function and array specific items */
	HashTable *ht;
	void (*function)(INTERNAL_FUNCTION_PARAMS);

} dplValue;

struct _dplVal {
	int type;
	dplValue value;
	int isNull;
	int isArray;
};

typedef struct _functionEntry {
	char *functionName;
	void (*function)(INTERNAL_FUNCTION_PARAMS);
} functionEntry;

extern int execute;
extern int currentLevel;

extern HashTable	variableSymbolTable;
extern HashTable	functionSymbolTable;
extern Stack		css;

#define YYSTYPE dplVal
#define vst variableSymbolTable
#define fst functionSymbolTable

#define STR_FREE(s) if(s && s != empty_string) { free(s); }

/* dpl error codes */
#define DPL_CORE		0x1
#define DPL_WARNINGL	0x2
#define DPL_SYNTAX		0x3

/* dpl data types */
#define IS_INT		0x1
#define IS_DOUBLE	0x2
#define IS_STRING	0x4
#define IS_BOOL		0x8
#define IS_FILE		0x9

/* combos */
#define IS_NUMBER (IS_INT | IS_DOUBLE)

/* dpl core types */
#define IS_INTERNAL_FUNCTION	0x1a

#endif
