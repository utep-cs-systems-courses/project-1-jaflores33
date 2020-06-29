#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"

#define MAX 50

int main(){

  printf(" > \n");
  char str[MAX];
  fgets(str, MAX, stdin);
  printf(".. %s", str);

  int wordCount = count_words(str);
  printf("\n ... %d", wordCount);

  char sc = str[1];
  int space = space_char(sc);
  printf("\n ...%d", space);

  int noSpace = non_space_char(sc);
  printf("\n ...%d", noSpace);

  char * start = word_start(str+2);
  printf("\n :: %s", start);

  char * end = word_terminator(start);
  printf("\n :: %s", end);


  short len= end - start;
  printf("\nLen: %d",len);


  char * strCopy = copy_str(start, len);
  printf("\nCopy: %s \n", strCopy);


  char **tokens = tokenize(str);

  print_tokens(tokens);

  free_tokens(tokens);
  
  printf("\n :D %s", str);
  return 0;
}
