#include "list.h"
#include <stdio.h>
#include <stdlib.h>

// Initializes a sequential list with a capacity of 100
sqList *init() {
  sqList *L = NULL;
  L = (sqList *)malloc(sizeof(sqList));
  if (!L) exit(0);
  L->next = NULL;
  return L;
}  // init

// insert value to node index
sqList *insert(sqList *L, int pos, int data) {
  int i = 0;
  sqList *p;                              // insert node p
  for (i = 1; i < pos; i++) L = L->next;  // find i node

  p = (sqList *)malloc(sizeof(sqList));
  p->data = data;
  p->next = L->next;
  L->next = p;

  return L;
}

int getLength(sqList *L) {
  sqList *p;
  int length = 0;
  for (p = L->next; p != NULL; p = p->next) length += 1;

  return length;
}

sqList *delByPos(sqList *L, int data) {
  sqList *node, *pre;  // pre为前驱结点，p为查找的结点。
  node = L->next;
  while (node->data != data) {  //查找值为x的元素
    pre = node;
    node = node->next;
  }
  pre->next = node->next;  //删除操作，将其前驱next指向其后继。
  free(node);
  return L;
}

void dis(sqList *L) {
  sqList *node;
  for (node = L->next; node != NULL; node = node->next)
    printf("Data:%d\n", node->data);

  putchar('\n');
}

int main() {
  sqList *L;
  L = init();
  insert(L, 1, 1);
  insert(L, 2, 2);
  insert(L, 3, 3);
  insert(L, 4, 4);
  insert(L, 5, 5);
  insert(L, 6, 6);
  insert(L, 7, 7);
  insert(L, 8, 8);
  insert(L, 9, 9);
  insert(L, 10, 10);
  insert(L, 11, 11);
  printf("Length:%d\n", getLength(L));
  dis(L);
  delByPos(L, 11);
  printf("Length:%d\n", getLength(L));
  dis(L);
  return 0;
}