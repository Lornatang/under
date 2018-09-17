#include "dbLinkList.h"
#include <stdio.h>
#include <stdlib.h>

//创建双向链表
pNode init(void) {
  int i, length = 0, data = 0;
  pNode pTail = NULL, p_new = NULL;
  pNode L = (pNode)malloc(sizeof(node));

  if (NULL == L) {
    printf("内存分配失败！\n");
    exit(EXIT_FAILURE);
  }

  L->data = 0;
  L->pre = NULL;
  L->next = NULL;
  pTail = L;

  printf("请输入想要创建链表的长度：");
  scanf("%d", &length);

  for (i = 1; i < length + 1; i++) {
    p_new = (pNode)malloc(sizeof(node));

    if (NULL == p_new) {
      printf("内存分配失败！\n");
      exit(EXIT_FAILURE);
    }

    printf("请输入第%d个元素的值：", i);
    scanf("%d", &data);

    p_new->data = data;
    p_new->next = NULL;
    p_new->pre = pTail;
    pTail->next = p_new;
    pTail = p_new;
  }

  return L;
}

// 这部分是获得双向链表的信息，这里和单向链表基本一致，因为遍历的时候只用到了一个指针。
//打印链表
void print(pNode L) {
  pNode pt = L->next;

  printf("打印链表如：");
  while (pt != NULL) {
    printf("%d ", pt->data);
    pt = pt->next;
  }
  putchar('\n');
}

//判断链表是否为空
int IsEmptyDbLinkList(pNode L) {
  pNode pt = L->next;

  if (pt == NULL)
    return 1;
  else
    return 0;
}

//计算链表的长度
int getLength(pNode L) {
  int length = 0;
  pNode pt = L->next;

  while (pt != NULL) {
    length++;
    pt = pt->next;
  }
  return length;
}

//向双向链表中插入节点
int insert(pNode L, int pos, int data) {
  pNode pt = NULL, p_new = NULL;

  if (pos > 0 && pos < getLength(L) + 2) {
    p_new = (pNode)malloc(sizeof(node));

    if (NULL == p_new) {
      printf("内存分配失败！\n");
      exit(EXIT_FAILURE);
    }

    while (1) {
      pos--;
      if (0 == pos) break;
      L = L->next;
    }

    pt = L->next;
    p_new->data = data;
    p_new->next = pt;
    if (NULL != pt) pt->pre = p_new;
    p_new->pre = L;
    L->next = p_new;

    return 1;
  } else
    return 0;
}

// 这部分是从链表中删除节点，当然这里和单向链表差不多，要注意的地方和插入节点时是一样的，上面已经说明了。
// 从链表中删除节点
int DeleteEleDbLinkList(pNode L, int pos) {
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
    if (NULL != pt) pt->pre = L;

    return 1;
  } else
    return 0;
}

// 这部分是用来释放内存的，注意的地方和上面一样。
//删除整个链表，释放内存
void FreeMemory(pNode *ppHead) {
  pNode pt = NULL;

  while (*ppHead != NULL) {
    pt = (*ppHead)->next;
    free(*ppHead);
    if (NULL != pt) pt->pre = NULL;
    *ppHead = pt;
  }
}

int main() {
  int flag = 0, length = 0;
  int position = 0, value = 0;
  pNode head = NULL;

  head = init();

  flag = IsEmptyDbLinkList(head);
  if (flag)
    printf("双向链表为空！\n");
  else {
    length = getLength(head);
    printf("双向链表的长度为：%d\n", length);
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

  flag = IsEmptyDbLinkList(head);
  if (flag)
    printf("双向链表为空，不能进行删除操作！\n");
  else {
    printf("请输入要删除节点的位置：");
    scanf("%d", &position);
    flag = DeleteEleDbLinkList(head, position);
    if (flag) {
      printf("删除节点成功！\n");
      print(head);
    } else
      printf("删除节点失败！\n");
  }

  FreeMemory(&head);
  if (NULL == head)
    printf("已成功删除双向链表，释放内存完成！\n");
  else
    printf("删除双向链表失败，释放内存未完成！\n");

  return 0;
}
