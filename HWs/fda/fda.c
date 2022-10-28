#include "fda.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

node* push(node* first, char element, int data) {
  node* new_node = (node*)malloc(sizeof(node));
  new_node->element = element;
  new_node->data = data;
  new_node->next = NULL;

  if (first == NULL) {
    first = new_node;
    return new_node;
  }
  first->next = push(first->next, element, data);
  return first;
}

int fda(node** graph, int current, char* input, int* accept, int start) {
  // string has been consumed
  if (start == (int)strlen(input)) return accept[current];

  // search through the edges of the node
  node* temp = graph[current];
  while (temp != NULL) {
    if (input[start] == temp->element)
      if (fda(graph, temp->data, input, accept, start + 1) == 1) return 1;
    temp = temp->next;
  }
  return 0;
}

