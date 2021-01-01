/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "project.y"

#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int yyerror();
extern int yylex();
extern int yylineno;
extern char *yytext;

typedef struct node
{
	char *token;
	struct node *left;
	struct node *right;
	char *code;
	char *var;
	char *label;
	char *truelabel;
	char *falselabel;
	int sum;
}node;

typedef struct Arguments {
    char **name;
    char **type;
    char **len;
}Arguments;

typedef struct Function {
    char *name;
    struct Arguments *args;
    char *return_type;
    int count_args;
}Function;

typedef struct Varaiables {
    int isArg;
    char **name;
    char **value;
    char **type;
    char **len;
}Varaiable;

typedef struct code_scope {
    int scope_level;
    char *name;
    Varaiable *var;
    Function *func;
    int countvar;
    int countfunc;
    struct code_scope *next_scope;
    struct code_scope *previous_scope;
}code_scope;

code_scope *stack = NULL;
static int current_scope = 0;

struct node* mkleaf(char *token);
struct node* mknode2(char *token,node *left, node *right);
int printtree(node* tree);
void syntaxMKscope(node *tree);
code_scope* mkcode(char* name);
void push(code_scope *new_scope); // ADDS NEW SCOPE TO THE STACK //
Arguments* mkargs(node *tree, int *args_count); // CREATES ARGUMENT SCOPE //
Function* create_function(char *name, Arguments *args, char *return_type, int countArgs, code_scope *code_scope); // CREATES FUNCTION SCOPE //
code_scope* create_scope(char* name, Function* function); // CREATES NEW SCOPE //
void add_varaiable(node* tree); // ADDS VARAIABLES TO CURRENT SCOPE //
void add_string_varaiable(node* tree);
void add_varaiable_rec(node* tree, char* var_type);
char* insert_values_into_vars(node* tree, char* var_type);
bool var_redeclaration_check(char* token);
char* var_declaration_check(char* token, int scope_level);
void func_existence_check(char* token);
char* func_call_existence_check(char* token, int scope_level, node* tree);
void func_call_args_check(code_scope *scope, node* tree);
void func_call_args_type_check(code_scope *scope, int index, char* type , char* token);
void return_check(node* tree, char* var_type);
void boolean_statement_check(node* tree);
char* arithmetic_statement_check(node* tree);
void for_initialization_check(node* tree);
void for_condition_check(node* tree);
void assignment(node* tree);

// PART 3
static node * firstNode;
int POPParams(Arguments * args,int count);
void addCode(node* node,char *code,char *var,char *label,char *truelabel,char *falselabel);
void addCode2(node* node,char *code,char *var,char *label,char *truelabel,char *falselabel);
char* freshVar();
char* freshLabel();
char* gen(char*,char*,char*,char*,char*);
char* mystrcat(char*des,char*src);
char* mystrcat2(char*des,char*src);
char *replaceWord(const char *s, const char *oldW, const char *newW);
char * mkspace(char *label);
void calc3AC(node * tree);
int findfunc(char *func_name);
static int t = 1;
static int l = 1;
static int line = 1;



#line 177 "y.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


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
    INT = 258,
    CHAR = 259,
    STRING = 260,
    REAL = 261,
    BOOL = 262,
    ID = 263,
    VERTICAL_BAR = 264,
    REAL_TYPE = 265,
    INT_TYPE = 266,
    CHAR_TYPE = 267,
    STRING_TYPE = 268,
    REALP_TYPE = 269,
    CHARP_TYPE = 270,
    INTP_TYPE = 271,
    VOID_TYPE = 272,
    BOOL_TYPE = 273,
    RETURN = 274,
    NULL_ = 275,
    DO = 276,
    FUNCTION = 277,
    MAIN = 278,
    FOR = 279,
    WHILE = 280,
    IF = 281,
    ELSE = 282,
    VAR = 283,
    SQR_C = 284,
    SQR_O = 285,
    BAR = 286,
    PAREN_C = 287,
    PAREN_O = 288,
    CURLY_C = 289,
    CURLY_O = 290,
    COMMA = 291,
    SEMI = 292,
    PTR_VAL = 293,
    ADRS = 294,
    OP_DIV = 295,
    OP_MULT = 296,
    OP_MINUS = 297,
    OP_PLUS = 298,
    OP_PLUS_PLUS = 299,
    ASSIGN = 300,
    NOT = 301,
    COLUMS = 302,
    OR = 303,
    AND = 304,
    ROP_NE = 305,
    ROP_EQ = 306,
    ROP_GE = 307,
    ROP_LT = 308,
    ROP_LE = 309,
    ROP_GT = 310
  };
#endif
/* Tokens.  */
#define INT 258
#define CHAR 259
#define STRING 260
#define REAL 261
#define BOOL 262
#define ID 263
#define VERTICAL_BAR 264
#define REAL_TYPE 265
#define INT_TYPE 266
#define CHAR_TYPE 267
#define STRING_TYPE 268
#define REALP_TYPE 269
#define CHARP_TYPE 270
#define INTP_TYPE 271
#define VOID_TYPE 272
#define BOOL_TYPE 273
#define RETURN 274
#define NULL_ 275
#define DO 276
#define FUNCTION 277
#define MAIN 278
#define FOR 279
#define WHILE 280
#define IF 281
#define ELSE 282
#define VAR 283
#define SQR_C 284
#define SQR_O 285
#define BAR 286
#define PAREN_C 287
#define PAREN_O 288
#define CURLY_C 289
#define CURLY_O 290
#define COMMA 291
#define SEMI 292
#define PTR_VAL 293
#define ADRS 294
#define OP_DIV 295
#define OP_MULT 296
#define OP_MINUS 297
#define OP_PLUS 298
#define OP_PLUS_PLUS 299
#define ASSIGN 300
#define NOT 301
#define COLUMS 302
#define OR 303
#define AND 304
#define ROP_NE 305
#define ROP_EQ 306
#define ROP_GE 307
#define ROP_LT 308
#define ROP_LE 309
#define ROP_GT 310

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 107 "project.y"

  char* string; 
  struct node* node;

#line 341 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);





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
typedef yytype_int16 yy_state_t;

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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   639

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  157
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  375

#define YYUNDEFTOK  2
#define YYMAXUTOK   310


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   130,   130,   133,   136,   137,   138,   141,   144,   148,
     152,   156,   157,   158,   159,   160,   161,   162,   165,   166,
     167,   168,   169,   170,   173,   176,   177,   180,   181,   184,
     185,   188,   189,   193,   196,   199,   200,   203,   204,   207,
     208,   209,   212,   215,   221,   224,   227,   230,   233,   236,
     239,   242,   245,   248,   249,   250,   251,   252,   253,   254,
     255,   258,   261,   264,   267,   270,   273,   276,   279,   282,
     283,   284,   285,   286,   287,   288,   289,   292,   295,   298,
     301,   304,   307,   310,   313,   316,   317,   318,   319,   320,
     323,   323,   326,   329,   330,   331,   332,   335,   338,   339,
     340,   341,   344,   344,   347,   348,   351,   354,   355,   356,
     357,   358,   361,   363,   364,   367,   368,   369,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   394,   395,
     396,   397,   398,   399,   402,   405,   405,   408,   408,   411,
     412,   413,   414,   415,   416,   419,   420,   423
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "CHAR", "STRING", "REAL", "BOOL",
  "ID", "VERTICAL_BAR", "REAL_TYPE", "INT_TYPE", "CHAR_TYPE",
  "STRING_TYPE", "REALP_TYPE", "CHARP_TYPE", "INTP_TYPE", "VOID_TYPE",
  "BOOL_TYPE", "RETURN", "NULL_", "DO", "FUNCTION", "MAIN", "FOR", "WHILE",
  "IF", "ELSE", "VAR", "SQR_C", "SQR_O", "BAR", "PAREN_C", "PAREN_O",
  "CURLY_C", "CURLY_O", "COMMA", "SEMI", "PTR_VAL", "ADRS", "OP_DIV",
  "OP_MULT", "OP_MINUS", "OP_PLUS", "OP_PLUS_PLUS", "ASSIGN", "NOT",
  "COLUMS", "OR", "AND", "ROP_NE", "ROP_EQ", "ROP_GE", "ROP_LT", "ROP_LE",
  "ROP_GT", "$accept", "program", "code", "code_", "functions", "function",
  "procedure", "main_func", "args_type", "f_type", "id", "array_id",
  "func_args", "f_args", "fargs", "body_f", "body_p", "fbody_", "pbody_",
  "assignment", "ptr_id", "for_init", "stmts_oneline", "stmt_p", "stmt_f",
  "block_stmt", "decleration", "var_decleration", "vardec_args",
  "str_decleration", "str_dec_args", "int_or_id", "char_or_string",
  "func_call", "id_list", "bool_expr", "bool_expr_", "expr", "ptr_expr",
  "code_block", "stmt_block_rec", "code_block_dec", "literal", "return",
  "end_return", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310
};
# endif

#define YYPACT_NINF (-299)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      24,   404,    18,  -299,  -299,    24,    24,  -299,  -299,  -299,
    -299,  -299,  -299,    14,  -299,    97,  -299,  -299,  -299,  -299,
    -299,    69,    88,   100,    98,   349,   349,   105,  -299,  -299,
    -299,  -299,  -299,  -299,  -299,    97,   110,  -299,   114,   438,
     112,   122,   127,   130,    97,   135,   413,   143,   151,   166,
     349,    10,    97,  -299,  -299,    -6,   155,   167,  -299,   168,
     164,   438,  -299,  -299,   181,    97,   349,   438,   462,   173,
     184,  -299,   438,    97,    36,   106,   106,    36,    10,   189,
       8,  -299,   115,   209,   106,   106,  -299,  -299,   106,  -299,
    -299,  -299,  -299,   193,   196,   195,   200,   202,    10,  -299,
    -299,   205,   215,   211,   462,  -299,   217,   121,  -299,   212,
      46,   219,   226,  -299,  -299,  -299,  -299,  -299,  -299,    54,
     106,    28,    28,   106,    49,  -299,   227,   552,  -299,   228,
       5,   225,   229,  -299,  -299,   230,   238,   240,   241,    10,
     239,     8,   242,  -299,   234,   253,   248,   262,   259,   584,
     584,   584,  -299,   462,    36,   106,   106,   267,  -299,   106,
    -299,  -299,  -299,  -299,  -299,  -299,   274,   279,   106,    12,
     276,   277,   479,    97,   282,  -299,  -299,  -299,  -299,   121,
      23,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,    34,    36,    36,  -299,     8,    36,   106,
     106,   280,  -299,  -299,  -299,  -299,  -299,   209,  -299,   209,
     294,   283,   284,   286,  -299,   498,     9,   288,   517,   438,
     289,   290,  -299,  -299,  -299,   201,   299,   438,   292,  -299,
    -299,  -299,  -299,  -299,   568,  -299,   210,   210,   210,   210,
     210,   210,   438,   296,  -299,  -299,   298,   303,   304,   305,
    -299,  -299,  -299,   106,   306,    59,    62,    84,  -299,    97,
      94,   106,    36,   308,  -299,  -299,   327,   335,   336,   340,
    -299,   312,  -299,   106,   106,   313,   108,   324,   123,   133,
     153,   536,   325,   462,   314,   462,   315,   462,   329,  -299,
    -299,  -299,   318,   341,  -299,  -299,   342,   343,   344,   346,
    -299,  -299,  -299,   354,    36,  -299,   350,     8,   347,     8,
     351,     8,   359,  -299,   358,   294,  -299,   294,  -299,   294,
     161,    97,   356,  -299,  -299,  -299,  -299,   352,   361,   106,
     362,  -299,   363,  -299,   364,   163,   106,   365,   367,   383,
      36,  -299,  -299,  -299,   438,  -299,   386,  -299,  -299,   399,
      36,  -299,   400,  -299,  -299,   409,   403,   405,   401,   407,
     406,   410,   415,  -299,  -299,  -299,   438,  -299,  -299,   462,
     414,   294,  -299,   419,  -299
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     3,     0,     0,     6,    23,    19,
      20,    22,    21,     0,    18,     0,     1,     7,     4,     5,
      24,     0,     0,     0,     0,    28,    28,     0,    11,    13,
      14,    17,    16,    15,    12,     0,     0,    27,     0,    38,
      32,    30,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   148,     0,    59,    58,     0,     0,     0,    34,     0,
       0,    38,    55,    90,     0,     0,     0,    38,    36,     0,
       0,    97,    38,     0,     0,     0,     0,     0,   148,     0,
     146,    42,     0,   111,     0,     0,    10,    57,     0,    37,
      56,    31,    29,     0,     0,     0,     0,     0,   148,    75,
      74,     0,     0,     0,    36,    71,     0,     0,    91,     0,
       0,     0,     0,   149,   150,   151,   152,   154,   153,     0,
       0,     0,     0,     0,   136,   132,     0,   114,   131,     0,
      93,    96,     0,   147,    60,     0,     0,     0,     0,   148,
       0,   146,     0,   144,     0,     0,   108,     0,   110,    39,
      40,    41,     9,    36,     0,     0,     0,     0,     8,     0,
      33,    73,    35,    72,   102,   103,     0,     0,     0,     0,
       0,     0,     0,     0,   142,   143,   130,   129,   128,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    92,   146,     0,     0,
       0,     0,    88,   145,    87,    25,    26,   111,   106,   111,
     156,     0,     0,     0,    76,     0,    99,     0,     0,    38,
       0,     0,   134,   133,   137,     0,     0,    38,     0,   121,
     120,   119,   118,   112,   117,   113,   122,   123,   125,   126,
     127,   124,    38,    47,    94,    95,     0,     0,     0,     0,
      89,   107,   109,     0,     0,     0,     0,     0,   157,     0,
       0,     0,     0,     0,    44,    54,     0,     0,     0,     0,
     135,     0,    51,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    36,     0,    36,     0,    36,    63,    98,
     104,   105,   100,     0,    43,    53,     0,     0,     0,     0,
      50,   115,   116,    45,     0,    48,     0,   146,     0,   146,
       0,   146,    79,   155,     0,   156,    70,   156,    67,   156,
       0,     0,     0,   141,   140,   139,   138,     0,     0,     0,
       0,    86,     0,    83,     0,     0,     0,     0,     0,     0,
       0,    64,   101,    52,    38,    49,     0,    85,    82,    77,
       0,    80,     0,    69,    66,    61,     0,     0,     0,     0,
       0,     0,     0,    65,    46,    84,    38,    81,    68,    36,
       0,   156,    78,     0,    62
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -299,  -299,  -299,   444,   449,     0,     3,  -299,   411,  -299,
      13,    57,   442,   412,   416,  -299,   418,  -102,   -47,    83,
    -299,  -143,   178,  -299,  -299,  -299,   -38,  -299,    -4,  -299,
    -249,   293,  -299,   158,  -101,   -72,  -185,   221,   355,   -83,
    -134,   393,   -71,  -298,  -299
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    17,    18,    53,    54,     7,    35,    15,
     124,    56,    36,    37,    41,   101,    57,   102,    58,   220,
      60,   112,   221,    61,   104,   141,    62,    63,   132,    70,
      71,   166,   292,   125,   147,   126,   233,   127,   176,    79,
     143,    80,   128,   254,   160
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       5,   235,   162,     6,   129,     5,     5,   203,     6,     6,
     289,   211,   148,    78,    89,   157,    20,   337,    16,   338,
      20,   339,    20,    44,    82,   109,    22,    83,    23,   135,
     105,    20,   136,   137,   138,    82,    20,    21,    50,    84,
      78,   194,    20,   139,    20,   259,     1,   219,    40,    52,
      84,   210,    55,    52,   260,   247,   201,    69,   227,   170,
      78,   173,    20,   246,    52,    81,   105,    20,    99,   242,
      20,   100,   342,   373,    55,    52,    82,    52,    40,   179,
      55,    55,    83,   212,   213,    55,    22,   110,   301,   302,
     130,    84,    20,    55,   283,   145,   146,   285,   290,   291,
      52,    78,    24,    52,    99,    20,   251,   100,   252,   113,
     114,   115,   116,   117,    20,   105,    20,    55,   144,   287,
     165,    25,    59,    20,   164,    52,   118,   248,   249,    20,
      27,    20,   171,    26,   174,   174,   148,   119,   148,   120,
      39,    20,    42,   304,    59,   121,    43,   122,    65,    52,
      59,   103,   123,    99,    55,    59,   100,   111,   307,    66,
     131,    20,    67,   140,    52,    68,    55,   110,   309,    20,
      72,    20,   263,   330,    52,   332,    74,   334,   175,   175,
     271,   315,   110,   317,    75,   319,   225,   103,   311,   293,
     244,   245,   165,   110,    52,   275,   340,    64,   350,    76,
      85,    86,    52,   107,    52,    87,   110,   130,   130,    88,
      55,   110,   113,   114,   115,   116,   117,    20,    90,    64,
     146,   108,   146,   134,   140,    64,   106,   152,   154,   118,
      64,   153,    55,   155,   159,   156,   103,   111,   142,   158,
      55,   266,   267,   268,   269,   105,   167,   105,   161,   105,
     181,   182,   183,   184,   163,    55,   168,   346,   169,   180,
     193,   195,   106,   205,   352,   197,   196,   371,   110,   110,
     110,   198,    69,   199,   200,   110,   202,   131,   131,   204,
     140,   111,   206,    99,   207,    99,   100,    99,   100,   110,
     100,   110,   110,   110,   208,   209,    55,   357,    55,   142,
      55,   214,    59,   216,   217,   149,   150,   222,   223,   151,
      59,   106,    82,   253,   250,   255,   256,   110,   257,   370,
      55,   261,    55,   276,    55,    59,   264,   265,   270,   272,
     296,   105,   277,   110,    69,   278,   279,   280,   297,   298,
     282,   172,   295,   299,   178,   294,   300,   303,   110,   306,
     314,   316,   318,   110,   321,   142,   320,    55,   228,    28,
      29,    30,    31,   110,    32,    33,   103,    34,   103,    99,
     103,   243,   100,   322,   323,   324,   325,    64,   326,    55,
     215,   327,    55,   329,   331,    64,   335,   344,   333,   218,
     140,   336,   140,   343,   140,   345,   347,   348,   349,   353,
      64,   354,   229,   230,   231,   232,   234,   234,   236,   237,
     238,   239,   240,   241,     8,     9,    10,   355,   358,    11,
      12,    13,    14,     8,     9,    10,   359,    59,    11,    12,
      73,    14,   361,   284,   286,   288,   362,   363,   365,   364,
     367,   106,   366,   106,     4,   106,    20,   368,   372,    59,
     369,    44,   103,   374,   305,    19,   308,   310,   312,    45,
      46,    77,    47,    48,    49,   142,    50,   142,    38,   142,
      20,   133,   226,    51,   281,    44,     0,   177,    92,    52,
       0,    91,   328,    94,    46,    93,    95,    96,    97,     0,
      50,     0,     0,     0,   234,   234,     0,    98,   341,     0,
       0,     0,    64,    52,     0,     0,     0,     0,     0,     0,
       0,   224,     0,   351,     0,     0,     0,     0,   356,   181,
     182,   183,   184,     0,    64,     0,     0,   106,   360,   187,
     188,   189,   190,   191,   192,   258,     0,     0,   181,   182,
     183,   184,     0,     0,     0,     0,     0,     0,   187,   188,
     189,   190,   191,   192,   262,     0,     0,   181,   182,   183,
     184,     0,     0,     0,     0,     0,     0,   187,   188,   189,
     190,   191,   192,   313,     0,     0,   181,   182,   183,   184,
       0,     0,     0,     0,     0,     0,   187,   188,   189,   190,
     191,   192,   181,   182,   183,   184,     0,     0,     0,     0,
     185,   186,   187,   188,   189,   190,   191,   192,   181,   182,
     183,   184,     0,     0,     0,     0,   273,   274,   187,   188,
     189,   190,   191,   192,   181,   182,   183,   184,     0,     0,
       0,     0,     0,     0,   187,   188,   189,   190,   191,   192
};

static const yytype_int16 yycheck[] =
{
       0,   186,   104,     0,    76,     5,     6,   141,     5,     6,
     259,   154,    83,    51,    61,    98,     8,   315,     0,   317,
       8,   319,     8,    13,    30,    72,    13,    33,    15,    21,
      68,     8,    24,    25,    26,    30,     8,    23,    28,    45,
      78,    36,     8,    35,     8,    36,    22,    35,    35,    41,
      45,   153,    39,    41,    45,   198,   139,    44,    35,     5,
      98,    33,     8,   197,    41,    52,   104,     8,    68,    35,
       8,    68,   321,   371,    61,    41,    30,    41,    65,    30,
      67,    68,    33,   155,   156,    72,    73,    74,   273,   274,
      77,    45,     8,    80,    35,    82,    83,    35,     4,     5,
      41,   139,    33,    41,   104,     8,   207,   104,   209,     3,
       4,     5,     6,     7,     8,   153,     8,   104,     3,    35,
     107,    33,    39,     8,     3,    41,    20,   199,   200,     8,
      32,     8,   119,    33,   121,   122,   207,    31,   209,    33,
      35,     8,    32,    35,    61,    39,    32,    41,    36,    41,
      67,    68,    46,   153,   141,    72,   153,    74,    35,    37,
      77,     8,    35,    80,    41,    35,   153,   154,    35,     8,
      35,     8,   219,   307,    41,   309,    33,   311,   121,   122,
     227,   283,   169,   285,    33,   287,   173,   104,    35,   261,
     194,   195,   179,   180,    41,   242,    35,    39,    35,    33,
      45,    34,    41,    30,    41,    37,   193,   194,   195,    45,
     197,   198,     3,     4,     5,     6,     7,     8,    37,    61,
     207,    37,   209,    34,   141,    67,    68,    34,    33,    20,
      72,    35,   219,    33,    19,    33,   153,   154,    80,    34,
     227,    40,    41,    42,    43,   283,    34,   285,    37,   287,
      40,    41,    42,    43,    37,   242,    37,   329,    32,    32,
      32,    36,   104,    29,   336,    35,    37,   369,   255,   256,
     257,    33,   259,    33,    33,   262,    37,   194,   195,    37,
     197,   198,    29,   283,    36,   285,   283,   287,   285,   276,
     287,   278,   279,   280,    32,    36,   283,   344,   285,   141,
     287,    34,   219,    29,    25,    84,    85,    31,    31,    88,
     227,   153,    30,    19,    34,    32,    32,   304,    32,   366,
     307,    33,   309,    27,   311,   242,    37,    37,    29,    37,
       3,   369,    34,   320,   321,    32,    32,    32,     3,     3,
      34,   120,    34,     3,   123,   262,    34,    34,   335,    25,
      25,    37,    37,   340,    36,   197,    27,   344,   180,    10,
      11,    12,    13,   350,    15,    16,   283,    18,   285,   369,
     287,   193,   369,    32,    32,    32,    32,   219,    32,   366,
     159,    27,   369,    33,    37,   227,    27,    35,    37,   168,
     307,    33,   309,    37,   311,    34,    34,    34,    34,    34,
     242,    34,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,    10,    11,    12,    34,    32,    15,
      16,    17,    18,    10,    11,    12,    27,   344,    15,    16,
      17,    18,    32,   255,   256,   257,    27,    34,    37,    34,
      34,   283,    35,   285,     0,   287,     8,    37,    34,   366,
      35,    13,   369,    34,   276,     6,   278,   279,   280,    21,
      22,    50,    24,    25,    26,   307,    28,   309,    26,   311,
       8,    78,   179,    35,   253,    13,    -1,   122,    66,    41,
      -1,    65,   304,    21,    22,    67,    24,    25,    26,    -1,
      28,    -1,    -1,    -1,   273,   274,    -1,    35,   320,    -1,
      -1,    -1,   344,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    -1,   335,    -1,    -1,    -1,    -1,   340,    40,
      41,    42,    43,    -1,   366,    -1,    -1,   369,   350,    50,
      51,    52,    53,    54,    55,    37,    -1,    -1,    40,    41,
      42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,
      52,    53,    54,    55,    37,    -1,    -1,    40,    41,    42,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,
      53,    54,    55,    37,    -1,    -1,    40,    41,    42,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,    53,
      54,    55,    40,    41,    42,    43,    -1,    -1,    -1,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    40,    41,
      42,    43,    -1,    -1,    -1,    -1,    48,    49,    50,    51,
      52,    53,    54,    55,    40,    41,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    51,    52,    53,    54,    55
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    22,    57,    58,    59,    61,    62,    63,    10,    11,
      12,    15,    16,    17,    18,    65,     0,    59,    60,    60,
       8,    23,    66,    66,    33,    33,    33,    32,    10,    11,
      12,    13,    15,    16,    18,    64,    68,    69,    68,    35,
      66,    70,    32,    32,    13,    21,    22,    24,    25,    26,
      28,    35,    41,    61,    62,    66,    67,    72,    74,    75,
      76,    79,    82,    83,    89,    36,    37,    35,    35,    66,
      85,    86,    35,    17,    33,    33,    33,    64,    82,    95,
      97,    66,    30,    33,    45,    45,    34,    37,    45,    74,
      37,    70,    69,    72,    21,    24,    25,    26,    35,    61,
      62,    71,    73,    75,    80,    82,    89,    30,    37,    74,
      66,    75,    77,     3,     4,     5,     6,     7,    20,    31,
      33,    39,    41,    46,    66,    89,    91,    93,    98,    91,
      66,    75,    84,    97,    34,    21,    24,    25,    26,    35,
      75,    81,    89,    96,     3,    66,    66,    90,    98,    93,
      93,    93,    34,    35,    33,    33,    33,    95,    34,    19,
     100,    37,    73,    37,     3,    66,    87,    34,    37,    32,
       5,    66,    93,    33,    66,    67,    94,    94,    93,    30,
      32,    40,    41,    42,    43,    48,    49,    50,    51,    52,
      53,    54,    55,    32,    36,    36,    37,    35,    33,    33,
      33,    95,    37,    96,    37,    29,    29,    36,    32,    36,
      73,    77,    91,    91,    34,    93,    29,    25,    93,    35,
      75,    78,    31,    31,    32,    66,    87,    35,    78,    93,
      93,    93,    93,    92,    93,    92,    93,    93,    93,    93,
      93,    93,    35,    78,    84,    84,    96,    77,    91,    91,
      34,    90,    90,    19,    99,    32,    32,    32,    37,    36,
      45,    33,    37,    74,    37,    37,    40,    41,    42,    43,
      29,    74,    37,    48,    49,    74,    27,    34,    32,    32,
      32,    93,    34,    35,    78,    35,    78,    35,    78,    86,
       4,     5,    88,    91,    75,    34,     3,     3,     3,     3,
      34,    92,    92,    34,    35,    78,    25,    35,    78,    35,
      78,    35,    78,    37,    25,    73,    37,    73,    37,    73,
      27,    36,    32,    32,    32,    32,    32,    27,    78,    33,
      96,    37,    96,    37,    96,    27,    33,    99,    99,    99,
      35,    78,    86,    37,    35,    34,    91,    34,    34,    34,
      35,    78,    91,    34,    34,    34,    78,    74,    32,    27,
      78,    32,    27,    34,    34,    37,    35,    34,    37,    35,
      74,    73,    34,    99,    34
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    56,    57,    58,    59,    59,    59,    60,    61,    62,
      63,    64,    64,    64,    64,    64,    64,    64,    65,    65,
      65,    65,    65,    65,    66,    67,    67,    68,    68,    69,
      69,    70,    70,    71,    72,    73,    73,    74,    74,    75,
      75,    75,    76,    77,    78,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      82,    82,    83,    84,    84,    84,    84,    85,    86,    86,
      86,    86,    87,    87,    88,    88,    89,    90,    90,    90,
      90,    90,    91,    91,    91,    92,    92,    92,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    94,    94,
      94,    94,    94,    94,    95,    96,    96,    97,    97,    98,
      98,    98,    98,    98,    98,    99,    99,   100
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     1,     1,     9,     9,
       8,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     1,     0,     4,
       2,     3,     1,     2,     1,     2,     0,     2,     0,     3,
       3,     3,     2,     5,     2,     7,    11,     5,     7,     9,
       7,     6,     9,     7,     6,     1,     2,     2,     1,     1,
       3,     8,    13,     5,     7,     9,     8,     6,    10,     8,
       6,     1,     2,     2,     1,     1,     3,     7,    11,     5,
       7,     9,     7,     6,     9,     7,     6,     2,     2,     3,
       1,     3,     4,     1,     3,     3,     1,     1,     6,     4,
       6,     8,     1,     1,     1,     1,     4,     3,     1,     3,
       1,     0,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       2,     1,     1,     3,     3,     4,     1,     3,     5,     5,
       5,     5,     1,     1,     2,     2,     0,     2,     0,     1,
       1,     1,     1,     1,     1,     3,     0,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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
  case 2:
#line 130 "project.y"
                             { /*print_input_code();*/ printtree((yyvsp[0].node)); printf("\n"); syntaxMKscope((yyvsp[0].node)); printf("\n"); calc3AC((yyvsp[0].node)); }
#line 1819 "y.tab.c"
    break;

  case 3:
#line 133 "project.y"
                          { (yyval.node) = mknode2("CODE", NULL, (yyvsp[0].node)); }
#line 1825 "y.tab.c"
    break;

  case 4:
#line 136 "project.y"
                                           { (yyval.node) = mknode2("FUNCTION", (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1831 "y.tab.c"
    break;

  case 5:
#line 137 "project.y"
                                            { (yyval.node) = mknode2("PROCEDURE", (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1837 "y.tab.c"
    break;

  case 6:
#line 138 "project.y"
                                  { (yyval.node) = mknode2("FUNCTION",(yyvsp[0].node),NULL); }
#line 1843 "y.tab.c"
    break;

  case 7:
#line 141 "project.y"
                              { (yyval.node) = (yyvsp[0].node); }
#line 1849 "y.tab.c"
    break;

  case 8:
#line 145 "project.y"
                    { (yyval.node) = mknode2((yyvsp[-6].string), mknode2((yyvsp[-7].string), (yyvsp[-4].node), NULL), (yyvsp[-1].node)); }
#line 1855 "y.tab.c"
    break;

  case 9:
#line 149 "project.y"
                    { (yyval.node) = mknode2((yyvsp[-6].string), mknode2("VOID TYPE",(yyvsp[-4].node), NULL), (yyvsp[-1].node));}
#line 1861 "y.tab.c"
    break;

  case 10:
#line 153 "project.y"
                    { (yyval.node) = mknode2("MAIN",mknode2("VOID TYPE", mkleaf("ARGS NONE"),NULL), (yyvsp[-1].node)); }
#line 1867 "y.tab.c"
    break;

  case 11:
#line 156 "project.y"
                                  { (yyval.string) = strdup("REAL"); }
#line 1873 "y.tab.c"
    break;

  case 12:
#line 157 "project.y"
                                  { (yyval.string) = strdup("BOOL"); }
#line 1879 "y.tab.c"
    break;

  case 13:
#line 158 "project.y"
                                 { (yyval.string) = strdup("INT"); }
#line 1885 "y.tab.c"
    break;

  case 14:
#line 159 "project.y"
                                  { (yyval.string) = strdup("CHAR"); }
#line 1891 "y.tab.c"
    break;

  case 15:
#line 160 "project.y"
                                  { (yyval.string) = strdup("INTP"); }
#line 1897 "y.tab.c"
    break;

  case 16:
#line 161 "project.y"
                                   { (yyval.string) = strdup("CHARP"); }
#line 1903 "y.tab.c"
    break;

  case 17:
#line 162 "project.y"
                                    { (yyval.string) = strdup("STRING"); }
#line 1909 "y.tab.c"
    break;

  case 18:
#line 165 "project.y"
                                  { (yyval.string) = strdup("BOOL"); }
#line 1915 "y.tab.c"
    break;

  case 19:
#line 166 "project.y"
                                 { (yyval.string) = strdup("INT"); }
#line 1921 "y.tab.c"
    break;

  case 20:
#line 167 "project.y"
                                  { (yyval.string) = strdup("CHAR"); }
#line 1927 "y.tab.c"
    break;

  case 21:
#line 168 "project.y"
                                  { (yyval.string) = strdup("INTP"); }
#line 1933 "y.tab.c"
    break;

  case 22:
#line 169 "project.y"
                                   { (yyval.string) = strdup("CHARP"); }
#line 1939 "y.tab.c"
    break;

  case 23:
#line 170 "project.y"
                              { (yyval.string) = strdup("REAL"); }
#line 1945 "y.tab.c"
    break;

  case 24:
#line 173 "project.y"
                                   { (yyval.string) = strdup(yytext); }
#line 1951 "y.tab.c"
    break;

  case 25:
#line 176 "project.y"
                                           {(yyval.node)=mknode2((yyvsp[-3].string),mkleaf((yyvsp[-1].string)),NULL);}
#line 1957 "y.tab.c"
    break;

  case 26:
#line 177 "project.y"
                                          {(yyval.node)=mknode2((yyvsp[-3].string),mkleaf((yyvsp[-1].string)),NULL);}
#line 1963 "y.tab.c"
    break;

  case 27:
#line 180 "project.y"
                           { (yyval.node) = mknode2("ARGS", (yyvsp[0].node), NULL); }
#line 1969 "y.tab.c"
    break;

  case 28:
#line 181 "project.y"
                    { (yyval.node) = mknode2("ARGS NONE", NULL, NULL); }
#line 1975 "y.tab.c"
    break;

  case 29:
#line 184 "project.y"
                                                    { (yyval.node) = mknode2((yyvsp[-3].string), (yyvsp[0].node), (yyvsp[-2].node)); }
#line 1981 "y.tab.c"
    break;

  case 30:
#line 185 "project.y"
                                    { (yyval.node) = mknode2((yyvsp[-1].string), NULL, (yyvsp[0].node)); }
#line 1987 "y.tab.c"
    break;

  case 31:
#line 188 "project.y"
                                       { (yyval.node) = mknode2((yyvsp[-2].string), NULL, (yyvsp[0].node)); }
#line 1993 "y.tab.c"
    break;

  case 32:
#line 189 "project.y"
                       { (yyval.node) = mkleaf((yyvsp[0].string)); }
#line 1999 "y.tab.c"
    break;

  case 33:
#line 193 "project.y"
                                          { (yyval.node) = mknode2("BODY", (yyvsp[-1].node), (yyvsp[0].node)); }
#line 2005 "y.tab.c"
    break;

  case 34:
#line 196 "project.y"
                               { (yyval.node) = mknode2("BODY", (yyvsp[0].node), NULL); }
#line 2011 "y.tab.c"
    break;

  case 35:
#line 199 "project.y"
                                  { (yyval.node) = mknode2("STATEMENT", (yyvsp[-1].node), (yyvsp[0].node)); }
#line 2017 "y.tab.c"
    break;

  case 36:
#line 200 "project.y"
                    { (yyval.node) = NULL; }
#line 2023 "y.tab.c"
    break;

  case 37:
#line 203 "project.y"
                                  { (yyval.node) = mknode2("STATEMENT", (yyvsp[-1].node), (yyvsp[0].node)); }
#line 2029 "y.tab.c"
    break;

  case 38:
#line 204 "project.y"
                    { (yyval.node) = NULL; }
#line 2035 "y.tab.c"
    break;

  case 39:
#line 207 "project.y"
                                       { (yyval.node) = mknode2("=", mkleaf((yyvsp[-2].string)), (yyvsp[0].node)); }
#line 2041 "y.tab.c"
    break;

  case 40:
#line 208 "project.y"
                                             { (yyval.node) = mknode2("=", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2047 "y.tab.c"
    break;

  case 41:
#line 209 "project.y"
                                       { (yyval.node) = mknode2("=", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2053 "y.tab.c"
    break;

  case 42:
#line 212 "project.y"
                               { (yyval.node)=mknode2("PTR",mkleaf((yyvsp[0].string)),NULL); }
#line 2059 "y.tab.c"
    break;

  case 43:
#line 215 "project.y"
                                                             {
                    (yyval.node) = mknode2("FOR-INIT",(yyvsp[-4].node), mknode2("FOR-CONDITION", (yyvsp[-2].node), (yyvsp[0].node)));
                    addCode((yyvsp[-2].node), NULL, NULL, NULL, freshLabel(), NULL);
                    addCode((yyvsp[-2].node), NULL, NULL, NULL, NULL, freshLabel()); }
#line 2068 "y.tab.c"
    break;

  case 44:
#line 221 "project.y"
                                        { (yyval.node) = mknode2("STATEMENT", mknode2("ASSIGNMENT", (yyvsp[-1].node), NULL), NULL); }
#line 2074 "y.tab.c"
    break;

  case 45:
#line 224 "project.y"
                                                                                   {
                    (yyval.node)=mknode2("IF", (yyvsp[-4].node), mknode2("IF-BODY",(yyvsp[-1].node), NULL));
                    addCode((yyvsp[-4].node), NULL, NULL, NULL, NULL, freshLabel()); }
#line 2082 "y.tab.c"
    break;

  case 46:
#line 227 "project.y"
                                                                                                    {
                    (yyval.node) = mknode2("IF-ELSE", mknode2("IF", (yyvsp[-8].node), mknode2("IF-BODY", (yyvsp[-5].node), NULL)), mknode2("ELSE", mknode2("ELSE-BODY", (yyvsp[-1].node), NULL), NULL));
                    addCode((yyvsp[-8].node), NULL, NULL, NULL, NULL, freshLabel()); addCode((yyvsp[-8].node), NULL, NULL, NULL, freshLabel(), NULL); }
#line 2090 "y.tab.c"
    break;

  case 47:
#line 230 "project.y"
                                                                          {
                    (yyval.node) = mknode2("IF", (yyvsp[-2].node), mknode2("IF-BODY", (yyvsp[0].node), NULL));
                    addCode((yyvsp[-2].node), NULL, NULL, NULL, NULL, freshLabel()); }
#line 2098 "y.tab.c"
    break;

  case 48:
#line 233 "project.y"
                                                                                  {
                    (yyval.node) = mknode2("IF-ELSE", mknode2("IF", (yyvsp[-4].node), mknode2("IF-BODY", (yyvsp[-2].node), NULL)), mknode2("ELSE", mknode2("ELSE-BODY", (yyvsp[0].node), NULL),NULL));
                    addCode((yyvsp[-4].node), NULL, NULL, NULL, NULL, freshLabel()); addCode((yyvsp[-4].node), NULL, NULL, NULL, freshLabel(), NULL); }
#line 2106 "y.tab.c"
    break;

  case 49:
#line 237 "project.y"
                    { (yyval.node) = mknode2("IF-ELSE", mknode2("IF", (yyvsp[-6].node), (yyvsp[-4].node)), mknode2("ELSE", (yyvsp[-1].node), NULL));
                    addCode((yyvsp[-6].node), NULL, NULL, NULL, NULL, freshLabel()); addCode((yyvsp[-6].node), NULL, NULL, NULL, freshLabel(), NULL); }
#line 2113 "y.tab.c"
    break;

  case 50:
#line 239 "project.y"
                                                                                {
                    (yyval.node) = mknode2("WHILE", (yyvsp[-4].node), mknode2("WHILE-BODY",(yyvsp[-1].node), NULL));
                    addCode((yyvsp[-4].node), NULL, NULL, NULL, freshLabel(), NULL); addCode((yyvsp[-4].node), NULL, NULL, NULL, NULL, freshLabel());  }
#line 2121 "y.tab.c"
    break;

  case 51:
#line 242 "project.y"
                                                                           {
                    (yyval.node) = mknode2("WHILE", (yyvsp[-3].node), mknode2("WHILE-BODY", (yyvsp[-1].node), NULL));
                    addCode((yyvsp[-3].node), NULL, NULL, NULL, freshLabel(), NULL); addCode((yyvsp[-3].node), NULL, NULL, NULL, NULL, freshLabel()); }
#line 2129 "y.tab.c"
    break;

  case 52:
#line 245 "project.y"
                                                                                       {
                    (yyval.node) = mknode2("DO-WHILE", mknode2("DO-WHILE-BODY",(yyvsp[-6].node),NULL), (yyvsp[-2].node));
                    addCode((yyvsp[-2].node), NULL, NULL, NULL, freshLabel(), NULL); addCode((yyvsp[-2].node), NULL, NULL, NULL, NULL, freshLabel()); }
#line 2137 "y.tab.c"
    break;

  case 53:
#line 248 "project.y"
                                                                            { (yyval.node) = mknode2("FOR",(yyvsp[-4].node), mknode2("FOR-BODY",(yyvsp[-1].node), NULL)); }
#line 2143 "y.tab.c"
    break;

  case 54:
#line 249 "project.y"
                                                                        { (yyval.node) = mknode2("FOR",(yyvsp[-3].node), mknode2("FOR-BODY",(yyvsp[-1].node), NULL)); }
#line 2149 "y.tab.c"
    break;

  case 55:
#line 250 "project.y"
                                    { (yyval.node) = mknode2("DECLETARION", (yyvsp[0].node), NULL); }
#line 2155 "y.tab.c"
    break;

  case 56:
#line 251 "project.y"
                                       { (yyval.node) = (yyvsp[-1].node); }
#line 2161 "y.tab.c"
    break;

  case 57:
#line 252 "project.y"
                                         { (yyval.node) = mknode2("ASSIGNMENT", (yyvsp[-1].node), NULL); }
#line 2167 "y.tab.c"
    break;

  case 58:
#line 253 "project.y"
                                  { (yyval.node) = mknode2("PROCEDURE", (yyvsp[0].node), NULL); }
#line 2173 "y.tab.c"
    break;

  case 59:
#line 254 "project.y"
                                 { (yyval.node) = mknode2("FUNCTION", (yyvsp[0].node), NULL); }
#line 2179 "y.tab.c"
    break;

  case 60:
#line 255 "project.y"
                                                   { (yyval.node) = (yyvsp[-1].node); }
#line 2185 "y.tab.c"
    break;

  case 61:
#line 258 "project.y"
                                                                                          {
                    (yyval.node)=mknode2("IF", (yyvsp[-5].node), mknode2("IF-BODY",(yyvsp[-2].node), (yyvsp[-1].node)));
                    addCode((yyvsp[-5].node), NULL, NULL, NULL, NULL, freshLabel()); }
#line 2193 "y.tab.c"
    break;

  case 62:
#line 261 "project.y"
                                                                                                                  {
                    (yyval.node) = mknode2("IF-ELSE", mknode2("IF", (yyvsp[-10].node), mknode2("IF-BODY",(yyvsp[-7].node),(yyvsp[-6].node))), mknode2("ELSE", mknode2("ELSE-BODY",(yyvsp[-2].node),(yyvsp[-1].node)), NULL));
                    addCode((yyvsp[-10].node), NULL, NULL, NULL, NULL, freshLabel()); addCode((yyvsp[-10].node), NULL, NULL, NULL, freshLabel(), NULL); }
#line 2201 "y.tab.c"
    break;

  case 63:
#line 264 "project.y"
                                                                          {
                    (yyval.node) = mknode2("IF", (yyvsp[-2].node), mknode2("IF-BODY", (yyvsp[0].node), NULL));
                    addCode((yyvsp[-2].node), NULL, NULL, NULL, NULL, freshLabel()); }
#line 2209 "y.tab.c"
    break;

  case 64:
#line 267 "project.y"
                                                                                  {
                    (yyval.node) = mknode2("IF-ELSE", mknode2("IF", (yyvsp[-4].node), mknode2("IF-BODY", (yyvsp[-2].node), NULL)), mknode2("ELSE", mknode2("ELSE-BODY", (yyvsp[0].node), NULL),NULL));
                    addCode((yyvsp[-4].node), NULL, NULL, NULL, NULL, freshLabel()); addCode((yyvsp[-4].node), NULL, NULL, NULL, freshLabel(), NULL); }
#line 2217 "y.tab.c"
    break;

  case 65:
#line 270 "project.y"
                                                                                                  {
                    (yyval.node) = mknode2("IF-ELSE", mknode2("IF", (yyvsp[-6].node), mknode2("IF-BODY", (yyvsp[-4].node), NULL)), mknode2("ELSE", mknode2("ELSE-BODY", (yyvsp[-1].node), NULL), NULL));
                    addCode((yyvsp[-6].node), NULL, NULL, NULL, NULL, freshLabel()); addCode((yyvsp[-6].node), NULL, NULL, NULL, freshLabel(), NULL); }
#line 2225 "y.tab.c"
    break;

  case 66:
#line 273 "project.y"
                                                                                       {
                    (yyval.node) = mknode2("WHILE", (yyvsp[-5].node), mknode2("WHILE-BODY",(yyvsp[-2].node),(yyvsp[-1].node)));
                    addCode((yyvsp[-5].node), NULL, NULL, NULL, freshLabel(), NULL); addCode((yyvsp[-5].node), NULL, NULL, NULL, NULL, freshLabel());  }
#line 2233 "y.tab.c"
    break;

  case 67:
#line 276 "project.y"
                                                                           {
                    (yyval.node) = mknode2("WHILE", (yyvsp[-3].node), mknode2("WHILE-BODY", (yyvsp[-1].node), NULL));
                    addCode((yyvsp[-3].node), NULL, NULL, NULL, freshLabel(), NULL); addCode((yyvsp[-3].node), NULL, NULL, NULL, NULL, freshLabel()); }
#line 2241 "y.tab.c"
    break;

  case 68:
#line 279 "project.y"
                                                                                              {
                    (yyval.node) = mknode2("DO-WHILE", mknode2("DO-WHILE-BODY", (yyvsp[-7].node), (yyvsp[-6].node)), (yyvsp[-2].node));
                    addCode((yyvsp[-2].node), NULL, NULL, NULL, freshLabel(), NULL); addCode((yyvsp[-2].node), NULL, NULL, NULL, NULL, freshLabel()); }
#line 2249 "y.tab.c"
    break;

  case 69:
#line 282 "project.y"
                                                                                   { (yyval.node) = mknode2("FOR",(yyvsp[-5].node),mknode2("FOR-BODY", (yyvsp[-2].node), (yyvsp[-1].node))); }
#line 2255 "y.tab.c"
    break;

  case 70:
#line 283 "project.y"
                                                                        { (yyval.node) = mknode2("FOR", (yyvsp[-3].node), mknode2("FOR-BODY",(yyvsp[-1].node), NULL));}
#line 2261 "y.tab.c"
    break;

  case 71:
#line 284 "project.y"
                                    { (yyval.node) = mknode2("DECLETARION", (yyvsp[0].node), NULL); }
#line 2267 "y.tab.c"
    break;

  case 72:
#line 285 "project.y"
                                       { (yyval.node) = (yyvsp[-1].node); }
#line 2273 "y.tab.c"
    break;

  case 73:
#line 286 "project.y"
                                        { (yyval.node) = mknode2("ASSIGNMENT", (yyvsp[-1].node), NULL); }
#line 2279 "y.tab.c"
    break;

  case 74:
#line 287 "project.y"
                                  { (yyval.node) = mknode2("PROCEDURE", (yyvsp[0].node), NULL); }
#line 2285 "y.tab.c"
    break;

  case 75:
#line 288 "project.y"
                                 { (yyval.node) = mknode2("FUNCTION", (yyvsp[0].node), NULL); }
#line 2291 "y.tab.c"
    break;

  case 76:
#line 289 "project.y"
                                                   { (yyval.node) = (yyvsp[-1].node); }
#line 2297 "y.tab.c"
    break;

  case 77:
#line 292 "project.y"
                                                                                            {
                    (yyval.node)=mknode2("IF", (yyvsp[-4].node), mknode2("IF-BODY", (yyvsp[-1].node), NULL));
                    addCode((yyvsp[-4].node), NULL, NULL, NULL, NULL, freshLabel()); }
#line 2305 "y.tab.c"
    break;

  case 78:
#line 295 "project.y"
                                                                                                            {
                    (yyval.node) = mknode2("IF-ELSE", mknode2("IF", (yyvsp[-8].node), mknode2("IF-BODY", (yyvsp[-5].node), NULL)), mknode2("ELSE", mknode2("ELSE-BODY", (yyvsp[-1].node), NULL), NULL));
                    addCode((yyvsp[-8].node), NULL, NULL, NULL, NULL, freshLabel()); addCode((yyvsp[-8].node), NULL, NULL, NULL, freshLabel(), NULL); }
#line 2313 "y.tab.c"
    break;

  case 79:
#line 298 "project.y"
                                                                          {
                    (yyval.node) = mknode2("IF", (yyvsp[-2].node), mknode2("IF-BODY", (yyvsp[0].node), NULL));
                    addCode((yyvsp[-2].node), NULL, NULL, NULL, NULL, freshLabel()); }
#line 2321 "y.tab.c"
    break;

  case 80:
#line 301 "project.y"
                                                                                  {
                    (yyval.node) = mknode2("IF-ELSE", mknode2("IF", (yyvsp[-4].node), mknode2("IF-BODY", (yyvsp[-2].node), NULL)), mknode2("ELSE", mknode2("ELSE-BODY", (yyvsp[0].node), NULL),NULL));
                    addCode((yyvsp[-4].node), NULL, NULL, NULL, NULL, freshLabel()); addCode((yyvsp[-4].node), NULL, NULL, NULL, freshLabel(), NULL); }
#line 2329 "y.tab.c"
    break;

  case 81:
#line 304 "project.y"
                                                                                                  {
                    (yyval.node) = mknode2("IF-ELSE", mknode2("IF", (yyvsp[-6].node), mknode2("IF-BODY", (yyvsp[-4].node), NULL)), mknode2("ELSE", mknode2("ELSE-BODY", (yyvsp[-1].node), NULL), NULL));
                    addCode((yyvsp[-6].node), NULL, NULL, NULL, NULL, freshLabel()); addCode((yyvsp[-6].node), NULL, NULL, NULL, freshLabel(), NULL); }
#line 2337 "y.tab.c"
    break;

  case 82:
#line 307 "project.y"
                                                                                   {
                    (yyval.node) = mknode2("WHILE", (yyvsp[-4].node), mknode2("WHILE-BODY",(yyvsp[-1].node), NULL));
                    addCode((yyvsp[-4].node), NULL, NULL, NULL, freshLabel(), NULL); addCode((yyvsp[-4].node), NULL, NULL, NULL, NULL, freshLabel()); }
#line 2345 "y.tab.c"
    break;

  case 83:
#line 310 "project.y"
                                                                       {
                    (yyval.node) = mknode2("WHILE", (yyvsp[-3].node), mknode2("WHILE-BODY",(yyvsp[-1].node), NULL));
                    addCode((yyvsp[-3].node), NULL, NULL, NULL, freshLabel(), NULL); addCode((yyvsp[-3].node), NULL, NULL, NULL, NULL, freshLabel()); }
#line 2353 "y.tab.c"
    break;

  case 84:
#line 313 "project.y"
                                                                                           {
                    (yyval.node) = mknode2("DO-WHILE", mknode2("DO-WHILE-BODY",(yyvsp[-6].node),NULL), (yyvsp[-2].node));
                    addCode((yyvsp[-2].node), NULL, NULL, NULL, freshLabel(), NULL); addCode((yyvsp[-2].node), NULL, NULL, NULL, NULL, freshLabel()); }
#line 2361 "y.tab.c"
    break;

  case 85:
#line 316 "project.y"
                                                                                {(yyval.node)=mknode2("FOR",(yyvsp[-4].node), mknode2("FOR-BODY",(yyvsp[-1].node), NULL));}
#line 2367 "y.tab.c"
    break;

  case 86:
#line 317 "project.y"
                                                                    {(yyval.node)=mknode2("FOR",(yyvsp[-3].node), mknode2("FOR-BODY",(yyvsp[-1].node), NULL));}
#line 2373 "y.tab.c"
    break;

  case 87:
#line 318 "project.y"
                                   { (yyval.node) = (yyvsp[-1].node); }
#line 2379 "y.tab.c"
    break;

  case 88:
#line 319 "project.y"
                                    { (yyval.node) = mknode2("ASSIGNMENT", (yyvsp[-1].node), NULL); }
#line 2385 "y.tab.c"
    break;

  case 89:
#line 320 "project.y"
                                               { (yyval.node) = (yyvsp[-1].node); }
#line 2391 "y.tab.c"
    break;

  case 90:
#line 323 "project.y"
                                    { (yyval.node) = (yyvsp[0].node); }
#line 2397 "y.tab.c"
    break;

  case 91:
#line 323 "project.y"
                                                                                    { (yyval.node) = mknode2("STRING", (yyvsp[-1].node), NULL); }
#line 2403 "y.tab.c"
    break;

  case 92:
#line 326 "project.y"
                                                       { (yyval.node) = mknode2((yyvsp[-2].string), (yyvsp[-1].node), NULL); }
#line 2409 "y.tab.c"
    break;

  case 93:
#line 329 "project.y"
                           { (yyval.node) = mkleaf((yyvsp[0].string)); }
#line 2415 "y.tab.c"
    break;

  case 94:
#line 330 "project.y"
                                             { (yyval.node) = mknode2((yyvsp[-2].string), (yyvsp[0].node),NULL); }
#line 2421 "y.tab.c"
    break;

  case 95:
#line 331 "project.y"
                                                     { (yyval.node) = mknode2("ASSIGN-DECLER", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2427 "y.tab.c"
    break;

  case 96:
#line 332 "project.y"
                                   { (yyval.node) = mknode2("ASSIGN-DECLER", (yyvsp[0].node), NULL); }
#line 2433 "y.tab.c"
    break;

  case 97:
#line 335 "project.y"
                                 { (yyval.node) = (yyvsp[0].node); }
#line 2439 "y.tab.c"
    break;

  case 98:
#line 338 "project.y"
                                                                { (yyval.node) = mknode2((yyvsp[-5].string), (yyvsp[0].node) , mkleaf((yyvsp[-3].string)));}
#line 2445 "y.tab.c"
    break;

  case 99:
#line 339 "project.y"
                                             { (yyval.node) = mknode2((yyvsp[-3].string), NULL, mkleaf((yyvsp[-1].string))); }
#line 2451 "y.tab.c"
    break;

  case 100:
#line 340 "project.y"
                                                                   { (yyval.node) = mknode2((yyvsp[-5].string), NULL, mknode2((yyvsp[-3].string), NULL, mkleaf((yyvsp[0].string)))); }
#line 2457 "y.tab.c"
    break;

  case 101:
#line 341 "project.y"
                                                                                      { (yyval.node) = mknode2((yyvsp[-7].string), (yyvsp[0].node), mknode2((yyvsp[-5].string), NULL, mkleaf((yyvsp[-2].string)))); }
#line 2463 "y.tab.c"
    break;

  case 102:
#line 344 "project.y"
                        {(yyval.string) = strdup(yytext); }
#line 2469 "y.tab.c"
    break;

  case 104:
#line 347 "project.y"
                         { (yyval.string) = strdup(yytext); }
#line 2475 "y.tab.c"
    break;

  case 105:
#line 348 "project.y"
                               { (yyval.string) = strdup(yytext); }
#line 2481 "y.tab.c"
    break;

  case 106:
#line 351 "project.y"
                                                   {(yyval.node)=mknode2("FUNC CALL",mkleaf((yyvsp[-2].string)),(yyvsp[-1].node));}
#line 2487 "y.tab.c"
    break;

  case 107:
#line 354 "project.y"
                                         {(yyval.node)=mknode2((yyvsp[-2].string),(yyvsp[0].node),NULL);}
#line 2493 "y.tab.c"
    break;

  case 108:
#line 355 "project.y"
                           {(yyval.node)=mkleaf((yyvsp[0].string));}
#line 2499 "y.tab.c"
    break;

  case 109:
#line 356 "project.y"
                                              {(yyval.node)=mknode2((yyvsp[-2].string),(yyvsp[0].node),NULL);}
#line 2505 "y.tab.c"
    break;

  case 110:
#line 357 "project.y"
                                { (yyval.node)=mkleaf((yyvsp[0].string)); }
#line 2511 "y.tab.c"
    break;

  case 111:
#line 358 "project.y"
                        {(yyval.node)=NULL;}
#line 2517 "y.tab.c"
    break;

  case 112:
#line 361 "project.y"
                                       {
                    (yyval.node) = mknode2("||", (yyvsp[0].node), (yyvsp[-2].node)); addCode((yyvsp[-2].node), NULL, NULL, NULL,NULL ,freshLabel()); addCode((yyvsp[-2].node), NULL, NULL, NULL,freshLabel() ,NULL); }
#line 2524 "y.tab.c"
    break;

  case 113:
#line 363 "project.y"
                                        { (yyval.node) = mknode2("&&", (yyvsp[0].node), (yyvsp[-2].node)); }
#line 2530 "y.tab.c"
    break;

  case 114:
#line 364 "project.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 2536 "y.tab.c"
    break;

  case 115:
#line 367 "project.y"
                                       { (yyval.node) = mknode2("||", (yyvsp[0].node), (yyvsp[-2].node)); addCode((yyvsp[-2].node), NULL, NULL, NULL, freshLabel(), freshLabel()); }
#line 2542 "y.tab.c"
    break;

  case 116:
#line 368 "project.y"
                                        { (yyval.node) = mknode2("&&", (yyvsp[0].node), (yyvsp[-2].node)); }
#line 2548 "y.tab.c"
    break;

  case 117:
#line 369 "project.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 2554 "y.tab.c"
    break;

  case 118:
#line 372 "project.y"
                                          { (yyval.node) = mknode2("+", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2560 "y.tab.c"
    break;

  case 119:
#line 373 "project.y"
                                       { (yyval.node) = mknode2("-", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2566 "y.tab.c"
    break;

  case 120:
#line 374 "project.y"
                                       { (yyval.node) = mknode2("*", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2572 "y.tab.c"
    break;

  case 121:
#line 375 "project.y"
                                     { (yyval.node) = mknode2("/", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2578 "y.tab.c"
    break;

  case 122:
#line 376 "project.y"
                                     { (yyval.node) = mknode2("!=", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2584 "y.tab.c"
    break;

  case 123:
#line 377 "project.y"
                                     { (yyval.node) = mknode2("==", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2590 "y.tab.c"
    break;

  case 124:
#line 378 "project.y"
                                     { (yyval.node) = mknode2(">", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2596 "y.tab.c"
    break;

  case 125:
#line 379 "project.y"
                                     { (yyval.node) = mknode2(">", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2602 "y.tab.c"
    break;

  case 126:
#line 380 "project.y"
                                     { (yyval.node) = mknode2("<", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2608 "y.tab.c"
    break;

  case 127:
#line 381 "project.y"
                                     { (yyval.node) = mknode2("<=", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2614 "y.tab.c"
    break;

  case 128:
#line 382 "project.y"
                             { (yyval.node) = mknode2("!", NULL, (yyvsp[0].node)); }
#line 2620 "y.tab.c"
    break;

  case 129:
#line 383 "project.y"
                                     { (yyval.node) = mknode2("PTR",(yyvsp[0].node), NULL); }
#line 2626 "y.tab.c"
    break;

  case 130:
#line 384 "project.y"
                                     { (yyval.node) = mknode2("&", NULL, (yyvsp[0].node)); }
#line 2632 "y.tab.c"
    break;

  case 131:
#line 385 "project.y"
                            { (yyval.node) = mkleaf((yyvsp[0].string)); }
#line 2638 "y.tab.c"
    break;

  case 132:
#line 386 "project.y"
                              { (yyval.node) = (yyvsp[0].node); }
#line 2644 "y.tab.c"
    break;

  case 133:
#line 387 "project.y"
                               { (yyval.node) = mknode2("|", mkleaf((yyvsp[-1].string)), NULL); }
#line 2650 "y.tab.c"
    break;

  case 134:
#line 388 "project.y"
                                   { (yyval.node) = mknode2("|", mkleaf((yyvsp[-1].string)), NULL); }
#line 2656 "y.tab.c"
    break;

  case 135:
#line 389 "project.y"
                                             { (yyval.node) = mknode2((yyvsp[-3].string), mkleaf((yyvsp[-1].string)), NULL); }
#line 2662 "y.tab.c"
    break;

  case 136:
#line 390 "project.y"
                        { (yyval.node) = mkleaf((yyvsp[0].string)); }
#line 2668 "y.tab.c"
    break;

  case 137:
#line 391 "project.y"
                                         { (yyval.node) = mknode2("()", NULL, (yyvsp[-1].node)); }
#line 2674 "y.tab.c"
    break;

  case 138:
#line 394 "project.y"
                                                        { (yyval.node) = mknode2("+", mkleaf((yyvsp[-3].string)),mkleaf((yyvsp[-1].string))); }
#line 2680 "y.tab.c"
    break;

  case 139:
#line 395 "project.y"
                                                         { (yyval.node) = mknode2("+", mkleaf((yyvsp[-3].string)),mkleaf((yyvsp[-1].string))); }
#line 2686 "y.tab.c"
    break;

  case 140:
#line 396 "project.y"
                                                        { (yyval.node) = mknode2("+", mkleaf((yyvsp[-3].string)),mkleaf((yyvsp[-1].string))); }
#line 2692 "y.tab.c"
    break;

  case 141:
#line 397 "project.y"
                                                       { (yyval.node) = mknode2("+", mkleaf((yyvsp[-3].string)),mkleaf((yyvsp[-1].string))); }
#line 2698 "y.tab.c"
    break;

  case 142:
#line 398 "project.y"
                           { (yyval.node) = mknode2((yyvsp[0].string), NULL,NULL); }
#line 2704 "y.tab.c"
    break;

  case 143:
#line 399 "project.y"
                                 { (yyval.node) = (yyvsp[0].node); }
#line 2710 "y.tab.c"
    break;

  case 144:
#line 402 "project.y"
                                                  { (yyval.node) = mknode2("CODE BLOCK", (yyvsp[-1].node), (yyvsp[0].node)); }
#line 2716 "y.tab.c"
    break;

  case 145:
#line 405 "project.y"
                                              { (yyval.node) = mknode2("STATEMENT", (yyvsp[-1].node), (yyvsp[0].node)); }
#line 2722 "y.tab.c"
    break;

  case 146:
#line 405 "project.y"
                                                                                       { (yyval.node) = NULL; }
#line 2728 "y.tab.c"
    break;

  case 147:
#line 408 "project.y"
                                               { (yyval.node) = mknode2("STATEMENT", mknode2("DECLETARION", (yyvsp[-1].node), NULL), (yyvsp[0].node)); }
#line 2734 "y.tab.c"
    break;

  case 148:
#line 408 "project.y"
                                                                                                                      { (yyval.node) = NULL; }
#line 2740 "y.tab.c"
    break;

  case 149:
#line 411 "project.y"
                            { (yyval.string) = strdup(yytext); }
#line 2746 "y.tab.c"
    break;

  case 150:
#line 412 "project.y"
                             { (yyval.string) = strdup(yytext); }
#line 2752 "y.tab.c"
    break;

  case 151:
#line 413 "project.y"
                               { (yyval.string) = strdup(yytext); }
#line 2758 "y.tab.c"
    break;

  case 152:
#line 414 "project.y"
                             { (yyval.string) = strdup(yytext); }
#line 2764 "y.tab.c"
    break;

  case 153:
#line 415 "project.y"
                              { (yyval.string) = strdup(yytext); }
#line 2770 "y.tab.c"
    break;

  case 154:
#line 416 "project.y"
                             { (yyval.string) = strdup(yytext); }
#line 2776 "y.tab.c"
    break;

  case 155:
#line 419 "project.y"
                                         { (yyval.node) = mknode2("RETURN",(yyvsp[-1].node),NULL); }
#line 2782 "y.tab.c"
    break;

  case 156:
#line 420 "project.y"
                        { (yyval.node)=NULL; }
#line 2788 "y.tab.c"
    break;

  case 157:
#line 423 "project.y"
                                         { (yyval.node) = mknode2("RETURN",(yyvsp[-1].node),NULL); }
#line 2794 "y.tab.c"
    break;


#line 2798 "y.tab.c"

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 426 "project.y"

#include "lex.yy.c"
int main() {
	yyparse();
	return 0;
}

int tabCount1 = 0;
int tabCount2 = 0;

struct node* mkleaf(char* token) {
	node* newnode=(node*)malloc(sizeof(node));
	char* newstr;

	if(token) {
		newstr=(char*)malloc(sizeof(token)+1);
		newstr[sizeof(token)]='\0';
		strcpy(newstr,token);
	}
	else {
        newstr=(char*)malloc(1);
		strcpy(newstr,"");
		
	}
    newnode->left=NULL;
	newnode->right=NULL;
	newnode->token=newstr;
	return newnode;
}


struct node* mknode2(char* token,node*left,node*right) {
    node* newnode = mkleaf(token);
	newnode->left=left;
	newnode->right=right;
    return newnode;
}

void printTabs1() {
	for(int i=0;i<tabCount1;i++){
		printf(".  ");	
	}
}

void printTabs2() {
	int i;
	for(i=0;i<tabCount2;i++) {
		printf(".  ");
	}
}

void openTag() {
	printf("(%d)" , tabCount1);	
}

void closeTag() {
	printf("(/%d)" , tabCount1);	
}

int printtree(node* tree) {
	tabCount1++;
    if (tree->left!=NULL || tree->right!=NULL){
        if(strcmp(tree->token," ")!=0){
        printTabs1();
        printf("(");
        printf("%s\n",tree->token);
        tabCount2=tabCount1;
        }
    }
    else if(tree->left==NULL && tree->right==NULL){
        printTabs1();
        printf("(");
        printf("%s",tree->token);
        printf(")\n");
        }
    
    if(tree->left){
        printf("LEFT: ");
        printtree(tree->left);
    }
    if(tree->right)
    {
        printf("RIGHT: ");
        printtree(tree->right);
    }
    if(tree->left != NULL || tree->right != NULL){
        if(strcmp(tree->token," ") !=0 ) {
            printTabs2();
            printf(")\n");
            tabCount2--;
        }
    }
    tabCount1--;
    return 1;

}

void syntaxMKscope(node *tree) {
    if (tree == NULL) { return;/*FINISH*/}
    else if (!strcmp(tree->token, "FUNCTION") || !strcmp(tree->token, "PROCEDURE")) {
        current_scope++; // JUMP TO NEXT SCOPE LEVEL //
        int args_count = 0;
        Function *function = NULL;
        Arguments *function_args = NULL;
        if (strcmp(tree->left->left->left->token, "ARGS NONE")) {
            function_args = mkargs(tree->left->left->left->left, &args_count);
        }
        // FUNCTION CREATION //
        function = create_function(/*FUNCTION NAME*/ tree->left->token, function_args,/*FUNCTION TYPE*/ tree->left->left->token,/*ARGS COUNT*/ args_count, NULL);
        // CHECKS IF THE FUNCTION ALREADY EXIST IN THE CURRENT SCOPE //
        func_existence_check(tree->left->token);
        // SCOPE CREATION //
        code_scope *new_scope = create_scope("FUNCTION", function);
        push(new_scope);
        syntaxMKscope(tree->left->right->left); // MOVING INTO THE BODY //
        current_scope--; // JUMP TO PREVIOUS SCOPE LEVEL //
        syntaxMKscope(tree->left->right->right); // MOVING INTO THE BODY //
        syntaxMKscope(tree->right); // MOVE TO NEXT FUNCTION //
    }
    
    else if (!strcmp(tree->token, "CODE")) {
        push(NULL);
        syntaxMKscope(tree->right);
    }
    
    else if (!strcmp(tree->token, "STATEMENT")) {
        syntaxMKscope(tree->left);
        syntaxMKscope(tree->right);
    }
    
    else if (!strcmp(tree->token, "DECLETARION")) {
        add_varaiable(tree->left);
    }
    
    else if (!strcmp(tree->token, "FUNC CALL")) {
        current_scope++;
        func_call_existence_check(tree->left->token, current_scope, tree);
        current_scope--;
    }
    
    else if (!strcmp(tree->token, "IF-ELSE")) {
        syntaxMKscope(tree->left); // IF //
        syntaxMKscope(tree->right); // ELSE //
    }
    
    else if (!strcmp(tree->token, "WHILE")) {
        boolean_statement_check(tree->left); // IF VARS //
        syntaxMKscope(tree->right);
    }
    
    else if (!strcmp(tree->token, "WHILE-BODY")) {
        current_scope++;
        code_scope *new_scope = create_scope("WHILE", NULL);
        push(new_scope);
        syntaxMKscope(tree->left);
        syntaxMKscope(tree->right);
        current_scope--;
    }
    
    else if (!strcmp(tree->token, "DO-WHILE")) {
        boolean_statement_check(tree->right); // IF VARS //
        syntaxMKscope(tree->left);
    }
    
    else if (!strcmp(tree->token, "DO-WHILE-BODY")) {
        current_scope++;
        code_scope *new_scope = create_scope("DO-WHILE", NULL);
        push(new_scope);
        syntaxMKscope(tree->left);
        syntaxMKscope(tree->right);
        current_scope--;
    }
    
    else if (!strcmp(tree->token,"CODE BLOCK")) {
        current_scope++;
        code_scope *new_scope = create_scope("CODE-BLOCK", NULL);
        push(new_scope);
        syntaxMKscope(tree->left);
        syntaxMKscope(tree->right);
        current_scope--;
    }
    
    else if (!strcmp(tree->token, "IF")) {
        addCode(tree, NULL, NULL, freshLabel(), NULL, NULL);
        boolean_statement_check(tree->left); // IF VARS //
        syntaxMKscope(tree->right);
    }
    
    else if (!strcmp(tree->token, "IF-BODY")) {
        current_scope++;
        code_scope *scope = stack;
        code_scope *new_scope = create_scope("IF", NULL);
        push(new_scope);
        syntaxMKscope(tree->left);
        syntaxMKscope(tree->right);
        current_scope--;
    }
    
    else if (!strcmp(tree->token, "ELSE")) {
        syntaxMKscope(tree->left); // MOVE TO ELSE BODY //
    }
    
    else if (!strcmp(tree->token, "ELSE-BODY")) {
        current_scope++;
        code_scope *scope = stack;
        code_scope *new_scope = create_scope("ELSE", NULL);
        push(new_scope);
        syntaxMKscope(tree->left);
        syntaxMKscope(tree->right);
        current_scope--;
    }
    
    else if (!strcmp(tree->token, "RETURN")) {
        current_scope++;
        code_scope* code = stack;
        while (strcmp(code->name,"FUNCTION")) {
            code = code->previous_scope;
        }
        return_check(tree->left, code->func->return_type);
        current_scope--;
    }
    
    else if (!strcmp(tree->token, "|")) {
    }
    
    else if (!strcmp(tree->token, "ASSIGNMENT")) {
        assignment(tree->left);
    }
    
    else if (!strcmp(tree->token, "FOR")) {
        for_initialization_check(tree->left->left);
        for_condition_check(tree->left->right->left);
        for_initialization_check(tree->left->right->right);
        current_scope++;
        code_scope *scope = stack;
        code_scope *new_scope = create_scope("FOR", NULL);
        push(new_scope);
        syntaxMKscope(tree->right->left); // MOVING INTO FOR BODY //
        syntaxMKscope(tree->right->right); // MOVING INTO FOR BODY //
        current_scope--;
    }
    else {
        syntaxMKscope(tree->left);
        syntaxMKscope(tree->right);
    }
}

void add_varaiable(node* tree) {
    if (!strcmp(tree->token, "STRING")) {
        add_string_varaiable(tree->left);
    }
    else {
        char *var_type = tree->token;
        var_type[strlen(tree->token)] = '\0'; // VAR TYPE //
        add_varaiable_rec(tree->left, var_type);
    }
}

void add_string_varaiable(node* tree) {
    while (tree) {
        if (var_redeclaration_check(tree->token)) {
            stack->var->name[stack->countvar] = strdup(tree->token);
            stack->var->type[stack->countvar] = "STRING";
            char* type = var_declaration_check(tree->right->token, current_scope);
            if (strcmp(type, "INT")) {
                printf("\033[31mError - string index expects type 'INT', but index type '%s'.\n\033[0m", type);
                exit(1);
                //stack->var->len[stack->countvar++] = NULL;
            }
            else stack->var->len[stack->countvar++] = strdup(tree->right->token);
        }
        tree = tree->left;
    }
}

void assignment(node* tree) {
    char* type;
    if (!strcmp(tree->left->token, "PTR") || !strcmp(tree->left->token, "&")) {
        type = var_declaration_check(tree->left->left->token, current_scope);
    } else {
        type = var_declaration_check(tree->left->token, current_scope);
    }
    if (strcmp(type, "NULL")) {
        if (!strcmp(type, "STRING")) {
            if (tree->left->left != NULL) {
                char *index_type = var_declaration_check(tree->left->left->token, current_scope);
                if (strcmp(index_type, "INT")) {
                    printf("\033[31mError - string index expects type 'INT', but index type '%s'.\n\033[0m", type);
                    exit(1);
                }
                else insert_values_into_vars(tree->right, "CHAR");
            }
            else insert_values_into_vars(tree->right, "STRING");
        }
        else {
            insert_values_into_vars(tree->right, type);
        }
    }
}

void add_varaiable_rec(node* tree, char* var_type) {
    if (tree == NULL) { /*FINISH*/ }
    else if (!strcmp(tree->token, "=")) {
        if (var_redeclaration_check(tree->left->token)) {
            stack->var->name[stack->countvar] = (char*)malloc(sizeof(char));
            stack->var->name[stack->countvar] = tree->left->token;
            stack->var->name[stack->countvar][strlen(tree->left->token)] = '\0';
            stack->var->type[stack->countvar] = var_type;
            stack->var->value[stack->countvar] = (char*)malloc(sizeof(char));
            stack->var->value[stack->countvar] = insert_values_into_vars(tree->right, var_type);
            stack->var->len[stack->countvar++] = NULL;
        }
    }
    else if (!strcmp(tree->token, "ASSIGN-DECLER")) {
        add_varaiable_rec(tree->left, var_type);
        add_varaiable_rec(tree->right, var_type);
    }
    else { // ID TOKEN DOESN'T HAVE A RIGHT NODE //
        if (var_redeclaration_check(tree->token)) {
            stack->var->name[stack->countvar] = (char*)malloc(sizeof(char));
            stack->var->name[stack->countvar] = tree->token;
            stack->var->name[stack->countvar][strlen(tree->token)] = '\0';
            stack->var->value[stack->countvar] = NULL;
            stack->var->type[stack->countvar] = var_type;
            stack->var->len[stack->countvar++] = NULL;
        }
        add_varaiable_rec(tree->left, var_type);
    }
}

// CHECKS IF THE FUNCTION ALREADY EXIST IN THE CURRENT SCOPE //
void func_existence_check(char* token) {
    int scope_level = current_scope;
    code_scope *search = stack;
    while (search->scope_level != 0) {
        if (search->scope_level == scope_level && !strcmp(search->func->name, token)) {
            printf("\033[31mFunction %s() already exists.\n\033[0m", token);
            exit(1);
        }
        search = search->previous_scope;
    }
}

char* func_call_existence_check(char* token, int scope_level, node* tree) {
    code_scope *search;
    while (scope_level != 0) {
        search = stack;
        while(search->scope_level != 1) {
            if (search->func) {
                if (search->scope_level == scope_level && !strcmp(search->func->name, token)) {
                    func_call_args_check(search, tree);
                    return search->func->return_type;
                }
            }
            search = search->previous_scope;
        }
        scope_level--;
    }
    search = stack;
    while (search->scope_level != 0) {
        if (search->scope_level == 1 && !strcmp(search->func->name, token)) {
            func_call_args_check(search, tree);
            return search->func->return_type;
        }
        search = search->previous_scope;
    }
    printf("\033[31mFunction Error - function %s() doesn't exist.\n\033[0m", token);
    exit(1);
    return NULL;
}

void func_call_args_check(code_scope *scope, node* tree) {
    int func_call_args_count = 0;
    if (tree->right) {
        node* check = tree;
        char *type = var_declaration_check(check->right->token, current_scope);
        func_call_args_type_check(scope, func_call_args_count, type, check->right->token);
        check = check->right->left;
        func_call_args_count++;
        while (check) {
            char *type2 = var_declaration_check(check->token, current_scope);
            func_call_args_type_check(scope, func_call_args_count, type2, check->token);
            check = check->left;
            func_call_args_count++;
        }
    }
    if (func_call_args_count != scope->func->count_args) {
        printf("\033[31mFunction Error - amount of args in func call %s() don't match.\n\033[0m", scope->func->name);
        exit(1);
    }
}

void func_call_args_type_check(code_scope *scope, int index, char* type , char* token) {
    if (index >= scope->func->count_args) { return; }
    if (strcmp(scope->func->args->type[index], type)) {
        printf("\033[31mFunction Error - function ‘%s()’ expects type '%s', but argument %d has type '%s'.\n\033[0m", scope->func->name,scope->func->args->type[index],index+1, type);
        exit(1);
    }
}

char* insert_values_into_vars(node* tree, char* var_type) {
    char *value = (char*)malloc(sizeof(char));
    if (!strcmp(tree->token, "+") || !strcmp(tree->token, "-") || !strcmp(tree->token, "*") || !strcmp(tree->token, "/")) {
        if (!strcmp(var_type, "CHAR") || !strcmp(var_type, "STRING")) {
            printf("\033[31mError - can't use operator '%s' on '%s' type variables.\n\033[0m", tree->token, var_type);
        }
        strcat(value, insert_values_into_vars(tree->left, var_type));
        strcat(value,tree->token);
        strcat(value,insert_values_into_vars(tree->right, var_type));
        return value;
    }
    else if (!strcmp(tree->token, "()")) {
        return insert_values_into_vars(tree->right, var_type);
    }
    
    else if (!strcmp(tree->token, "NULL")) {
        if (strcmp(var_type, "INTP") && strcmp(var_type, "CHARP") && strcmp(var_type, "REALP")) {
            printf("\033[31mError - can't assign 'NULL' to %s.\n\033[0m", var_type);
            exit(1);
        }
    }
    else if (!strcmp(tree->token, "PTR")) {
        char *type = strdup(var_declaration_check(tree->left->token, current_scope));
        if (strcmp(type, "INTP") && strcmp(type, "CHARP") && strcmp(type, "REALP")) {
            printf("\033[31mError - can't add '*' to %s.\n\033[0m", tree->left->token);
            exit(1);
        }
        else if (strcmp(type, var_type)) {
            printf("\033[31mError - can't assign %s%s to '%s' type.\n\033[0m", tree->token,tree->left->token, var_type);
            exit(1);
        }
        char *value = (char*)malloc(sizeof(char));
        value = strcpy(value, "*"); strcat(value, tree->left->token);
        return value;
    }
    else if (!strcmp(tree->token, "FUNC CALL")) {
        current_scope++;
        char *type = func_call_existence_check(tree->left->token, current_scope, tree);
        if (strcmp(type, var_type)) {
            printf("\033[31mError - function %s() can't return '%s' to '%s'.\n\033[0m", tree->left->token, type, var_type);
            exit(1);
        }
        current_scope--;
        return tree->left->token;
    }
    else if (!strcmp(tree->token, "|")) {
        char *type = var_declaration_check(tree->left->token, current_scope);
        if (strcmp(type, "STRING") || strcmp(var_type, "INT")) {
            printf("\033[31mError - can't assign length of %s %s to '%s' type.\n\033[0m", type, tree->left->token, var_type);
            exit(1);
        }
        return tree->left->token;
    }
    else if (!strcmp(tree->token, "&")) {
        char *type = var_declaration_check(tree->right->token, current_scope);
        if (!strcmp(type, "BOOL") || !strcmp(type, "INTP") || !strcmp(type, "CHARP") ||!strcmp(type, "REALP")) {
            printf("\033[31mError - can't use '&' on '%s' type.\n\033[0m", type);
            exit(1);
        }
    }
    else if (!strcmp(tree->token, "!")) {
            char *type = var_declaration_check(tree->right->token, current_scope);
            if (strcmp(type, "BOOL")) {
                printf("\033[31mError - can't use '!' on '%s' type.\n\033[0m", type);
                exit(1);
            }
    }
    
    else if (!strcmp(tree->token, "<") || !strcmp(tree->token, ">") || !strcmp(tree->token, "<=") || !strcmp(tree->token, ">=") || !strcmp(tree->token, "<==") || !strcmp(tree->token, "!=")) {
        printf("\033[31mError - Can't use %s in assignment.\n\033[0m", tree->token);
        exit(1);
    }
    else {
        char *type = strdup(var_declaration_check(tree->token, current_scope));
        if (strcmp(type, var_type)) {
            printf("\033[31mError - can't assign %s to '%s' type.\n\033[0m", tree->token, var_type);
            exit(1);
        }
        return tree->token;
    }
}

void return_check(node* tree, char* var_type) {
    char *value = (char*)malloc(sizeof(char));
    if (!strcmp(tree->token, "+") || !strcmp(tree->token, "-") || !strcmp(tree->token, "*") || !strcmp(tree->token, "/")) {
        return_check(tree->left, var_type);
        return_check(tree->right, var_type);
    }
    else if (!strcmp(tree->token, "FUNC CALL")) {
        current_scope++;
        char *type = func_call_existence_check(tree->left->token, current_scope, tree);
        if (strcmp(type, var_type)) {
            printf("\033[31mError - function %s() can't return '%s' to '%s'.\n\033[0m", tree->left->token, type, var_type);
            exit(1);
        }
        current_scope--;
    }
    else {
        char *type = strdup(var_declaration_check(tree->token, current_scope));
        if (strcmp(type, var_type)) {
            printf("\033[31mFunction Error - %s %s is not a valid return type.\n\033[0m", type, tree->token);
            exit(1);
        }
    }
}

// CHECKS IF THE VALUE HAS ALREADY BEEN DECLARED IN THE SCOPE //
bool var_redeclaration_check(char* token) {
    code_scope *search = stack;
    int level = current_scope;
    while (strcmp(search->name, "FUNCTION") != 0 && strcmp(search->name, "CODE-BLOCK") != 0) {
        if (search->scope_level == level) {
            for (int i = 0; i < search->countvar; i++) {
                if (!strcmp(token, search->var->name[i])) {
                    printf("\033[31mError - redeclaration of %s.\n\033[0m", token);
                    exit(1);
                    return false;
                    
                }
            }
        }
        search = search->previous_scope;
        level--;
    }
    for (int i = 0; i < search->countvar; i++) {
        if (!strcmp(token, search->var->name[i])) {
            printf("\033[31mError - redeclaration of %s.\n\033[0m", token);
            exit(1);
            return false;
        }
    }
    return true;
}

// CHECKS IF THE VALUE HAS BEEN DECLARED IN THE HIS SCOPE OR IN THE PREVIOUS SCOPES //
char* var_declaration_check(char* token, int scope_level) {
    int n;
    if (token[0] == '\"') { return "STRING"; }
    char* dot_position = strchr(token, '.');
    if (dot_position) { return "REAL"; }
    if (sscanf(token, "%d", &n) == 1) { return "INT"; } // IF THE TOKEN IS A NUMBER - NO DECLERATION CHECK IS NEEDED //
    if (token[0] == '\'' && token[2] == '\'') { return "CHAR"; }
    if (!strcmp(token, "TRUE") || !strcmp(token, "true") || !strcmp(token, "FALSE") || !strcmp(token, "false") ) { return "BOOL"; }
    if (scope_level == 0) {
        printf("\033[31mError - '%s' is not declered.\n\033[0m", token);
        exit(1);
        return "NULL";
    }
    code_scope *search = stack;
    while (search->scope_level != 0) {
        if (search->scope_level == scope_level) {
            break;
        }
        search = search->previous_scope;
    }
    for (int i = 0; i < search->countvar; i++) {
        if (!strcmp(token, search->var->name[i])) {
            return search->var->type[i];
        }
    }
    return var_declaration_check(token, scope_level-1);
}

code_scope* create_scope(char* name, Function* function) {
    code_scope *scope = (code_scope*)malloc(sizeof(code_scope));
    scope->name = name;
    scope->scope_level = current_scope;
    scope->var = (Varaiable*)malloc(sizeof(Varaiable));
    scope->var->name = (char**)malloc(sizeof(char*) * 256);
    scope->var->value = (char**)malloc(sizeof(char*) * 256);
    scope->var->type = (char**)malloc(sizeof(char*) * 256);
    scope->var->len = (char**)malloc(sizeof(char*) * 256);
    scope->func = function;
    scope->countvar = 0;
    if (function != NULL) {
        for (int i = 0; i < scope->func->count_args; i++) {
            scope->var->name[scope->countvar] = strdup(scope->func->args->name[i]);
            scope->var->type[scope->countvar] = strdup(scope->func->args->type[i]);
            scope->countvar++;
        }
    }
    scope->next_scope = NULL;
    scope->previous_scope = NULL;
    return scope;
}

Function* create_function(char *name, Arguments *args, char *return_type, int count_args, code_scope *code_scope) {
    Function *function = (Function*)malloc(sizeof(Function));
    function->name = name;
    function->args = args;
    function->return_type = strdup(return_type);
    function->count_args = count_args;
    return function;
}

void push(code_scope *new_scope) {
    if (new_scope == NULL) {
        stack = mkcode("CODE");
    }
    else {
        new_scope->previous_scope = stack;
        stack = NULL;
        stack = new_scope;
    }
}

Arguments* mkargs(node *tree, int *args_count) {
    Arguments *args = (Arguments*)malloc(sizeof(Arguments));
    args->type = (char**)malloc(sizeof(char*) * 256);
    args->name = (char**)malloc(sizeof(char*) * 256);
    args->len = (char**)malloc(sizeof(char*) * 256);
    char *token = NULL ,*type_token = NULL;
    int index = 0;
    while (tree) {
        type_token = strdup(tree->token);
        node* right = tree->right;
        while (right) {
            args->type[index] = strdup(type_token);
            args->name[index] = malloc(sizeof(right->token) + 1);
            args->name[index++] = strdup(right->token);
            right = right->right;
            (*args_count)++;
        }
        tree = tree->left;
    }
    return args;
}

        
code_scope* mkcode(char* name) {
    code_scope *newlevel = (code_scope*)malloc(sizeof(code_scope));
    newlevel->scope_level = current_scope;
    newlevel->name = name;
    newlevel->var = NULL;
    newlevel->countvar = 0;
    newlevel->func = NULL;
    newlevel->countfunc = 0;
    newlevel->next_scope = NULL;
    newlevel->previous_scope = NULL;
    return newlevel;
}

int yyerror(char *e) {
	int yydebug = 1;
	fflush(stdout);
	fprintf(stderr,"Error %s at line %d\n" ,e, yylineno);
	fprintf(stderr, "Does not accept '%s'\n",(yytext));
	return 0;
}

void boolean_statement_check(node* tree) {
    char *left, *right;
    if (tree != NULL){
        if ((!strcmp(tree->token,"<") || !strcmp(tree->token,">") || !strcmp(tree->token,"==") || !strcmp(tree->token,"!=")
		|| !strcmp(tree->token,"<=") || !strcmp(tree->token,">=")))
        {
            if (!strcmp(tree->left->token,"<") || !strcmp(tree->left->token,">") || !strcmp(tree->left->token,"==") || !strcmp(tree->left->token,"!=") || !strcmp(tree->left->token,">=") || !strcmp(tree->left->token,"<=")) {
                printf("Error. Two boolean operators following each other. '%s' followed by '%s'.\n", tree->left->token, tree->token);
                exit(1);
            }
            else if (!strcmp(tree->left->token,"()")){
                boolean_statement_check(tree->left->right);
            }
            else if (!strcmp(tree->left->token,"+") || !strcmp(tree->left->token,"-") || !strcmp(tree->left->token,"*")
            || !strcmp(tree->left->token,"/")){
                left = arithmetic_statement_check(tree->left);
            }
			else if (!strcmp(tree->left->token,"|")){
				left = "INT";
			}
            else {
                left = var_declaration_check(tree->left->token,current_scope);
            }
            if (!strcmp(tree->right->token,"<") || !strcmp(tree->right->token,">") || !strcmp(tree->right->token,"==") || !strcmp(tree->right->token,"!=") || !strcmp(tree->right->token,">=") || !strcmp(tree->right->token,"<=")) {
                printf("Error. Two boolean operators following each other. '%s' followed by '%s'.\n", tree->left->token, tree->token);
                exit(1);
            }
            else if (!strcmp(tree->right->token,"()") ){
                boolean_statement_check(tree->right->right);
            }
            else if (!strcmp(tree->right->token,"+") || !strcmp(tree->right->token,"-") || !strcmp(tree->right->token,"*")
            || !strcmp(tree->right->token,"/")){
                right = arithmetic_statement_check(tree->right);
            }
			else if (!strcmp(tree->right->token,"|")){
				right = "INT";
			}
            else {
                right = var_declaration_check(tree->right->token,current_scope);
            }
            if ((!strcmp(left,"REAL") && !strcmp(right,"INT")) || (!strcmp(right,"REAL") && !strcmp(left,"INT"))){
                printf("Warning. Comparison of '%s' and '%s' may cause precision loss.\n", left, right);
            }
            else if (!strcmp(tree->token,"==") || !strcmp(tree->token, "!=")){
                if (strcmp(left,right)) {
                    printf("Error. Cannot us boolean comparison on '%s' and '%s' type.\n",left,right);
                    exit(1);
                }
            }
            else if (!strcmp(tree->token,"<") || !strcmp(tree->token, ">") || !strcmp(tree->token, ">=") || !strcmp(tree->token, "<=")){
                if (strcmp(left,"INT") && strcmp(left,"REAL")){
                    printf("Error. Cannot use boolean comparison on '%s' type.\n", left);
                    exit(1);
                }
                if (strcmp(right,"INT") && strcmp(right,"REAL")){
                    printf("Error. Cannot use boolean comparison on '%s' type.\n", right);
                    exit(1);
                }
            }
            
        }
        else if (!strcmp(tree->token,"||") || !strcmp(tree->token,"&&")){
            boolean_statement_check(tree->left);
            boolean_statement_check(tree->right);
            return;
        }
        else if (!strcmp(tree->token,"()")){
            if (tree->left == NULL && tree->right == NULL) {
                printf("\033[31mEmpty '()' unacceptable in boolean statement.\033[0m\n");
                exit(1);
            }
            if (tree->left != NULL) { boolean_statement_check(tree->left); };
            if (tree->right != NULL) { boolean_statement_check(tree->right); };
        }
        else if (strcmp(var_declaration_check(tree->token,current_scope),"BOOL")){ /*boolean*/
            printf("\033[31mError. Parameter %s has to be boolean.\033[0m\n", tree->token);
            exit(1);
        }
        
    }
}

char* arithmetic_statement_check(node* tree) {
    char *left = NULL, *right = NULL;
    //TOKEN??
    if (!strcmp(tree->token,"()")){
        if (tree->left == NULL && tree->right == NULL) {
                printf("\033[31mEmpty '()' unacceptable in arithmetic statement.\033[0m\n");
                exit(1);
              }
            if (tree->left != NULL) { return arithmetic_statement_check(tree->left); };
            if (tree->right != NULL) { return arithmetic_statement_check(tree->right); };
    }
    else if (!strcmp(tree->token,"&&") || !strcmp(tree->token,"||") || !strcmp(tree->token,"<") || !strcmp(tree->token,">")
		 || !strcmp(tree->token,"<=") || !strcmp(tree->token,">=")){
        printf("Boolean symbol %s is not allowed in arithmetic statement.\n", tree->token);
        exit(1);
    }
    else if (!strcmp(tree->token,"+") || !strcmp(tree->token, "-") || !strcmp(tree->token, "*") || !strcmp(tree->token, "/")){
        //LEFT//
        if (!strcmp(tree->left->token,"+") || !strcmp(tree->left->token,"-") || !strcmp(tree->left->token,"*")
            || !strcmp(tree->left->token,"/") || !strcmp(tree->left->token,"&&") || !strcmp(tree->left->token,"||")
            || !strcmp(tree->left->token,"<") || !strcmp(tree->left->token,">") || !strcmp(tree->left->token,"<=") 
		|| !strcmp(tree->left->token,">=") || !strcmp(tree->left->token, "()")){
            left = arithmetic_statement_check(tree->left);
        }
		else if (!strcmp(tree->left->token,"|")){
				left = "INT";
		}
        else {
            left = var_declaration_check(tree->left->token,current_scope);
        }
        //RIGHT//
        if (!strcmp(tree->right->token,"+") || !strcmp(tree->right->token,"-") || !strcmp(tree->right->token,"*")
            || !strcmp(tree->right->token,"/") || !strcmp(tree->right->token,"&&") || !strcmp(tree->right->token,"||")
            || !strcmp(tree->right->token,"<") || !strcmp(tree->right->token,">") || !strcmp(tree->right->token,"<=") || 
		!strcmp(tree->right->token,">=") || !strcmp(tree->right->token, "()")){
            right = arithmetic_statement_check(tree->right);
        }
		else if (!strcmp(tree->right->token,"|")){
				right = "INT";
		}
        else {
            right = var_declaration_check(tree->right->token,current_scope);
        }
        if (!strcmp(left,"INT") && !strcmp(right,"INT")) {
            return "INT";
        }
        else if ((!strcmp(left,"REAL") && !strcmp(right,"REAL")) || (!strcmp(left,"REAL") && !strcmp(right,"INT"))
            || (!strcmp(left,"INT") && !strcmp(right,"REAL"))){
            return "REAL";
        }
        else {
            if (strcmp(left,"REAL") && strcmp(left,"INT")) {
                printf("Error. Cannot use arithmetic symbol '%s' on '%s' types.\n", tree->token, left);
                exit(1);
            }
            else if (strcmp(right,"REAL") && strcmp(right,"INT")) {
                printf("Error. Cannot use arithmetic symbol '%s' on '%s' types.\n", tree->token, right);
                exit(1);
            }
            if (strcmp(left,"REAL") && strcmp(left,"INT")){
                return left;
            }
            else return right;
        }
    }
    else {
            //printf("var_dec: %s\n",var_declaration_check(tree->token,current_scope));
            return var_declaration_check(tree->token,current_scope);
    }
}


void for_initialization_check(node* tree) {
    if (tree == NULL) { /*FINISH*/ }
    else if (!strcmp(tree->token, "=")) {
        char *type = var_declaration_check(tree->left->token, current_scope);
        if (strcmp(type, "INT") && strcmp(type, "NULL") && strcmp(type, "REAL")) {
            printf("\033[31mFor Initialization/increment/decrement Error - Parameter %s has to be INT type or REAL type.\033[0m\n", tree->left->token);
            exit(1);
        }
        else {
            code_scope* scope = stack;
            while (scope->scope_level != 0) {
                if (scope->scope_level == current_scope) {
                    break;
                }
                scope = scope->previous_scope;
            }
            for (int i = 0; i < scope->countvar ; i++) {
                if (!strcmp(scope->var->name[i], tree->left->token)) {
                    scope->var->value[i] = strdup(insert_values_into_vars(tree->right, type));
                }
            }
        }
    }
}

void for_condition_check(node* tree) {
    boolean_statement_check(tree);
}

/* Part 3 */
void addCode(node* node, char *code, char *var, char *label, char *truelabel, char *falselabel) {
    if(code != NULL) {
        node->code = (char*)malloc(sizeof(char)*(1+strlen(code)));
        strcpy(node->code, code);
    }
    else if(node->code == NULL) {
        node->code = (char*)malloc(sizeof(char)*2);
        strcpy(node->code,"");
    }
    if(var != NULL) {
        node->var=(char*)malloc(sizeof(char)*(1+strlen(var)));
        strcpy(node->var, var);
    }
    else if(node->var == NULL) {
        node->var = (char*)malloc(sizeof(char)*2);
        strcpy(node->var, "");
    }
    if(label != NULL && node->label == NULL) {
        node->label = (char*)malloc(sizeof(char)*(1+strlen(label)));
        strcpy(node->label, label);
    }
    if(truelabel != NULL && node->truelabel == NULL) {
        node->truelabel = (char*)malloc(sizeof(char)*(1+strlen(truelabel)));
        strcpy(node->truelabel, truelabel);
    }
    if(falselabel != NULL && node->falselabel == NULL) {
        node->falselabel = (char*)malloc(sizeof(char)*(1+strlen(falselabel)));
        strcpy(node->falselabel, falselabel);
    }
}

void addCode2(node* node,char *code,char *var,char *label,char *truelabel,char *falselabel) {
    if(code != NULL){
        node->code = (char*)malloc(sizeof(char)*(1+strlen(code)));
        strcpy(node->code, code);
    }
    else if(node->code == NULL){
		node->code = (char*)malloc(sizeof(char)*2);
		strcpy(node->code, "");
    }

    if(var!=NULL){
		node->var=(char*)malloc(sizeof(char)*(1+strlen(var)));
		strcpy(node->var, var);
    }
    else if(node->var == NULL){
		node->var = (char*)malloc(sizeof(char)*2);
		strcpy(node->var, "");
    }

    if(label != NULL){
		node->label=(char*)malloc(sizeof(char)*(1+strlen(label)));
		strcpy(node->label,label);
    }

    if(truelabel != NULL){
		node->truelabel = (char*)malloc(sizeof(char)*(1+strlen(truelabel)));
		strcpy(node->truelabel, truelabel);
    }
		
    if(falselabel != NULL && node->falselabel == NULL){
		node->falselabel = (char*)malloc(sizeof(char)*(1+strlen(falselabel)));
		strcpy(node->falselabel, falselabel);
    }
}
	
char* freshVar(){
    char* x;
    asprintf(&x,"t%d", t++);
    return x;
}

char* freshLabel(){
    char* x;
    asprintf(&x,"L%d", l++);
    return x;
}

char* gen(char*s1, char*s2, char*s3, char*s4, char*s5) {
    char* x;
    asprintf(&x,"%s %s %s %s %s\n", s1, s2, s3, s4,s5);
    return x;
}
	
char* mystrcat(char*des,char*src){
    char* tamp = des;
    char* num;
    asprintf(&num, "%d ", line++);
    if( src != NULL) {
        if (des == NULL){
            des = (char*)malloc((strlen(src)+1)*sizeof(char));
            strcpy(des,src);
            return des;
        }
		des = (char*)malloc((strlen(des)+strlen(src)+1+strlen(num))*sizeof(char));
		if (tamp!=NULL) {
            strcat(des,tamp);
		}
		if (src!=NULL) {
            strcat(des,src);
		}
    }
	return des;
}

char *replaceWord(const char *s, const char *oldW, const char *newW) {
    char *result; 
    int i, cnt = 0; 
    int newWlen = strlen(newW); 
    int oldWlen = strlen(oldW); 
  
    // Counting the number of times old word 
    // occur in the string 
    for (i = 0; s[i] != '\0'; i++) { 
        if (strstr(&s[i], oldW) == &s[i]) { 
            cnt++; 
  
            // Jumping to index after the old word. 
            i += oldWlen - 1; 
        } 
    } 
  
    // Making new string of enough length 
    result = (char *)malloc(i + cnt * (newWlen - oldWlen) + 1); 
  
    i = 0; 
    while (*s) { 
        // compare the substring with the result
        if (strstr(s, oldW) == s) { 
            strcpy(&result[i], newW); 
            i += newWlen; 
            s += oldWlen; 
        } 
        else
            result[i++] = *s++; 
    } 
  
    result[i] = '\0'; 
    return result; 
} 

 
char* mkspace(char *label) {
	char* msg;
	char x = ' ';
	int len = strlen(mystrcat(label, "\0"));
	if (label == NULL || !strcmp(label, "")) {
		msg = "";
    }
	else {
		asprintf(&msg,"%c",x);
		while (len < 5) {
		asprintf(&msg, "%c%s", x, msg);
			len++;
		}
		asprintf(&label, "%s: \n", mystrcat(label,"\0"));
		msg = mystrcat(msg, label);
	}
	return msg;
}

int POPParams(Arguments *args, int args_amount) {
    int size = 0;
    for(int i = 0 ; i < args_amount ; i++) {
        if(!strcmp(args->type[i],"INT"))
            size += 4;
        else if(!strcmp(args->type[i],"CHAR"))
            size += 1;
        else if(!strcmp(args->type[i],"REAL"))
            size += 8;
        else if(strcmp(args->type[i],"STRING") == 0)
            size += atoi(args->len[i]);
        else if(strcmp(args->type[i],"BOOL") == 0)
            size += 4;
        else if(strcmp(args->type[i],"INTP") == 0)
            size += 4;
        else if(strcmp(args->type[i],"CHARP") == 0)
            size += 4;
        else if(strcmp(args->type[i],"REALP") == 0)
            size += 4;
    }
    return size;
}

int findfunc(char *func_name) {
    code_scope *search = stack;
    int size;
    while (search->scope_level != 0) {
        if (search->func) {
            if (!strcmp(func_name, search->func->name)) {
                break;
            }
        }
        search = search->previous_scope;
    }
    return POPParams(search->func->args, search->func->count_args);
}


void calc3AC(node* tree) {
    if (tree == NULL) { /* FINISH */ return; }
    
    if (!strcmp(tree->token, "=")) {
        //calc3AC(tree->left);
        calc3AC(tree->right);
        addCode(tree, mystrcat(tree->right->code, mystrcat(tree->left->token, gen(" =", tree->right->var, "", "",""))), NULL, NULL, NULL, NULL);
        //addCode(tree, mystrcat(tree->right->code, gen(tree->left->var, "=", tree->right->var,"","")), NULL, NULL, NULL, NULL);
	}
    
	else if (!strcmp(tree->token, "FUNCTION") || !strcmp(tree->token, "PROCEDURE")) {
        t = 0;
        calc3AC(tree->left->right);
        if (tree->right) {
            calc3AC(tree->right);
        }
        char *x;
        asprintf(&x, "\x1B[32m %s:\n\x1B[0m", tree->left->token);
        if (tree->right) {
            addCode(tree, mystrcat(mystrcat(x, tree->left->right->code), tree->right->code), NULL, NULL, NULL, NULL);
        }
        else {
            addCode(tree, mystrcat(x, tree->left->right->code), NULL, NULL, NULL, NULL);
        }
		return;
	}
    
	else if (!strcmp(tree->token, "CODE")) {
	 	calc3AC(tree->right); // GO TO FUNCTION //
        if (tree->right) {
			addCode(tree, tree->right->code, NULL, NULL, NULL, NULL);
        }
		tree->code = replaceWord(tree->code, "\n\n", "\n") ;
		char x = 'a', *y, *z;
        while (x <= 'z') {
            asprintf(&y, "\n%c", x);
            asprintf(&z, "\n\t%c", x);
			tree->code = replaceWord(tree->code, y, z) ;
			x++;
		}
		x = 'A';
        while (x <= 'Z') {
			asprintf(&y, "\n%c", x);
			asprintf(&z, "\n\t%c", x);
			tree->code = replaceWord(tree->code, y, z) ;
			x++;
		}
        printf("%s\n", tree->code);
		return;
	}
    
    else if (!strcmp(tree->token, "BODY")) {
        if (tree->left != NULL) {
            calc3AC(tree->left);
        }
        if (tree->right != NULL) {
            calc3AC(tree->right);
        }
        if (tree->right && tree->left) {
            addCode(tree, mystrcat(mystrcat("\tBeginFunc\n", mystrcat(tree->left->code, tree->right->code)), "\tEndFunc\n"), tree->left->var, tree->left->label, tree->left->truelabel, tree->left->falselabel);
        }
        else if (tree->left && !tree->right) {
            addCode(tree, mystrcat(mystrcat("\tBeginFunc\n", tree->left->code), "\tEndFunc\n"), tree->left->var, tree->left->label, tree->left->truelabel, tree->left->falselabel);
        }
        else if (!tree->left && tree->right) {
            addCode(tree, mystrcat(mystrcat("\tBeginFunc\n", tree->right->code), "\tEndFunc\n"), tree->right->var, tree->right->label, tree->right->truelabel, tree->right->falselabel);
        }
        else {
            addCode(tree, mystrcat("\tBeginFunc\n", "\tEndFunc\n"), NULL, NULL, NULL, NULL);
        }
		return;
	}
    
    else if (!strcmp(tree->token, "FUNC CALL")) {
        if (tree->right!=NULL) calc3AC(tree->right);

        node* args_run = tree->right;
        while (args_run != NULL) {
            addCode(tree, mystrcat(tree->code, gen(args_run->var, "=",args_run->token,"","")), NULL, NULL, NULL, NULL);
            addCode(tree, mystrcat(tree->code, mystrcat("PushParam ",mystrcat(args_run->var,"\n"))),NULL,NULL,NULL,NULL);
            args_run = args_run->left;
        }
        tree->sum = findfunc(tree->left->token);
        char *x;
        addCode(tree, NULL, freshVar(), NULL, NULL, NULL);
        asprintf(&x,"%s = LCALL %s\n‪\tPopParams %d‬‬‬‬\n", tree->var, tree->left->token, tree->sum);

        addCode(tree,mystrcat(tree->code,x),NULL,NULL,NULL,NULL);
        return;
    }
    
    else if (!strcmp(tree->token, "STATEMENT")) {
        calc3AC(tree->left);
        calc3AC(tree->right);
        if (tree->right) {
            addCode(tree, mystrcat(tree->left->code,tree->right->code),tree->left->var, tree->left->label, tree->left->truelabel, tree->left->falselabel);
        }
        else {
            addCode(tree, tree->left->code,tree->left->var, tree->left->label, tree->left->truelabel, tree->left->falselabel);
        }
    }
    
    else if (!strcmp(tree->token, "ASSIGNMENT")) {
        calc3AC(tree->left);
        addCode(tree, tree->left->code, tree->left->var, tree->left->label, tree->left->truelabel, tree->left->falselabel);
    }
    
    else if (!strcmp(tree->token ,"DECLETARION")) {
        if (!strcmp(tree->left->token, "STRING")) {
            calc3AC(tree->left);
            addCode(tree, tree->left->code, tree->left->var, tree->left->label, tree->left->truelabel, tree->left->falselabel);
        }
        else {
            node* search = tree;
            while (search) {
                if (!strcmp(search->token, "ASSIGN-DECLER")) {
                    calc3AC(search->left);
                    addCode(tree, mystrcat(search->code, search->left->code), search->left->var, search->left->label, search->left->truelabel, search->left->falselabel);
                }
                search = search->left;
            }
        }
    }
    
    else if (!strcmp(tree->token ,"STRING")) {
        if (tree->left->right->right) {
            calc3AC(tree->left->right->right);
            addCode(tree, NULL, freshVar(), NULL, NULL, NULL);
            addCode(tree, mystrcat(tree->left->right->right->code, gen(tree->left->token, "=", tree->left->right->right->var, "","")), NULL, NULL, NULL, NULL);
            return;
        }
    }
    
    else if (!strcmp(tree->token ,"ASSIGN-DECLER")) {
        calc3AC(tree->left);
        addCode(tree, tree->left->code, tree->left->var, tree->left->label, tree->left->truelabel, tree->left->falselabel);
    }
    
    else if (!strcmp(tree->token, "+") || !strcmp(tree->token, "-") || !strcmp(tree->token, "/") || !strcmp(tree->token, "*")) {
        if (!strcmp(tree->left->token, "+") || !strcmp(tree->left->token, "-") || !strcmp(tree->left->token, "/") || !strcmp(tree->left->token, "*")) {
            calc3AC(tree->left);
            calc3AC(tree->right);
            addCode(tree, NULL, freshVar(), NULL, NULL, NULL);
            addCode(tree, mystrcat(tree->left->code, tree->right->code), NULL, NULL, NULL, NULL);
            addCode(tree, mystrcat(tree->code, gen(tree->var, "=", tree->left->var, tree->left->token, tree->right->var)), NULL, NULL, NULL, NULL);
        }
        else {
            addCode(tree, NULL, freshVar(), NULL, NULL, NULL);
            addCode(tree, mystrcat(mystrcat(tree->left->code, tree->right->code), gen(tree->var, "=", tree->left->token, tree->token, tree->right->token)), NULL, NULL, NULL, NULL);
        }
        return;
    }
    
    else if (!strcmp(tree->token, ">") || !strcmp(tree->token, "<") || !strcmp(tree->token, "==") || !strcmp(tree->token, ">=") || !strcmp(tree->token, "<=") || !strcmp(tree->token, "!=")) {
        if (!strcmp(tree->left->token, "+") || !strcmp(tree->left->token, "-") || !strcmp(tree->left->token, "/") || !strcmp(tree->left->token, "*")) {
            calc3AC(tree->left);
        }
        calc3AC(tree->right);

        addCode(tree, NULL, freshVar(), NULL, NULL, NULL);
        addCode(tree,  mystrcat(mystrcat(tree->left->code,tree->right->code), gen(tree->var, "=",tree->left->token,tree->token ,tree->right->var)),NULL,NULL,NULL,NULL);
        addCode(tree, mystrcat(tree->code,gen("ifz", tree->var, "goto", tree->falselabel,"\n")), tree->left->var, NULL, NULL, NULL);
    }
    
    else if (!strcmp(tree->token, "IF")) {
        calc3AC(tree->left);
        calc3AC(tree->right);

        if(tree->left) addCode(tree->left,NULL,NULL,NULL,NULL,tree->label);
        if(tree->right) addCode(tree->right,NULL,NULL,NULL,tree->label,NULL);

        addCode(tree,mystrcat(tree->left->code,mystrcat(mkspace(tree->left->label),mystrcat(mkspace(tree->left->truelabel),mystrcat(mkspace(tree->left->right->truelabel),mystrcat(mkspace(tree->truelabel),mystrcat(tree->right->code,mkspace(tree->truelabel))))))),NULL,NULL,NULL,NULL);
        addCode(tree, mystrcat(tree->code, mkspace(tree->left->falselabel)), NULL, NULL, NULL, NULL);
        return;
    }
    
    else if (!strcmp(tree->token, "IF-ELSE")) {
        calc3AC(tree->left->left);
        calc3AC(tree->left->right);
        calc3AC(tree->right);

        addCode(tree, tree->left->left->code, NULL, NULL, NULL, NULL);
        addCode(tree, mystrcat(tree->code, mystrcat(mkspace(tree->left->left->right->truelabel),tree->left->right->code)), NULL, NULL, NULL, NULL);
        addCode(tree, mystrcat(tree->code, gen("goto", tree->left->left->truelabel, "","","")), NULL, NULL, NULL, NULL);
        addCode(tree, mystrcat(tree->code, mkspace(tree->left->left->falselabel)), NULL, NULL, NULL, NULL);
        addCode(tree, mystrcat(tree->code, tree->right->code), NULL, NULL, NULL, NULL);
        addCode(tree, mystrcat(tree->code, mkspace(tree->left->left->truelabel)), NULL, NULL, NULL, NULL);
    }
    
    else if (!strcmp(tree->token, "ELSE")) {
        calc3AC(tree->left);
        addCode(tree, tree->left->code, tree->left->var, tree->left->label, tree->left->truelabel, tree->left->falselabel);
    }
    
    else if (!strcmp(tree->token, "WHILE")) {
        if (tree->left) calc3AC(tree->left);
        if (tree->right) calc3AC(tree->right);

        addCode(tree, mystrcat(mkspace(tree->left->truelabel), tree->left->code), NULL, NULL, NULL, freshLabel());
        addCode(tree, mystrcat(tree->code, mystrcat(mkspace(tree->left->right->truelabel),tree->right->code)), NULL, NULL, NULL, NULL);
        addCode(tree, mystrcat(tree->code, mystrcat("goto ", tree->left->truelabel)),  NULL, NULL, NULL, NULL);
        addCode(tree, mystrcat(tree->code, "\n"), NULL, NULL, NULL, NULL);
        addCode(tree, mystrcat(tree->code, mkspace(tree->left->falselabel)), NULL, NULL, NULL, NULL);
        return;
    }
    
    else if (!strcmp(tree->token, "WHILE-BODY")) {
        if (tree->left) calc3AC(tree->left);
        if (tree->right) calc3AC(tree->right);
        if (tree->left && tree->right) {
            addCode(tree, mystrcat(tree->left->code, tree->right->code), tree->left->var, tree->left->label, tree->left->truelabel, tree->left->falselabel);
        }
        else if (!tree->left && tree->right) {
            addCode(tree, tree->right->code, tree->right->var, tree->right->label, tree->right->truelabel, tree->right->falselabel);
        }
        else if (tree->left && !tree->right) {
            addCode(tree, tree->left->code, tree->left->var, tree->left->label, tree->left->truelabel, tree->left->falselabel);
        }
        else {
            addCode(tree, "", tree->token, NULL, NULL, NULL);
        }
    }
    
    else if (!strcmp(tree->token, "DO-WHILE")) {
        calc3AC(tree->left);
        calc3AC(tree->right);

        addCode(tree, mystrcat(mkspace(tree->right->truelabel), tree->left->code), NULL, NULL, NULL, NULL);
        addCode(tree, mystrcat(tree->code, tree->right->code), NULL, NULL, NULL, NULL);
        addCode(tree, mystrcat(tree->code, mystrcat("goto ",tree->right->truelabel)), NULL, NULL, NULL, NULL);
        addCode(tree, mystrcat(tree->code, "\n"), NULL, NULL, NULL, NULL);
        addCode(tree, mystrcat(tree->code, mkspace(tree->right->falselabel)), NULL, NULL, NULL, NULL);
    }
    
    else if (!strcmp(tree->token, "DO-WHILE-BODY")) {
        if (tree->left) calc3AC(tree->left);
        if (tree->right) calc3AC(tree->right);
        if (tree->left && tree->right) {
            addCode(tree, mystrcat(tree->left->code, tree->right->code), tree->left->var, tree->left->label, tree->left->truelabel, tree->left->falselabel);
        }
        else if (!tree->left && tree->right) {
            addCode(tree, tree->right->code, tree->right->var, tree->right->label, tree->right->truelabel, tree->right->falselabel);
        }
        else if (tree->left && !tree->right) {
            addCode(tree, tree->left->code, tree->left->var, tree->left->label, tree->left->truelabel, tree->left->falselabel);
        }
        else {
            addCode(tree, "", tree->token, NULL, NULL, NULL);
        }
    }
    
    else if (!strcmp(tree->token, "FOR")) {
        calc3AC(tree->left->left); // GO TO FOR-INIT //
        calc3AC(tree->left->right->left); // GO TO FOR-CONDITION //
        calc3AC(tree->right); // GO TO BODY //
        calc3AC(tree->left->right->right); // GO TO ADVENCMENT //
        
        addCode(tree, mystrcat(tree->code, tree->left->left->code), NULL, NULL, NULL, NULL);
        addCode(tree, mystrcat(tree->code, mystrcat(mkspace(tree->left->right->left->truelabel), tree->left->right->left->code)), NULL, NULL, NULL, NULL);
        addCode(tree, mystrcat(tree->code, tree->right->code), NULL, NULL, NULL, NULL);
        addCode(tree, mystrcat(tree->code, tree->left->right->right->code), NULL, NULL, NULL, NULL);
        addCode(tree, mystrcat(tree->code, mystrcat("goto ",tree->left->right->left->truelabel)), NULL, NULL, NULL, NULL);
        addCode(tree, mystrcat(tree->code, "\n"), NULL, NULL, NULL, NULL);
        addCode(tree, mystrcat(tree->code, mkspace(tree->left->right->left->falselabel)), NULL, NULL, NULL, NULL);
    }
    
    else if (!strcmp(tree->token, "FOR-BODY")) {
        if (tree->left) calc3AC(tree->left);
        if (tree->right) calc3AC(tree->right);
        if (tree->left && tree->right) {
            addCode(tree, mystrcat(tree->left->code, tree->right->code), tree->left->var, tree->left->label, tree->left->truelabel, tree->left->falselabel);
        }
        else if (!tree->left && tree->right) {
            addCode(tree, tree->right->code, tree->right->var, tree->right->label, tree->right->truelabel, tree->right->falselabel);
        }
        else if (tree->left && !tree->right) {
            addCode(tree, tree->left->code, tree->left->var, tree->left->label, tree->left->truelabel, tree->left->falselabel);
        }
        else {
            addCode(tree, "", tree->token, NULL, NULL, NULL);
        }
    }
    
    else if (!strcmp(tree->token, "ELSE-BODY")) {
        calc3AC(tree->left);
        addCode(tree, tree->left->code, tree->left->var, tree->left->label, tree->left->truelabel, tree->left->falselabel);
    }
    
    else if (!strcmp(tree->token, "IF-BODY")) {
        if (tree->left) calc3AC(tree->left);
        if (tree->right) calc3AC(tree->right);
        if (tree->left && tree->right) {
            addCode(tree, mystrcat(tree->left->code, tree->right->code), tree->left->var, tree->left->label, tree->left->truelabel, tree->left->falselabel);
        }
        else if (!tree->left && tree->right) {
            addCode(tree, tree->right->code, tree->right->var, tree->right->label, tree->right->truelabel, tree->right->falselabel);
        }
        else if (tree->left && !tree->right) {
            addCode(tree, tree->left->code, tree->left->var, tree->left->label, tree->left->truelabel, tree->left->falselabel);
        }
        else {
            addCode(tree, "", tree->token, NULL, NULL, NULL);
        }
    }

    else if (!strcmp(tree->token, "RETURN")) {
        if (!strcmp(tree->token, "+") || !strcmp(tree->token, "-") || !strcmp(tree->token, "/") || !strcmp(tree->token, "*")) {
            calc3AC(tree->left);
            addCode(tree, mystrcat(tree->left->code, gen("RETURN", tree->left->var, "","","")), NULL, NULL, NULL, NULL);
        }
        else {
            addCode(tree, mystrcat(tree->left->code, gen("RETURN", tree->left->token, "","","")), NULL, NULL, NULL, NULL);
        }
    }
    
    else if (!strcmp(tree->token, "CODE BLOCK")) {
        if (tree->left != NULL) {
            calc3AC(tree->left);
        }
        if (tree->right != NULL) {
            calc3AC(tree->right);
        }
        if (tree->right && tree->left) {
            addCode(tree, mystrcat(mystrcat("\tBeginCodeBlock\n", mystrcat(tree->left->code, tree->right->code)), "\tEndCodeBlock\n"), tree->left->var, tree->left->label, tree->left->truelabel, tree->left->falselabel);
        }
        else if (tree->left && !tree->right) {
            addCode(tree, mystrcat(mystrcat("\tBeginCodeBlock\n", tree->left->code), "\tEndCodeBlock\n"), tree->left->var, tree->left->label, tree->left->truelabel, tree->left->falselabel);
        }
        else if (!tree->left && tree->right) {
            addCode(tree, mystrcat(mystrcat("\tBeginCodeBlock\n", tree->right->code), "\tEndCodeBlock\n"), tree->right->var, tree->right->label, tree->right->truelabel, tree->right->falselabel);
        }
        else {
            addCode(tree, mystrcat("\tBeginCodeBlock\n", "\tEndCodeBlock\n"), NULL, NULL, NULL, NULL);
        }
        return;
    }
    
    else if (!strcmp(tree->token, "||")) {
        if (!strcmp(tree->left->token,"||")) calc3AC(tree->left);

        addCode(tree->right, NULL, NULL, NULL, NULL, NULL);
        addCode(tree->left, NULL, NULL, NULL, tree->falselabel, tree->falselabel);

        if (tree->right) calc3AC(tree->right);
        if (tree->left) calc3AC(tree->left);

        addCode(tree,mystrcat(tree->right->code, mystrcat(mystrcat("goto ", tree->right->truelabel), "\n")),NULL,NULL,NULL,NULL);
        addCode(tree, mystrcat(tree->code, mkspace(tree->right->falselabel)),NULL,NULL,NULL,NULL);
        addCode(tree, mystrcat(tree->code, tree->left->code),NULL,NULL,NULL,NULL);
    }
    
    else if (!strcmp(tree->token, "&&")) {
        addCode(tree->right, NULL, NULL, NULL, NULL, tree->falselabel);
        addCode(tree->left, NULL, NULL, NULL, NULL, tree->falselabel);
        
        if (tree->right) calc3AC(tree->right);
        if (tree->left) calc3AC(tree->left);

        addCode(tree, mystrcat(tree->code, tree->right->code),NULL,NULL,NULL,NULL);
        addCode(tree, mystrcat(tree->code, tree->left->code), NULL, NULL, NULL, NULL);
    }
    
    else {
        addCode(tree, NULL, freshVar(), NULL, NULL, NULL);

        if (!strcmp(tree->token, "&") || !strcmp(tree->token, "*")) {
            addCode(tree, mystrcat(tree->var, mystrcat(mystrcat(" = ", mystrcat(tree->token, tree->right->token)),"\n")), NULL, NULL, NULL, NULL);
        }
        else addCode(tree, gen(tree->var, "=", tree->token,"",""), NULL, NULL, NULL, NULL);

        if (tree->left) calc3AC(tree->left);
    }
    
}
