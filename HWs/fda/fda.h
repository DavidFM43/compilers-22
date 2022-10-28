/* Structure to represent an adjacency list of the graph */
struct node {
  int data;
  struct node* next;
  char element;
} typedef node;

/* Adds an edge to an adjacency list */
node* push(node*, char, int);

/* Recursive function to check acceptance of input */
int fda(node**, int, char*, int*, int);
