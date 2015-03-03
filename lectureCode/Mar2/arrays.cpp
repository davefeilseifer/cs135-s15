#include <stdio.h>

int main(){

  int nums[10];
  for(int i = 0; i < 10; i++){
    scanf("%d", &nums[i]);
  }

  printArray(nums);

}
