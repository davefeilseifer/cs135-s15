#include<stdio.h>
#include<string.h>
#include <ctype.h>

int main(int argc, char *argv[]){

  char filename[1024];

  strcpy(filename, argv[1]);
  FILE *fp = fopen(filename, "r");
  int c;
  int oldC;
  int charCount = 0;
  int wordCount = 0;
  int lineCount = 0;
  int spaceCount = 0;
  int allCharCount = 0;
  oldC = '\0';
  while((c = fgetc(fp)) != EOF){
    if(c == '\n') lineCount++;
    if (!isspace(oldC) && isspace(c)) wordCount++;
    if (!isspace(c)) charCount++;
    if (isspace(c)) spaceCount++;
    allCharCount++;
    oldC = c;
  }

  printf("  %d %d %d %d\n", lineCount, wordCount, allCharCount, charCount);

  return 0;
}
