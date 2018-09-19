#ifndef STACK_H

#ifndef MAX_SIZE
#define MAX_SIZE
#define maxSize 100
#endif

typedef struct Stack {
  int data;
  struct Stack *top;
  struct Stack *base;
} sqStack;

// init stack
sqStack *init();

// push node
sqStack *push(sqStack *s, int data);

// print value of node
void print(sqStack *s);

// pop node
sqStack *pop(sqStack *s, int *data);

#define STACK_H
#endif