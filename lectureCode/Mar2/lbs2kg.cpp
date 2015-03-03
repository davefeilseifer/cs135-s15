#include <stdio.h>

float lbsToKgs(float foo){
  float kgs = foo/2.20462;
  return kgs;
}

int main(){

  printf("Enter number of pounds: ");
  float lbs;
  scanf("%f", &lbs);
  float kgs = lbsToKgs(lbs);
  printf("%f pounds = %f kgs\n",lbs, kgs);
}
