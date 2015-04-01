/* Sushil Louis
   sorting example for cs135
   March 1, 2015
*/
#include <stdio.h>
#include <stdlib.h>

void printArray(int *array, int n);
void readArray(int *array, int n);
void bubbleSort(int *array, int n);
void swap(int &foo, int &bar);

int main(int argc, char *argv[]){
  int count = 1000000;       // One Meeeelllliiiiooooon default size
  if(argc == 2)              // command line processing
    count = atoi(argv[1]);

  int input[count];
  readArray(input, count);   // read the input
  bubbleSort(input, count);  // sort the read input
  printArray(input, count);  // print sorted array

}

void printArray(int array[], int n){
  for(int i = 0; i < n; i++){
    printf("%d\n", array[i]);
  }
}

void readArray(int *array, int n){
  int error;
  int counter;
  for(counter = 0; counter < n; counter++){
    error = scanf("%d", &array[counter]); // if error < 1, I am done reading
    if (error < 1) break;
  }
  return;// counter;
}

void swap(int &foo, int &bar){
  int tmp = foo;
  foo = bar;
  bar = tmp;
}

void bubbleSort(int *array, int n){
  bool isSorted = false;
  while (!isSorted){
    isSorted = true;                // assume array is sorted then test
    for(int i = 0; i < n-1; i++){
      if (array[i] > array[i+1]){   // test if adjacent elements are sorted
	swap(array[i], array[i+1]); // if not, swap
	isSorted = false;           // cannot assume array is sorted
      }
    }
  }
}
