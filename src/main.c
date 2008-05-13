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
#include <stdarg.h>

#include "dpl.h"

#include "ext/math.h"
#include "ext/string.h"
#include "ext/array.h"

char *dplSourceFileName;
FILE *dplSourceFileHandle;

extern FILE *yyin;
extern void yyparse();

void dplInit();
void dplCleanup();

int main(int argc,char *argv[]) {
	/* validate cmd line */
	if(argc < 2) {
		fprintf(stderr, "dpl: no input file\n");
		exit(1);
	}

	/* store source filename and read handle to file */
	dplSourceFileName = argv[1];

	if(strcmp(dplSourceFileName, "stdin") == 0) {
		dplSourceFileHandle = stdin;
	}
	else {
		dplSourceFileHandle = fopen(dplSourceFileName, "r");
	}

	/* verify fopen */
	if(!dplSourceFileHandle) {
		fprintf(stderr, "dpl: cannot open %s\n", dplSourceFileName);
		exit(1);
	}

	/* initialize dpl */
	dplInit();

	/* direct source file into parser and execute */
	yyin = dplSourceFileHandle;
	yyparse();

	dplCleanup();

	return 0;
}

void dplInit() {
	/* initialize the variable symbol table */
	if(dplHashInit(&_global(vst), 50, DPLVAL_DESTROY) == FAILURE) {
		dplError(DPL_CORE, "unable to initialize variable symbol table.");
	}

	/* initialize the function symbol table */
	if(dplHashInit(&_global(fst), 50, NULL) == FAILURE) {
		dplError(DPL_CORE, "unable to initialize module hash table.");
	}
}

void dplCleanup() {
	/* destory vst and fst */
	dplHashDestroy(&_global(vst));
	dplHashDestroy(&_global(fst));

	/* destroy css */
	// stackDestroy(&_global(css));
}

void dplLoadModule(dplVal *module) {
	char *moduleName = module->value.str.val;

	if(strcmp(moduleName, "simple") == 0) {
		mathInit();
		stringInit();
		arrayExtInit();
	}
	else if(strcmp(moduleName, "math") == 0) {
		mathInit();
	}
	else if(strcmp(moduleName, "string") == 0) {
		stringInit();
	}
	else if(strcmp(moduleName, "array") == 0) {
		arrayExtInit();
	}
	else {
		dplError(DPL_WARNINGL, "unknown internal module");
	}
}

void dplError(int errcode, const char *txt, ...) {
	va_list args;
	char buffer[1024];

	va_start(args,txt);
	(void) vsnprintf(buffer, sizeof(buffer) - 1, txt, args);
	va_end(args);

	switch(errcode) {
		case DPL_CORE:
			printf("[dpl core error]: %s\n", buffer);
		break;
		case DPL_WARNINGL:
			printf("[dpl warning on line %d]: %s\n", dplSourceLineNo, buffer);
		break;
		case DPL_SYNTAX:
			printf("[dpl syntax error on line %d]: %s\n", dplSourceLineNo, buffer);
		break;
	}
}
