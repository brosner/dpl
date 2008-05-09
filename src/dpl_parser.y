%{
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
	#include "dpl.h"
	#include "arrays.h"
	#include "variables.h"
	#include "operators.h"
	#include "functions.h"
	#include "control_structs.h"
	#include "file.h"

	int _global(execute) = TRUE;
	int _global(currentLevel) = 0;
	extern char *yytext;

	HashTable vst;
	HashTable fst;
	Stack css;

%}

%{

	void yyerror(const char *str) {
		dplError(DPL_SYNTAX,"%s",yytext);
	}
	
	int yywrap() {
		return 1;
	}

%}

%right PRINT

%left '+' '-' '.'
%left '*' '/' '%' POW

%nonassoc IS_EQUAL IS_NOT_EQUAL
%nonassoc '>' '<'

%token TYPE
%token EXEC
%token LEVEL

%token IF
%token ELSE

%token IS_EQUAL
%token IS_NOT_EQUAL

%token PRINT
%token GETTYPE
%token ARRAY_HT_DUMP

%token LABEL
%token INT
%token DOUBLE
%token BOOLEAN
%token STRING

%token USE_INTERNAL
%token USE_EXTERNAL
%token MODULE

%token FILE_CONTENTS
%token _FILE_PATH

%token COMMENT

%token OPEN CLOSE

%token POW

%expect 1

%%

statements:
		statements statement
	|	/* empty */
;

statement:
		';'
	|	IF '(' expr ')' { csIfStart(&$3); } statement else_single { csIfEnd(); }
	|	declaration
	|	construct
	|	'{' statements '}'
	|	function_call
;

else_single:
		/* empty */
	|	ELSE { csElseStart(); } statement
;

declaration:
		type_declaration ';'
	|	type_value_declaration ';'
	|	value_declaration ';'
;

type_declaration:
		TYPE LABEL			{ if(_global(execute)) variableInit(&$1,&$2); }
	|	TYPE LABEL '[' ']'	{ if(_global(execute)) arrayInit(&$1,&$2); }
;

type_value_declaration:
		TYPE LABEL '=' expr				{ if(_global(execute)) variableCreate(&$1,&$2,&$4); }
	|	TYPE LABEL '[' ']' '=' expr		{ if(_global(execute)) arrayCreate(&$1,&$2,&$6); }
;

value_declaration:
		LABEL '=' expr				{ if(_global(execute)) variableAssign(&$1,&$3); }
	|	LABEL '[' expr ']' '=' expr	{ if(_global(execute)) arrayAssign(&$1,&$3,&$6); }
;

construct:
		PRINT expr ';'			{ if(_global(execute)) valuePrint(&$2); }
	|	GETTYPE expr ';'		{ if(_global(execute)) typePrint(&$2); }
	|	EXEC ';'				{ dplError(DPL_SYNTAX,"exec = %d",_global(execute)); }
	|	ARRAY_HT_DUMP LABEL ';'	{ arrayElementDump(&$2); }
	|	use_module ';'
;

use_module:
		USE_INTERNAL MODULE		{ dplLoadModule(&$2); }
	|	USE_EXTERNAL MODULE		{ /*printf("using external module: %s\n",$2.value.str.val);*/ }
;

expr:
		INT						{ if(_global(execute)) valueCopy(&$$,&$1); }
	|	DOUBLE					{ if(_global(execute)) valueCopy(&$$,&$1); }
	|	BOOLEAN					{ if(_global(execute)) valueCopy(&$$,&$1); }
	|	'"' STRING '"'			{ if(_global(execute)) valueCopy(&$$,&$2); }
	|	variable				{ if(_global(execute)) valueCopy(&$$,&$1); }
	|	file_exprs				{ if(_global(execute)) valueCopy(&$$,&$1); }
	|	function_call			{ if(_global(execute)) valueCopy(&$$,&$1); }
	|	expr '+' expr			{ if(_global(execute)) opAdd(&$$,&$1,&$3); }
	|	expr '-' expr			{ if(_global(execute)) opSub(&$$,&$1,&$3); }
	|	expr '*' expr			{ if(_global(execute)) opMul(&$$,&$1,&$3); }
	|	expr '/' expr			{ if(_global(execute)) opDiv(&$$,&$1,&$3); }
	|	expr POW expr			{ if(_global(execute)) opPow(&$$,&$1,&$3); }
	|	expr '.' expr			{ if(_global(execute)) opConcat(&$$,&$1,&$3); }
	|	'(' expr ')'			{ if(_global(execute)) valueCopy(&$$,&$2); }
	|	expr IS_EQUAL expr		{ if(_global(execute)) isEqualFunc(&$$,&$1,&$3); }
	|	expr IS_NOT_EQUAL expr	{ if(_global(execute)) isNotEqualFunc(&$$,&$1,&$3); }
	|	expr '>' expr			{ if(_global(execute)) isGreaterThanFunc(&$$,&$1,&$3); }
	|	expr '<' expr			{ if(_global(execute)) isLessThanFunc(&$$,&$1,&$3); }
	|	'[' array_values ']'	{ if(_global(execute)) arrayValueCopy(&$$,&$2); }
;

variable:
		LABEL				{ if(_global(execute)) variableFetch(&$$,&$1); }
	|	LABEL '[' INT ']'	{ if(_global(execute)) arrayElementFetch(&$$,&$1,&$3); }
	|	FILE_CONTENTS		{ if(_global(execute)) variableFetch(&$$,&$1); }
;

file_exprs:
		'@' _FILE_PATH		{ if(_global(execute)) valueCopy(&$$,&$2); fileOpen(&$$,&$2); }
	|	'@' variable		{ if(_global(execute)) $$.value.file.print_context = TRUE; valueCopy(&$$,&$2); fileRead(&$$); }
;

function_call:
	LABEL '(' function_call_args ')'	{ if(_global(execute)) callInternalFunction(&$$,&$1,&$3); }
;

function_call_args:
		non_empty_function_call_args
	|	/* empty */
;

non_empty_function_call_args:
		expr							{ passArgument(&$$,&$1,1); }
	|	function_call_args ',' expr		{ passArgument(&$$,&$3,0); }
;

array_values:
		non_empty_array_values
	|	/* empty */
;

non_empty_array_values:
		expr					{ passArrayValue(&$$,&$1,1); }
	|	array_values ',' expr	{ passArrayValue(&$$,&$3,0); }
;

%%
