#ifndef STACK_H

#ifndef BOOL
#define true 0
#define false 1
#endif  // BOOL

#ifndef LENGTH
#define MAX_SIZE
#define size 10
#define increase 2
#endif

typedef struct Stack {
  int data;
  struct Stack *top;
  struct Stack *base;

  int length;
} sqStack;

// init stack
sqStack *init();

// push node
int push(sqStack *S, int data);

// print value of node
void print(sqStack *S);

// pop node
int pop(sqStack *S, int data);

#define STACK_H
#endif