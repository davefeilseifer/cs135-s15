#include <stdio.h>

void swap(int &foo, int &bar){
  int tmp;
  tmp = foo;
  foo = bar;
  bar = tmp;
}

int main(){
  int a = 5;
  int b = 37;
  printf ("Before: a: %d, b: %d\n", a, b);
  swap(a, b);
  printf ("After: a: %d, b: %d\n", a, b);
}
