#ifndef _CSCI_4200_Parser
#define _CSCI_4200_Parser 201609

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* Definitions */

#define LETTER      0
#define DIGIT       1
#define UNKNOWN     99

#define INT_LIT     10
#define IDENT       11
#define ASSIGN_OP   20
#define ADD_OP      21
#define SUB_OP      22
#define MULT_OP     23
#define DIV_OP      24
#define LEFT_PAREN  25
#define RIGHT_PAREN 26

#define MAX_LEX  100

/* Exported Globals */

extern int nextToken;
extern FILE *in_fp;

/* Function Prototypes */

int  lookup(char ch);
void addChar();
void getChar();
void getNonBlank();
int  lex();

void parse_error(char *msg, int code);
void parse_msg(char *msg);

void stmt();
void expr();
void term();
void factor();

#endif
/***** End parser.h *****/