/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 5 "calc.y"

  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <math.h>
  #include "calc.h"
  extern FILE *yyin;
  int yylex(void);
  void yyerror(const char *);
  FILE *llvm_out;

  int temp_var_count = 0;
  int get_temp_var_count() {
    return temp_var_count++;
  }

  // Aloca nova string para nome temporário (ex: %t0, %t1, ...)
  char *new_temp() {
    char buffer[32];
    snprintf(buffer, sizeof(buffer), "%%t%d", get_temp_var_count());
    return strdup(buffer);  // aloca nova string para evitar sobrescrever
  }

#line 95 "calc.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "calc.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUM = 3,                        /* NUM  */
  YYSYMBOL_PLUS = 4,                       /* PLUS  */
  YYSYMBOL_MINUS = 5,                      /* MINUS  */
  YYSYMBOL_MULTIPLY = 6,                   /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 7,                     /* DIVIDE  */
  YYSYMBOL_ASSIGN = 8,                     /* ASSIGN  */
  YYSYMBOL_IF = 9,                         /* IF  */
  YYSYMBOL_THEN = 10,                      /* THEN  */
  YYSYMBOL_ELSE = 11,                      /* ELSE  */
  YYSYMBOL_EQUAL = 12,                     /* EQUAL  */
  YYSYMBOL_LESS = 13,                      /* LESS  */
  YYSYMBOL_GREATER = 14,                   /* GREATER  */
  YYSYMBOL_LESS_EQUAL = 15,                /* LESS_EQUAL  */
  YYSYMBOL_NOT_EQUAL = 16,                 /* NOT_EQUAL  */
  YYSYMBOL_GREATER_EQUAL = 17,             /* GREATER_EQUAL  */
  YYSYMBOL_AND = 18,                       /* AND  */
  YYSYMBOL_OR = 19,                        /* OR  */
  YYSYMBOL_NOT = 20,                       /* NOT  */
  YYSYMBOL_OPEN_BRACKETS = 21,             /* OPEN_BRACKETS  */
  YYSYMBOL_CLOSE_BRACKETS = 22,            /* CLOSE_BRACKETS  */
  YYSYMBOL_OPEN_PARENTHESIS = 23,          /* OPEN_PARENTHESIS  */
  YYSYMBOL_CLOSE_PARENTHESIS = 24,         /* CLOSE_PARENTHESIS  */
  YYSYMBOL_TRUEbool = 25,                  /* TRUEbool  */
  YYSYMBOL_FALSEbool = 26,                 /* FALSEbool  */
  YYSYMBOL_NEWLINE = 27,                   /* NEWLINE  */
  YYSYMBOL_QUIT = 28,                      /* QUIT  */
  YYSYMBOL_INT = 29,                       /* INT  */
  YYSYMBOL_FLOAT = 30,                     /* FLOAT  */
  YYSYMBOL_BOOL = 31,                      /* BOOL  */
  YYSYMBOL_READ = 32,                      /* READ  */
  YYSYMBOL_WRITE = 33,                     /* WRITE  */
  YYSYMBOL_END = 34,                       /* END  */
  YYSYMBOL_ID = 35,                        /* ID  */
  YYSYMBOL_YYACCEPT = 36,                  /* $accept  */
  YYSYMBOL_program = 37,                   /* program  */
  YYSYMBOL_lines = 38,                     /* lines  */
  YYSYMBOL_line = 39,                      /* line  */
  YYSYMBOL_declarations = 40,              /* declarations  */
  YYSYMBOL_declaration = 41,               /* declaration  */
  YYSYMBOL_commands = 42,                  /* commands  */
  YYSYMBOL_command = 43,                   /* command  */
  YYSYMBOL_block = 44,                     /* block  */
  YYSYMBOL_block_element = 45,             /* block_element  */
  YYSYMBOL_read_command = 46,              /* read_command  */
  YYSYMBOL_write_command = 47,             /* write_command  */
  YYSYMBOL_assignments = 48,               /* assignments  */
  YYSYMBOL_assignment = 49,                /* assignment  */
  YYSYMBOL_expression = 50,                /* expression  */
  YYSYMBOL_term = 51,                      /* term  */
  YYSYMBOL_factor = 52,                    /* factor  */
  YYSYMBOL_boolean_expression = 53,        /* boolean_expression  */
  YYSYMBOL_if_command = 54                 /* if_command  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  29
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   126

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  50
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  96

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   290


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    53,    53,    54,    60,    61,    65,    66,    70,    71,
      75,    76,    77,    81,    82,    86,    87,    88,    89,    92,
      93,    94,    98,    99,   102,   135,   148,   152,   175,   186,
     187,   215,   246,   247,   275,   306,   315,   337,   343,   349,
     355,   363,   374,   385,   396,   407,   418,   429,   437,   448,
     475
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUM", "PLUS", "MINUS",
  "MULTIPLY", "DIVIDE", "ASSIGN", "IF", "THEN", "ELSE", "EQUAL", "LESS",
  "GREATER", "LESS_EQUAL", "NOT_EQUAL", "GREATER_EQUAL", "AND", "OR",
  "NOT", "OPEN_BRACKETS", "CLOSE_BRACKETS", "OPEN_PARENTHESIS",
  "CLOSE_PARENTHESIS", "TRUEbool", "FALSEbool", "NEWLINE", "QUIT", "INT",
  "FLOAT", "BOOL", "READ", "WRITE", "END", "ID", "$accept", "program",
  "lines", "line", "declarations", "declaration", "commands", "command",
  "block", "block_element", "read_command", "write_command", "assignments",
  "assignment", "expression", "term", "factor", "boolean_expression",
  "if_command", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-84)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      35,    -2,    20,    -8,    14,    40,    60,    64,    81,    90,
      72,   -84,    30,   -84,    79,   -84,    65,    66,   -84,   -84,
     -84,     5,   -84,    76,    88,    89,    61,     6,     5,   -84,
     -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,     5,     6,
     -84,   -84,   -84,   104,    10,   -84,    -4,   -84,   -84,   -84,
      74,    -1,    38,     0,   -84,     2,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     5,     5,    92,   -84,
     -84,   -84,   -84,    10,    10,    41,    41,    41,    41,    41,
      41,   -84,   -84,   -84,   -84,    72,   -84,   -84,    47,   -84,
     113,   -84,    94,    72,    62,   -84
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       2,     4,     0,     8,     0,    13,     0,     0,    16,    26,
      15,     0,     3,     0,     0,     0,     0,     0,     0,     1,
       5,     6,     9,     7,    14,    17,    18,    35,     0,     0,
      38,    39,    36,     0,    29,    32,     0,    10,    11,    12,
       0,     0,     0,    28,    40,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    24,
      25,    27,    37,    30,    31,    41,    43,    44,    45,    42,
      46,    33,    34,    47,    48,    19,    22,    23,     0,    20,
      50,    21,     0,    19,     0,    49
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -84,   -84,   -84,   115,   -84,    12,   -84,    48,    33,   -83,
     -84,   -84,   -84,   -84,   -26,    17,    21,   -28,   -84
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     9,    10,    11,    12,    86,    14,    87,    88,    89,
      16,    17,    18,    19,    43,    44,    45,    46,    20
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      53,    51,    52,    56,    57,    91,    56,    57,    37,    37,
      54,    91,    13,    55,    66,    67,    64,    65,    66,    67,
      68,    21,    13,    70,    32,    38,    72,    23,    39,    39,
      40,    41,    75,    76,    77,    78,    79,    80,    83,    84,
      42,    42,    56,    57,     1,    56,    57,    22,    15,    24,
      58,    59,    60,    61,    62,    63,     1,    31,    15,     3,
       4,     5,    34,     2,     3,     4,     5,     6,     7,    90,
       8,     1,    71,    73,    74,    25,     3,     4,     5,     6,
       7,     1,     8,    26,    95,    81,    82,    27,     1,    28,
      29,     3,     4,     5,     6,     7,    50,     8,    69,    35,
      36,     3,     4,     5,     6,     7,    33,     8,    56,    57,
      47,     6,     7,    85,     8,    93,    58,    59,    60,    61,
      62,    63,    48,    49,    92,    30,    94
};

static const yytype_int8 yycheck[] =
{
      28,    27,    28,     4,     5,    88,     4,     5,     3,     3,
      38,    94,     0,    39,    18,    19,     6,     7,    18,    19,
      24,    23,    10,    24,    12,    20,    24,    35,    23,    23,
      25,    26,    58,    59,    60,    61,    62,    63,    66,    67,
      35,    35,     4,     5,     9,     4,     5,    27,     0,    35,
      12,    13,    14,    15,    16,    17,     9,    27,    10,    29,
      30,    31,    14,    28,    29,    30,    31,    32,    33,    22,
      35,     9,    34,    56,    57,    35,    29,    30,    31,    32,
      33,     9,    35,    23,    22,    64,    65,    23,     9,     8,
       0,    29,    30,    31,    32,    33,    35,    35,    24,    34,
      34,    29,    30,    31,    32,    33,    27,    35,     4,     5,
      34,    32,    33,    21,    35,    21,    12,    13,    14,    15,
      16,    17,    34,    34,    11,    10,    93
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     9,    28,    29,    30,    31,    32,    33,    35,    37,
      38,    39,    40,    41,    42,    43,    46,    47,    48,    49,
      54,    23,    27,    35,    35,    35,    23,    23,     8,     0,
      39,    27,    41,    27,    43,    34,    34,     3,    20,    23,
      25,    26,    35,    50,    51,    52,    53,    34,    34,    34,
      35,    50,    50,    53,    53,    50,     4,     5,    12,    13,
      14,    15,    16,    17,     6,     7,    18,    19,    24,    24,
      24,    34,    24,    51,    51,    50,    50,    50,    50,    50,
      50,    52,    52,    53,    53,    21,    41,    43,    44,    45,
      22,    45,    11,    21,    44,    22
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    36,    37,    37,    38,    38,    39,    39,    40,    40,
      41,    41,    41,    42,    42,    43,    43,    43,    43,    44,
      44,    44,    45,    45,    46,    47,    48,    49,    49,    50,
      50,    50,    51,    51,    51,    52,    52,    52,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    54,
      54
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     2,     2,     1,     2,
       3,     3,     3,     1,     2,     1,     1,     2,     2,     0,
       1,     2,     1,     1,     4,     4,     1,     4,     3,     1,
       3,     3,     1,     3,     3,     1,     1,     3,     1,     1,
       2,     3,     3,     3,     3,     3,     3,     3,     3,    11,
       7
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 3: /* program: QUIT NEWLINE  */
#line 54 "calc.y"
                   { 
        exit(0);
    }
#line 1204 "calc.tab.c"
    break;

  case 10: /* declaration: INT ID END  */
#line 75 "calc.y"
                   { add_symbol((yyvsp[-1].ID), INT_VAR, llvm_out); }
#line 1210 "calc.tab.c"
    break;

  case 11: /* declaration: FLOAT ID END  */
#line 76 "calc.y"
                   { add_symbol((yyvsp[-1].ID), FLOAT_VAR, llvm_out); }
#line 1216 "calc.tab.c"
    break;

  case 12: /* declaration: BOOL ID END  */
#line 77 "calc.y"
                   { add_symbol((yyvsp[-1].ID), BOOL_VAR, llvm_out); }
#line 1222 "calc.tab.c"
    break;

  case 19: /* block: %empty  */
#line 92 "calc.y"
    { /* bloco vazio */ }
#line 1228 "calc.tab.c"
    break;

  case 24: /* read_command: READ OPEN_PARENTHESIS ID CLOSE_PARENTHESIS  */
#line 102 "calc.y"
                                               { 
        switch (get_variable_type((yyvsp[-1].ID))) {
            case INT_VAR: {
                int auxInt;
                printf("Enter an integer: ");
                scanf("%d", &auxInt);
                while (getchar() != '\n'); // limpar buffer
                set_int_value((yyvsp[-1].ID), auxInt, llvm_out);
                break;
            }
            case FLOAT_VAR: {
                float auxFloat;
                printf("Enter a float: ");
                scanf("%f", &auxFloat);
                while (getchar() != '\n'); // limpar buffer
                set_float_value((yyvsp[-1].ID), auxFloat, llvm_out);
                break;
            }
            case BOOL_VAR: {
                int auxBool;
                printf("Enter a boolean (0 or 1): ");
                scanf("%d", &auxBool);
                while (getchar() != '\n'); // limpar buffer
                set_bool_value((yyvsp[-1].ID), auxBool, llvm_out);
                break;
            }
            default:
                break;
        }
    }
#line 1263 "calc.tab.c"
    break;

  case 25: /* write_command: WRITE OPEN_PARENTHESIS expression CLOSE_PARENTHESIS  */
#line 135 "calc.y"
                                                        { 
        // Exemplo simples para imprimir float, adaptar para tipo
        if ((yyvsp[-1].expression)->type == FLOAT_VAR)
            printf("%f\n", atof((yyvsp[-1].expression)->name));
        else if ((yyvsp[-1].expression)->type == INT_VAR)
            printf("%d\n", atoi((yyvsp[-1].expression)->name));
        else if ((yyvsp[-1].expression)->type == BOOL_VAR)
            printf("%d\n", atoi((yyvsp[-1].expression)->name));
        free_llvm_val((yyvsp[-1].expression));
    }
#line 1278 "calc.tab.c"
    break;

  case 27: /* assignment: ID ASSIGN expression END  */
#line 152 "calc.y"
                             {
        int var_type = get_variable_type((yyvsp[-3].ID));
        int expr_type = (yyvsp[-1].expression)->type;
        
        if (var_type != expr_type) {
            fprintf(stderr, "Erro de tipo na atribuição: variável '%s' do tipo %d, expressão do tipo %d\n", (yyvsp[-3].ID), var_type, expr_type);
            YYABORT;
        } else {
            switch (var_type) {
                case INT_VAR:
                    // Aloca um inteiro (caso não alocado antes) e armazena valor
                    fprintf(llvm_out, "store i32 %s, i32* %s\n", (yyvsp[-1].expression)->name, (yyvsp[-3].ID));
                    break;
                case FLOAT_VAR:
                    fprintf(llvm_out, "store float %s, float* %s\n", (yyvsp[-1].expression)->name, (yyvsp[-3].ID));
                    break;
                default:
                    fprintf(stderr, "Tipo desconhecido para variável '%s'\n", (yyvsp[-3].ID));
                    YYABORT;
            }
        }
        free_llvm_val((yyvsp[-1].expression));
    }
#line 1306 "calc.tab.c"
    break;

  case 28: /* assignment: ID ASSIGN boolean_expression  */
#line 175 "calc.y"
                                   {
        if (get_variable_type((yyvsp[-2].ID)) != BOOL_VAR) {
            fprintf(stderr, "Erro de tipo na atribuição: variável '%s' não é do tipo booleano\n", (yyvsp[-2].ID));
            YYABORT;
        } else {
            fprintf(llvm_out, "store i1 %s, i1* %s\n", (yyvsp[0].boolean_expression)->name, (yyvsp[-2].ID));
        }
    }
#line 1319 "calc.tab.c"
    break;

  case 29: /* expression: term  */
#line 186 "calc.y"
         { (yyval.expression) = (yyvsp[0].term); }
#line 1325 "calc.tab.c"
    break;

  case 30: /* expression: expression PLUS term  */
#line 187 "calc.y"
                         {
        llvm_val *res = malloc(sizeof(llvm_val));
		if (((yyvsp[-2].expression)->type != FLOAT_VAR && (yyvsp[-2].expression)->type != INT_VAR) || ((yyvsp[0].term)->type != FLOAT_VAR && (yyvsp[0].term)->type != INT_VAR)) {
			fprintf(stderr, "Error: Que conta é essa?\n");
			exit(1);
		}
		if ((yyvsp[-2].expression)->type == FLOAT_VAR || (yyvsp[0].term)->type == FLOAT_VAR) {
			res->type = FLOAT_VAR; // se um dos operandos for float, o resultado é float
		}
		else {
			res->type = INT_VAR;
		}

        res->name = new_temp();

        if (res->type == INT_VAR) {
            fprintf(llvm_out, "  %s = add i32 %s, %s\n", res->name, (yyvsp[-2].expression)->name, (yyvsp[0].term)->name);
        } else if (res->type == FLOAT_VAR) {
            fprintf(llvm_out, "  %s = fadd float %s, %s\n", res->name, (yyvsp[-2].expression)->name, (yyvsp[0].term)->name);
        } else {
            // erro de tipo, tratar
        }

        free_llvm_val((yyvsp[-2].expression));
        free_llvm_val((yyvsp[0].term));

        (yyval.expression) = res;
    }
#line 1358 "calc.tab.c"
    break;

  case 31: /* expression: expression MINUS term  */
#line 215 "calc.y"
                          {
        llvm_val *res = malloc(sizeof(llvm_val));
		if (((yyvsp[-2].expression)->type != FLOAT_VAR && (yyvsp[-2].expression)->type != INT_VAR) || ((yyvsp[0].term)->type != FLOAT_VAR && (yyvsp[0].term)->type != INT_VAR)) {
			fprintf(stderr, "Error: Que conta é essa?\n");
			exit(1);
		}
		if ((yyvsp[-2].expression)->type == FLOAT_VAR || (yyvsp[0].term)->type == FLOAT_VAR) {
			res->type = FLOAT_VAR; // se um dos operandos for float, o resultado é float
		}
		else {
			res->type = INT_VAR;
		}

        res->name = new_temp();

        if (res->type == INT_VAR) {
            fprintf(llvm_out, "  %s = sub i32 %s, %s\n", res->name, (yyvsp[-2].expression)->name, (yyvsp[0].term)->name);
        } else if (res->type == FLOAT_VAR) {
            fprintf(llvm_out, "  %s = fsub float %s, %s\n", res->name, (yyvsp[-2].expression)->name, (yyvsp[0].term)->name);
        } else {
            // erro de tipo, tratar
        }

        free_llvm_val((yyvsp[-2].expression));
        free_llvm_val((yyvsp[0].term));

        (yyval.expression) = res;
    }
#line 1391 "calc.tab.c"
    break;

  case 32: /* term: factor  */
#line 246 "calc.y"
           { (yyval.term) = (yyvsp[0].factor); }
#line 1397 "calc.tab.c"
    break;

  case 33: /* term: term MULTIPLY factor  */
#line 247 "calc.y"
                         {
        llvm_val *res = malloc(sizeof(llvm_val));
		if (((yyvsp[-2].term)->type != FLOAT_VAR && (yyvsp[-2].term)->type != INT_VAR) || ((yyvsp[0].factor)->type != FLOAT_VAR && (yyvsp[0].factor)->type != INT_VAR)) {
			fprintf(stderr, "Error: Que conta é essa?\n");
			exit(1);
		}
		if ((yyvsp[-2].term)->type == FLOAT_VAR || (yyvsp[0].factor)->type == FLOAT_VAR) {
			res->type = FLOAT_VAR; // se um dos operandos for float, o resultado é float
		}
		else {
			res->type = INT_VAR;
		}

        res->name = new_temp();

        if (res->type == INT_VAR) {
            fprintf(llvm_out, "  %s = mul i32 %s, %s\n", res->name, (yyvsp[-2].term)->name, (yyvsp[0].factor)->name);
        } else if (res->type == FLOAT_VAR) {
            fprintf(llvm_out, "  %s = fmul float %s, %s\n", res->name, (yyvsp[-2].term)->name, (yyvsp[0].factor)->name);
        } else {
            // erro de tipo, tratar
        }

        free_llvm_val((yyvsp[-2].term));
        free_llvm_val((yyvsp[0].factor));

        (yyval.term) = res;
    }
#line 1430 "calc.tab.c"
    break;

  case 34: /* term: term DIVIDE factor  */
#line 275 "calc.y"
                       {
        llvm_val *res = malloc(sizeof(llvm_val));
		if (((yyvsp[-2].term)->type != FLOAT_VAR && (yyvsp[-2].term)->type != INT_VAR) || ((yyvsp[0].factor)->type != FLOAT_VAR && (yyvsp[0].factor)->type != INT_VAR)) {
			fprintf(stderr, "Error: Que conta é essa?\n");
			exit(1);
		}
		if ((yyvsp[-2].term)->type == FLOAT_VAR || (yyvsp[0].factor)->type == FLOAT_VAR) {
			res->type = FLOAT_VAR; // se um dos operandos for float, o resultado é float
		}
		else {
			res->type = INT_VAR;
		}

        res->name = new_temp();

        if (res->type == INT_VAR) {
            fprintf(llvm_out, "  %s = sdiv i32 %s, %s\n", res->name, (yyvsp[-2].term)->name, (yyvsp[0].factor)->name);
        } else if (res->type == FLOAT_VAR) {
            fprintf(llvm_out, "  %s = fdiv float %s, %s\n", res->name, (yyvsp[-2].term)->name, (yyvsp[0].factor)->name);
        } else {
            // erro de tipo, tratar
        }

        free_llvm_val((yyvsp[-2].term));
        free_llvm_val((yyvsp[0].factor));

        (yyval.term) = res;
    }
#line 1463 "calc.tab.c"
    break;

  case 35: /* factor: NUM  */
#line 306 "calc.y"
        {
        llvm_val *res = malloc(sizeof(llvm_val));
        res->type = FLOAT_VAR; 

        res->name = malloc(32);
        snprintf(res->name, 32, "%f", (yyvsp[0].NUM));

        (yyval.factor) = res;
    }
#line 1477 "calc.tab.c"
    break;

  case 36: /* factor: ID  */
#line 315 "calc.y"
       {
        llvm_val *res = malloc(sizeof(llvm_val));
        res->type = get_variable_type((yyvsp[0].ID));
        res->name = new_temp();

        switch (res->type) {
            case INT_VAR:
                fprintf(llvm_out, "  %s = load i32, i32* %%%s\n", res->name, (yyvsp[0].ID));
                break;
            case FLOAT_VAR:
                fprintf(llvm_out, "  %s = load float, float* %%%s\n", res->name, (yyvsp[0].ID));
                break;
            case BOOL_VAR:
                fprintf(llvm_out, "  %s = load i1, i1* %%%s\n", res->name, (yyvsp[0].ID));
                break;
            default:
                // erro: variável não encontrada
                break;
        }

        (yyval.factor) = res;
    }
#line 1504 "calc.tab.c"
    break;

  case 37: /* factor: OPEN_PARENTHESIS expression CLOSE_PARENTHESIS  */
#line 337 "calc.y"
                                                  {
        (yyval.factor) = (yyvsp[-1].expression);
    }
#line 1512 "calc.tab.c"
    break;

  case 38: /* boolean_expression: TRUEbool  */
#line 343 "calc.y"
             {
        llvm_val *res = malloc(sizeof(llvm_val));
        res->type = BOOL_VAR;
        res->name = strdup("true");
        (yyval.boolean_expression) = res;
    }
#line 1523 "calc.tab.c"
    break;

  case 39: /* boolean_expression: FALSEbool  */
#line 349 "calc.y"
              {
        llvm_val *res = malloc(sizeof(llvm_val));
        res->type = BOOL_VAR;
        res->name = strdup("false");
        (yyval.boolean_expression) = res;
    }
#line 1534 "calc.tab.c"
    break;

  case 40: /* boolean_expression: NOT boolean_expression  */
#line 355 "calc.y"
                           {
        llvm_val *res = malloc(sizeof(llvm_val));
        res->type = BOOL_VAR;
        res->name = new_temp();
        fprintf(llvm_out, "  %s = xor i1 %s, true\n", res->name, (yyvsp[0].boolean_expression)->name);
        free_llvm_val((yyvsp[0].boolean_expression));
        (yyval.boolean_expression) = res;
    }
#line 1547 "calc.tab.c"
    break;

  case 41: /* boolean_expression: expression EQUAL expression  */
#line 363 "calc.y"
                                {
        llvm_val *res = malloc(sizeof(llvm_val));
        res->type = BOOL_VAR;
        res->name = new_temp();
        if ((yyvsp[-2].expression)->type == FLOAT_VAR || (yyvsp[0].expression)->type == FLOAT_VAR)
            fprintf(llvm_out, "  %s = fcmp oeq float %s, %s\n", res->name, (yyvsp[-2].expression)->name, (yyvsp[0].expression)->name);
        else
            fprintf(llvm_out, "  %s = icmp eq i32 %s, %s\n", res->name, (yyvsp[-2].expression)->name, (yyvsp[0].expression)->name);
        free_llvm_val((yyvsp[-2].expression)); free_llvm_val((yyvsp[0].expression));
        (yyval.boolean_expression) = res;
    }
#line 1563 "calc.tab.c"
    break;

  case 42: /* boolean_expression: expression NOT_EQUAL expression  */
#line 374 "calc.y"
                                    {
        llvm_val *res = malloc(sizeof(llvm_val));
        res->type = BOOL_VAR;
        res->name = new_temp();
        if ((yyvsp[-2].expression)->type == FLOAT_VAR || (yyvsp[0].expression)->type == FLOAT_VAR)
            fprintf(llvm_out, "  %s = fcmp one float %s, %s\n", res->name, (yyvsp[-2].expression)->name, (yyvsp[0].expression)->name);
        else
            fprintf(llvm_out, "  %s = icmp ne i32 %s, %s\n", res->name, (yyvsp[-2].expression)->name, (yyvsp[0].expression)->name);
        free_llvm_val((yyvsp[-2].expression)); free_llvm_val((yyvsp[0].expression));
        (yyval.boolean_expression) = res;
    }
#line 1579 "calc.tab.c"
    break;

  case 43: /* boolean_expression: expression LESS expression  */
#line 385 "calc.y"
                               {
        llvm_val *res = malloc(sizeof(llvm_val));
        res->type = BOOL_VAR;
        res->name = new_temp();
        if ((yyvsp[-2].expression)->type == FLOAT_VAR || (yyvsp[0].expression)->type == FLOAT_VAR)
            fprintf(llvm_out, "  %s = fcmp olt float %s, %s\n", res->name, (yyvsp[-2].expression)->name, (yyvsp[0].expression)->name);
        else
            fprintf(llvm_out, "  %s = icmp slt i32 %s, %s\n", res->name, (yyvsp[-2].expression)->name, (yyvsp[0].expression)->name);
        free_llvm_val((yyvsp[-2].expression)); free_llvm_val((yyvsp[0].expression));
        (yyval.boolean_expression) = res;
    }
#line 1595 "calc.tab.c"
    break;

  case 44: /* boolean_expression: expression GREATER expression  */
#line 396 "calc.y"
                                  {
        llvm_val *res = malloc(sizeof(llvm_val));
        res->type = BOOL_VAR;
        res->name = new_temp();
        if ((yyvsp[-2].expression)->type == FLOAT_VAR || (yyvsp[0].expression)->type == FLOAT_VAR)
            fprintf(llvm_out, "  %s = fcmp ogt float %s, %s\n", res->name, (yyvsp[-2].expression)->name, (yyvsp[0].expression)->name);
        else
            fprintf(llvm_out, "  %s = icmp sgt i32 %s, %s\n", res->name, (yyvsp[-2].expression)->name, (yyvsp[0].expression)->name);
        free_llvm_val((yyvsp[-2].expression)); free_llvm_val((yyvsp[0].expression));
        (yyval.boolean_expression) = res;
    }
#line 1611 "calc.tab.c"
    break;

  case 45: /* boolean_expression: expression LESS_EQUAL expression  */
#line 407 "calc.y"
                                     {
        llvm_val *res = malloc(sizeof(llvm_val));
        res->type = BOOL_VAR;
        res->name = new_temp();
        if ((yyvsp[-2].expression)->type == FLOAT_VAR || (yyvsp[0].expression)->type == FLOAT_VAR)
            fprintf(llvm_out, "  %s = fcmp ole float %s, %s\n", res->name, (yyvsp[-2].expression)->name, (yyvsp[0].expression)->name);
        else
            fprintf(llvm_out, "  %s = icmp sle i32 %s, %s\n", res->name, (yyvsp[-2].expression)->name, (yyvsp[0].expression)->name);
        free_llvm_val((yyvsp[-2].expression)); free_llvm_val((yyvsp[0].expression));
        (yyval.boolean_expression) = res;
    }
#line 1627 "calc.tab.c"
    break;

  case 46: /* boolean_expression: expression GREATER_EQUAL expression  */
#line 418 "calc.y"
                                        {
        llvm_val *res = malloc(sizeof(llvm_val));
        res->type = BOOL_VAR;
        res->name = new_temp();
        if ((yyvsp[-2].expression)->type == FLOAT_VAR || (yyvsp[0].expression)->type == FLOAT_VAR)
            fprintf(llvm_out, "  %s = fcmp oge float %s, %s\n", res->name, (yyvsp[-2].expression)->name, (yyvsp[0].expression)->name);
        else
            fprintf(llvm_out, "  %s = icmp sge i32 %s, %s\n", res->name, (yyvsp[-2].expression)->name, (yyvsp[0].expression)->name);
        free_llvm_val((yyvsp[-2].expression)); free_llvm_val((yyvsp[0].expression));
        (yyval.boolean_expression) = res;
    }
#line 1643 "calc.tab.c"
    break;

  case 47: /* boolean_expression: boolean_expression AND boolean_expression  */
#line 429 "calc.y"
                                              {
        llvm_val *res = malloc(sizeof(llvm_val));
        res->type = BOOL_VAR;
        res->name = new_temp();
        fprintf(llvm_out, "  %s = and i1 %s, %s\n", res->name, (yyvsp[-2].boolean_expression)->name, (yyvsp[0].boolean_expression)->name);
        free_llvm_val((yyvsp[-2].boolean_expression)); free_llvm_val((yyvsp[0].boolean_expression));
        (yyval.boolean_expression) = res;
    }
#line 1656 "calc.tab.c"
    break;

  case 48: /* boolean_expression: boolean_expression OR boolean_expression  */
#line 437 "calc.y"
                                             {
        llvm_val *res = malloc(sizeof(llvm_val));
        res->type = BOOL_VAR;
        res->name = new_temp();
        fprintf(llvm_out, "  %s = or i1 %s, %s\n", res->name, (yyvsp[-2].boolean_expression)->name, (yyvsp[0].boolean_expression)->name);
        free_llvm_val((yyvsp[-2].boolean_expression)); free_llvm_val((yyvsp[0].boolean_expression));
        (yyval.boolean_expression) = res;
    }
#line 1669 "calc.tab.c"
    break;

  case 49: /* if_command: IF OPEN_PARENTHESIS boolean_expression CLOSE_PARENTHESIS OPEN_BRACKETS block CLOSE_BRACKETS ELSE OPEN_BRACKETS block CLOSE_BRACKETS  */
#line 450 "calc.y"
                                            {
        int label_id = get_temp_var_count();

        char *then_label = malloc(32);
        char *else_label = malloc(32);
        char *end_label = malloc(32);

        snprintf(then_label, 32, "label_then_%d", label_id);
        snprintf(else_label, 32, "label_else_%d", label_id);
        snprintf(end_label, 32, "label_end_%d", label_id);

        fprintf(llvm_out, "  br i1 %s, label %%%s, label %%%s\n", (yyvsp[-8].boolean_expression)->name, then_label, else_label);
        fprintf(llvm_out, "%s:\n", then_label);
        // Código gerado pelo bloco $6 (then)
        fprintf(llvm_out, "  br label %%%s\n", end_label);
        fprintf(llvm_out, "%s:\n", else_label);
        // Código gerado pelo bloco $10 (else)
        fprintf(llvm_out, "  br label %%%s\n", end_label);
        fprintf(llvm_out, "%s:\n", end_label);

        free_llvm_val((yyvsp[-8].boolean_expression));
        free(then_label);
        free(else_label);
        free(end_label);
    }
#line 1699 "calc.tab.c"
    break;

  case 50: /* if_command: IF OPEN_PARENTHESIS boolean_expression CLOSE_PARENTHESIS OPEN_BRACKETS block CLOSE_BRACKETS  */
#line 476 "calc.y"
                                       {
        int label_id = get_temp_var_count();

        char *then_label = malloc(32);
        char *end_label = malloc(32);

        snprintf(then_label, 32, "label_then_%d", label_id);
        snprintf(end_label, 32, "label_end_%d", label_id);

        fprintf(llvm_out, "  br i1 %s, label %%%s, label %%%s\n", (yyvsp[-4].boolean_expression)->name, then_label, end_label);
        fprintf(llvm_out, "%s:\n", then_label);
        // Código gerado pelo bloco $6 (then)
        fprintf(llvm_out, "  br label %%%s\n", end_label);
        fprintf(llvm_out, "%s:\n", end_label);

        free_llvm_val((yyvsp[-4].boolean_expression));
        free(then_label);
        free(end_label);
    }
#line 1723 "calc.tab.c"
    break;


#line 1727 "calc.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 498 "calc.y"


int main() {
    yyin = stdin;

    llvm_out = fopen("output.ll", "w");
    if (!llvm_out) {
        fprintf(stderr, "Error opening output file.\n");
        return 1;
    }

    do {
        yyparse();
    } while(!feof(yyin));

    fclose(llvm_out);

    return 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "Parse error: %s\n", s);
    exit(1);
}
