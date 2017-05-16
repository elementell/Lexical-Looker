#include "parser.h"

/*********************************************
 * This file will contain your code for the
 * recursive-descent syntax analyzer. You have
 * to implement the functions stmt(), expr(),
 * term(), and factor().
 *********************************************/

/*********************************************
 *
 * void parse_error (char *msg, int code)
 *
 * Prints "msg" and exits with code "code".
 *
 *********************************************/

void parse_error (char *msg, int code)
{
  printf ("Error - %s\n", msg);
  exit (code);
}

/*********************************************
 *
 * void parse_msg (char *msg)
 *
 * Prints "msg".
 *
 *********************************************/

void parse_msg (char *msg)
{
  printf ("%s\n", msg);
}

void stmt(){
    parse_msg("Entering <stmt>");
    if (nextToken != IDENT)
        parse_error("Statement must begin with an ID",3);
    lex();
    if (nextToken != ASSIGN_OP)
        parse_error("Expected assignment operator",1);
    lex();
    expr();
    parse_msg("Exiting <stmt>");
}
void expr(){
    parse_msg("Entering <expr>");
    while (nextToken != EOF) {
        if (nextToken == IDENT || nextToken == MULT_OP || nextToken == DIV_OP || nextToken == INT_LIT) {
            term();
        } else {
            lex();
        }
    }
    parse_msg("Exiting <expr>");
}
void term(){
    parse_msg("Entering <term>");
    while (nextToken == IDENT || nextToken == INT_LIT || nextToken == MULT_OP || nextToken == DIV_OP) {
        if (nextToken == IDENT || nextToken == INT_LIT)
            factor();
        else
            lex();
    }
    parse_msg("Exiting <term>");
}
void factor(){
    parse_msg("Entering <factor>");
    /*while(nextToken == IDENT || nextToken == INT_LIT) {
        lex();
    }*/
    lex();
    if (nextToken == IDENT || nextToken == INT_LIT)
        parse_error("Two IDs or integer literals next to each other without an operator",2);
    parse_msg("Exiting <factor>");
}

 /***** End syntax.c *****/
