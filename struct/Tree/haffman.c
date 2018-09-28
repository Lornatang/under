#include "haffman.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char **HuffmanCode;  //二维字符数组

//选出无父结点，并且权值最小的两个结点，赋值给s1，s2
void Select(hTree &HT, int x) {
  int i, min1 = 9999, min2 = 9999;
  for (i = 1; i <= x; i++) {  //找最小
  if (HT[i].weight)
    if (HT[i].weight < min1 && HT[i].parent == 0) {
      min1 = HT[i].weight;
      s1 = i;
    }
  }
  for (i = 1; i <= x; i++) {  //找次小
    if (HT[i].weight < min2 && i != s1 && HT[i].parent == 0) {
      min2 = HT[i].weight;
      s2 = i;
    }
  }
}

//根据输入的结点的权值和个数来构建赫夫曼树
void HuffmanCoding(hTree &HT, HuffmanCode &HC, int *w, int n) {
  if (n <= 1) return;
  int m = 2 * n - 1;  // n个叶子，有2*n-1个结点
  int i;
  HT = (hTree)malloc((m + 1) * sizeof(hNode));  // 0号单元未用
  hTree p;
  for (p = HT + 1, i = 1; i <= n; i++, p++, w++) {  //叶子结点赋值
    p->weight = *w;
    p->parent = 0;
    p->lchild = 0;
    p->rchild = 0;
  }
  for (; i <= m; i++, p++) {  //非叶子结点初始化
    p->weight = 0;
    p->parent = 0;
    p->lchild = 0;
    p->rchild = 0;
  }
  for (i = n + 1; i <= m; i++) {
    Select(HT, i - 1);  //选出最小的两个无父节点的结点
    HT[s1].parent = i;
    HT[s2].parent = i;
    HT[i].lchild = s1;
    HT[i].rchild = s2;
    HT[i].weight = HT[s1].weight + HT[s2].weight;
  }
  //----------下面是将每个结点的赫夫曼编码存入二维字符数组
  /*申请一段以HC为首地址的内存，可以看成二维字符数组
    这里先申请了第一维*/
  HC = (HuffmanCode)malloc((n + 1) * sizeof(char *));
  char *cd = (char *)malloc(n * sizeof(char));  //申请一段临时工作空间
  cd[n - 1] = '\0';                             //编码结束符
  for (i = 1; i <= n; i++) {
    int start = n - 1, c, f;
    for (c = i, f = HT[i].parent; f != 0;
         c = f, f = HT[f].parent) {  //从叶子到根逆向求编码
      if (HT[f].lchild == c)
        cd[--start] = '0';  //如果当前结点是父节点的左孩子，则存一个1
      else
        cd[--start] = '1';  //反之
    }
    HC[i] = (char *)malloc((n - start) * sizeof(char));  //申请第二维
    strcpy(HC[i], &cd[start]);  //将编码从工作空间存入赫夫曼编码表中
  }
  free(cd);  //释放临时空间
}
int main() {
  hTree HT;
  HuffmanCode HC;
  int w[MAX_NUM], n;
  printf("输入结点的个数:\n");
  scanf("%d", &n);
  printf("输入每个结点的权值:\n");
  for (int i = 0; i < n; i++) scanf("%d", &w[i]);
  HuffmanCoding(HT, HC, w, n);
  for (int i = 1; i <= n; i++)
    printf("%d的赫夫曼编码为：%s\n", HT[i].weight, HC[i]);
  return 0;
}