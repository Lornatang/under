#include "list.h"
#include <stdio.h>
#include <stdlib.h>

// Initializes a sequential list with a capacity of 100
sqList *init() {
  sqList *L = NULL;
  L = (sqList *)malloc(sizeof(sqList));
  if (!L) exit(0);
  L->next = NULL;
  L->data = 0;
  return L;
}  // init

// insert next to node index
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
  pre->next = node->next;  //删除操作，将其前驱pre指向其后继next。
  free(node);
  return L;
}

void dis(sqList *L) {
  sqList *node;
  for (node = L->next; node != NULL; node = node->next)
    printf("Data:%d\n", node->data);

  putchar('\n');
}

int find(sqList *L, int data) {
  sqList *node;
  for (node = L->next; node != NULL; node = node->next)
    if (node->data == data) {
      printf("Find.\n");
      return 0;
    }
  printf("Not find.\n");
  return 0;
}

// Merge list
sqList *merge(sqList *A, sqList *B) {
  // if (!A) {
  //   return B;
  // }
  // if (!B) {
  //   return A;
  // }
  // sqList *L = NULL;
  // if (A->next < B->next) {
  //   L = A;
  //   L->next = merge(A->next, B);
  // } else {
  //   L = B;
  //   L->next = merge(A, B->next);
  // }
  // return L;
  if (!A) {
    return B;
  }
  if (!B) {
    return A;
  }
  sqList *L;
  if (A->next < B->next) {
    L = A;
    L->next = merge(A->next, B);
  } else {
    L = B;
    L->next = merge(A, B->next);
  }

  return L;
}

int main() {
  sqList *L;
  sqList *B;
  sqList *C;
  L = init();
  B = init();
  C = init();
  insert(L, 1, 1);
  insert(L, 2, 2);
  insert(L, 3, 3);
  insert(L, 4, 4);
  insert(L, 5, 5);
  insert(B, 1, 6);
  insert(B, 2, 7);
  insert(B, 3, 8);
  insert(B, 4, 9);
  insert(B, 5, 10);
  printf("L Length:%d\n", getLength(L));
  dis(L);
  dis(B);
  // find(L, 8);
  C = merge(L, B);
  dis(C);
  printf("C Length:%d\n", getLength(C));
  free(L);
  return 0;
}