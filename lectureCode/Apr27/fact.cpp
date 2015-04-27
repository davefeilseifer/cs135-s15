#include <stdio.h>
#include <stdlib.h>

int factorial(int n){
  if (n == 0)
    return 1;
  else
    return n * factorial(n - 1);
}

int factiterative(int n){
  int prod = n;
  for (int i = n-1; i > 0; i--){
    prod = prod * i;
  }
  return prod;
}


int main(int argc, char *argv[]){

  int n = 5;
  if( argc == 2)
    n = atoi(argv[1]);

  //int result = factorial(n);
  int result = factiterative(n);
  printf("\n%d! =  %d\n\n", n, result);
}

