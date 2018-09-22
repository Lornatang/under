#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

pQueue init() {
  pQueue Q = (pQueue)malloc(sizeof(pQueue));
  if (!Q) exit(0);
  Q->front = -1;
  Q->rear = -1;
  Q->size = 0;
  return Q;
}

int IsFull(pQueue Q) { return (Q->size == max_size); }

void insert(pQueue Q, int item) {
  if (IsFull(Q)) {
    printf("Queue is full!\n");
    return;
  }
  Q->rear++;
  Q->rear %= max_size;
  Q->size++;
  Q->data[Q->rear] = item;
}

int isEmpty(pQueue Q) { return (Q->size == 0); }

int del(pQueue Q) {
  if (isEmpty(Q)) {
    printf("空队列\n");
    return 1;
  }
  Q->front++;
  Q->front %= max_size;  // 0 1 2 3 4 5
  Q->size--;
  return Q->data[Q->front];
}

void dis(pQueue Q) {
  if (isEmpty(Q)) {
    printf("空队列\n");
    return;
  }
  printf("打印队列数据元素：\n");
  int index = Q->front;
  int i;
  for (i = 0; i < Q->size; i++) {
    index++;
    index %= max_size;
    printf("%d ", Q->data[index]);
  }
  printf("\n");
}

int main(int argc, const char* argv[]) {
  pQueue Q = init();

  insert(Q, 0);
  insert(Q, 1);
  insert(Q, 2);
  insert(Q, 3);
  insert(Q, 4);
  insert(Q, 5);
  dis(Q);

  del(Q);
  del(Q);
  del(Q);
  dis(Q);

  insert(Q, 6);
  insert(Q, 7);
  insert(Q, 8);
  dis(Q);

  return 0;
}