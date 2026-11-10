#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  size_t data;
  struct Node* next_node;
} Node;

typedef struct{
  Node* head;
  size_t len;
} LinkedList;

void llappend(LinkedList *ll, int data){
  Node *new_node = malloc(sizeof(Node));

  new_node -> data = data;
  new_node->next_node = NULL;
  
  if (ll -> head == NULL){
    ll -> head = new_node;
    ll -> len += 1;
    return;
  }

  Node *last_node = ll -> head;
  while (last_node -> next_node != NULL){
    last_node = last_node -> next_node;
  }
  
  last_node -> next_node = new_node;
  ll -> len += 1;
  return;
}


void llrepr(LinkedList *ll){
  Node *node = ll -> head;
  while (node != NULL){
    printf("%lu -> ", node -> data);
    node = node -> next_node;
  }
  return;
}
  
int main(){
  LinkedList *list = malloc(sizeof(LinkedList));
  int a = 5;

  // ll init
  list->head = NULL;
  list->len = 0;

  // llappend(list, a);

  for(int i = 1; i < 1000 + 1; i++){
      llappend(list, i);  
  } 
  llrepr(list);
  free(list);
  return 0;
}
