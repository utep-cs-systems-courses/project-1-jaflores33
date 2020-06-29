#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

#define MAX 50

int main(){

  while(1){

    printf("> ..");
    char str[MAX];
    fgets(str, MAX, stdin);
    //printf("string: %s\n",str);
    char** tokens = tokenize(str);
    //print_tokens(tokens);
    
    if(*str == 'q')
      break;
    
  }

  
  return 0;

}
