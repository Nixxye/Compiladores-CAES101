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

#ifndef YY_YY_CALC_TAB_H_INCLUDED
# define YY_YY_CALC_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "calc.y"

  #include "calc.h"

#line 53 "calc.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NUM = 258,                     /* NUM  */
    PLUS = 259,                    /* PLUS  */
    MINUS = 260,                   /* MINUS  */
    MULTIPLY = 261,                /* MULTIPLY  */
    DIVIDE = 262,                  /* DIVIDE  */
    ASSIGN = 263,                  /* ASSIGN  */
    IF = 264,                      /* IF  */
    THEN = 265,                    /* THEN  */
    ELSE = 266,                    /* ELSE  */
    EQUAL = 267,                   /* EQUAL  */
    LESS = 268,                    /* LESS  */
    GREATER = 269,                 /* GREATER  */
    LESS_EQUAL = 270,              /* LESS_EQUAL  */
    NOT_EQUAL = 271,               /* NOT_EQUAL  */
    GREATER_EQUAL = 272,           /* GREATER_EQUAL  */
    AND = 273,                     /* AND  */
    OR = 274,                      /* OR  */
    NOT = 275,                     /* NOT  */
    OPEN_BRACKETS = 276,           /* OPEN_BRACKETS  */
    CLOSE_BRACKETS = 277,          /* CLOSE_BRACKETS  */
    OPEN_PARENTHESIS = 278,        /* OPEN_PARENTHESIS  */
    CLOSE_PARENTHESIS = 279,       /* CLOSE_PARENTHESIS  */
    TRUEbool = 280,                /* TRUEbool  */
    FALSEbool = 281,               /* FALSEbool  */
    NEWLINE = 282,                 /* NEWLINE  */
    QUIT = 283,                    /* QUIT  */
    INT = 284,                     /* INT  */
    FLOAT = 285,                   /* FLOAT  */
    BOOL = 286,                    /* BOOL  */
    READ = 287,                    /* READ  */
    WRITE = 288,                   /* WRITE  */
    END = 289,                     /* END  */
    ID = 290                       /* ID  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
  char* ID;                                /* ID  */
  float NUM;                               /* NUM  */
  int TRUEbool;                            /* TRUEbool  */
  int FALSEbool;                           /* FALSEbool  */
  llvm_val* expression;                    /* expression  */
  llvm_val* term;                          /* term  */
  llvm_val* factor;                        /* factor  */
  llvm_val* boolean_expression;            /* boolean_expression  */

#line 114 "calc.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_CALC_TAB_H_INCLUDED  */
