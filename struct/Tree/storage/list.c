#include "list.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void InitTree(Tree *tree, char ref) {
  tree->root = NULL;
  tree->refValue = ref;
}

void CreateTree(Tree *tree, TreeNode *&t, char *&str) {
  if (*str == tree->refValue)
    t = NULL;
  else {
    t = (TreeNode *)malloc(sizeof(TreeNode));
    assert(t != NULL);
    t->data = *str;
    CreateTree(tree, t->firstChild, ++str);
    CreateTree(tree, t->nextSibling, ++str);
  }
}

TreeNode *Root(Tree *tree) { return tree->root; }

TreeNode *FirstChild(TreeNode *t) {
  if (t == NULL) return NULL;
  return t->firstChild;
}
TreeNode *NextSibling(TreeNode *t) {
  if (t == NULL) return NULL;
  return t->nextSibling;
}

TreeNode *Find(TreeNode *t, char key) {
  if (t == NULL) return NULL;
  if (t->data == key) return t;

  TreeNode *p;
  p = Find(t->firstChild, key);
  if (p != NULL) return p;
  return Find(t->nextSibling, key);
}

TreeNode *Parent(TreeNode *t, TreeNode *p) {
  if (t == NULL || p == NULL || t == p) return NULL;

  TreeNode *q = t->firstChild;
  TreeNode *parent;
  while (q != NULL && q != p) {
    parent = Parent(q, p);
    if (parent != NULL) return parent;
    q = q->nextSibling;
  }

  if (q != NULL && q == p) return t;
  return NULL;
}

int main() {
  char *str = "RAD#E##B#CFG#H#K#####";
  Tree mytree;
  InitTree(&mytree, '#');
  CreateTree(&mytree, str);

  TreeNode *p = Find(&mytree, 'K');
  TreeNode *parent = Parent(&mytree, p);
  printf("%c\n", parent->data);

  return 0;
}