#include "list.h"
#include <stdio.h>
#include <stdlib.h>

// Initializes a sequential list with a capacity of 100
sqList *init() {
  sqList *L = NULL;
  L = (sqList *)malloc(sizeof(sqList));
  if (!L) exit(0);
  L->data = 0;
  L->length = maxSize;
  return L;
}  // init

// insert value to node index
int insert(sqList *L, int pos, int data) {
  sqList *index;
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
  node = &(L[pos - 1]);
  for (index = &(L[L->length - 1]); index > node; index--)
    *(index + 1) = *index;
  node->data = data;
  L->length += 1;
  return 0;
}

int delByPos(sqList *L, int pos) {
  sqList *node;
  sqList *index;
  // pos (i <= i < L->index+1)
  if ((pos < 1) || pos > L->length + 1) {
    return 0;
  }
  index = &(L[pos - 1]);  // get index
  
  return 0;
}

int main() {
  sqList *L;
  L = init();
  insert(L, 1, 10);
  printf("Length:%d\n", L->length);
  return 0;
}