#include "linkList.h"
#include <stdio.h>
#include <stdlib.h>

linkList init() {
  node *L;
  L = (node *)malloc(sizeof(node));
  if (!L) {
    printf("Space error.\n");
    exit(0);
  }
  L->next = NULL;
  return L;
}

// List head insertion
linkList linkListCreateH() {
  node *L;
  int x = 0;
  L = (node *)malloc(sizeof(node));
  L->next = NULL;

  while (scanf("%d", &x) != EOF) {
    node *p;
    p = (node *)malloc(sizeof(node));  // Apply for new node
    p->data = x;                       // node data field assignment
    p->next = L->next;  // Insert the node into the header L-->|2|-->|1|-->NULL
    L->next = p;
  }
  return L;
}

// Insert at the end of the list
linkList insert() {
  linkList L = NULL;
  node *s, *r = NULL;
  int x;
  scanf("%d", &x); /* sets the type of data element to be int*/
  while (x != EOF) {
    s = (node *)malloc(sizeof(node));
    s->data = x;
    if (L == NULL)
      L = s; /* the processing of the first node */
    else
      r->next = s; /* processing of other nodes */
    r = s;         /*r points to the new tail node */
    scanf("%d", &x);
  }
  if (r != NULL)
    r->next = NULL; /* for non-null tables, the pointer field of the last node
                       is null pointer */
  return L;
}

linkList del(linkList L, int data) {
  node *beg, *p;
  p = L->next;
  while (p->data != data) {
    beg = p;
    p = p->next;
  }
  beg->next = p->next;
  free(p);
  return L;
}

/**
 * Let L be a single linked list without a leading node.
 * Algorithm idea: set a moving pointer p and counter j. After initialization,
 * if there are nodes behind the node indicated by p, p moves backward and the
 * counter is added 1.
 */
int getLength(linkList L) {
  node *p = L;
  int j = 0;
  if (p == NULL) return 0;
  j = 1;
  while (p->next != NULL) {
    p = p->next;
    j++;
  }
  return j;
}

/**
 * Algorithm idea: from the first element node of the list, determine whether
 * the current node's value is equal to x. If so, return the pointer of the
 * node, otherwise continue the last one, and end the table. Return empty if not
 * found.
 */
node *find(linkList L, int x) {
  node *p = L->next;
  while (p != NULL && p->data != x) {
    p = p->next;
    return p;
  }
  return p;
}

// merger list_A and list_B
void merge(linkList A, linkList B, linkList L);

int main() {
  linkList list, start;
  int i;
  int x;

  printf("请输入单链表的数据：");
  list = insert();
  for (start = list->next; start != NULL; start = start->next)
    printf("%d ", start->data);
  printf("\n");

  // printf("请输入插入数据的位置：");
  // scanf("%d", &i);
  // printf("请输入插入数据的值：");
  // scanf("%d", &x);
  // linkListCreateT();

  // for (start = list->next; start != NULL; start = start->next)
  //   printf("%d ", start->data);
  // printf("\n");

  // printf("请输入要删除的元素的值：");
  // scanf("%d", &x);
  // linkListDel(list, x);
  // for (start = list->next; start != NULL; start = start->next)
  //   printf("%d ", start->data);
  int length = getLength(list);
  printf("Length: %d", length);
  printf("\n");

  return 0;
}