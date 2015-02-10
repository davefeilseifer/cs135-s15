#include <stdio.h>


// sushil's way
void convertToBinary(int input){
  printf("Convert %d to binary \n", input);

  while(input > 0){
    printf ("%d", input%2);
    input = input/2;

  }
  printf("\n");
}

void convertToBinaryCorrect(int input){

  if( input >= 4 ) {
    printf( "1" );
    input -= 4;
  }
  else {
    printf( "0" );
  }

  if( input >= 2 ) {
    printf( "1" );
    input -= 2;
  }
  else {
    printf("0");
  }
  if( input >= 1 ) {
    printf( "1"  );
    input -= 1;
  }
  else
    printf("0");

  printf("\n");
}




int main(){

  int decimal;
  // read
  printf("Enter decimal\n");
  scanf("%d", &decimal);
  // do the conversion
  convertToBinaryCorrect(decimal);
  return 0;

}

