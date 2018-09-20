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
  struct Stack *top;
  struct Stack *base;

  int length;
} sqStack;

// init stack
sqStack *init();

// push node
sqStack *push(sqStack *S, int data);

// print value of node
void print(sqStack *S);

// pop node
sqStack *pop(sqStack *S, int data);

#define STACK_H
#endif