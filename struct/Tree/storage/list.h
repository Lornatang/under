#ifndef LIST_H
#define LIST_H

typedef struct TreeNode {
  char data;
  struct TreeNode *firstChild;
  struct TreeNode *nextSibling;
} TreeNode;
typedef struct Tree {
  TreeNode *root;
  char refValue;
} Tree;

void InitTree(Tree *tree, char ref);
void CreateTree(Tree *tree, char *str);
void CreateTree(Tree *tree, TreeNode *&t, char *&str);
TreeNode *Root(Tree *tree);
TreeNode *FirstChild(Tree *tree);
TreeNode *FirstChild(TreeNode *t);
TreeNode *NextSibling(Tree *tree);
TreeNode *NextSibling(TreeNode *t);
TreeNode *Find(Tree *tree, char key);
TreeNode *Find(TreeNode *t, char key);
TreeNode *Parent(Tree *tree, TreeNode *p);
TreeNode *Parent(TreeNode *t, TreeNode *p);

#endif  // LIST_H