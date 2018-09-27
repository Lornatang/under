#ifndef LIST_H
#define LIST_H

typedef struct Node {
  char data;
  struct Node *fchild;
  struct Node *nchild;
} node;

typedef struct Tree {
  node *root;
  char value;
} tree;

#endif  // LIST_H