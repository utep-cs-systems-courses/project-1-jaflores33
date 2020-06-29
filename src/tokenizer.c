#include "tokenizer.h"
#include <stdlib.h>
#include <stdio.h>

int count_words(char *str){

  int s=0;
  int count=0;

  while(*str){
    if(*str == ' ')
      s=0;

    else if(s == 0){
      s=1;
      ++count;
    }
    *str++;
  }
  return count;
}

int space_char(char c){
  if(c==' ' || c=='\t')
    return 1;

  else
    return 0;
}

int non_space_char(char c){
  if(c!=' ' && c!='\t')
    return 1;

  else
    return 0;
}
char *word_start(char *str){

  if(space_char(*str)==1)
    *str++;

  else
    return str;
  
}

char *word_terminator(char *word){

  while(non_space_char(*word)==1){
    *word++;
  }

  return word;

}

char *copy_str(char *inStr, short len){

  char* copy;
  copy = malloc(sizeof(char) * len);

  for(int i=0; i < len; i++){
    copy[i]= *inStr;
    *inStr++;
  }
  copy[len]='\0';
  
  return copy;

}

char **tokenize(char *string){

  char** tokens;
  int size = count_words(string);
  tokens = malloc(size * sizeof(char*));
  int i=0;
  char* s = word_start(string);
  char* e = word_terminator(string);

  while(i<size){ 
    tokens[i] =copy_str(s, (e-s));
    ++i;
    s=word_start(e);
    e=word_terminator(s);

  }
  tokens[size]='\0';

  return tokens;

}

void print_tokens(char **tokens){

  int i=0;
  while(tokens[i] != NULL){
    printf("++ %s \n", tokens[i]);
    ++i;
  }

}

void free_tokens(char **tokens){
  int i=0;
    while(tokens[i] != NULL){
      free(tokens[i]);
      ++i;
    }
  free(tokens);
}

