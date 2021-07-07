#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

#define MAX 50

int main(){

  List * lis = init_history();
  char** tokens;
  
  while(1){

    printf("> ..");
    char str[MAX];
    fgets(str, MAX, stdin);
    //printf("string: %s\n",str);
    tokens = tokenize(str);
    print_tokens(tokens);
    free_tokens(tokens);
    
    if(*str == 'q')
      break;

    else if(*str == '!'){
      int ind = str[1] - '0';
      //printf("index %d", ind);
      printf( "\n>>> %s", get_history(lis, ind));
    }

    else{
      add_history(lis, str);
    }
  }

  
  return 0;

}
