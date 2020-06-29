#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List* init_history(){
  Item * head = NULL;

  List * list = (List*)malloc(sizeof(List));
  list->root = head;
    }

void add_history(List *list, char *str){

  if(list->root==NULL){
    Item * p = (Item*)malloc(sizeof(Item));
    p->id=0;
    p->str=str;
    p->next=NULL;

    list->root = p;
  }

  else{
    int i=1;
    Item * p = (Item*)malloc(sizeof(Item));

    p=list->root;
    while(p->next!=NULL){
      ++i;
      p=p->next;
    }
  }

}

//char *get_history(List *list, int id){}

//void print_history(List *list){}

//void free_history(List *list){}
