#ifndef STACK_H
typedef struct Stack {
  int a[20];
  int top;
} sqStack;

// init stack
sqStack *init();

// push node
int push(sqStack *s, int data);

// print value of node
void print(sqStack *s);

// pop node
int pop(sqStack *s, int data);

#define STACK_H
#endif