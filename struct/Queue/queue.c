#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

// init queue node
seQueue init() {
  seQueue Q;
  queue *q;
  Q->front = Q->rear = (queuePtr)malloc(sizeof(queue));
  if (!Q->front) exit(0);

  Q->front->next = NULL;
  q->num = 0;
  return Q;
}  // init queue

// destory queue
seQueue destory(seQueue Q) {
  while (Q->front) {
    Q->rear = Q->front->next;
    free(Q->front);
    Q->front = Q->rear;
  }
  return Q;
}  // destory queue

//