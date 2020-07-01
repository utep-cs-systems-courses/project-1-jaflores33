#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List* init_history(){
  Item * head = (Item*)malloc(sizeof(Item));
  head->id = 0;
  head->str = NULL;
  head->next = NULL;
  
  List * list = (List*)malloc(sizeof(List));
  list->root = head;

  return list;
    }

void add_history(List *list, char *str){

  Item * head = list->root;
  Item * p = (Item*)malloc(sizeof(Item));
  
  int i = 1;
  
  while(head->next != NULL){
    head = head->next;
    ++i;
  }
  p->id=i;
  p->str = str;
  p->next=NULL;

  head->next=p;
}

char *get_history(List *list, int id){
  Item * p = list->root;
  
  while(id != 1){
    --id;
    p=p->next;
  }
  return p->str;
}

//void print_history(List *list){}

//void free_history(List *list){}
