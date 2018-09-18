#include "list.h"
#include <stdio.h>
#include <stdlib.h>

// Initializes a sequential list with a capacity of 100
sqList *init() {
  sqList *L = NULL;
  L = (sqList *)malloc(sizeof(sqList));
  if (!L) exit(0);
  L->data = 0;
  L->length = 0;
  return L;
}  // init

// insert value to node index
int insert(sqList *L, int pos, int data) {
  int i = 0;
  sqList *node;
  node = L;
  if (pos < 1 && pos > L->length + 1) exit(0);
  if (L->length >= maxSize) {
    // Increase storage space
    sqList *add;
    add = (sqList *)realloc(L, (maxSize + increase) * sizeof(sqList));
    if (!add) exit(0);
    L = add;                // 传递新地址
    L->length += increase;  // 增加存储容量
  }
  while (i < pos - 1) {
    node = node->next;
    i += 1;
  }
  sqList *p_new;
  p_new = (sqList *)malloc(sizeof(sqList));
  p_new->data = data;
  node = node->next;
  node->next = p_new;
  p_new->next = node;
  return 0;
}

int main() {
  sqList *L;
  L = init();
  insert(L, 1, 10);
  printf("Length:%d\n", L->length);
  return 0;
}