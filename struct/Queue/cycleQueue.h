#ifndef CYCLEQUEUE_H
#define CYCLEQUEUE_H

#ifndef MAXSIZE
#define max_size 10
#define increase 2
#endif  // SIZE

typedef struct Queue {
  int front;  // front point
  int rear;   // rear point
  struct Queue *next;
} queue;

// init queue
queue *init();

// get queue length
int getLength(queue *Q);

// insert value to queue
int insert(queue *Q, queue data);

// delete value to queue
int del(queue *Q);

// print value
void dis(queue *Q);

#endif  // CYCLEQUEUE_H
