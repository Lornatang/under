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

// 输出链表
void print(pNode L) {
  pNode p = L->next;

  printf("Display：");
  while (p != L) {
    printf("%d ", p->data);
    p = p->next;
  }
  putchar('\n');
}

// 判断链表是否为空
int isEmpty(pNode L) {
  pNode p = L->next;

  if (p == L) {
    return 1;
  } else {
    return 0;
  }
}

// 获取链表的长度
int getLength(pNode L) {
  pNode p = L->next;
  int length = 0;

  while (p != L) {
    length += 1;
    p = p->next;
  }
  return length;
}

int insert(pNode L, int pos, int data) {
  pNode p = NULL, end = NULL;
  if (pos > 0 && pos < getLength(L) + 2) {
    p = (pNode)malloc(sizeof(node));
    if (p == NULL) {
      printf("Application memory space failed！\n");
      exit(0);
    }
    while (true) {
      pos -= 1;
      if (pos == 0) break;
      L = L->next;
    }
    p->data = data;
    end = L->next;
    p->next = end;
    p->pre = L;
    L->next = p;
    end->pre = p;

    return 1;
  } else
    return 0;
}

int DeleteEleDbCcLinkList(pNode L, int pos) {
  pNode pt = NULL;
  if (pos > 0 && pos < getLength(L) + 1) {
    while (1) {
      pos--;
      if (0 == pos) break;
      L = L->next;
    }
    pt = L->next->next;
    free(L->next);
    L->next = pt;
    pt->pre = L;

    return 1;
  } else
    return 0;
}

// 这是释放内存操作，和上面讲的一样，不需要判断最后一个节点是否为空，每次释放一个节点的内存的以后它还是保持环状的结构，所以没有节点为空。
//删除整个链表，释放内存空间
void freeMemory(pNode *p) {
  pNode pt = NULL;
  while (*p != NULL) {
    pt = (*p)->next->next;

    if ((*p)->next == *p) {
      free(*p);
      *p = NULL;
    } else {
      free((*p)->next);
      (*p)->next = pt;
      pt->pre = *p;
    }
  }
}

int main() {
  int flag = 0, length = 0;
  int position = 0, value = 0;
  pNode L = NULL;

  L = init();

  flag = isEmpty(L);
  if (flag)
    printf("双向循环链表为空！\n");
  else {
    length = getLength(L);
    printf("双向循环链表的长度为：%d\n", length);
    print(L);
  }

  printf("请输入要插入节点的位置和元素值(两个数用空格隔开)：");
  scanf("%d %d", &position, &value);
  flag = insert(L, position, value);
  if (flag) {
    printf("插入节点成功！\n");
    print(L);
  } else
    printf("插入节点失败！\n");

  flag = isEmpty(L);
  if (flag)
    printf("双向循环链表为空，不能进行删除操作！\n");
  else {
    printf("请输入要删除节点的位置：");
    scanf("%d", &position);
    flag = DeleteEleDbCcLinkList(L, position);
    if (flag) {
      printf("删除节点成功！\n");
      print(L);
    } else
      printf("删除节点失败！\n");
  }

  freeMemory(&L);
  if (NULL == L)
    printf("已成功删除双向循环链表，释放内存完成！\n");
  else
    printf("删除双向循环链表失败，释放内存未完成！\n");

  return 0;

  return 0;
}
