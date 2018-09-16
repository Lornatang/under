#ifndef LINKLIST_H
#define LINKLIST_H
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} Node, *linkList;

linkList linkListInit() {
  Node *L;
  L = (Node *)malloc(sizeof(Node));
  if (L == NULL) printf("Space error.\n");
  L->next = NULL;
  return L;
}

// List head insertion
linkList linkListCreateH() {
  Node *L;
  int x = 0;
  L = (Node *)malloc(sizeof(Node));
  L->next = NULL;

  while (scanf("%d", &x) != EOF) {
    Node *p;
    p = (Node *)malloc(sizeof(Node));  // Apply for new node
    p->data = x;                       // Node data field assignment
    p->next = L->next;  // Insert the node into the header L-->|2|-->|1|-->NULL
    L->next = p;
  }
  return L;
}

// Insert at the end of the list
linkList linkListCreateT() {
  linkList L = NULL;
  Node *s, *r = NULL;
  int x;
  scanf("%d", &x); /* sets the type of data element to be int*/
  while (x != EOF) {
    s = (Node *)malloc(sizeof(Node));
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

linkList linkListDel(linkList L, int data) {
  Node *beg, *p;
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
  Node *p = L;
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
Node *find(linkList L, int x) {
  Node *p = L->next;
  while (p != NULL && p->data != x) {
    p = p->next;
    return p;
  }
  return p;
}

#endif  // LIST_H