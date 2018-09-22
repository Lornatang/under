#include "cycleQueue.h"
#include <stdio.h>
#include <stdlib.h>

queue *init() {
  queue *Q;
  Q->next = (queue *)malloc(max_size * sizeof(queue));
  if (!Q->next) exit(0);
  Q->front = Q->rear = 0;

  return Q;
}  // init queue

int getLength(queue *Q) {
  return (Q->rear - Q->front + max_size) % max_size;
}  // get queue length

int insert(queue *Q, queue data) {
  if ((Q->rear + 1) % max_size == Q->front) return -1;
  Q->next[Q->rear] = data;
  Q->rear = (Q->rear + 1) % max_size;
  return 0;
}  // insert node to value

int del(queue *Q) {
  queue *node;
  if (Q->rear == Q->front) return -1;
  *node = Q->next[Q->rear];
  Q->front = (Q->front + 1) % max_size;
  return 0;
}

void dis(queue *Q) {
  queue *node;
  node = Q->next;
  printf("Print queue:\t");
  for (node = Q->next; node != NULL; node = node->next) {
    printf("%d ", node->front);
  }
  putchar('\n');
}

int main() {
  queue *Q = init();

  free(Q);

  return 0;
}