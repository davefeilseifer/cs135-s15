#include <stdio.h>
#include <stdlib.h>

int main(){

  for (int i = 0; i < 200;i++){
    printf ("%ld\n",  random()%201);
  }

  return 0;
}
