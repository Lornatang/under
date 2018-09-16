#include "cycle.h"

pNode create() {
  int i, length = 0, data = 0;
  pNode L = NULL;
  pNode end = NULL;

  L = (pNode)malloc(sizeof(Node));

  if (L == NULL) {
    printf("space error!.\n");
    exit(0);
  }
  L->data = 0;
  L->next = L;
  end = L;

  printf("Length: ");
  scanf("%d", &length);

  for (i = 1; i < length; i++) {
    pNode p = (pNode)malloc(sizeof(Node));

    if (p == NULL) {
      printf("space error!.\n");
      exit(0);
    }
    p->data = data;
    p->next = L;
    end->next = p;
    end = p;
  }
  return L;
}

//打印链表
void print(pNode L) {
  pNode p = L->next;
  printf("===========Data==========.\n");
  if (p != NULL) {
    printf("%d", p->data);
    p = p->next;
  }
  putchar('\n');
}

//判断链表是否为空
int isEmpty(pNode L) {
  if (L->next == L) {
    printf("is NULL.\n");
    return -1;
  } else {
    printf("not NULL.\n");
    return 0;
  }
}

//计算链表的长度
int getLength(pNode L) {
  int length = 0;
  pNode p = L->next;
  while (p != L) {
    length += 1;
    p = p->next;
  }
  return length;
}

//向链表中插入节点
int insert(pNode L, int pos, int data) {
  pNode p = NULL;
  bool flag = true;
  if (pos > 0 || pos < getLength(L) + 2) {
    p = (pNode)malloc(sizeof(Node));

    if (p == NULL) {
      printf("space error!.\n");
      exit(0);
    }

    while (flag) {
      pos -= 1;
      if (pos == 0) 
        break;
      L = L->next;
    }
    p->data = data;
    p->next = L->next;
    L->next = p;
    return 0;
  }
  else
    flag = false;
  
  return 0;
}

//从链表中删除节点
int del(pNode L, int pos);

//删除整个链表，释放内存
void freeMemory(pNode *p);