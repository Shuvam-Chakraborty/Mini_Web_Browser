/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_MNT_C_USERS_91798_DESKTOP_MINIBROWSER_PROJECT_BUILD_HTML2AST_TAB_HPP_INCLUDED
# define YY_YY_MNT_C_USERS_91798_DESKTOP_MINIBROWSER_PROJECT_BUILD_HTML2AST_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TEXT = 258,                    /* TEXT  */
    IMG = 259,                     /* IMG  */
    A_OPEN = 260,                  /* A_OPEN  */
    HTML_OPEN = 261,               /* HTML_OPEN  */
    HTML_CLOSE = 262,              /* HTML_CLOSE  */
    HEAD_OPEN = 263,               /* HEAD_OPEN  */
    HEAD_CLOSE = 264,              /* HEAD_CLOSE  */
    TITLE_OPEN = 265,              /* TITLE_OPEN  */
    TITLE_CLOSE = 266,             /* TITLE_CLOSE  */
    BODY_OPEN = 267,               /* BODY_OPEN  */
    BODY_CLOSE = 268,              /* BODY_CLOSE  */
    NAV_OPEN = 269,                /* NAV_OPEN  */
    NAV_CLOSE = 270,               /* NAV_CLOSE  */
    UL_OPEN = 271,                 /* UL_OPEN  */
    UL_CLOSE = 272,                /* UL_CLOSE  */
    LI_OPEN = 273,                 /* LI_OPEN  */
    LI_CLOSE = 274,                /* LI_CLOSE  */
    HEADER_OPEN = 275,             /* HEADER_OPEN  */
    HEADER_CLOSE = 276,            /* HEADER_CLOSE  */
    H1_OPEN = 277,                 /* H1_OPEN  */
    H1_CLOSE = 278,                /* H1_CLOSE  */
    H2_OPEN = 279,                 /* H2_OPEN  */
    H2_CLOSE = 280,                /* H2_CLOSE  */
    H3_OPEN = 281,                 /* H3_OPEN  */
    H3_CLOSE = 282,                /* H3_CLOSE  */
    H4_OPEN = 283,                 /* H4_OPEN  */
    H4_CLOSE = 284,                /* H4_CLOSE  */
    H5_OPEN = 285,                 /* H5_OPEN  */
    H5_CLOSE = 286,                /* H5_CLOSE  */
    P_OPEN = 287,                  /* P_OPEN  */
    P_CLOSE = 288,                 /* P_CLOSE  */
    SECTION_OPEN = 289,            /* SECTION_OPEN  */
    SECTION_CLOSE = 290,           /* SECTION_CLOSE  */
    ARTICLE_OPEN = 291,            /* ARTICLE_OPEN  */
    ARTICLE_CLOSE = 292,           /* ARTICLE_CLOSE  */
    ASIDE_OPEN = 293,              /* ASIDE_OPEN  */
    ASIDE_CLOSE = 294,             /* ASIDE_CLOSE  */
    FOOTER_OPEN = 295,             /* FOOTER_OPEN  */
    FOOTER_CLOSE = 296,            /* FOOTER_CLOSE  */
    A_CLOSE = 297,                 /* A_CLOSE  */
    STRONG_OPEN = 298,             /* STRONG_OPEN  */
    STRONG_CLOSE = 299,            /* STRONG_CLOSE  */
    EM_OPEN = 300,                 /* EM_OPEN  */
    EM_CLOSE = 301,                /* EM_CLOSE  */
    U_OPEN = 302,                  /* U_OPEN  */
    U_CLOSE = 303,                 /* U_CLOSE  */
    SMALL_OPEN = 304,              /* SMALL_OPEN  */
    SMALL_CLOSE = 305,             /* SMALL_CLOSE  */
    BLOCKQUOTE_OPEN = 306,         /* BLOCKQUOTE_OPEN  */
    BLOCKQUOTE_CLOSE = 307,        /* BLOCKQUOTE_CLOSE  */
    PRE_OPEN = 308,                /* PRE_OPEN  */
    PRE_CLOSE = 309,               /* PRE_CLOSE  */
    CODE_OPEN = 310,               /* CODE_OPEN  */
    CODE_CLOSE = 311,              /* CODE_CLOSE  */
    OL_OPEN = 312,                 /* OL_OPEN  */
    OL_CLOSE = 313                 /* OL_CLOSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 32 "HTML2AST.y"

    char* text;

#line 126 "/mnt/c/Users/91798/Desktop/minibrowser/project/build/HTML2AST.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_MNT_C_USERS_91798_DESKTOP_MINIBROWSER_PROJECT_BUILD_HTML2AST_TAB_HPP_INCLUDED  */
