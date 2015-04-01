#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "rotUtils.h"

void decrypt(char *crypt, char *clear, int n, int size);
bool find(char *clear, int length, char dict[][100], int nwords);
void printText(char *c, int size);

int main(int argc, char *argv[]){

  FILE *cryptFile  = fopen(argv[1], "r");
  FILE *dictionaryFile = fopen(argv[2], "r");

  //--------read cyphertext------------------------------------
  int c; 
  int i = 0;
  char cryptText[30000];
  char clearText[30000];
  while((c = fgetc(cryptFile)) != EOF){
    cryptText[i++] = c;
  }
  cryptText[i] = '\0';
  printf("\nRead cipher Text\n");
  int length = i; // length of encrypted text
  //--------read dictionary------------------------------------
  int n = 0;
  int nwords = 0;
  char dictionary[25000][100];
  while( (n = fscanf(dictionaryFile, "%s", dictionary[nwords])) > 0 && (nwords < 25000) ){
    nwords++;
  }
  printf("Read dictionary\n");

  fclose(cryptFile);
  fclose(dictionaryFile);

  //-----break cypher, brute force-----------------------------
  int key = -100;
  for(int rot = -50; rot <= 50; rot++){
    //    printText(cryptText, length);
    decrypt(cryptText, clearText, rot, length);
    //    printText(clearText, length);
    if(find(clearText, length,  dictionary, nwords)){
      key = rot;
      break;
    }
  }
  //-------print clear text------------------------------------
  printText(clearText, length);
  printf ("\nThe ceasar cypher key was: %2d\n", key);
}

void decrypt(char *crypt, char *clear, int n, int size){
  for(int i = 0; i < size; i++){
    if(!isspace(crypt[i])){
      clear[i] = rotate(crypt[i], n);
    } else {
      clear[i] = crypt[i];
    }
  }
  clear[size] = '\0'; //ensure clear text is a C string!
}

bool find(char *clear, int nchars, char dict[][100], int nwords){
  for(int i = 0; i < nwords; i++){
    if (strstr(clear, dict[i]) != NULL) {
      printf("\nMatch found: %s\n", dict[i]);
      return true;
    }
  }
  return false;
}

void printText(char *text, int size){
  for(int i = 0; i < size; i++){
    printf("%c", text[i]);
  }
  printf("\n         --------------------             \n");
}


