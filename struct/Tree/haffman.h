#ifndef HAFFMAN_H
#define HAFFMAN_H

#define MAX_NUM 100

typedef struct {
  int weight;                  // 权值
  int parent, lchild, rchild;  // 父节点，孩子结点的权值
} hNode, *hTree;

int s1, s2;  // 最小的两个结点
#endif       // HAFFMAN_H