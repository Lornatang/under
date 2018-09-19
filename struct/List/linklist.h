#ifndef LINKLIST_H
#define LINKLIST_H
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} node, *linkList;

linkList init();

// List head insertion
linkList linkListCreateH();

// Insert at the end of the list
linkList insert();

linkList del(linkList L, int data);

/**
 * Let L be a single linked list without a leading node.
 * Algorithm idea: set a moving pointer p and counter j. After initialization,
 * if there are nodes behind the node indicated by p, p moves backward and the
 * counter is added 1.
 */
int getLength(linkList L);

/**
 * Algorithm idea: from the first element node of the list, determine whether
 * the current node's value is equal to x. If so, return the pointer of the
 * node, otherwise continue the last one, and end the table. Return empty if not
 * found.
 */
node *find(linkList L, int x);

// merger list_A and list_B
void merge(linkList A, linkList B, linkList L);

#endif  // LIST_H