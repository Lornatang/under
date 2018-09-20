#ifndef QUEUE_H
#define QUEUE_H

#ifndef SIZE
#define MAX_SIZE 10
#define increase 2
#endif  // SIZE

typedef struct Queue {
  int data[MAX_SIZE];
  int num;  // number of queue elements
  struct Queue *next;
} queue, *queuePtr;

typedef struct {
  queuePtr rear;
  queuePtr front;
} * seQueue;

// init queue
seQueue init();

#endif  // QUEUE_H