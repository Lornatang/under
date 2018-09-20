#include "linkStack.h"
#include <stdio.h>
#include <stdlib.h>

linkStack init() {
  linkStack S;
  S = (linkStack)malloc(sizeof(stack));
  if (!S) exit(0);
  S->next = NULL;
  return S;
}  // init stack func

int isEmpty(linkStack S) {
  if (S->next == NULL)
    return 1;
  else
    return 0;
}  // judge stack is empty.

// push node
linkStack push(linkStack S, int data) {
  linkStack node;
  node = (linkStack)malloc(sizeof(stack));
  if (!node) exit(0);
  node->data = data;
  node->next = S;
  S = node;
  return S;
}

// pop node
linkStack pop(linkStack S, int *data) {
  linkStack node;
  if (S->next == NULL)
    return NULL;
  else {
    *data = S->data;
    node = S;
    S = S->next;
    free(node);
    return S;
  }
}

// print stack node value.
void dis(linkStack S) {
  linkStack node;
  node = S->next;
  while (node != NULL) {
    printf("Value: %d.\n", node->data);
    node = node->next;
  }
}

// Numerical transformation
void conv() {
  linkStack S;
  S = init();
  int x = 0;
  printf("Input decimal number.\n");

  while (scanf("%d", &x)) {
    push(S, x % 8);
    x = x / 8;
  }
  int *y;
  pop(S, y);
  printf("Value: %d", *y);
}

int main() {
  linkStack S;

  S = init();

  push(S, 1);
  push(S, 2);
  push(S, 3);
  push(S, 4);
  push(S, 5);
  push(S, 6);
  dis(S);

  int data1 = 1;
  int data2 = 2;
  int data3 = 3;
  pop(S, &data1);
  pop(S, &data2);
  pop(S, &data3);

  // conv();
  return 0;
}