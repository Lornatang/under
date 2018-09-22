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

void AddQ(pQueue Q, int item) {
  if (IsFull(Q)) {
    printf("队列已满\n");
    return;
  }
  Q->rear++;
  Q->rear %= max_size;
  Q->size++;
  Q->data[Q->rear] = item;
}

int IsEmptyQ(pQueue Q) { return (Q->size == 0); }

int DeleteQ(pQueue Q) {
  if (IsEmptyQ(Q)) {
    printf("空队列\n");
    return 1;
  }
  Q->front++;
  Q->front %= max_size;  // 0 1 2 3 4 5
  Q->size--;
  return Q->data[Q->front];
}

void PrintQueue(pQueue Q) {
  if (IsEmptyQ(Q)) {
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

  AddQ(Q, 0);
  AddQ(Q, 1);
  AddQ(Q, 2);
  AddQ(Q, 3);
  AddQ(Q, 4);
  AddQ(Q, 5);
  PrintQueue(Q);

  DeleteQ(Q);
  DeleteQ(Q);
  DeleteQ(Q);
  PrintQueue(Q);

  AddQ(Q, 6);
  AddQ(Q, 7);
  AddQ(Q, 8);
  PrintQueue(Q);

  return 0;
}