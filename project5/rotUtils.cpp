#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "rotUtils.h"

int rotate(int c, int n){
  if (n == 0) return c;
  int nRot = abs(n) % (RANGECHAR + 1);
  if(n > 0)
    return rotatePlus(c + nRot);
  else
    return rotateMinus(c - nRot);
}

int rotatePlus(int sum){
  int diff = sum - MAXCHAR;
  if (sum > MAXCHAR) sum = MINCHAR + diff - 1;
  return sum;
}

int rotateMinus(int sum){
  int diff = MINCHAR - sum;
  if (sum < MINCHAR) sum = MAXCHAR - diff + 1;
  return sum;
}
