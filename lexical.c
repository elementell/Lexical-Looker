#include "parser.h"

/*** Globals ****/

int  charClass;
int  lexLen;
int  token;
int  nextToken;

char nextChar;
char lexeme[MAX_LEX];

FILE *in_fp;

/****************************
 *
 * int lookup(char ch)
 *
 * looks up operators
 *
 ****************************/
 
 int lookup(char ch)
 {
   switch (ch)
   {
     case '=':
       addChar();
       nextToken = ASSIGN_OP;
       break;
       
     case '(':
       addChar();
       nextToken = LEFT_PAREN;
       break;
       
     case ')':
       addChar();
       nextToken = RIGHT_PAREN;
       break;
       
     case '+':
       addChar();
       nextToken = ADD_OP;
       break;
       
     case '-':
       addChar();
       nextToken = SUB_OP;
       break;
       
     case '*':
       addChar();
       nextToken = MULT_OP;
       break;
       
     case '/':
       addChar();
       nextToken = DIV_OP;
       break;
       
     default:
       addChar();
       nextToken = EOF;
       break;
    }
 
    return nextToken;
  }
 
/****************************
 *
 * void addChar()
 *
 * adds nextChar to lexeme
 *
 ****************************/
 
 void addChar()
 {
   if (lexLen < MAX_LEX-1)
   {
     lexeme[lexLen++] = nextChar;
     lexeme[lexLen]   = '\0';
   }
   else
   {
     printf ("Error - lexeme is too long.\n");
     exit (3);
   }
 }
 
/****************************
 *
 * void getChar()
 *
 * reads next char from input
 * assigns charClass
 *
 ****************************/
 
 void getChar()
 {
   if ((nextChar = getc(in_fp)) != EOF)
   {
     if (isalpha(nextChar))
       charClass = LETTER;
     else if (isdigit(nextChar))
       charClass = DIGIT;
     else
       charClass = UNKNOWN;
   }
   else
     charClass = EOF;
 }
 
/****************************
 *
 * void getNonBlank()
 *
 * skips white space
 *
 ****************************/
 
 void getNonBlank()
 {
   while (isspace(nextChar))
     getChar();
 }
 
/****************************
 *
 * int lex()
 *
 * simple lexical analyzer
 *
 ****************************/ 

 int lex()
 {
   lexLen = 0;
   getNonBlank();
   
   switch (charClass)
   {
     case LETTER:  /* identifiers */
     
       addChar();
       getChar();
       
       while (charClass == LETTER || charClass == DIGIT)
       {
         addChar();
         getChar();
       }
       
       nextToken = IDENT;
       break;
       
     case DIGIT:  /* integer literals */
     
       addChar();
       getChar();
       
       while (charClass == DIGIT)
       {
         addChar();
         getChar();
       }
       
       nextToken = INT_LIT;
       break;
       
     case UNKNOWN:  /* operators */
     
       lookup(nextChar);
       getChar();
       break;
       
     case EOF:
     
       nextToken = EOF;
       lexeme[0] = 'E';
       lexeme[1] = 'O';
       lexeme[2] = 'F';
       lexeme[3] = '\0';
       break;
   }
   
   printf ("Next token is: %d, next lexeme is %s\n", nextToken, lexeme);
   
   return nextToken;
 }

 /***** End lexical.c *****/
