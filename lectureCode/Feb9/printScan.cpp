#include <stdio.h>

int main(){

  int foo, bar;
  float foobar;
  char c;
  double dfoo = 8.0;
  printf("type in two integers and a float and a char: ");

  scanf("%d %d %f %c", &foo, &bar, &foobar, &c);
  printf("%d %d %.2f %c %lf\n", foo, bar, foobar, c, dfoo);

  float product = foo * bar * foobar;

  printf ("product: %.4f\n", product);
  return 0;
}
