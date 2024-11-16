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
#line 1 "HTML2AST.y"

#include <stdio.h>
#include <string>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "HTML2AST.h"
#include<fstream>
#include <sstream>
#include <sys/mman.h>
#include <sys/stat.h>        
#include <fcntl.h>           
#include <unistd.h>  
#include <semaphore.h>
#include <cstdio>   



using namespace std;

extern int yylex();
void yyerror(const char *s);
extern char* yytext;
extern int yyparse(void);
extern FILE* yyin;

// Initialize global AST
AST htmlAst;
shared_ptr<ASTNode> currentNode = nullptr;

#line 102 "/mnt/c/Users/91798/Desktop/minibrowser/project/build/HTML2AST.tab.cpp"

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

#include "HTML2AST.tab.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TEXT = 3,                       /* TEXT  */
  YYSYMBOL_IMG = 4,                        /* IMG  */
  YYSYMBOL_A_OPEN = 5,                     /* A_OPEN  */
  YYSYMBOL_HTML_OPEN = 6,                  /* HTML_OPEN  */
  YYSYMBOL_HTML_CLOSE = 7,                 /* HTML_CLOSE  */
  YYSYMBOL_HEAD_OPEN = 8,                  /* HEAD_OPEN  */
  YYSYMBOL_HEAD_CLOSE = 9,                 /* HEAD_CLOSE  */
  YYSYMBOL_TITLE_OPEN = 10,                /* TITLE_OPEN  */
  YYSYMBOL_TITLE_CLOSE = 11,               /* TITLE_CLOSE  */
  YYSYMBOL_BODY_OPEN = 12,                 /* BODY_OPEN  */
  YYSYMBOL_BODY_CLOSE = 13,                /* BODY_CLOSE  */
  YYSYMBOL_NAV_OPEN = 14,                  /* NAV_OPEN  */
  YYSYMBOL_NAV_CLOSE = 15,                 /* NAV_CLOSE  */
  YYSYMBOL_UL_OPEN = 16,                   /* UL_OPEN  */
  YYSYMBOL_UL_CLOSE = 17,                  /* UL_CLOSE  */
  YYSYMBOL_LI_OPEN = 18,                   /* LI_OPEN  */
  YYSYMBOL_LI_CLOSE = 19,                  /* LI_CLOSE  */
  YYSYMBOL_HEADER_OPEN = 20,               /* HEADER_OPEN  */
  YYSYMBOL_HEADER_CLOSE = 21,              /* HEADER_CLOSE  */
  YYSYMBOL_H1_OPEN = 22,                   /* H1_OPEN  */
  YYSYMBOL_H1_CLOSE = 23,                  /* H1_CLOSE  */
  YYSYMBOL_H2_OPEN = 24,                   /* H2_OPEN  */
  YYSYMBOL_H2_CLOSE = 25,                  /* H2_CLOSE  */
  YYSYMBOL_H3_OPEN = 26,                   /* H3_OPEN  */
  YYSYMBOL_H3_CLOSE = 27,                  /* H3_CLOSE  */
  YYSYMBOL_H4_OPEN = 28,                   /* H4_OPEN  */
  YYSYMBOL_H4_CLOSE = 29,                  /* H4_CLOSE  */
  YYSYMBOL_H5_OPEN = 30,                   /* H5_OPEN  */
  YYSYMBOL_H5_CLOSE = 31,                  /* H5_CLOSE  */
  YYSYMBOL_P_OPEN = 32,                    /* P_OPEN  */
  YYSYMBOL_P_CLOSE = 33,                   /* P_CLOSE  */
  YYSYMBOL_SECTION_OPEN = 34,              /* SECTION_OPEN  */
  YYSYMBOL_SECTION_CLOSE = 35,             /* SECTION_CLOSE  */
  YYSYMBOL_ARTICLE_OPEN = 36,              /* ARTICLE_OPEN  */
  YYSYMBOL_ARTICLE_CLOSE = 37,             /* ARTICLE_CLOSE  */
  YYSYMBOL_ASIDE_OPEN = 38,                /* ASIDE_OPEN  */
  YYSYMBOL_ASIDE_CLOSE = 39,               /* ASIDE_CLOSE  */
  YYSYMBOL_FOOTER_OPEN = 40,               /* FOOTER_OPEN  */
  YYSYMBOL_FOOTER_CLOSE = 41,              /* FOOTER_CLOSE  */
  YYSYMBOL_A_CLOSE = 42,                   /* A_CLOSE  */
  YYSYMBOL_STRONG_OPEN = 43,               /* STRONG_OPEN  */
  YYSYMBOL_STRONG_CLOSE = 44,              /* STRONG_CLOSE  */
  YYSYMBOL_EM_OPEN = 45,                   /* EM_OPEN  */
  YYSYMBOL_EM_CLOSE = 46,                  /* EM_CLOSE  */
  YYSYMBOL_U_OPEN = 47,                    /* U_OPEN  */
  YYSYMBOL_U_CLOSE = 48,                   /* U_CLOSE  */
  YYSYMBOL_SMALL_OPEN = 49,                /* SMALL_OPEN  */
  YYSYMBOL_SMALL_CLOSE = 50,               /* SMALL_CLOSE  */
  YYSYMBOL_BLOCKQUOTE_OPEN = 51,           /* BLOCKQUOTE_OPEN  */
  YYSYMBOL_BLOCKQUOTE_CLOSE = 52,          /* BLOCKQUOTE_CLOSE  */
  YYSYMBOL_PRE_OPEN = 53,                  /* PRE_OPEN  */
  YYSYMBOL_PRE_CLOSE = 54,                 /* PRE_CLOSE  */
  YYSYMBOL_CODE_OPEN = 55,                 /* CODE_OPEN  */
  YYSYMBOL_CODE_CLOSE = 56,                /* CODE_CLOSE  */
  YYSYMBOL_OL_OPEN = 57,                   /* OL_OPEN  */
  YYSYMBOL_OL_CLOSE = 58,                  /* OL_CLOSE  */
  YYSYMBOL_YYACCEPT = 59,                  /* $accept  */
  YYSYMBOL_document = 60,                  /* document  */
  YYSYMBOL_61_1 = 61,                      /* $@1  */
  YYSYMBOL_head = 62,                      /* head  */
  YYSYMBOL_63_2 = 63,                      /* $@2  */
  YYSYMBOL_title = 64,                     /* title  */
  YYSYMBOL_body = 65,                      /* body  */
  YYSYMBOL_66_3 = 66,                      /* $@3  */
  YYSYMBOL_elements = 67,                  /* elements  */
  YYSYMBOL_element = 68,                   /* element  */
  YYSYMBOL_nav = 69,                       /* nav  */
  YYSYMBOL_70_4 = 70,                      /* $@4  */
  YYSYMBOL_ul = 71,                        /* ul  */
  YYSYMBOL_72_5 = 72,                      /* $@5  */
  YYSYMBOL_li = 73,                        /* li  */
  YYSYMBOL_74_6 = 74,                      /* $@6  */
  YYSYMBOL_a = 75,                         /* a  */
  YYSYMBOL_76_7 = 76,                      /* $@7  */
  YYSYMBOL_header = 77,                    /* header  */
  YYSYMBOL_78_8 = 78,                      /* $@8  */
  YYSYMBOL_h1 = 79,                        /* h1  */
  YYSYMBOL_80_9 = 80,                      /* $@9  */
  YYSYMBOL_h2 = 81,                        /* h2  */
  YYSYMBOL_82_10 = 82,                     /* $@10  */
  YYSYMBOL_h3 = 83,                        /* h3  */
  YYSYMBOL_84_11 = 84,                     /* $@11  */
  YYSYMBOL_h4 = 85,                        /* h4  */
  YYSYMBOL_86_12 = 86,                     /* $@12  */
  YYSYMBOL_h5 = 87,                        /* h5  */
  YYSYMBOL_88_13 = 88,                     /* $@13  */
  YYSYMBOL_p = 89,                         /* p  */
  YYSYMBOL_90_14 = 90,                     /* $@14  */
  YYSYMBOL_section = 91,                   /* section  */
  YYSYMBOL_92_15 = 92,                     /* $@15  */
  YYSYMBOL_article = 93,                   /* article  */
  YYSYMBOL_94_16 = 94,                     /* $@16  */
  YYSYMBOL_strong = 95,                    /* strong  */
  YYSYMBOL_96_17 = 96,                     /* $@17  */
  YYSYMBOL_em = 97,                        /* em  */
  YYSYMBOL_98_18 = 98,                     /* $@18  */
  YYSYMBOL_u = 99,                         /* u  */
  YYSYMBOL_100_19 = 100,                   /* $@19  */
  YYSYMBOL_small = 101,                    /* small  */
  YYSYMBOL_102_20 = 102,                   /* $@20  */
  YYSYMBOL_blockquote = 103,               /* blockquote  */
  YYSYMBOL_104_21 = 104,                   /* $@21  */
  YYSYMBOL_pre = 105,                      /* pre  */
  YYSYMBOL_106_22 = 106,                   /* $@22  */
  YYSYMBOL_code = 107,                     /* code  */
  YYSYMBOL_108_23 = 108,                   /* $@23  */
  YYSYMBOL_ol = 109,                       /* ol  */
  YYSYMBOL_110_24 = 110,                   /* $@24  */
  YYSYMBOL_aside = 111,                    /* aside  */
  YYSYMBOL_112_25 = 112,                   /* $@25  */
  YYSYMBOL_footer = 113,                   /* footer  */
  YYSYMBOL_114_26 = 114,                   /* $@26  */
  YYSYMBOL_img = 115,                      /* img  */
  YYSYMBOL_text = 116                      /* text  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   83

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  58
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  140

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   313


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    51,    51,    51,    57,    57,    63,    67,    67,    73,
      74,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    82,    82,    88,    88,
      94,    94,   100,   100,   106,   106,   112,   112,   118,   118,
     124,   124,   130,   130,   136,   136,   142,   142,   148,   148,
     154,   154,   160,   160,   166,   166,   172,   172,   178,   178,
     184,   184,   190,   190,   196,   196,   202,   202,   208,   208,
     214,   214,   220,   228
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
  "\"end of file\"", "error", "\"invalid token\"", "TEXT", "IMG",
  "A_OPEN", "HTML_OPEN", "HTML_CLOSE", "HEAD_OPEN", "HEAD_CLOSE",
  "TITLE_OPEN", "TITLE_CLOSE", "BODY_OPEN", "BODY_CLOSE", "NAV_OPEN",
  "NAV_CLOSE", "UL_OPEN", "UL_CLOSE", "LI_OPEN", "LI_CLOSE", "HEADER_OPEN",
  "HEADER_CLOSE", "H1_OPEN", "H1_CLOSE", "H2_OPEN", "H2_CLOSE", "H3_OPEN",
  "H3_CLOSE", "H4_OPEN", "H4_CLOSE", "H5_OPEN", "H5_CLOSE", "P_OPEN",
  "P_CLOSE", "SECTION_OPEN", "SECTION_CLOSE", "ARTICLE_OPEN",
  "ARTICLE_CLOSE", "ASIDE_OPEN", "ASIDE_CLOSE", "FOOTER_OPEN",
  "FOOTER_CLOSE", "A_CLOSE", "STRONG_OPEN", "STRONG_CLOSE", "EM_OPEN",
  "EM_CLOSE", "U_OPEN", "U_CLOSE", "SMALL_OPEN", "SMALL_CLOSE",
  "BLOCKQUOTE_OPEN", "BLOCKQUOTE_CLOSE", "PRE_OPEN", "PRE_CLOSE",
  "CODE_OPEN", "CODE_CLOSE", "OL_OPEN", "OL_CLOSE", "$accept", "document",
  "$@1", "head", "$@2", "title", "body", "$@3", "elements", "element",
  "nav", "$@4", "ul", "$@5", "li", "$@6", "a", "$@7", "header", "$@8",
  "h1", "$@9", "h2", "$@10", "h3", "$@11", "h4", "$@12", "h5", "$@13", "p",
  "$@14", "section", "$@15", "article", "$@16", "strong", "$@17", "em",
  "$@18", "u", "$@19", "small", "$@20", "blockquote", "$@21", "pre",
  "$@22", "code", "$@23", "ol", "$@24", "aside", "$@25", "footer", "$@26",
  "img", "text", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-33)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -2,   -33,     3,    -1,   -33,   -33,    -7,    -4,   -33,     1,
       6,     5,    -3,   -33,     7,   -33,   -33,   -33,   -33,   -33,
     -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,
     -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,
     -33,     9,    -3,   -33,   -33,   -33,   -33,   -33,   -33,   -33,
     -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,
     -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,    -3,
      -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,
      -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,
      -3,    -3,   -33,   -33,   -32,    11,    -5,    13,    15,    16,
      -9,    14,    18,   -11,    10,    43,   -13,    12,     4,   -10,
     -16,    31,   -12,    28,    27,    26,    25,   -33,   -33,   -33,
     -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,
     -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     2,     0,     0,     1,     4,     0,     0,     7,     0,
       0,     0,    10,     3,     0,     5,    83,    82,    42,    36,
      38,    40,    44,    46,    48,    50,    52,    54,    56,    58,
      60,    78,    80,    62,    64,    66,    68,    70,    72,    74,
      76,     0,    10,    11,    12,    13,    14,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    15,     6,    10,
      10,    10,    10,    10,    10,    10,    10,    10,    10,    10,
      10,    10,    10,    10,    10,    10,    10,    10,    10,    10,
      10,    10,     8,     9,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    43,    37,    39,
      41,    45,    47,    49,    51,    53,    55,    57,    59,    61,
      79,    81,    63,    65,    67,    69,    71,    73,    75,    77
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,   -14,   -33,
     -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,
     -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,
     -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,
     -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,
     -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,     6,     7,    11,     9,    12,    41,    42,
      43,    70,    44,    71,    45,    72,    46,    69,    47,    73,
      48,    74,    49,    75,    50,    76,    51,    77,    52,    78,
      53,    79,    54,    80,    55,    81,    56,    84,    57,    85,
      58,    86,    59,    87,    60,    88,    61,    89,    62,    90,
      63,    91,    64,    82,    65,    83,    66,    67
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      16,    17,    18,     4,     1,     8,    10,     5,    13,    14,
     117,    19,   119,    20,    15,    21,   123,    22,    68,    23,
     126,    24,    92,    25,   129,    26,   118,    27,    93,    28,
     133,    29,   120,    30,   132,    31,   121,    32,   135,   122,
      33,   124,    34,   127,    35,   131,    36,   125,    37,     0,
      38,   130,    39,     0,    40,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   128,   134,
     136,   137,   138,   139
};

static const yytype_int8 yycheck[] =
{
       3,     4,     5,     0,     6,    12,    10,     8,     7,     3,
      42,    14,    17,    16,     9,    18,    25,    20,    11,    22,
      31,    24,    13,    26,    37,    28,    15,    30,    42,    32,
      46,    34,    19,    36,    44,    38,    21,    40,    50,    23,
      43,    27,    45,    33,    47,    41,    49,    29,    51,    -1,
      53,    39,    55,    -1,    57,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    35,    48,
      52,    54,    56,    58
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,    60,    61,     0,     8,    62,    63,    12,    65,
      10,    64,    66,     7,     3,     9,     3,     4,     5,    14,
      16,    18,    20,    22,    24,    26,    28,    30,    32,    34,
      36,    38,    40,    43,    45,    47,    49,    51,    53,    55,
      57,    67,    68,    69,    71,    73,    75,    77,    79,    81,
      83,    85,    87,    89,    91,    93,    95,    97,    99,   101,
     103,   105,   107,   109,   111,   113,   115,   116,    11,    76,
      70,    72,    74,    78,    80,    82,    84,    86,    88,    90,
      92,    94,   112,   114,    96,    98,   100,   102,   104,   106,
     108,   110,    13,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    42,    15,    17,
      19,    21,    23,    25,    27,    29,    31,    33,    35,    37,
      39,    41,    44,    46,    48,    50,    52,    54,    56,    58
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    59,    61,    60,    63,    62,    64,    66,    65,    67,
      67,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    70,    69,    72,    71,
      74,    73,    76,    75,    78,    77,    80,    79,    82,    81,
      84,    83,    86,    85,    88,    87,    90,    89,    92,    91,
      94,    93,    96,    95,    98,    97,   100,    99,   102,   101,
     104,   103,   106,   105,   108,   107,   110,   109,   112,   111,
     114,   113,   115,   116
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     5,     0,     4,     3,     0,     4,     2,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     4,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     4,     0,     4,
       0,     4,     1,     1
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
  case 2: /* $@1: %empty  */
#line 51 "HTML2AST.y"
              { startElement("html"); }
#line 1303 "/mnt/c/Users/91798/Desktop/minibrowser/project/build/HTML2AST.tab.cpp"
    break;

  case 3: /* document: HTML_OPEN $@1 head body HTML_CLOSE  */
#line 53 "HTML2AST.y"
               { endElement(); }
#line 1309 "/mnt/c/Users/91798/Desktop/minibrowser/project/build/HTML2AST.tab.cpp"
    break;

  case 4: /* $@2: %empty  */
#line 57 "HTML2AST.y"
              { startElement("head"); }
#line 1315 "/mnt/c/Users/91798/Desktop/minibrowser/project/build/HTML2AST.tab.cpp"
    break;

  case 5: /* head: HEAD_OPEN $@2 title HEAD_CLOSE  */
#line 59 "HTML2AST.y"
               { endElement(); }
#line 1321 "/mnt/c/Users/91798/Desktop/minibrowser/project/build/HTML2AST.tab.cpp"
    break;

  case 6: /* title: TITLE_OPEN TEXT TITLE_CLOSE  */
#line 63 "HTML2AST.y"
                                { startElement("title"); addContent((yyvsp[-1].text)); free((yyvsp[-1].text)); endElement(); }
#line 1327 "/mnt/c/Users/91798/Desktop/minibrowser/project/build/HTML2AST.tab.cpp"
    break;

  case 7: /* $@3: %empty  */
#line 67 "HTML2AST.y"
              { startElement("body"); }
#line 1333 "/mnt/c/Users/91798/Desktop/minibrowser/project/build/HTML2AST.tab.cpp"
    break;

  case 8: /* body: BODY_OPEN $@3 elements BODY_CLOSE  */
#line 69 "HTML2AST.y"
               { endElement(); }
#line 1339 "/mnt/c/Users/91798/Desktop/minibrowser/project/build/HTML2AST.tab.cpp"
    break;

  case 36: /* $@4: %empty  */
#line 82 "HTML2AST.y"
             { startElement("nav"); }
#line 1345 "/mnt/c/Users/91798/Desktop/minibrowser/project/build/HTML2AST.tab.cpp"
    break;

  case 37: /* nav: NAV_OPEN $@4 elements NAV_CLOSE  */
#line 84 "HTML2AST.y"
              { endElement(); }
#line 1351 "/mnt/c/Users/91798/Desktop/minibrowser/project/build/HTML2AST.tab.cpp"
    break;

  case 38: /* $@5: %empty  */
#line 88 "HTML2AST.y"
            { startElement("ul"); }
#line 1357 "/mnt/c/Users/91798/Desktop/minibrowser/project/build/HTML2AST.tab.cpp"
    break;

  case 39: /* ul: UL_OPEN $@5 elements UL_CLOSE  */
#line 90 "HTML2AST.y"
             { endElement(); }
#line 1363 "/mnt/c/Users/91798/Desktop/minibrowser/project/build/HTML2AST.tab.cpp"
    break;

  case 40: /* $@6: %empty  */
#line 94 "HTML2AST.y"
            { startElement("li"); }
#line 1369 "/mnt/c/Users/91798/Desktop/minibrowser/project/build/HTML2AST.tab.cpp"
    break;

  case 41: /* li: LI_OPEN $@6 elements LI_CLOSE  */
#line 96 "HTML2AST.y"
             { endElement(); }
#line 1375 "/mnt/c/Users/91798/Desktop/minibrowser/project/build/HTML2AST.tab.cpp"
    break;

  case 42: /* $@7: %empty  */
#line 100 "HTML2AST.y"
           { startElement("a", (yyvsp[0].text)); free((yyvsp[0].text)); }
#line 1381 "/mnt/c/Users/91798/Desktop/minibrowser/project/build/HTML2AST.tab.cpp"
    break;

  case 43: /* a: A_OPEN $@7 elements A_CLOSE  */
#line 102 "HTML2AST.y"
            { endElement(); }
#line 1387 "/mnt/c/Users/91798/Desktop/minibrowser/project/build/HTML2AST.tab.cpp"
    break;

  case 44: /* $@8: %empty  */
#line 106 "HTML2AST.y"
                { startElement("header"); }
#line 1393 "/mnt/c/Users/91798/Desktop/minibrowser/project/build/HTML2AST.tab.cpp"
    break;

  case 45: /* header: HEADER_OPEN $@8 elements HEADER_CLOSE  */
#line 108 "HTML2AST.y"
                 { endElement(); }
#line 1399 "/mnt/c/Users/91798/Desktop/minibrowser/project/build/HTML2AST.tab.cpp"
    break;

  case 46: /* $@9: %empty  */
#line 112 "HTML2AST.y"
            { startElement("h1"); }
#line 1405 "/mnt/c/Users/91798/Desktop/minibrowser/project/build/HTML2AST.tab.cpp"
    break;

  case 47: /* h1: H1_OPEN $@9 elements H1_CLOSE  */
#line 114 "HTML2AST.y"
             { endElement(); }
#line 1411 "/mnt/c/Users/91798/Desktop/minibrowser/project/build/HTML2AST.tab.cpp"
    break;

  case 48: /* $@10: %empty  */
#line 118 "HTML2AST.y"
            { startElement("h2"); }
#line 1417 "/mnt/c/Users/91798/Desktop/minibrowser/project/build/HTML2AST.tab.cpp"
    break;

  case 49: /* h2: H2_OPEN $@10 elements H2_CLOSE  */
#line 120 "HTML2AST.y"
             { endElement(); }
#line 1423 "/mnt/c/Users/91798/Desktop/minibrowser/project/build/HTML2AST.tab.cpp"
    break;

  case 50: /* $@11: %empty  */
#line 124 "HTML2AST.y"
            { startElement("h3"); }
#line 1429 "/mnt/c/Users/91798/Desktop/minibrowser/project/build/HTML2AST.tab.cpp"
    break;

  case 51: /* h3: H3_OPEN $@11 elements H3_CLOSE  */
#line 126 "HTML2AST.y"
             { endElement(); }
#line 1435 "/mnt/c/Users/91798/Desktop/minibrowser/project/build/HTML2AST.tab.cpp"
    break;

  case 52: /* $@12: %empty  */
#line 130 "HTML2AST.y"
            { startElement("h4"); }
#line 1441 "/mnt/c/Users/91798/Desktop/minibrowser/project/build/HTML2AST.tab.cpp"
    break;

  case 53: /* h4: H4_OPEN $@12 elements H4_CLOSE  */
#line 132 "HTML2AST.y"
             { endElement(); }
#line 1447 "/mnt/c/Users/91798/Desktop/minibrowser/project/build/HTML2AST.tab.cpp"
    break;

  case 54: /* $@13: %empty  */
#line 136 "HTML2AST.y"
            { startElement("h5"); }
#line 1453 "/mnt/c/Users/91798/Desktop/minibrowser/project/build/HTML2AST.tab.cpp"
    break;

  case 55: /* h5: H5_OPEN $@13 elements H5_CLOSE  */
#line 138 "HTML2AST.y"
             { endElement(); }
#line 1459 "/mnt/c/Users/91798/Desktop/minibrowser/project/build/HTML2AST.tab.cpp"
    break;

  case 56: /* $@14: %empty  */
#line 142 "HTML2AST.y"
           { startElement("p"); }
#line 1465 "/mnt/c/Users/91798/Desktop/minibrowser/project/build/HTML2AST.tab.cpp"
    break;

  case 57: /* p: P_OPEN $@14 elements P_CLOSE  */
#line 144 "HTML2AST.y"
            { endElement(); }
#line 1471 "/mnt/c/Users/91798/Desktop/minibrowser/project/build/HTML2AST.tab.cpp"
    break;

  case 58: /* $@15: %empty  */
#line 148 "HTML2AST.y"
                 { startElement("section"); }
#line 1477 "/mnt/c/Users/91798/Desktop/minibrowser/project/build/HTML2AST.tab.cpp"
    break;

  case 59: /* section: SECTION_OPEN $@15 elements SECTION_CLOSE  */
#line 150 "HTML2AST.y"
                  { endElement(); }
#line 1483 "/mnt/c/Users/91798/Desktop/minibrowser/project/build/HTML2AST.tab.cpp"
    break;

  case 60: /* $@16: %empty  */
#line 154 "HTML2AST.y"
                 { startElement("article"); }
#line 1489 "/mnt/c/Users/91798/Desktop/minibrowser/project/build/HTML2AST.tab.cpp"
    break;

  case 61: /* article: ARTICLE_OPEN $@16 elements ARTICLE_CLOSE  */
#line 156 "HTML2AST.y"
                  { endElement(); }
#line 1495 "/mnt/c/Users/91798/Desktop/minibrowser/project/build/HTML2AST.tab.cpp"
    break;

  case 62: /* $@17: %empty  */
#line 160 "HTML2AST.y"
                { startElement("strong"); }
#line 1501 "/mnt/c/Users/91798/Desktop/minibrowser/project/build/HTML2AST.tab.cpp"
    break;

  case 63: /* strong: STRONG_OPEN $@17 elements STRONG_CLOSE  */
#line 162 "HTML2AST.y"
                 { endElement(); }
#line 1507 "/mnt/c/Users/91798/Desktop/minibrowser/project/build/HTML2AST.tab.cpp"
    break;

  case 64: /* $@18: %empty  */
#line 166 "HTML2AST.y"
            { startElement("em"); }
#line 1513 "/mnt/c/Users/91798/Desktop/minibrowser/project/build/HTML2AST.tab.cpp"
    break;

  case 65: /* em: EM_OPEN $@18 elements EM_CLOSE  */
#line 168 "HTML2AST.y"
             { endElement(); }
#line 1519 "/mnt/c/Users/91798/Desktop/minibrowser/project/build/HTML2AST.tab.cpp"
    break;

  case 66: /* $@19: %empty  */
#line 172 "HTML2AST.y"
           { startElement("u"); }
#line 1525 "/mnt/c/Users/91798/Desktop/minibrowser/project/build/HTML2AST.tab.cpp"
    break;

  case 67: /* u: U_OPEN $@19 elements U_CLOSE  */
#line 174 "HTML2AST.y"
            { endElement(); }
#line 1531 "/mnt/c/Users/91798/Desktop/minibrowser/project/build/HTML2AST.tab.cpp"
    break;

  case 68: /* $@20: %empty  */
#line 178 "HTML2AST.y"
               { startElement("small"); }
#line 1537 "/mnt/c/Users/91798/Desktop/minibrowser/project/build/HTML2AST.tab.cpp"
    break;

  case 69: /* small: SMALL_OPEN $@20 elements SMALL_CLOSE  */
#line 180 "HTML2AST.y"
                { endElement(); }
#line 1543 "/mnt/c/Users/91798/Desktop/minibrowser/project/build/HTML2AST.tab.cpp"
    break;

  case 70: /* $@21: %empty  */
#line 184 "HTML2AST.y"
                    { startElement("blockquote"); }
#line 1549 "/mnt/c/Users/91798/Desktop/minibrowser/project/build/HTML2AST.tab.cpp"
    break;

  case 71: /* blockquote: BLOCKQUOTE_OPEN $@21 elements BLOCKQUOTE_CLOSE  */
#line 186 "HTML2AST.y"
                     { endElement(); }
#line 1555 "/mnt/c/Users/91798/Desktop/minibrowser/project/build/HTML2AST.tab.cpp"
    break;

  case 72: /* $@22: %empty  */
#line 190 "HTML2AST.y"
             { startElement("pre"); }
#line 1561 "/mnt/c/Users/91798/Desktop/minibrowser/project/build/HTML2AST.tab.cpp"
    break;

  case 73: /* pre: PRE_OPEN $@22 elements PRE_CLOSE  */
#line 192 "HTML2AST.y"
              { endElement(); }
#line 1567 "/mnt/c/Users/91798/Desktop/minibrowser/project/build/HTML2AST.tab.cpp"
    break;

  case 74: /* $@23: %empty  */
#line 196 "HTML2AST.y"
              { startElement("code"); }
#line 1573 "/mnt/c/Users/91798/Desktop/minibrowser/project/build/HTML2AST.tab.cpp"
    break;

  case 75: /* code: CODE_OPEN $@23 elements CODE_CLOSE  */
#line 198 "HTML2AST.y"
               { endElement(); }
#line 1579 "/mnt/c/Users/91798/Desktop/minibrowser/project/build/HTML2AST.tab.cpp"
    break;

  case 76: /* $@24: %empty  */
#line 202 "HTML2AST.y"
            { startElement("ol"); }
#line 1585 "/mnt/c/Users/91798/Desktop/minibrowser/project/build/HTML2AST.tab.cpp"
    break;

  case 77: /* ol: OL_OPEN $@24 elements OL_CLOSE  */
#line 204 "HTML2AST.y"
             { endElement(); }
#line 1591 "/mnt/c/Users/91798/Desktop/minibrowser/project/build/HTML2AST.tab.cpp"
    break;

  case 78: /* $@25: %empty  */
#line 208 "HTML2AST.y"
               { startElement("aside"); }
#line 1597 "/mnt/c/Users/91798/Desktop/minibrowser/project/build/HTML2AST.tab.cpp"
    break;

  case 79: /* aside: ASIDE_OPEN $@25 elements ASIDE_CLOSE  */
#line 210 "HTML2AST.y"
                { endElement(); }
#line 1603 "/mnt/c/Users/91798/Desktop/minibrowser/project/build/HTML2AST.tab.cpp"
    break;

  case 80: /* $@26: %empty  */
#line 214 "HTML2AST.y"
                { startElement("footer"); }
#line 1609 "/mnt/c/Users/91798/Desktop/minibrowser/project/build/HTML2AST.tab.cpp"
    break;

  case 81: /* footer: FOOTER_OPEN $@26 elements FOOTER_CLOSE  */
#line 216 "HTML2AST.y"
                 { endElement(); }
#line 1615 "/mnt/c/Users/91798/Desktop/minibrowser/project/build/HTML2AST.tab.cpp"
    break;

  case 82: /* img: IMG  */
#line 220 "HTML2AST.y"
        { 
        startElement("img", (yyvsp[0].text));
        endElement();
        free((yyvsp[0].text));
    }
#line 1625 "/mnt/c/Users/91798/Desktop/minibrowser/project/build/HTML2AST.tab.cpp"
    break;

  case 83: /* text: TEXT  */
#line 228 "HTML2AST.y"
         {
	startElement("text"); 
        addContent((yyvsp[0].text));
        free((yyvsp[0].text));
	endElement();
    }
#line 1636 "/mnt/c/Users/91798/Desktop/minibrowser/project/build/HTML2AST.tab.cpp"
    break;


#line 1640 "/mnt/c/Users/91798/Desktop/minibrowser/project/build/HTML2AST.tab.cpp"

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

#line 236 "HTML2AST.y"


void yyerror(const char *s) {
    cerr << "Error: " << s << endl;
}

//consumer

void* ptr2;
int out=0;
sem_t* emp ;
sem_t* filled ;
sem_t* bsem ;

int n;

//producer functions and vars
void* ptr2_dup;
int in_dup=0;
sem_t* emp_dup ;
sem_t* filled_dup ;
sem_t* bsem_dup ;



#define SIZE_OF_PAGE 20*1024


//producer for html.y
// void* ptr2_dup;
// int in_dup=0;
// sem_t* emp_dup ;
// sem_t* filled_dup ;
// sem_t* bsem_dup ;


void printstring_from_buffer(void* ptr,int index){
     cout<<((char*)ptr)+SIZE_OF_PAGE*index<< endl;
    return;
}


void copystring_to_buffer(void*ptr, string temp,int index){

    strcpy(static_cast<char*>(ptr)+SIZE_OF_PAGE*index, temp.c_str());

    return;
}


string calling_parser(){
    ofstream outputFile("example"+ to_string(out)+".txt");

    outputFile << ((char*)ptr2)+SIZE_OF_PAGE*out;
    outputFile.close();

    FILE* file = fopen(("example"+ to_string(out)+".txt").c_str(), "r");
    if (!file) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }

    // Set Flex's input source to the file
    yyin = file;

    // Parse the input
    yyparse();
    htmlAst.writeToFile("example_ast"+ to_string(out)+".txt");

    // Close the file
    fclose(file);

    ifstream inputFile("example_ast"+ to_string(out)+".txt");

    string fileContents((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());

    inputFile.close();

    //deleting the previous file
    const char* filename = ("example"+ to_string(out)+".txt").c_str();
    remove(filename);
    remove(("example_ast"+ to_string(out)+".txt").c_str());
    return fileContents;

}





void consumer_func(){

    string ast;
    while(1)
    {

        sem_wait(filled);
        sem_wait(bsem);

        ast=calling_parser();

        
        //cout<<ast<<endl;
        

        out=(out+1)%n;


        

        

        sem_post(bsem);
        sem_post(emp);

        //cout<<ast;
        sem_wait(emp_dup);
        sem_wait(bsem_dup);
        
        copystring_to_buffer(ptr2_dup,ast,in_dup);
        //printstring_from_buffer(ptr2_dup,in_dup);
        //cout<<ast;
        in_dup=(in_dup+1)%n;
        

        sem_post(bsem_dup);
        sem_post(filled_dup);

        //cout<<ast;


    }

    

}





//bison -d -o HTML2AST.tab.cpp HTML2AST.y
//flex -o HTML2AST.lex.cpp HTML2AST.l
//g++ HTML2AST.tab.cpp HTML2AST.lex.cpp HTML2AST.h -o consumer
 int main() {
     
    const char* n_shared_name = "/size_of_buffer";
    int shm_fd1 = shm_open(n_shared_name, O_RDWR, 0666);
    void* ptr1 = mmap(0, sizeof(int), PROT_READ, MAP_SHARED, shm_fd1, 0);
    

    n=*((int*)(ptr1));
    //shared memory storing strings
    const char* storing_web_pages = "/strings";
    int shm_fd2 = shm_open(storing_web_pages,O_RDWR, 0666);  
    ptr2 = mmap(0, SIZE_OF_PAGE*n*sizeof(char), PROT_WRITE, MAP_SHARED, shm_fd2, 0);
    

    //html.y will put data into following 

    //shared memory storing strings
    const char* asts = "/asts";
    shm_unlink(asts);

    int shm_fd2_dup = shm_open(asts, O_CREAT | O_RDWR, 0666);  

    //size of memory is 20*1024*40(each webpage can have atmost 20*1024 characters and we could have atmost 40 webpages)
    ftruncate(shm_fd2_dup, SIZE_OF_PAGE*n*sizeof(char));  
    ptr2_dup = mmap(0, SIZE_OF_PAGE*n*sizeof(char), PROT_WRITE, MAP_SHARED, shm_fd2_dup, 0);



    emp = sem_open("/emp", 0);
    filled = sem_open("/filled", 0);
    bsem = sem_open("/bsem", 0);

    //unlinking if we already have the semophore with same name
    sem_unlink("/emp_dup");
    sem_unlink("/filled_dup");
    sem_unlink("/bsem_dup");

    //semophores have to be declared before forking the consumer
    emp_dup = sem_open("/emp_dup", O_CREAT, 0644, n);
    filled_dup = sem_open("/filled_dup", O_CREAT, 0644, 0);
    bsem_dup = sem_open("/bsem_dup", O_CREAT, 0644, 1);

    pid_t pid1 =fork();  

    if (pid1 == 0) 
    {
        //cout<<"hello\n";
        char *args[] = {nullptr};
        execvp("./ASTRenderer", args);  
        
        
    }


    consumer_func();



    
    munmap(ptr1, sizeof(int));
    close(shm_fd1);
    shm_unlink(n_shared_name);

    munmap(ptr2, SIZE_OF_PAGE*n*sizeof(char));
    close(shm_fd2);
    shm_unlink(storing_web_pages);

    munmap(ptr2_dup, SIZE_OF_PAGE*n*sizeof(char));
    close(shm_fd2_dup);

    return 0;

    
 }
