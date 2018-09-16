#ifndef LIST_H
#define LIST_H
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct Sequential {
  int data[MAX_SIZE];
  int last;
} seqList;

// Initializes a sequential list with a capacity of 100
seqList *initList() {
  seqList *L;
  L = (seqList *)malloc(sizeof(seqList));
  L->last = -1;  // The index that the pointer points to is -1
  return L;
}

/**
 * Insert data into a sequential linked list.
 */
int insertList(seqList *L, int i, int x) {
  if (L->last == MAX_SIZE - 1) {
    printf("The space is insufficient.\n");
    return -1;
  }
  if (i < 1 || i > L->last + 2) {
    printf("Index error.\n");
    return 0;
  }
  for (int j = L->last; j > i - 1; j--) {
    L->data[j + 1] = L->data[j];
    L->data[i - 1] = x;  // insert data
    L->last++;           // get last element index
    return 0;
  }
  return 0;
}

int delList(seqList *L, int i) {
  int j = 0;
  // Check the legality of empty table and delete position
  if (i < 1 || i > L->last + 1) {
    printf("data is not exist!.\n");
    return 0;
  }
  for (j = i; j <= L->last; j++) {
    L->data[j - 1] = L->data[j];  // Move to the previous digit
  }
  L->last--;
  return 0;  // Del success
}

/**
 * find data is exist
 */
int find(seqList *L, int x) {
  int i = 0;
  while (i <= L->last && L->data[i] != x) {
    i++;
  }
  if (i > L->last)
    return -1;
  else
    return i;
  return 0;
}
#endif  // LIST_H