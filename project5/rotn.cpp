#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "rotUtils.h"

int main(int argc, char *argv[]){
  FILE *fp = stdin;  // defaults
  int  n = 13;
  // process command line
  switch(argc) {
  case 2: // only have n, assumed input from stdin
    n = atoi(argv[1]);
    break;
  case 3: // have n and input file 
    fp = fopen(argv[1], "r"); // should check for problems
    n  = atoi(argv[2]);
    break;
  default:
    fp = stdin;
    n  = 13;
  }
  // rotate text
  int c;
  while( (c = fgetc(fp)) != EOF){
    if(!isspace(c)){
      c = rotate(c, n);
    }

    printf("%c", c);
  }
  fclose(fp);
}
