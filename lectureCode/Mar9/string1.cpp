#include <stdio.h>
#include <string.h>

int length(char x[]){
  int i = 0;
  while(x[i] != '\0') i++;
  return i;
}

int main(){
  char foo[100];
  printf("Type in a string\n");
  for(int i = 0; i < 100; i++){
    foo[i] = 'u';
  }

  scanf("%s", foo);

  foo[5] = 'u';
  foo[6] = 'u';

  for (int i = 0; i < length(foo); i++){
      printf("%c", foo[i]);
  }
  printf("\n");

}

