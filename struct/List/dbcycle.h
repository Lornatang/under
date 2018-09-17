#ifndef DBCYCLE_H
#define DBCYCLE_H
typedef struct Node {
  int data;
  struct Node *next;  // next point
  struct Node *pre;   // beg point
} node, *pNode;

// 创建双向循环链表
pNode init(void);

// 打印链表
void print(pNode L);

// 判断链表是否为空
int isEmpty(pNode L);

// 计算链表的长度
int getLength(pNode L);

// 向链表中插入节点
int insert(pNode L, int pos, int data);

// 从链表中删除节点
int del(pNode L, int pos);

// 删除整个链表，释放内存
void freeMemory(pNode *p);

#endif  // DBCYCLE_H

#ifndef STATUS
#define STATUS
#define true 1
#define flase 0
#endif