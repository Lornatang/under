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

// insert node to queue
int push(seQueue Q, int data) {
  queue *node;
  node = (queuePtr)malloc(sizeof(queue));
  if (!node) exit(0);

  node->data = data;
  node->next = NULL;
  Q->rear->next = node;
  Q->rear = node;
  return 0;
}

int pop(seQueue Q, int *data) {
  queue *node;
  if (Q->front == Q->rear) return -1;
  node = Q->front->next;
  *data = node->data;
  Q->front->next = node->next;
  if (Q->rear == node) Q->rear = Q->front;
  free(node);
  return 0;
}

void dis(queue *node) {
  node = node->next;
  while (node != NULL) {
    printf("Value: %d.\n", node->data);
    node = node->next;
  }
}

int main() {
  
}