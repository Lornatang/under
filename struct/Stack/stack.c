#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

sqStack *init() {
  sqStack *S;
  S->base = (sqStack *)malloc(size * sizeof(sqStack));
  if (!S->base) exit(0);
  S->top = S->base;
  S->length = size;
  return S;
}  // init struct

sqStack *getTop(sqStack *S) {
  sqStack *node;
  node = S;
  int data = 0;
  if (S->top == S->base) return 0;

  node = S->top - 1;
  return node;
}  // get stack top

// push node to stack
sqStack *push(sqStack *S, sqStack data) {
  if (S->top - S->base >= S->length) {
    S->base = (sqStack *)realloc(S->base, (size + increase) * sizeof(sqStack));

    if (!S->base) exit(0);

    S->top = S->base + S->length;
    S->length += increase;
  }
  *S->top++ = data;
  return 0;
}

sqStack *pop(sqStack *S, sqStack data) {
  if (S->top == S->base) return 0;

  data = *--S->top;
  return 0;
}

void print(sqStack *S) {
  sqStack *node;
  node = S->top;
  while (!node) {
    printf("Value: %d\n", node->top);
    node = node->top;
  }
}

int main() {
  int h = 4;
  int p = 0;
  int i = 0;
  int x = 3;
  sqStack *S;

  S = init();

  for (i = 0; i < 5; i++) {
    push(S, i);
  }
  print(S);

  return 0;
}