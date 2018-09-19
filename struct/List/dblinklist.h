#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

typedef struct Node {
  int data;
  struct Node *next;
  struct Node *pre;
} node, *pNode;

// 创建双向链表
pNode init();

// 打印链表
void print(pNode L);

// 判断链表是否为空
int isEmpty(pNode L);

// 计算链表长度
int getLength(pNode L);

// 向链表插入节点
pNode insert(pNode L, int pos, int data);

// 从链表删除节点
pNode del(pNode L, int pos);

// 删除整个链表，释放内存
void freeMemory(pNode *p);

#endif

#ifndef TRUE
#define true 1
#endif

#ifndef FALSE
#define false 0
#endif