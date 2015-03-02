#include <stdio.h>

int main(){
  // read some numbers
  int grade;
  int max;

  printf ("Max uninitialized: %d\n", max);

  scanf("%d", &grade);
  max = grade;
  for(int i = 0; i < 500 ; i++){
    if (grade > max){
      max = grade;
    }
    int n = scanf("%d", &grade);
    if(n < 0)
      break;
  }

  // find the max


  // print the result

  printf("Max is %d\n", max);



}
