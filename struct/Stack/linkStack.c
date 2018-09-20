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

linkStack push(linkStack S, int data) {
  linkStack node;
  node = (linkStack)malloc(sizeof(stack));
  node->data = data;
  node->next = S;
  S = node;
  return S;
}

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

void dis(linkStack S) {
  linkStack node;
  node = S->next;
  while (node != NULL) {
    printf("Value: %d.\n", node->data);
    node = node->next;
  }
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

  int data1 = 1;
  int data2 = 2;
  int data3 = 3;
  pop(S, &data1);
  pop(S, &data2);
  pop(S, &data3);

  return 0;
}