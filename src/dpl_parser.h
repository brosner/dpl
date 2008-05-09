/* A Bison parser, made by GNU Bison 1.875b.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     PRINT = 258,
     POW = 259,
     IS_NOT_EQUAL = 260,
     IS_EQUAL = 261,
     TYPE = 262,
     EXEC = 263,
     LEVEL = 264,
     IF = 265,
     ELSE = 266,
     GETTYPE = 267,
     ARRAY_HT_DUMP = 268,
     LABEL = 269,
     INT = 270,
     DOUBLE = 271,
     BOOLEAN = 272,
     STRING = 273,
     USE_INTERNAL = 274,
     USE_EXTERNAL = 275,
     MODULE = 276,
     FILE_CONTENTS = 277,
     _FILE_PATH = 278,
     COMMENT = 279,
     OPEN = 280,
     CLOSE = 281
   };
#endif
#define PRINT 258
#define POW 259
#define IS_NOT_EQUAL 260
#define IS_EQUAL 261
#define TYPE 262
#define EXEC 263
#define LEVEL 264
#define IF 265
#define ELSE 266
#define GETTYPE 267
#define ARRAY_HT_DUMP 268
#define LABEL 269
#define INT 270
#define DOUBLE 271
#define BOOLEAN 272
#define STRING 273
#define USE_INTERNAL 274
#define USE_EXTERNAL 275
#define MODULE 276
#define FILE_CONTENTS 277
#define _FILE_PATH 278
#define COMMENT 279
#define OPEN 280
#define CLOSE 281




#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;



