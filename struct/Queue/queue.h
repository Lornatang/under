#ifndef QUEUE_H
#define QUEUE_H

#ifndef MAXSIZE
#define max_size 6  // 存储数据元素的最大个数
#define increase 2  // 超过元素最大个数后每次多增加两个元素空间
#endif              // MAXSIZE

typedef struct {
  int data[max_size];
  int front;  // 记录队列头元素位置
  int rear;   // 记录队列尾元素位置
  int size;   // 存储数据queue
} queue, *pQueue;

// init queue
pQueue init();

// check Q is full
int isFull(pQueue Q);

// insert node to Q
void insert(pQueue Q, int data);

// check Q is empty
int isEmpty(pQueue Q);

// delete node for Q
int del(pQueue Q);

// print Q value
void dis(pQueue Q);

#endif  // QUEUE_H