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
  Node* new_node = malloc(sizeof(Node));
  new_node -> data = data;
  new_node -> next_node = NULL;

  ll -> head = new_node;
}




int main(){
  LinkedList list;
  int a = 5;
  llappend(&list, a);
  
  printf("%zu", list.head -> data);

  return 0;
}
