/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

	#include <stdbool.h>
	#include "ast.h"
	#include "main.h"

	int yylex(void);
	void yyerror(char *);

#line 75 "parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TAG = 258,
    NAME = 259,
    MOT = 260,
    NUMBER = 261,
    LET = 262,
    REC = 263,
    FUNC = 264,
    IN = 265,
    WHERE = 266,
    IF = 267,
    THEN = 268,
    ELSE = 269,
    MATCH_T = 270,
    WITH = 271,
    END = 272,
    EMIT_T = 273,
    ARROW = 274,
    OU = 275,
    ET = 276,
    INF = 277,
    SUP = 278,
    INF_EQ = 279,
    SUP_EQ = 280,
    EQ_T = 281,
    NOT_EQ = 282
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 12 "parser.y" /* yacc.c:355  */

	int value;
	char * name;
	struct ast * ast;
	struct attributes * attributes;
	struct patterns * patterns;
	struct pattern * pattern;

#line 152 "parser.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 167 "parser.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  37
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   214

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  170

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   282

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    45,    35,    30,     2,     2,     2,     2,     2,
      36,    37,    33,    31,    44,    32,     2,    34,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    28,
       2,    29,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    42,     2,    43,     2,    39,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,    38,    41,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   102,   102,   103,   110,   111,   115,   116,   120,   121,
     125,   126,   130,   131,   132,   133,   140,   141,   142,   143,
     144,   148,   149,   153,   154,   155,   159,   160,   161,   162,
     163,   164,   165,   169,   170,   171,   175,   176,   177,   181,
     182,   186,   187,   188,   189,   193,   197,   198,   202,   203,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   225,   227,   236,   237,   238,   239,   240,   244,
     245,   249,   250,   251,   252,   258,   262,   263,   267,   268
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TAG", "NAME", "MOT", "NUMBER", "LET",
  "REC", "FUNC", "IN", "WHERE", "IF", "THEN", "ELSE", "MATCH_T", "WITH",
  "END", "EMIT_T", "\"=>\"", "\"||\"", "\"&&\"", "\"<\"", "\">\"",
  "\"<=\"", "\">=\"", "\"==\"", "\"!=\"", "';'", "'='", "'\"'", "'+'",
  "'-'", "'*'", "'/'", "'!'", "'('", "')'", "'|'", "'_'", "'{'", "'}'",
  "'['", "']'", "','", "' '", "$accept", "file", "declarations_globales",
  "declaration", "names", "functions", "declaration_locale", "expr",
  "conditional_expr", "logical_expr", "relational_expr", "additive_expr",
  "multiplicative_expr", "negative_expr", "factor_expr", "match_expr",
  "filter_expr", "pforests", "pattern_expr", "body", "tree", "attributs",
  "contenus", "contenu", "text", "word_t", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,    59,    61,
      34,    43,    45,    42,    47,    33,    40,    41,   124,    95,
     123,   125,    91,    93,    44,    32
};
# endif

#define YYPACT_NINF -129

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-129)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      21,   -21,    28,   138,     6,    27,    -5,  -129,    27,  -129,
     138,    32,    61,    61,    13,  -129,  -129,    73,    38,   138,
      16,    71,   124,   138,  -129,    79,  -129,    -4,   166,    -6,
      59,  -129,    78,  -129,  -129,    63,   138,  -129,  -129,    93,
    -129,    67,    83,    70,  -129,    87,   131,    99,   125,    18,
    -129,   120,   134,   102,   118,    71,  -129,   121,  -129,  -129,
      38,    38,    38,    38,    38,    38,    38,    38,    38,    38,
      38,    38,    80,  -129,  -129,  -129,  -129,   127,   -20,   131,
      61,  -129,  -129,   124,   126,   138,   137,   129,  -129,  -129,
    -129,  -129,   166,   166,    -6,    -6,    -6,    -6,    -6,    -6,
      59,    59,  -129,  -129,   133,   159,    71,  -129,   138,  -129,
     146,   160,   124,   155,   148,   162,    27,   138,   143,   147,
     135,   131,   138,   173,   138,   144,  -129,    33,    36,    41,
     145,   167,   148,  -129,  -129,  -129,   138,    32,  -129,  -129,
    -129,   138,  -129,    30,   168,   169,   170,   171,   172,   174,
      92,   138,  -129,  -129,  -129,  -129,  -129,   161,  -129,  -129,
    -129,  -129,  -129,  -129,  -129,   164,   137,  -129,  -129,  -129
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     3,    63,    67,
       0,     0,     9,     0,     0,    20,    44,     0,     0,     0,
       0,     0,     0,     0,    17,    74,    16,    22,    25,    32,
      35,    38,    39,    18,    43,     0,    72,     1,     2,     5,
      62,     0,     0,     0,     8,     0,     0,     0,     0,     0,
      39,     0,     0,    79,     0,    77,    40,     0,    75,    73,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    68,    71,     4,    66,     0,     0,     0,
       0,     6,    11,     0,     0,     0,     0,     0,    78,    42,
      76,    41,    23,    24,    26,    27,    29,    28,    30,    31,
      33,    34,    36,    37,     0,     0,     0,    65,     0,     7,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    58,     0,     0,     0,
      50,     0,    49,    45,    19,    14,     0,    70,    64,    10,
      12,     0,    21,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    48,    15,    69,    13,    52,     0,    61,    57,
      59,    55,    60,    56,    54,     0,    47,    51,    53,    46
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -129,  -129,   175,  -129,    -1,   -78,  -129,   -19,  -129,   189,
      46,   132,    42,    50,   -13,  -129,    43,    81,  -128,    82,
       2,    74,    -7,  -129,   -47,  -129
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,    14,    81,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,   115,   131,   132,     7,
      34,    43,    35,    36,    54,    55
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      51,   109,     8,    41,    57,    50,    37,     8,    90,    56,
       8,    44,    45,     9,   107,   157,    60,    61,    59,    10,
     108,    11,   165,    39,     1,    68,    69,    82,     2,    74,
       1,    85,    12,   125,   126,    42,    13,   144,    60,    61,
     146,     1,    46,   139,    16,   148,    52,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,   119,
      82,     3,   127,   128,   129,    12,   113,     3,    21,   130,
     111,   156,   145,    22,    23,   147,    53,    47,     3,   110,
     149,    48,     1,    15,   104,    16,    17,    38,   105,    72,
      40,    18,    70,    71,    19,   125,   126,    20,   135,   123,
       2,   120,    82,   140,    73,   142,    92,    93,    76,    21,
     100,   101,    77,    78,    22,    23,    79,   153,   134,     3,
     102,   103,   155,    58,   127,   128,   129,     1,    83,    84,
      16,   130,   166,   164,     1,    15,    86,    16,    17,    87,
      80,     1,    15,    18,    16,    17,    19,    88,    89,    20,
      18,   125,   126,    19,    21,   112,    20,   106,    91,   116,
      23,    21,   117,   118,     3,   121,    22,    23,    21,   124,
     122,     3,   136,    22,    23,   114,   138,   137,     3,   133,
     127,   128,   129,   141,   143,   150,   151,   130,    62,    63,
      64,    65,    66,    67,    94,    95,    96,    97,    98,    99,
     158,   159,   167,   160,   161,   168,   162,    49,   163,   169,
       0,   154,     0,   152,    75
};

static const yytype_int16 yycheck[] =
{
      19,    79,     0,    10,    23,    18,     0,     5,    55,    22,
       8,    12,    13,    34,    34,   143,    20,    21,    25,    40,
      40,    42,   150,    28,     3,    31,    32,    46,     7,    36,
       3,    13,     4,     3,     4,     3,     8,     4,    20,    21,
       4,     3,    29,   121,     6,     4,    30,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,   106,
      79,    40,    32,    33,    34,     4,    85,    40,    30,    39,
      83,    41,    39,    35,    36,    39,     5,     4,    40,    80,
      39,     8,     3,     4,     4,     6,     7,     5,     8,    11,
       8,    12,    33,    34,    15,     3,     4,    18,   117,   112,
       7,   108,   121,   122,    41,   124,    60,    61,    41,    30,
      68,    69,    29,    43,    35,    36,    29,   136,   116,    40,
      70,    71,   141,    44,    32,    33,    34,     3,    29,     4,
       6,    39,   151,    41,     3,     4,    16,     6,     7,     5,
       9,     3,     4,    12,     6,     7,    15,    45,    30,    18,
      12,     3,     4,    15,    30,    29,    18,    30,    37,    30,
      36,    30,    29,     4,    40,    19,    35,    36,    30,    14,
      10,    40,    29,    35,    36,    38,    41,    30,    40,    17,
      32,    33,    34,    10,    40,    40,    19,    39,    22,    23,
      24,    25,    26,    27,    62,    63,    64,    65,    66,    67,
      32,    32,    41,    33,    33,    41,    34,    18,    34,   166,
      -1,   137,    -1,   132,    39
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     7,    40,    47,    48,    49,    65,    66,    34,
      40,    42,     4,     8,    50,     4,     6,     7,    12,    15,
      18,    30,    35,    36,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    66,    68,    69,     0,    65,    28,
      65,    68,     3,    67,    50,    50,    29,     4,     8,    55,
      60,    53,    30,     5,    70,    71,    60,    53,    44,    68,
      20,    21,    22,    23,    24,    25,    26,    27,    31,    32,
      33,    34,    11,    41,    68,    48,    41,    29,    43,    29,
       9,    51,    53,    29,     4,    13,    16,     5,    45,    30,
      70,    37,    56,    56,    57,    57,    57,    57,    57,    57,
      58,    58,    59,    59,     4,     8,    30,    34,    40,    51,
      50,    60,    29,    53,    38,    62,    30,    29,     4,    70,
      68,    19,    10,    60,    14,     3,     4,    32,    33,    34,
      39,    63,    64,    17,    66,    53,    29,    30,    41,    51,
      53,    10,    53,    40,     4,    39,     4,    39,     4,    39,
      40,    19,    63,    53,    67,    53,    41,    64,    32,    32,
      33,    33,    34,    34,    41,    64,    53,    41,    41,    62
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    47,    48,    48,    49,    49,    50,    50,
      51,    51,    52,    52,    52,    52,    53,    53,    53,    53,
      53,    54,    54,    55,    55,    55,    56,    56,    56,    56,
      56,    56,    56,    57,    57,    57,    58,    58,    58,    59,
      59,    60,    60,    60,    60,    61,    62,    62,    63,    63,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    65,    65,    66,    66,    66,    66,    66,    67,
      67,    68,    68,    68,    68,    69,    70,    70,    71,    71
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     3,     2,     4,     5,     2,     1,
       4,     1,     6,     7,     5,     6,     1,     1,     1,     5,
       1,     6,     1,     3,     3,     1,     3,     3,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     1,     1,
       2,     3,     3,     1,     1,     5,     5,     4,     2,     1,
       1,     4,     3,     4,     3,     3,     3,     3,     1,     3,
       3,     3,     2,     1,     7,     5,     4,     2,     3,     6,
       5,     2,     1,     2,     1,     2,     2,     1,     2,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 102 "parser.y" /* yacc.c:1646  */
    { printf("lel1.1\n");(yyval. ast ) = mk_forest(false, (yyvsp[-1]. ast ), (yyvsp[0]. ast )); }
#line 1363 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 103 "parser.y" /* yacc.c:1646  */
    { printf("lel1.2\n");(yyval. ast ) = (yyvsp[0]. ast ); emit((yyval. ast ), "sortie.html");}
#line 1369 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 110 "parser.y" /* yacc.c:1646  */
    { printf("lel2.1\n");(yyval. ast ) = mk_forest(false, (yyvsp[-2]. ast ), (yyvsp[0]. ast ));}
#line 1375 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 111 "parser.y" /* yacc.c:1646  */
    { printf("lel2.2\n");(yyval. ast ) = (yyvsp[-1]. ast ); }
#line 1381 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 115 "parser.y" /* yacc.c:1646  */
    { printf("lel3.1\n");ajouter_body((yyvsp[-2]. ast )->node->fun->body, (yyvsp[0]. ast )); (yyval. ast ) = (yyvsp[-2]. ast ); }
#line 1387 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 116 "parser.y" /* yacc.c:1646  */
    { printf("lel3.2\n");ajouter_body((yyvsp[-2]. ast )->node->fun->body, (yyvsp[0]. ast )); (yyval. ast ) = (yyvsp[-2]. ast ); }
#line 1393 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 120 "parser.y" /* yacc.c:1646  */
    { printf("lel4.1\n");(yyval. ast ) = mk_fun((yyvsp[-1]. name ), (yyvsp[0]. ast )); }
#line 1399 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 121 "parser.y" /* yacc.c:1646  */
    { printf("lel4.2\n");(yyval. ast ) = mk_fun((yyvsp[0]. name ), NULL); }
#line 1405 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 125 "parser.y" /* yacc.c:1646  */
    { printf("lel5.1\n");ajouter_body((yyvsp[-2]. ast )->node->fun->body, (yyvsp[0]. ast )); (yyval. ast ) = (yyvsp[-2]. ast ); }
#line 1411 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 126 "parser.y" /* yacc.c:1646  */
    { printf("lel5.2\n");(yyval. ast ) = (yyvsp[0]. ast ); }
#line 1417 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 130 "parser.y" /* yacc.c:1646  */
    { printf("lel6.1\n");(yyval. ast ) = mk_app(mk_fun((yyvsp[-4]. name ), (yyvsp[0]. ast )), (yyvsp[-2]. ast )); }
#line 1423 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 131 "parser.y" /* yacc.c:1646  */
    { printf("lel6.2\n");(yyval. ast ) = mk_app(mk_fun((yyvsp[-4]. name ), (yyvsp[0]. ast )), mk_declrec((yyvsp[-4]. name ), (yyvsp[-2]. ast ))); }
#line 1429 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 132 "parser.y" /* yacc.c:1646  */
    { printf("lel6.3\n");(yyval. ast ) = mk_app(mk_fun((yyvsp[-2]. name ), (yyvsp[-4]. ast )), (yyvsp[0]. ast )); }
#line 1435 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 133 "parser.y" /* yacc.c:1646  */
    { printf("lel6.4\n");(yyval. ast ) = mk_app(mk_fun((yyvsp[-2]. name ), (yyvsp[-5]. ast )), mk_declrec((yyvsp[-2]. name ), (yyvsp[0]. ast ))); }
#line 1441 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 140 "parser.y" /* yacc.c:1646  */
    { printf("lel7.1\n");(yyval. ast ) = (yyvsp[0]. ast ); }
#line 1447 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 141 "parser.y" /* yacc.c:1646  */
    { printf("lel7.2\n");(yyval. ast ) = (yyvsp[0]. ast ); }
#line 1453 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 142 "parser.y" /* yacc.c:1646  */
    { printf("lel7.3\n");(yyval. ast ) = (yyvsp[0]. ast ); }
#line 1459 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 143 "parser.y" /* yacc.c:1646  */
    { printf("lel7.4\n");emit((yyvsp[0]. ast ), (yyvsp[-2]. name )); }
#line 1465 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 144 "parser.y" /* yacc.c:1646  */
    { printf("lel7.5\n");(yyval. ast ) = mk_var((yyvsp[0]. name )); }
#line 1471 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 148 "parser.y" /* yacc.c:1646  */
    { printf("lel8.1\n");(yyval. ast ) = mk_cond((yyvsp[-4]. ast ), (yyvsp[-2]. ast ), (yyvsp[0]. ast )); }
#line 1477 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 149 "parser.y" /* yacc.c:1646  */
    { printf("lel8.2\n");(yyval. ast ) = (yyvsp[0]. ast ); }
#line 1483 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 153 "parser.y" /* yacc.c:1646  */
    { printf("lel9.1\n");(yyval. ast ) = mk_app(mk_app(mk_binop(OR), (yyvsp[-2]. ast )), (yyvsp[0]. ast )); }
#line 1489 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 154 "parser.y" /* yacc.c:1646  */
    { printf("lel9.2\n");(yyval. ast ) = mk_app(mk_app(mk_binop(AND), (yyvsp[-2]. ast )), (yyvsp[0]. ast )); }
#line 1495 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 155 "parser.y" /* yacc.c:1646  */
    { printf("lel9.3\n");(yyval. ast ) = (yyvsp[0]. ast ); }
#line 1501 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 159 "parser.y" /* yacc.c:1646  */
    { printf("lel10.1\n");(yyval. ast ) = mk_app(mk_app(mk_binop(LE), (yyvsp[-2]. ast )), (yyvsp[0]. ast )); }
#line 1507 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 160 "parser.y" /* yacc.c:1646  */
    { printf("lel10.2\n");(yyval. ast ) = mk_app(mk_app(mk_binop(LEQ), (yyvsp[-2]. ast )), (yyvsp[0]. ast )); }
#line 1513 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 161 "parser.y" /* yacc.c:1646  */
    { printf("lel10.3\n");(yyval. ast ) = mk_app(mk_app(mk_binop(GE), (yyvsp[-2]. ast )), (yyvsp[0]. ast )); }
#line 1519 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 162 "parser.y" /* yacc.c:1646  */
    { printf("lel10.4\n");(yyval. ast ) = mk_app(mk_app(mk_binop(GEQ), (yyvsp[-2]. ast )), (yyvsp[0]. ast )); }
#line 1525 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 163 "parser.y" /* yacc.c:1646  */
    { printf("lel10.5\n");(yyval. ast ) = mk_app(mk_app(mk_binop(EQ), (yyvsp[-2]. ast )), (yyvsp[0]. ast )); }
#line 1531 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 164 "parser.y" /* yacc.c:1646  */
    { printf("lel10.6\n");(yyval. ast ) = mk_app(mk_app(mk_binop(NEQ), (yyvsp[-2]. ast )), (yyvsp[0]. ast )); }
#line 1537 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 165 "parser.y" /* yacc.c:1646  */
    { printf("lel10.7\n");(yyval. ast ) = (yyvsp[0]. ast ); }
#line 1543 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 169 "parser.y" /* yacc.c:1646  */
    { printf("lel11.1\n");(yyval. ast ) = mk_app(mk_app(mk_binop(PLUS), (yyvsp[-2]. ast )), (yyvsp[0]. ast )); }
#line 1549 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 170 "parser.y" /* yacc.c:1646  */
    { printf("lel11.2\n");(yyval. ast ) = mk_app(mk_app(mk_binop(MINUS), (yyvsp[-2]. ast )), (yyvsp[0]. ast )); }
#line 1555 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 171 "parser.y" /* yacc.c:1646  */
    { printf("lel11.3\n");(yyval. ast ) = (yyvsp[0]. ast ); }
#line 1561 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 175 "parser.y" /* yacc.c:1646  */
    { printf("lel12.1\n");(yyval. ast ) = mk_app(mk_app(mk_binop(MULT), (yyvsp[-2]. ast )), (yyvsp[0]. ast )); }
#line 1567 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 176 "parser.y" /* yacc.c:1646  */
    { printf("lel12.2\n");(yyval. ast ) = mk_app(mk_app(mk_binop(DIV), (yyvsp[-2]. ast )), (yyvsp[0]. ast )); }
#line 1573 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 177 "parser.y" /* yacc.c:1646  */
    { printf("lel12.3\n");(yyval. ast ) = (yyvsp[0]. ast ); }
#line 1579 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 181 "parser.y" /* yacc.c:1646  */
    { printf("lel13.1\n");(yyval. ast ) = (yyvsp[0]. ast ); }
#line 1585 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 182 "parser.y" /* yacc.c:1646  */
    { printf("lel13.2\n");(yyval. ast ) = mk_app(mk_unaryop(NOT), (yyvsp[0]. ast ));; }
#line 1591 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 186 "parser.y" /* yacc.c:1646  */
    { printf("lel14.1\n");(yyval. ast ) = (yyvsp[-1]. ast ); }
#line 1597 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 187 "parser.y" /* yacc.c:1646  */
    { printf("lel14.2\n");(yyval. ast ) = (yyvsp[-1]. ast ); }
#line 1603 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 188 "parser.y" /* yacc.c:1646  */
    { printf("lel14.3\n");(yyval. ast ) = (yyvsp[0]. ast ); }
#line 1609 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 189 "parser.y" /* yacc.c:1646  */
    { printf("lel14.4\n");(yyval. ast ) = mk_integer((yyvsp[0]. value )); }
#line 1615 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 193 "parser.y" /* yacc.c:1646  */
    { printf("lel15.1\n");(yyval. ast ) = mk_match((yyvsp[-3]. ast ), (yyvsp[-1]. patterns )); }
#line 1621 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 197 "parser.y" /* yacc.c:1646  */
    { printf("lel16.1\n");(yyval. patterns ) = mk_patterns((yyvsp[-3]. pattern ), (yyvsp[-1]. ast ), (yyvsp[0]. patterns )); }
#line 1627 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 198 "parser.y" /* yacc.c:1646  */
    { printf("lel16.2\n");(yyval. patterns ) = mk_patterns((yyvsp[-2]. pattern ), (yyvsp[0]. ast ), NULL); }
#line 1633 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 202 "parser.y" /* yacc.c:1646  */
    { printf("lel17.1\n");(yyval. pattern ) = mk_pforest((yyvsp[-1]. pattern ), (yyvsp[0]. pattern )); }
#line 1639 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 203 "parser.y" /* yacc.c:1646  */
    { printf("lel17.2\n");(yyval. pattern ) = (yyvsp[0]. pattern ); }
#line 1645 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 207 "parser.y" /* yacc.c:1646  */
    { printf("lel18.1\n");(yyval. pattern ) = mk_wildcard(ANY); }
#line 1651 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 208 "parser.y" /* yacc.c:1646  */
    { printf("lel18.2\n");(yyval. pattern ) = mk_ptree((yyvsp[-3]. name ), false, (yyvsp[-1]. pattern )); }
#line 1657 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 209 "parser.y" /* yacc.c:1646  */
    { printf("lel18.3\n");(yyval. pattern ) = mk_ptree((yyvsp[-2]. name ), true, NULL); }
#line 1663 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 210 "parser.y" /* yacc.c:1646  */
    { printf("lel18.4\n");(yyval. pattern ) = mk_anytree(false, (yyvsp[-1]. pattern )); }
#line 1669 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 211 "parser.y" /* yacc.c:1646  */
    { printf("lel18.5\n");(yyval. pattern ) = mk_anytree(true, NULL); }
#line 1675 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 212 "parser.y" /* yacc.c:1646  */
    { printf("lel18.6\n");(yyval. pattern ) = mk_wildcard(ANYSTRING); }
#line 1681 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 213 "parser.y" /* yacc.c:1646  */
    { printf("lel18.7\n");(yyval. pattern ) = mk_wildcard(ANYFOREST); }
#line 1687 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 214 "parser.y" /* yacc.c:1646  */
    { printf("lel18.8\n");(yyval. pattern ) = mk_wildcard(ANYSEQ); }
#line 1693 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 215 "parser.y" /* yacc.c:1646  */
    { printf("lel18.9\n");(yyval. pattern ) = mk_pattern_var((yyvsp[0]. name ), TREEVAR); }
#line 1699 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 216 "parser.y" /* yacc.c:1646  */
    { printf("lel18.10\n");(yyval. pattern ) = mk_pattern_var((yyvsp[-1]. name ), STRINGVAR); }
#line 1705 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 217 "parser.y" /* yacc.c:1646  */
    { printf("lel18.11\n");(yyval. pattern ) = mk_pattern_var((yyvsp[-1]. name ), FORESTVAR); }
#line 1711 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 218 "parser.y" /* yacc.c:1646  */
    { printf("lel18.12\n");(yyval. pattern ) = mk_pattern_var((yyvsp[-1]. name ), ANYVAR); }
#line 1717 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 225 "parser.y" /* yacc.c:1646  */
    { printf("lel19.1\n");(yyval. ast ) = mk_forest(false, (yyvsp[-1]. ast ), (yyvsp[0]. ast )); }
#line 1723 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 227 "parser.y" /* yacc.c:1646  */
    { printf("lel19.2\n");(yyval. ast ) = (yyvsp[0]. ast ); }
#line 1729 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 236 "parser.y" /* yacc.c:1646  */
    { printf("lel20.1\n");(yyval. ast ) = mk_tree((yyvsp[-6]. name ), true, false, false, (yyvsp[-4]. attributes ), (yyvsp[-1]. ast )); }
#line 1735 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 237 "parser.y" /* yacc.c:1646  */
    { printf("lel20.2\n");(yyval. ast ) = mk_tree((yyvsp[-4]. name ), true, true, false, (yyvsp[-2]. attributes ), NULL); }
#line 1741 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 238 "parser.y" /* yacc.c:1646  */
    { printf("lel20.3\n");(yyval. ast ) = mk_tree((yyvsp[-3]. name ), true, false, false, NULL, (yyvsp[-1]. ast )); }
#line 1747 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 239 "parser.y" /* yacc.c:1646  */
    { printf("lel20.4\n");(yyval. ast ) = mk_tree((yyvsp[-1]. name ), true, true, false, NULL, NULL); }
#line 1753 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 240 "parser.y" /* yacc.c:1646  */
    { printf("lel20.5\n");(yyval. ast ) = (yyvsp[-1]. ast ); }
#line 1759 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 244 "parser.y" /* yacc.c:1646  */
    { printf("lel21.1 %s\n", (yyvsp[-5]. name ));(yyval. attributes ) = mk_attributes(mk_var((yyvsp[-5]. name )), (yyvsp[-2]. ast ), (yyvsp[0]. attributes )); }
#line 1765 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 245 "parser.y" /* yacc.c:1646  */
    { printf("lel21.2 %s\n", (yyvsp[-4]. name ));(yyval. attributes ) = mk_attributes(mk_var((yyvsp[-4]. name )), (yyvsp[-1]. ast ), NULL);}
#line 1771 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 249 "parser.y" /* yacc.c:1646  */
    { printf("lel22.1\n");(yyval. ast ) = mk_forest(false, (yyvsp[-1]. ast ), (yyvsp[0]. ast )); }
#line 1777 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 250 "parser.y" /* yacc.c:1646  */
    { printf("lel22.2\n");(yyval. ast ) = (yyvsp[0]. ast ); }
#line 1783 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 251 "parser.y" /* yacc.c:1646  */
    { printf("lel22.3\n");(yyval. ast ) = mk_forest(false, (yyvsp[-1]. ast ), (yyvsp[0]. ast )); }
#line 1789 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 252 "parser.y" /* yacc.c:1646  */
    { printf("lel22.3\n");(yyval. ast ) = (yyvsp[0]. ast ); }
#line 1795 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 258 "parser.y" /* yacc.c:1646  */
    { printf("lel23.1\n");(yyval. ast ) = (yyvsp[-1]. ast ); }
#line 1801 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 262 "parser.y" /* yacc.c:1646  */
    { printf("lel24.1\n");(yyval. ast ) = mk_forest(false, (yyvsp[-1]. ast ), (yyvsp[0]. ast )); }
#line 1807 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 263 "parser.y" /* yacc.c:1646  */
    { printf("lel24.2\n");(yyval. ast ) = (yyvsp[0]. ast ); }
#line 1813 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 267 "parser.y" /* yacc.c:1646  */
    { printf("lel25.1 %s\n", (yyvsp[-1]. name ));(yyval. ast ) = mk_tree("text", false, false, true, NULL, mk_word((yyvsp[-1]. name ))); }
#line 1819 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 268 "parser.y" /* yacc.c:1646  */
    { printf("lel25.2 %s\n", (yyvsp[0]. name ));(yyval. ast ) = mk_tree("text", false, false, false, NULL, mk_word((yyvsp[0]. name ))); }
#line 1825 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 1829 "parser.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 270 "parser.y" /* yacc.c:1906  */

