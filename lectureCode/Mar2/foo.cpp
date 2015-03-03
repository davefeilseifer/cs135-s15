#include <stdio.h>

void foo(int x, float y){
  x++;
  y = y + 1.0f;
  printf("In foo:            x: %d, y: %f\n", x, y);

}

int main(){
  int   x = 10;
  float y = 87.0f;

  printf("In main: Before: x: %d, y = %f\n", x, y);
  foo(x, y);
  printf("In main: After:  x: %d, y = %f\n", x, y);
  return 0;
}
