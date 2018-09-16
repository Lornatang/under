#include "cycle.h"

pNode init() {
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
  if (pos > 0 && pos < getLength(L) + 2) {
    p = (pNode)malloc(sizeof(Node));

    if (p == NULL) {
      printf("space error!.\n");
      exit(0);
    }

    while (true) {
      pos -= 1;
      if (pos == 0) break;
      L = L->next;
    }
    p->data = data;
    p->next = L->next;
    L->next = p;
    return 1;
  } else
    return 0;
}

//从链表中删除节点
int del(pNode L, int pos) {
  pNode p = NULL;

  if (pos > 0 && pos < getLength(L) + 1) {
    while (true) {
      pos -= 1;
      if (pos == 0) break;
      L = L->next;
    }
    p = L->next->next;
    free(L->next);
    L->next = p;
    return 1;
  } else
    return 0;
}

//删除整个链表，释放内存
void freeMemory(pNode *p) {
  pNode head = NULL;
  while (*p != NULL) {
    if (*p == (*p)->next) {
      free(*p);
      *p = NULL;
    } else {
      head = (*p)->next->next;
      free((*p)->next);
      (*p)->next = head;
    }
  }
}

int main(void) {
  int flag = 0, length = 0;
  int position = 0, value = 0;
  pNode head = NULL;

  head = init();

  flag = isEmpty(head);
  if (flag)
    printf("单向循环链表为空！\n");
  else {
    length = getLength(head);
    printf("单向循环链表的长度为：%d\n", length);
    print(head);
  }

  printf("请输入要插入节点的位置和元素值(两个数用空格隔开)：");
  scanf("%d %d", &position, &value);
  flag = insert(head, position, value);
  if (flag) {
    printf("插入节点成功！\n");
    print(head);
  } else
    printf("插入节点失败！\n");

  flag = isEmpty(head);
  if (flag)
    printf("单向循环链表为空，不能进行删除操作！\n");
  else {
    printf("请输入要删除节点的位置：");
    scanf("%d", &position);
    flag = del(head, position);
    if (flag) {
      printf("删除节点成功！\n");
      print(head);
    } else
      printf("删除节点失败！\n");
  }

  freeMemory(&head);
  if (NULL == head)
    printf("已成功删除单向循环链表，释放内存完成！\n");
  else
    printf("删除单向循环链表失败，释放内存未完成！\n");

  return 0;
}