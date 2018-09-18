#ifndef LIST_H
#define LIST_H
#define MAX_SIZE 100

typedef struct Sequential {
  int length;
  struct Sequential *next;
} seqList;

// Initializes a sequential list with a capacity of 100
seqList *initList();

/**
 * Insert data into a sequential linked list.
 */
int insertList(seqList *L, int i, int x);

int delList(seqList *L, int i);

/**
 * find data is exist
 */
int find(seqList *L, int x);
#endif  // LIST_H