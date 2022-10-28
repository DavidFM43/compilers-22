#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fda.h"

int main() {
  system("clear");
  printf("Finite Deterministic Automata Program\n\n");

  int n;
  printf("Enter the number of states of the FDA.\n");
  scanf("%d", &n);  // Number of nodes

  /* Example FDA */
  // n = 4;
  // char* in[] = {"1 0 2 0 2 1 3", "2 0 1 0 4", "3 0 1 1 4", "4 1 2 0 4 1 4"};

  node* graph[n + 1];  // create a graph
  for (int i = 0; i < n + 1; i++) graph[i] = NULL;
  int accept[n + 1];  // array to store state of vertex

  printf("Enter the states of the FDA in the following manner:\n");
  printf("For each state enter: <idx> <acceptance> <number-of-edges>\n");
  printf("Then enter the edges info: <value(0 or 1)> <state>\n");

  for (int i = 0; i < n; i++) {
    // Index of vertex, acceptance state and number of edges
    int index, acc, number_edges;

    printf("Enter the index, acceptance and number of edges of the node:\n");
    scanf("%d%d%d", &index, &acc, &number_edges);

    // store acceptance
    accept[index] = acc;

    for (int j = 0; j < number_edges; j++)  // Add all edges
    {
      int node_add;
      int edge;
      printf("Enter the edge info:\n");
      scanf("%d%d", &edge, &node_add);
      graph[index] = push(graph[index], '0' + edge, node_add);
    }
  }

  /* Process string with the FDA*/
  char input[100];
  while (1) {
    printf("\nEnter an input string:\n");
    scanf("%s", input);

    if (fda(graph, 1, input, accept, 0) == 1)
      printf("Accepted\n");
    else
      printf("Rejected\n");
  }
}
