#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

sqStack *init() {
  sqStack *S;
  S = (sqStack *)malloc(sizeof(sqStack));
  if (!S) exit(0);
  S->data = 0;
  S->top = S->base;
  S->length = size;
  return S;
}  // init struct

int getTop(sqStack *S) {
  sqStack *node;
  node = S;
  if (S->top == S->base) {
    printf("Empty stack.\n");
    return 0;
  }
  node->top = S->top - 1;
  return node->data;
}  // get stack top

// push node to stack
int push(sqStack *S, int data) {
  if (S->top - S->base)
    return 0; /*栈满不能入栈*/
  else {
    S->top++;
    S->data[S->top] = data;
    return 1;
  }
}
}

sqStack *pop(sqStack *S, struct Stack data) {
  if (S->top == S->base) {
    printf("Empty stack.\n");
    return 0;
  }
  data = *S->top--;
  return S;
}

void print(sqStack *S) {
  sqStack *node;
  node = S;
  while (!node->top) {
    printf("Value: %d\n", node->data);
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

  /*弹出操作*/
  pop(S, &x);
  printf("弹出的元素是：%d\n", x);
  pop(S, &x);
  printf("弹出的元素是：%d\n", x);
  pop(S, &x);
  printf("弹出的元素是：%d\n", x);
  pop(S, &x);
  printf("弹出的元素是：%d\n", x);
  pop(S, &x);
  printf("弹出的元素是：%d\n", x);
  pop(S, &x);
  printf("%d\n", x);

  return 0;
}