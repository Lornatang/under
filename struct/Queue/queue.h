#ifndef QUEUE_H
#define QUEUE_H

#ifndef SIZE
#define MAX_SIZE 10
#define increase 2
#endif  // SIZE

typedef struct Queue {
  int data;
  int num;  // number of queue elements
  struct Queue *next;
} queue, *queuePtr;

typedef struct {
  queuePtr rear;
  queuePtr front;
} * seQueue;

// init queue
seQueue init();

// destory queue
seQueue destory(seQueue Q);

// push value to queue
int push(seQueue Q, int data);

// pop value to queue
int pop(seQueue Q, int *data);

// print value
void dis(seQueue Q);

#endif  // QUEUE_H