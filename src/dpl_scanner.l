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
	#include <string.h>
	#include "dpl.h"
	#include "dpl_parser.h"

	int dplSourceLineNo = 1;

%}

%x	ONE_LINE_COMMENT
%x	DOUBLE_QUOTES
%x	IN_FILE
%x	USING

ival	[0-9]+
dval	([0-9]*[\.][0-9]+)|([0-9]+[\.][0-9]*)
label	[a-zA-Z][a-zA-Z0-9_]*
ts		[ \t]*
path	[a-zA-Z0-9\/\._]*
tokens	[-{}()+*/\[\].=%@;<>,]

%%

"if" {
	return IF;
}

"else" {
	return ELSE;
}

"==" {
	return IS_EQUAL;
}

"!=" {
	return IS_NOT_EQUAL;
}

"**" {
	return POW;
}

"int" {
	yylval.type = IS_INT;
	return TYPE;
}

"double" {
	yylval.type = IS_DOUBLE;
	return TYPE;
}

"string" {
	yylval.type = IS_STRING;
	return TYPE;
}

"bool"|"boolean" {
	yylval.type = IS_BOOL;
	return TYPE;
}

"file" {
	yylval.type = IS_FILE;
	return TYPE;
}

"print" {
	return PRINT;
}

"type" {
	return GETTYPE;
}

"exec" {
	return EXEC;
}

"arraydump" {
	return ARRAY_HT_DUMP;
}

"level" {
	return LEVEL;
}

"true" {
	yylval.type = IS_BOOL;
	yylval.value.boolval = TRUE;
	return BOOLEAN;
}

"false" {
	yylval.type = IS_BOOL;
	yylval.value.boolval = FALSE;
	return BOOLEAN;
}

{label} {
	yylval.value.str.val = strdup(yytext);
	yylval.value.str.len = yyleng;
	return LABEL;
}

{ival} {
	yylval.type = IS_INT;
	yylval.value.ival = strtol(yytext,NULL,0);
	return INT;
}

{dval} {
	yylval.type = IS_DOUBLE;
	yylval.value.dval = strtod(yytext,NULL);
	return DOUBLE;
}

"use"{ts}("<"|"\""){ts} {
	BEGIN(USING);
	
	if(strpbrk(yytext,"<") != NULL) return USE_INTERNAL;
	else return USE_EXTERNAL;
}

<USING>{label} {
	yylval.value.str.val = strdup(yytext);
	yylval.value.str.len = yyleng;
	return MODULE;
}

<USING>{ts}("\""|">")";" {
	BEGIN(INITIAL);
	return ';';
}

"@" {
	BEGIN(IN_FILE);
	return '@';
}

<IN_FILE>{label} {
	yylval.value.str.val = strdup(yytext);
	yylval.value.str.len = yyleng;
	BEGIN(INITIAL);
	return FILE_CONTENTS;
}

<IN_FILE>{path} {
	yylval.type = IS_FILE;
	yylval.value.file.path = strdup(yytext);
	BEGIN(INITIAL);
	return _FILE_PATH;
}

["] {
	BEGIN(DOUBLE_QUOTES);
	return '\"';
}

<DOUBLE_QUOTES>[a-zA-Z0-9 \.\?!,=\(\)_\+\-\*/\n<>]+ {
	yylval.type = IS_STRING;
	yylval.value.str.val = strdup(yytext);
	yylval.value.str.len = yyleng;
	return STRING;
}

<DOUBLE_QUOTES>["] {
	BEGIN(INITIAL);
	return '\"';
}

"//" {
	BEGIN(ONE_LINE_COMMENT);
	yymore();
}

<ONE_LINE_COMMENT>. {
	yymore();
}

<ONE_LINE_COMMENT>[\n] {
	BEGIN(INITIAL);
	dplSourceLineNo++;
	return COMMENT;
}

{tokens} {
	return yytext[0];
}

(\n)|(\r\n)	{ dplSourceLineNo++; }
[ \t]+		;
.			{ dplError(DPL_SYNTAX,"unknown character '%c'",yytext[0]); }

%%
