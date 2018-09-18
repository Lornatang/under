#ifndef STACK_H

#ifndef MAX_SIZE
#define MAX_SIZE
#define maxSize 100
#endif

typedef struct Stack {
  int a[maxSize];
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