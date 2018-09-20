#ifndef LINKSTACK_H
#define LINKSTACK_H

typedef struct Stack {
  int data;
  struct Stack *next;
} stack, *linkStack;

// init link stack
linkStack init();

// judge link stack is empty?
int isEmpty(linkStack top);

// push node to linkStack
linkStack push(linkStack S, int data);

// popn node out linkStack
linkStack pop(linkStack S, int *data);

#endif