#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

pQueue init() {
  pQueue q = (queue*)malloc(sizeof(queue));
  if (!q) exit(0);
  q->front = -1;
  q->rear = -1;
  q->size = 0;
  return q;
}

int IsFullQ(queue* q) { return (q->size == max_size); }

void AddQ(queue* q, int item) {
  if (IsFullQ(q)) {
    printf("队列已满\n");
    return;
  }
  q->rear++;
  q->rear %= max_size;
  q->size++;
  q->data[q->rear] = item;
}

int IsEmptyQ(queue* q) { return (q->size == 0); }

int DeleteQ(queue* q) {
  if (IsEmptyQ(q)) {
    printf("空队列\n");
    return 1;
  }
  q->front++;
  q->front %= max_size;  // 0 1 2 3 4 5
  q->size--;
  return q->data[q->front];
}

void PrintQueue(queue* q) {
  if (IsEmptyQ(q)) {
    printf("空队列\n");
    return;
  }
  printf("打印队列数据元素：\n");
  int index = q->front;
  int i;
  for (i = 0; i < q->size; i++) {
    index++;
    index %= max_size;
    printf("%d ", q->data[index]);
  }
  printf("\n");
}

int main(int argc, const char* argv[]) {
  queue* q = init();

  AddQ(q, 0);
  AddQ(q, 1);
  AddQ(q, 2);
  AddQ(q, 3);
  AddQ(q, 4);
  AddQ(q, 5);
  PrintQueue(q);

  DeleteQ(q);
  DeleteQ(q);
  DeleteQ(q);
  PrintQueue(q);

  AddQ(q, 6);
  AddQ(q, 7);
  AddQ(q, 8);
  PrintQueue(q);

  return 0;
}