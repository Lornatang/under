#ifndef LIST_H
#define LIST_H
#ifndef MAX_SIZE
#define maxSize 10
#define increase 2
#endif  // MAX_SIZE

typedef struct Sequential {
  int data;
  int length;
  struct Sequential *next;
} sqList;

// Initializes a sequential list with a capacity of 100
sqList *init();

/**
 * Insert data into a sequential linked list.
 */
int insert(sqList *L, int i, int x);

// delete node value
int del(sqList *L, int i);

/**
 * find data is exist
 */
int find(sqList *L, int x);
#endif  // LIST_H