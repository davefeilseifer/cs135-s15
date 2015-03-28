#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]){

  int count = 100;
  int low   = -100000;
  int high  = 100000;

  if (argc == 2){
    count = atoi(argv[1]);
  }

  srandom((long int) time(NULL));
  int range = high - low;
    
  for(int i = 0; i < count; i++){
    printf("%d\n", low + (int) random()%range);
  }
  return 0;
}

