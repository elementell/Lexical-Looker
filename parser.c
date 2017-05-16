#include "parser.h"

int main (int argc, char *argv[])
{
  if (argc < 2)
  {
    printf ("Error - missing input file.\n");
    return 1;
  }
  else if ((in_fp = fopen(argv[1], "r")) == NULL)
  {
    printf ("Error - cannot open %s.\n", argv[1]);
    return 2;
  }
  else
  {
    getChar();
    lex();
    stmt();
  }

  fclose(in_fp);
  return 0;
}
