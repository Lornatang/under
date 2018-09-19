#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

sqStack *init() {
  sqStack *S = NULL;
  S = (sqStack *)malloc(sizeof(sqStack));
  if (!S) exit(0);
  S->top = 0;
  return S;
}  // init struct

int getTop(sqStack *S) {
  sqStack *node;
  if (S->top == S->base) return false;
  node->top = S->top - 1;
  return node->data;
}

sqStack *push(sqStack *S, int data) {
  sqStack *node;
  node = S;
  node = (sqStack *)malloc(sizeof(sqStack));
  if (!node) exit(0);
  *node->top++ = data;
  return S;
}

sqStack *pop(sqStack *s, int *data) {
  if (s->top == 0)
    printf("Stack is empty.\n");
  else {
    s->top -= 1;
    *data = s->a[s->top];
  }
  return 0;
}

void print(sqStack *s) {
  int i = 0;
  if (s->top == 0) {
    printf("It is empty\n");
  }
  /*s -> top，栈的长度*/
  else {
    for (i = 0; i < s->top; i++) printf("Stack data：%d\n", s->a[i]);
  }
}

int main() {
  int h = 4;
  int p = 0;
  int i = 0;
  int x = 3;
  sqStack *s;

  s = init();

  for (i = 0; i < 5; i++) {
    push(s, i);
  }
  print(s);

  /*弹出操作*/
  pop(s, &x);
  printf("弹出的元素是：%d\n", x);
  pop(s, &x);
  printf("弹出的元素是：%d\n", x);
  pop(s, &x);
  printf("弹出的元素是：%d\n", x);
  pop(s, &x);
  printf("弹出的元素是：%d\n", x);
  pop(s, &x);
  printf("弹出的元素是：%d\n", x);
  pop(s, &x);
  printf("%d\n", x);

  return 0;
}