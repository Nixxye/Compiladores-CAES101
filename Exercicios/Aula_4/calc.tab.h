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

  typedef struct symrec symrec;

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
    VAR = 259,                     /* VAR  */
    FUN = 260,                     /* FUN  */
    PLUS = 261,                    /* PLUS  */
    MINUS = 262,                   /* MINUS  */
    MULTIPLY = 263,                /* MULTIPLY  */
    DIVIDE = 264,                  /* DIVIDE  */
    ASSIGN = 265,                  /* ASSIGN  */
    IF = 266,                      /* IF  */
    THEN = 267,                    /* THEN  */
    ELSE = 268,                    /* ELSE  */
    EQUAL = 269,                   /* EQUAL  */
    LESS = 270,                    /* LESS  */
    GREATER = 271,                 /* GREATER  */
    LESS_EQUAL = 272,              /* LESS_EQUAL  */
    NOT_EQUAL = 273,               /* NOT_EQUAL  */
    GREATER_EQUAL = 274,           /* GREATER_EQUAL  */
    AND = 275,                     /* AND  */
    OR = 276,                      /* OR  */
    NOT = 277,                     /* NOT  */
    OPEN_BRACKETS = 278,           /* OPEN_BRACKETS  */
    CLOSE_BRACKETS = 279,          /* CLOSE_BRACKETS  */
    OPEN_PARENTHESIS = 280,        /* OPEN_PARENTHESIS  */
    CLOSE_PARENTHESIS = 281,       /* CLOSE_PARENTHESIS  */
    TRUEbool = 282,                /* TRUEbool  */
    FALSEbool = 283,               /* FALSEbool  */
    NEWLINE = 284,                 /* NEWLINE  */
    QUIT = 285                     /* QUIT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
  float NUM;                               /* NUM  */
  float expression;                        /* expression  */
  float if_command;                        /* if_command  */
  int TRUEbool;                            /* TRUEbool  */
  int FALSEbool;                           /* FALSEbool  */
  int boolean;                             /* boolean  */
  symrec* VAR;                             /* VAR  */
  symrec* FUN;                             /* FUN  */

#line 109 "calc.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_CALC_TAB_H_INCLUDED  */
