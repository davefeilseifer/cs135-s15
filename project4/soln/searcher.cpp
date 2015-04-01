/* Sushil Louis
   searching example for cs135
   March 1, 2015
*/

#include <stdio.h>
#include <stdlib.h>

void printArray(int *array, int n);
int readArray(int *array, int n);
int binarySearch(int *array, int n, int key);
void swap(int &foo, int &bar);

int main(int argc, char *argv[]){
  int count = 1000000; // One Meeeelllliiiiooooon 
  int input[count];
  int key = 100;
  if(argc == 3) {                             // command line processing
    count = atoi(argv[1]);
    key = atoi(argv[2]);
  }
  int actualCount = readArray(input, count);        // read the input
  int index = binarySearch(input, actualCount, key);// binary search for key
  //printArray(input, actualCount);                   // print sorted array
  if(index >= 0 && index < count){
    printf("Index of %d is %d\n", key, index);
  } else { // not found
    printf("Key %d not found\n", key);
  }

}

void printArray(int array[], int n){
  for(int i = 0; i < n; i++){
    printf("%d\n", array[i]);
  }
}

int readArray(int *array, int n){
  int error;
  int counter;
  for(counter = 0; counter < n; counter++){
    error = scanf("%d", &array[counter]); // if error < 1, I am done reading
    if (error < 1) break;
  }
  return counter;
}

int binarySearch(int *array, int n, int key){

  int low = 0;
  int high = n;
  int mid;
  while(high > low){
    mid = (high+low)/2;
    //    printf("low: %d, \tmid: %d, \t high: %d, \tval: %d\n", 
    //	   low, mid, high, array[mid]);
    if(key == array[mid]){
      return mid;
    } else if (key > array[mid]){ // must be in the top    portion of the array
      low = mid+1;
    } else {                      // must be in the bottom portion of the array
      high = mid;
    }
  }
  return -1;
}

