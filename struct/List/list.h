#ifndef LIST_H
#define LIST_H
#ifndef MAX_SIZE
#define maxSize 10
#define increase 2
#endif  // MAX_SIZE

typedef struct Sequential {
  int data;
  struct Sequential *next;
} sqList;

// Initializes a sequential list with a capacity of 100
sqList *init();

/**
 * Insert data into a sequential linked list.
 */
sqList *insert(sqList *L, int i, int x);

// delete node value
sqList *del(sqList *L, int i);

/**
 * find data is exist
 */
int find(sqList *L, int x);

// get List length
int getLength(sqList *L);

#endif  // LIST_H