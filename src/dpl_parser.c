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

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 1 "/home/brian/dpl2/src/dpl_parser.y"

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

#line 35 "/home/brian/dpl2/src/dpl_parser.y"


	void yyerror(const char *str) {
		dplError(DPL_SYNTAX,"%s",yytext);
	}
	
	int yywrap() {
		return 1;
	}



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 184 "/home/brian/dpl2/src/dpl_parser.c"

#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# if YYSTACK_USE_ALLOCA
#  define YYSTACK_ALLOC alloca
# else
#  ifndef YYSTACK_USE_ALLOCA
#   if defined (alloca) || defined (_ALLOCA_H)
#    define YYSTACK_ALLOC alloca
#   else
#    ifdef __GNUC__
#     define YYSTACK_ALLOC __builtin_alloca
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
# else
#  if defined (__STDC__) || defined (__cplusplus)
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  endif
#  define YYSTACK_ALLOC malloc
#  define YYSTACK_FREE free
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE))				\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  register YYSIZE_T yyi;		\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   227

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  20
/* YYNRULES -- Number of rules. */
#define YYNRULES  62
/* YYNRULES -- Number of states. */
#define YYNSTATES  115

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   281

#define YYTRANSLATE(YYX) 						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    43,     2,     2,     9,     2,     2,
      36,    37,     7,     4,    45,     5,     6,     8,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    35,
      14,    42,    13,     2,    44,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    40,     2,    41,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,     2,    39,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,    10,
      11,    12,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned char yyprhs[] =
{
       0,     0,     3,     6,     7,     9,    10,    18,    20,    22,
      26,    28,    29,    30,    34,    37,    40,    43,    46,    51,
      56,    63,    67,    74,    78,    82,    85,    89,    92,    95,
      98,   100,   102,   104,   108,   110,   112,   114,   118,   122,
     126,   130,   134,   138,   142,   146,   150,   154,   158,   162,
     164,   169,   171,   174,   177,   182,   184,   185,   187,   191,
     193,   194,   196
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const yysigned_char yyrhs[] =
{
      47,     0,    -1,    47,    48,    -1,    -1,    35,    -1,    -1,
      18,    36,    58,    37,    49,    48,    50,    -1,    52,    -1,
      56,    -1,    38,    47,    39,    -1,    61,    -1,    -1,    -1,
      19,    51,    48,    -1,    53,    35,    -1,    54,    35,    -1,
      55,    35,    -1,    15,    22,    -1,    15,    22,    40,    41,
      -1,    15,    22,    42,    58,    -1,    15,    22,    40,    41,
      42,    58,    -1,    22,    42,    58,    -1,    22,    40,    58,
      41,    42,    58,    -1,     3,    58,    35,    -1,    20,    58,
      35,    -1,    16,    35,    -1,    21,    22,    35,    -1,    57,
      35,    -1,    27,    29,    -1,    28,    29,    -1,    23,    -1,
      24,    -1,    25,    -1,    43,    26,    43,    -1,    59,    -1,
      60,    -1,    61,    -1,    58,     4,    58,    -1,    58,     5,
      58,    -1,    58,     7,    58,    -1,    58,     8,    58,    -1,
      58,    10,    58,    -1,    58,     6,    58,    -1,    36,    58,
      37,    -1,    58,    12,    58,    -1,    58,    11,    58,    -1,
      58,    13,    58,    -1,    58,    14,    58,    -1,    40,    64,
      41,    -1,    22,    -1,    22,    40,    23,    41,    -1,    30,
      -1,    44,    31,    -1,    44,    59,    -1,    22,    36,    62,
      37,    -1,    63,    -1,    -1,    58,    -1,    62,    45,    58,
      -1,    65,    -1,    -1,    58,    -1,    64,    45,    58,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned char yyrline[] =
{
       0,    93,    93,    94,    98,    99,    99,   100,   101,   102,
     103,   106,   108,   108,   112,   113,   114,   118,   119,   123,
     124,   128,   129,   133,   134,   135,   136,   137,   141,   142,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   168,
     169,   170,   174,   175,   179,   183,   184,   188,   189,   193,
     194,   198,   199
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PRINT", "'+'", "'-'", "'.'", "'*'", "'/'", 
  "'%'", "POW", "IS_NOT_EQUAL", "IS_EQUAL", "'>'", "'<'", "TYPE", "EXEC", 
  "LEVEL", "IF", "ELSE", "GETTYPE", "ARRAY_HT_DUMP", "LABEL", "INT", 
  "DOUBLE", "BOOLEAN", "STRING", "USE_INTERNAL", "USE_EXTERNAL", "MODULE", 
  "FILE_CONTENTS", "_FILE_PATH", "COMMENT", "OPEN", "CLOSE", "';'", "'('", 
  "')'", "'{'", "'}'", "'['", "']'", "'='", "'\"'", "'@'", "','", 
  "$accept", "statements", "statement", "@1", "else_single", "@2", 
  "declaration", "type_declaration", "type_value_declaration", 
  "value_declaration", "construct", "use_module", "expr", "variable", 
  "file_exprs", "function_call", "function_call_args", 
  "non_empty_function_call_args", "array_values", 
  "non_empty_array_values", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short yytoknum[] =
{
       0,   256,   257,   258,    43,    45,    46,    42,    47,    37,
     259,   260,   261,    62,    60,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,    59,    40,    41,   123,   125,
      91,    93,    61,    34,    64,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    46,    47,    47,    48,    49,    48,    48,    48,    48,
      48,    50,    51,    50,    52,    52,    52,    53,    53,    54,
      54,    55,    55,    56,    56,    56,    56,    56,    57,    57,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    59,
      59,    59,    60,    60,    61,    62,    62,    63,    63,    64,
      64,    65,    65
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     2,     0,     1,     0,     7,     1,     1,     3,
       1,     0,     0,     3,     2,     2,     2,     2,     4,     4,
       6,     3,     6,     3,     3,     2,     3,     2,     2,     2,
       1,     1,     1,     3,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       4,     1,     2,     2,     4,     1,     0,     1,     3,     1,
       0,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
       3,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     4,     3,     2,     7,     0,     0,     0,     8,
       0,    10,    49,    30,    31,    32,    51,     0,    60,     0,
       0,     0,    34,    35,    36,    17,    25,     0,     0,     0,
      56,     0,     0,    28,    29,     0,    14,    15,    16,    27,
       0,     0,    61,     0,    59,     0,    49,    52,    53,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    23,
       0,     0,     0,    24,    26,    57,     0,    55,     0,    21,
       9,     0,    43,    48,     0,    33,    37,    38,    42,    39,
      40,    41,    45,    44,    46,    47,    18,    19,     5,    54,
       0,     0,    50,    62,     0,     0,    58,     0,    20,    11,
      22,    12,     6,     0,    13
};

/* YYDEFGOTO[NTERM-NUM]. */
static const yysigned_char yydefgoto[] =
{
      -1,     1,    14,   105,   112,   113,    15,    16,    17,    18,
      19,    20,    31,    32,    33,    34,    76,    77,    53,    54
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -77
static const short yypact[] =
{
     -77,    48,   -77,     2,     8,   -12,    -3,     2,    18,   -23,
      23,    43,   -77,   -77,   -77,   -77,    12,    38,    39,   -77,
      42,   -77,   -22,   -77,   -77,   -77,   -77,     2,     2,    58,
     -15,   170,   -77,   -77,   -77,     1,   -77,     2,   187,    50,
       2,     2,     2,   -77,   -77,    87,   -77,   -77,   -77,   -77,
      64,   148,   202,    26,   -77,    45,    49,   -77,   -77,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   -77,
      51,     2,   159,   -77,   -77,   202,   -17,   -77,    -2,   202,
     -77,    52,   -77,   -77,     2,   -77,   213,   213,   213,    68,
      68,    68,   106,   106,    36,    36,    53,   202,   -77,   -77,
       2,    54,   -77,   202,     2,   113,   202,     2,   202,    72,
     202,   -77,   -77,   113,   -77
};

/* YYPGOTO[NTERM-NUM].  */
static const yysigned_char yypgoto[] =
{
     -77,    84,   -76,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,    -6,    69,   -77,    -1,   -77,   -77,   -77,   -77
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yysigned_char yytable[] =
{
      21,    38,    59,    60,    61,    62,    63,    56,    64,    65,
      66,    67,    68,    40,    40,    26,    57,    41,    50,    42,
      99,    51,    52,    36,    22,    23,    24,    25,   100,   109,
      35,    72,    26,    37,    75,    78,    79,   114,    27,   101,
      39,    70,    28,    71,    21,    29,    30,    46,     2,    -1,
      -1,     3,    43,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,     4,     5,    97,     6,    83,     7,     8,
       9,    84,    44,    47,    48,    10,    11,    49,   103,    65,
      66,    67,    68,    12,    55,    74,    13,    81,    85,    50,
       3,   111,    96,   102,   106,   104,   107,    45,   108,    58,
       0,   110,     4,     5,    21,     6,     0,     7,     8,     9,
       0,     0,    21,     0,    10,    11,     3,    -1,    -1,    67,
      68,     0,    12,     0,     0,    13,    80,     0,     4,     5,
       0,     6,     0,     7,     8,     9,     0,     0,     0,     0,
      10,    11,     0,     0,     0,     0,     0,     0,    12,     0,
       0,    13,    59,    60,    61,    62,    63,     0,    64,    65,
      66,    67,    68,    59,    60,    61,    62,    63,     0,    64,
      65,    66,    67,    68,    59,    60,    61,    62,    63,     0,
      64,    65,    66,    67,    68,    82,     0,     0,     0,     0,
       0,    59,    60,    61,    62,    63,    98,    64,    65,    66,
      67,    68,     0,     0,     0,    69,    59,    60,    61,    62,
      63,     0,    64,    65,    66,    67,    68,     0,     0,     0,
      62,    63,    73,    64,    65,    66,    67,    68
};

static const yysigned_char yycheck[] =
{
       1,     7,     4,     5,     6,     7,     8,    22,    10,    11,
      12,    13,    14,    36,    36,    30,    31,    40,    40,    42,
      37,    27,    28,    35,    22,    23,    24,    25,    45,   105,
      22,    37,    30,    36,    40,    41,    42,   113,    36,    41,
      22,    40,    40,    42,    45,    43,    44,    35,     0,    13,
      14,     3,    29,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    15,    16,    71,    18,    41,    20,    21,
      22,    45,    29,    35,    35,    27,    28,    35,    84,    11,
      12,    13,    14,    35,    26,    35,    38,    23,    43,    40,
       3,    19,    41,    41,   100,    42,    42,    13,   104,    30,
      -1,   107,    15,    16,   105,    18,    -1,    20,    21,    22,
      -1,    -1,   113,    -1,    27,    28,     3,    11,    12,    13,
      14,    -1,    35,    -1,    -1,    38,    39,    -1,    15,    16,
      -1,    18,    -1,    20,    21,    22,    -1,    -1,    -1,    -1,
      27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,
      -1,    38,     4,     5,     6,     7,     8,    -1,    10,    11,
      12,    13,    14,     4,     5,     6,     7,     8,    -1,    10,
      11,    12,    13,    14,     4,     5,     6,     7,     8,    -1,
      10,    11,    12,    13,    14,    37,    -1,    -1,    -1,    -1,
      -1,     4,     5,     6,     7,     8,    37,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    35,     4,     5,     6,     7,
       8,    -1,    10,    11,    12,    13,    14,    -1,    -1,    -1,
       7,     8,    35,    10,    11,    12,    13,    14
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,    47,     0,     3,    15,    16,    18,    20,    21,    22,
      27,    28,    35,    38,    48,    52,    53,    54,    55,    56,
      57,    61,    22,    23,    24,    25,    30,    36,    40,    43,
      44,    58,    59,    60,    61,    22,    35,    36,    58,    22,
      36,    40,    42,    29,    29,    47,    35,    35,    35,    35,
      40,    58,    58,    64,    65,    26,    22,    31,    59,     4,
       5,     6,     7,     8,    10,    11,    12,    13,    14,    35,
      40,    42,    58,    35,    35,    58,    62,    63,    58,    58,
      39,    23,    37,    41,    45,    43,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    41,    58,    37,    37,
      45,    41,    41,    58,    42,    49,    58,    42,    58,    48,
      58,    19,    50,    51,    48
};

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# if defined (__STDC__) || defined (__cplusplus)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# endif
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrlab1


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror ("syntax error: cannot back up");\
      YYERROR;							\
    }								\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)         \
  Current.first_line   = Rhs[1].first_line;      \
  Current.first_column = Rhs[1].first_column;    \
  Current.last_line    = Rhs[N].last_line;       \
  Current.last_column  = Rhs[N].last_column;
#endif

/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (0)

# define YYDSYMPRINT(Args)			\
do {						\
  if (yydebug)					\
    yysymprint Args;				\
} while (0)

# define YYDSYMPRINTF(Title, Token, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr, 					\
                  Token, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (cinluded).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short *bottom, short *top)
#else
static void
yy_stack_print (bottom, top)
    short *bottom;
    short *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %u), ",
             yyrule - 1, yylno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname [yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname [yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YYDSYMPRINT(Args)
# define YYDSYMPRINTF(Title, Token, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#if YYMAXDEPTH == 0
# undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  register const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  register char *yyd = yydest;
  register const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

#endif /* !YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    {
      YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
# ifdef YYPRINT
      YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
    }
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yydestruct (int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yytype, yyvaluep)
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  switch (yytype)
    {

      default:
        break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short	yyssa[YYINITDEPTH];
  short *yyss = yyssa;
  register short *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyoverflowlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	short *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyoverflowlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YYDSYMPRINTF ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */
  YYDPRINTF ((stderr, "Shifting token %s, ", yytname[yytoken]));

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 5:
#line 99 "/home/brian/dpl2/src/dpl_parser.y"
    { csIfStart(&yyvsp[-1]); }
    break;

  case 6:
#line 99 "/home/brian/dpl2/src/dpl_parser.y"
    { csIfEnd(); }
    break;

  case 12:
#line 108 "/home/brian/dpl2/src/dpl_parser.y"
    { csElseStart(); }
    break;

  case 17:
#line 118 "/home/brian/dpl2/src/dpl_parser.y"
    { if(_global(execute)) variableInit(&yyvsp[-1],&yyvsp[0]); }
    break;

  case 18:
#line 119 "/home/brian/dpl2/src/dpl_parser.y"
    { if(_global(execute)) arrayInit(&yyvsp[-3],&yyvsp[-2]); }
    break;

  case 19:
#line 123 "/home/brian/dpl2/src/dpl_parser.y"
    { if(_global(execute)) variableCreate(&yyvsp[-3],&yyvsp[-2],&yyvsp[0]); }
    break;

  case 20:
#line 124 "/home/brian/dpl2/src/dpl_parser.y"
    { if(_global(execute)) arrayCreate(&yyvsp[-5],&yyvsp[-4],&yyvsp[0]); }
    break;

  case 21:
#line 128 "/home/brian/dpl2/src/dpl_parser.y"
    { if(_global(execute)) variableAssign(&yyvsp[-2],&yyvsp[0]); }
    break;

  case 22:
#line 129 "/home/brian/dpl2/src/dpl_parser.y"
    { if(_global(execute)) arrayAssign(&yyvsp[-5],&yyvsp[-3],&yyvsp[0]); }
    break;

  case 23:
#line 133 "/home/brian/dpl2/src/dpl_parser.y"
    { if(_global(execute)) valuePrint(&yyvsp[-1]); }
    break;

  case 24:
#line 134 "/home/brian/dpl2/src/dpl_parser.y"
    { if(_global(execute)) typePrint(&yyvsp[-1]); }
    break;

  case 25:
#line 135 "/home/brian/dpl2/src/dpl_parser.y"
    { dplError(DPL_SYNTAX,"exec = %d",_global(execute)); }
    break;

  case 26:
#line 136 "/home/brian/dpl2/src/dpl_parser.y"
    { arrayElementDump(&yyvsp[-1]); }
    break;

  case 28:
#line 141 "/home/brian/dpl2/src/dpl_parser.y"
    { dplLoadModule(&yyvsp[0]); }
    break;

  case 29:
#line 142 "/home/brian/dpl2/src/dpl_parser.y"
    { /*printf("using external module: %s\n",$2.value.str.val);*/ }
    break;

  case 30:
#line 146 "/home/brian/dpl2/src/dpl_parser.y"
    { if(_global(execute)) valueCopy(&yyval,&yyvsp[0]); }
    break;

  case 31:
#line 147 "/home/brian/dpl2/src/dpl_parser.y"
    { if(_global(execute)) valueCopy(&yyval,&yyvsp[0]); }
    break;

  case 32:
#line 148 "/home/brian/dpl2/src/dpl_parser.y"
    { if(_global(execute)) valueCopy(&yyval,&yyvsp[0]); }
    break;

  case 33:
#line 149 "/home/brian/dpl2/src/dpl_parser.y"
    { if(_global(execute)) valueCopy(&yyval,&yyvsp[-1]); }
    break;

  case 34:
#line 150 "/home/brian/dpl2/src/dpl_parser.y"
    { if(_global(execute)) valueCopy(&yyval,&yyvsp[0]); }
    break;

  case 35:
#line 151 "/home/brian/dpl2/src/dpl_parser.y"
    { if(_global(execute)) valueCopy(&yyval,&yyvsp[0]); }
    break;

  case 36:
#line 152 "/home/brian/dpl2/src/dpl_parser.y"
    { if(_global(execute)) valueCopy(&yyval,&yyvsp[0]); }
    break;

  case 37:
#line 153 "/home/brian/dpl2/src/dpl_parser.y"
    { if(_global(execute)) opAdd(&yyval,&yyvsp[-2],&yyvsp[0]); }
    break;

  case 38:
#line 154 "/home/brian/dpl2/src/dpl_parser.y"
    { if(_global(execute)) opSub(&yyval,&yyvsp[-2],&yyvsp[0]); }
    break;

  case 39:
#line 155 "/home/brian/dpl2/src/dpl_parser.y"
    { if(_global(execute)) opMul(&yyval,&yyvsp[-2],&yyvsp[0]); }
    break;

  case 40:
#line 156 "/home/brian/dpl2/src/dpl_parser.y"
    { if(_global(execute)) opDiv(&yyval,&yyvsp[-2],&yyvsp[0]); }
    break;

  case 41:
#line 157 "/home/brian/dpl2/src/dpl_parser.y"
    { if(_global(execute)) opPow(&yyval,&yyvsp[-2],&yyvsp[0]); }
    break;

  case 42:
#line 158 "/home/brian/dpl2/src/dpl_parser.y"
    { if(_global(execute)) opConcat(&yyval,&yyvsp[-2],&yyvsp[0]); }
    break;

  case 43:
#line 159 "/home/brian/dpl2/src/dpl_parser.y"
    { if(_global(execute)) valueCopy(&yyval,&yyvsp[-1]); }
    break;

  case 44:
#line 160 "/home/brian/dpl2/src/dpl_parser.y"
    { if(_global(execute)) isEqualFunc(&yyval,&yyvsp[-2],&yyvsp[0]); }
    break;

  case 45:
#line 161 "/home/brian/dpl2/src/dpl_parser.y"
    { if(_global(execute)) isNotEqualFunc(&yyval,&yyvsp[-2],&yyvsp[0]); }
    break;

  case 46:
#line 162 "/home/brian/dpl2/src/dpl_parser.y"
    { if(_global(execute)) isGreaterThanFunc(&yyval,&yyvsp[-2],&yyvsp[0]); }
    break;

  case 47:
#line 163 "/home/brian/dpl2/src/dpl_parser.y"
    { if(_global(execute)) isLessThanFunc(&yyval,&yyvsp[-2],&yyvsp[0]); }
    break;

  case 48:
#line 164 "/home/brian/dpl2/src/dpl_parser.y"
    { if(_global(execute)) arrayValueCopy(&yyval,&yyvsp[-1]); }
    break;

  case 49:
#line 168 "/home/brian/dpl2/src/dpl_parser.y"
    { if(_global(execute)) variableFetch(&yyval,&yyvsp[0]); }
    break;

  case 50:
#line 169 "/home/brian/dpl2/src/dpl_parser.y"
    { if(_global(execute)) arrayElementFetch(&yyval,&yyvsp[-3],&yyvsp[-1]); }
    break;

  case 51:
#line 170 "/home/brian/dpl2/src/dpl_parser.y"
    { if(_global(execute)) variableFetch(&yyval,&yyvsp[0]); }
    break;

  case 52:
#line 174 "/home/brian/dpl2/src/dpl_parser.y"
    { if(_global(execute)) valueCopy(&yyval,&yyvsp[0]); fileOpen(&yyval,&yyvsp[0]); }
    break;

  case 53:
#line 175 "/home/brian/dpl2/src/dpl_parser.y"
    { if(_global(execute)) yyval.value.file.print_context = TRUE; valueCopy(&yyval,&yyvsp[0]); fileRead(&yyval); }
    break;

  case 54:
#line 179 "/home/brian/dpl2/src/dpl_parser.y"
    { if(_global(execute)) callInternalFunction(&yyval,&yyvsp[-3],&yyvsp[-1]); }
    break;

  case 57:
#line 188 "/home/brian/dpl2/src/dpl_parser.y"
    { passArgument(&yyval,&yyvsp[0],1); }
    break;

  case 58:
#line 189 "/home/brian/dpl2/src/dpl_parser.y"
    { passArgument(&yyval,&yyvsp[0],0); }
    break;

  case 61:
#line 198 "/home/brian/dpl2/src/dpl_parser.y"
    { passArrayValue(&yyval,&yyvsp[0],1); }
    break;

  case 62:
#line 199 "/home/brian/dpl2/src/dpl_parser.y"
    { passArrayValue(&yyval,&yyvsp[0],0); }
    break;


    }

/* Line 999 of yacc.c.  */
#line 1404 "/home/brian/dpl2/src/dpl_parser.c"

  yyvsp -= yylen;
  yyssp -= yylen;


  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  YYSIZE_T yysize = 0;
	  int yytype = YYTRANSLATE (yychar);
	  const char* yyprefix;
	  char *yymsg;
	  int yyx;

	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  int yyxbegin = yyn < 0 ? -yyn : 0;

	  /* Stay within bounds of both yycheck and yytname.  */
	  int yychecklim = YYLAST - yyn;
	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
	  int yycount = 0;

	  yyprefix = ", expecting ";
	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      {
		yysize += yystrlen (yyprefix) + yystrlen (yytname [yyx]);
		yycount += 1;
		if (yycount == 5)
		  {
		    yysize = 0;
		    break;
		  }
	      }
	  yysize += (sizeof ("syntax error, unexpected ")
		     + yystrlen (yytname[yytype]));
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "syntax error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[yytype]);

	      if (yycount < 5)
		{
		  yyprefix = ", expecting ";
		  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
		      {
			yyp = yystpcpy (yyp, yyprefix);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yyprefix = " or ";
		      }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    yyerror ("syntax error; also virtual memory exhausted");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror ("syntax error");
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      /* Return failure if at end of input.  */
      if (yychar == YYEOF)
        {
	  /* Pop the error token.  */
          YYPOPSTACK;
	  /* Pop the rest of the stack.  */
	  while (yyss < yyssp)
	    {
	      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
	      yydestruct (yystos[*yyssp], yyvsp);
	      YYPOPSTACK;
	    }
	  YYABORT;
        }

      YYDSYMPRINTF ("Error: discarding", yytoken, &yylval, &yylloc);
      yydestruct (yytoken, &yylval);
      yychar = YYEMPTY;

    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*----------------------------------------------------.
| yyerrlab1 -- error raised explicitly by an action.  |
`----------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
      yydestruct (yystos[yystate], yyvsp);
      yyvsp--;
      yystate = *--yyssp;

      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  YYDPRINTF ((stderr, "Shifting error token, "));

  *++yyvsp = yylval;


  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*----------------------------------------------.
| yyoverflowlab -- parser overflow comes here.  |
`----------------------------------------------*/
yyoverflowlab:
  yyerror ("parser stack overflow");
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 202 "/home/brian/dpl2/src/dpl_parser.y"


