#include "dbcycle.h"
#include <stdio.h>
#include <stdlib.h>

// 创建双向循环链表
pNode init(void) {
  int i, length = 0, data = 0;
  pNode p = NULL, end = NULL;
  pNode L = (pNode)malloc(sizeof(node));

  if (NULL == L) {
    printf("Application memory space failed！\n");
    exit(0);
  }
  L->data = 0;
  L->next = L;
  L->pre = L;
  end = L;

  printf("Length?：");
  scanf("%d", &length);

  for (i = 1; i < length + 1; i++) {
    p = (pNode)malloc(sizeof(node));

    if (NULL == p) {
      printf("Application memory space failed！\n");
      exit(0);
    }

    printf("Please input %d node value：", i);
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

void print(pNode L) {
  pNode p = L->next;

  printf("Display：");
  while (p != L) {
    printf("%d ", p->data);
    p = p->next;
  }
  putchar('\n');
}

int main(int argc, char const *argv[]) {
  pNode L;
  L = init();
  print(L);
  return 0;
}
