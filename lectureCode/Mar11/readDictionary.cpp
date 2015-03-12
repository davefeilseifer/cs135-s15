#include <stdio.h>

int main(int argc, char *argv[]){

  char dictionary[6][100];
  for(int i = 0; i < 6; i++){
    scanf("%s", dictionary[i]);
  }

  for(int i = 0; i < 6; i++){
    printf(" Word[%d] = %s\n", i, dictionary[i]);
  }

  return 0;
}


