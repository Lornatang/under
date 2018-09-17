#include "dbcycle.h"
#include <stdio.h>
#include <stdlib.h>

// 创建双向循环链表
pNode create(void) {
  int i, length = 0, data = 0;
  pNode p = NULL, end = NULL;
  pNode L = (pNode)malloc(sizeof(Node));

  if (NULL == L) {
    printf("Application memory space failed！\n");
    exit(0);
  }
  L->data = 0;
  L->next = L;
  L->pre = L;
  end = L;

  printf("请输入想要创建链表的长度：");
  scanf("%d", &length);

  for (i = 1; i < length + 1; i++) {
    p = (pNode)malloc(sizeof(Node));

    if (NULL == p) {
      printf("Application memory space failed！\n");
      exit(0);
    }

    printf("请输入第%d个节点元素值：", i);
    scanf("%d", &data);

    p->data = data;
    p->pre = end;
    p->next = L;
    end->next = p;
    L->pre = p;
    end = p;
  }
  return L;
}