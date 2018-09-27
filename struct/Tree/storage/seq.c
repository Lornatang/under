#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char data;
  int parent;
} node;

typedef struct {
  node data[20];
  int num;  // number of node
} tree;

tree *init() {
  tree *T;
  T = (tree *)malloc(20 * sizeof(tree));
  if (!T) exit(0);
  printf("Please input node of numbers!\n");
  char ch = scanf("%d", &T->num);

  printf("Please input node of value and parents value.\n");
  for (int i = 0; i < T->num; i++) {
    fflush(stdin);
    int j = 0;
    scanf("%c, %d", &ch, &j);
    T->data[i].data = ch;
    T->data[i].parent = j;
  }
  T->data[0].parent = -1;
  return T;
}

void findP(tree *T) {
  printf("Please input to query node sequence numbers.\n");
  int i = scanf("%d", &i);
  printf("%c parents node value is %d\n", T->data[i].data, T->data[i].parent);
}

int main() {
  tree *T;
  T = init();
  while (1) {
    findP(T);
  }

  return 0;
}