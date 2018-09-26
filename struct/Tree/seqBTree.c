#include "seqBTree.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int InitBiTree(SqBiTree T) {
  int i;

  for (i = 0; i < MAX_TREE_SIZE; i++) T[i] = Nil;  // 初值为空
  return 1;
}

void DestroyBiTree() {
  // 由于SqBiTree是定长类型,无法销毁
}

// 按层序次序输入二叉树中结点的值(字符型或整型), 构造顺序存储的二叉树T
int CreateBiTree(SqBiTree T) {
  int i = 0, l = 0;

  char s[MAX_TREE_SIZE];
  printf("请按层序输入结点的值(字符)，空格表示空结点，结点数≤%d:\n",
         MAX_TREE_SIZE);
  printf("例如：abcefgh\n");
  scanf("%s", s);  // 输入字符串
  // gets(s);       // this is unsafe!
  l = strlen(s);      // 求字符串的长度
  for (; i < l; i++)  // 将字符串赋值给T
  {
    T[i] = s[i];
    // 此结点(不空)无双亲且不是根,T[(i+1)/2-1] == Nil表示T[i]无双亲
    if (i != 0 && T[(i + 1) / 2 - 1] == Nil && T[i] != Nil) {
      printf("出现无双亲的非根结点%c\n", T[i]);
      exit(0);
    }
  }
  for (i = l; i < MAX_TREE_SIZE; i++)  // 将空赋值给T的后面的结点
    T[i] = Nil;
  return 0;
}

// 若T为空二叉树,则返回1,否则0
int BiTreeEmpty(SqBiTree T) {
  if (T[0] == Nil)  // 根结点为空,则树空
    return 1;
  else
    return 0;
}

//  返回T的深度
int BiTreeDepth(SqBiTree T) {
  int i, j = -1;
  for (i = MAX_TREE_SIZE - 1; i >= 0; i--)  // 找到最后一个结点
    if (T[i] != Nil) break;
  i++;  // 为了便于计算
  do
    j++;
  while (i >= pow(2, j));  // i > pow(2, depth-1) && i <= pow(2, depth)
  return j;                // j = depth;
}

// 当T不空,用e返回T的根,返回1;否则返回0,e无定义
int Root(SqBiTree T, char *e) {
  if (BiTreeEmpty(T))  // T空
    return 0;
  else {
    *e = T[0];
    return 1;
  }
}

// 返回处于位置e(层,本层序号)的结点的值
char Value(SqBiTree T, position e) {
  // 将层、本层序号转为矩阵的序号
  return T[((int)pow(2, e.level - 1) - 1) + (e.order - 1)];
  //	((int)pow(2,e.level-1) - 1)为该e.level的结点个数，
  // (e.order - 1)为本层的位置
}

// 给处于位置e(层,本层序号)的结点赋新值value
int Assign(SqBiTree T, position e, char value) {
  // 将层、本层序号转为矩阵的序号
  int i = (int)pow(2, e.level - 1) + e.order - 2;
  if (value != Nil && T[(i + 1) / 2 - 1] == Nil)  // 叶子非空值但双亲为空
    return 0;
  else if (value == Nil && (T[i * 2 + 1] != Nil || T[i * 2 + 2] != Nil))
    //  双亲空值但有叶子（不空）
    return 0;
  T[i] = value;
  return 1;
}

// 若e是T的非根结点,则返回它的双亲,否则返回＂空＂
char Parent(SqBiTree T, char e) {
  int i;
  if (T[0] == Nil)  // 空树
    return Nil;
  for (i = 1; i <= MAX_TREE_SIZE - 1; i++)
    if (T[i] == e)  // 找到e
      return T[(i + 1) / 2 - 1];
  return Nil;  // 没找到e
}

// 返回e的左孩子。若e无左孩子,则返回＂空＂
char LeftChild(SqBiTree T, char e) {
  int i;
  if (T[0] == Nil)  // 空树
    return Nil;
  for (i = 0; i <= MAX_TREE_SIZE - 1; i++)
    if (T[i] == e)  // 找到e
      return T[i * 2 + 1];
  return Nil;  // 没找到e
}

// 返回e的右孩子。若e无右孩子,则返回＂空＂
char RightChild(SqBiTree T, char e) {
  int i;
  if (T[0] == Nil)  // 空树
    return Nil;
  for (i = 0; i <= MAX_TREE_SIZE - 1; i++)
    if (T[i] == e)  // 找到e
      return T[i * 2 + 2];
  return Nil;  // 没找到e
}

// 返回e的左兄弟。若e是T的左孩子或无左兄弟,则返回＂空＂
char LeftSibling(SqBiTree T, char e) {
  int i;
  if (T[0] == Nil)  // 空树
    return Nil;
  for (i = 1; i <= MAX_TREE_SIZE - 1; i++)
    if (T[i] == e && i % 2 == 0)  // 找到e且其序号为偶数(是右孩子)
      return T[i - 1];
  return Nil;  // 没找到e
}

// 返回e的右兄弟。若e是T的右孩子或无右兄弟,则返回＂空＂
char RightSibling(SqBiTree T, char e) {
  int i;

  if (T[0] == Nil)  // 空树
    return Nil;
  for (i = 1; i <= MAX_TREE_SIZE - 1; i++)
    if (T[i] == e && i % 2)  // 找到e且其序号为奇数(是左孩子)
      return T[i + 1];
  return Nil;  // 没找到e
}

// 把从q的j结点开始的子树移为从T的i结点开始的子树
// InsertChild()用到
void Move(SqBiTree q, int j, SqBiTree T, int i) {
  if (q[2 * j + 1] != Nil)  // q的左子树不空
    Move(q, (2 * j + 1), T,
         (2 * i + 1));  // 把q的j结点的左子树移为T的i结点的左子树
  if (q[2 * j + 2] != Nil)  // q的右子树不空
    Move(q, (2 * j + 2), T,
         (2 * i + 2));  // 把q的j结点的右子树移为T的i结点的右子树
  T[i] = q[j];          // 把q的j结点移为T的i结点
  q[j] = Nil;           // 把q的j结点置空
}

// 根据LR为0或1,插入c为T中p结点的左或右子树。p结点的原有左或
// 右子树则成为c的右子树
int InsertChild(SqBiTree T, char p, int LR, SqBiTree c) {
  int j, k, i = 0;
  for (j = 0; j < (int)pow(2, BiTreeDepth(T)) - 1; j++)  // 查找p的序号
    if (T[j] == p)                                       // j为p的序号
      break;
  k = 2 * j + 1 + LR;  // k为p的左或右孩子的序号
  if (T[k] != Nil)     // p原来的左或右孩子不空
    Move(T, k, T,
         2 * k + 2);  // 把从T的k结点开始的子树移为从k结点的右子树开始的子树
  Move(c, i, T, k);  // 把从c的i结点开始的子树移为从T的k结点开始的子树
  return 1;
}

// 构造一个空队列Q
int InitQueue(SqQueue *Q) {
  (*Q).base =
      (int *)malloc(MAXQSIZE * sizeof(int));  //分配定长的空间，相当于一个数组
  if (!(*Q).base)                             // 存储分配失败
    exit(0);
  (*Q).front = (*Q).rear = 0;  //初始化下标
  return 1;
}

// 插入元素e为Q的新的队尾元素
int EnQueue(SqQueue *Q, int e) {
  if ((*Q).rear >= MAXQSIZE) {  // 队列满，增加1个存储单元
    (*Q).base = (int *)realloc((*Q).base, ((*Q).rear + 1) * sizeof(int));
    if (!(*Q).base)  // 增加单元失败
      return 0;
  }
  *((*Q).base + (*Q).rear) = e;
  (*Q).rear++;
  return 1;
}

// 若队列不空,则删除Q的队头元素,用e返回其值,并返回1,否则返回0
int DeQueue(SqQueue *Q, int *e) {
  if ((*Q).front == (*Q).rear)  // 队列空
    return 0;
  *e = (*Q).base[(*Q).front];
  (*Q).front = (*Q).front + 1;
  return 1;
}

// 根据LR为1或0,删除T中p所指结点的左或右子树
int DeleteChild(SqBiTree T, position p, int LR) {
  int i;
  int k = 1;  // 队列不空的标志
  SqQueue q;
  InitQueue(&q);  // 初始化队列，用于存放待删除的结点
  i = (int)pow(2, p.level - 1) + p.order - 2;  // 将层、本层序号转为矩阵的序号
  if (T[i] == Nil)                             // 此结点空
    return 0;
  i = i * 2 + 1 + LR;  // 待删除子树的根结点在矩阵中的序号
  while (k) {
    if (T[2 * i + 1] != Nil)   // 左结点不空
      EnQueue(&q, 2 * i + 1);  // 入队左结点的序号
    if (T[2 * i + 2] != Nil)   // 右结点不空
      EnQueue(&q, 2 * i + 2);  // 入队右结点的序号
    T[i] = Nil;                // 删除此结点
    k = DeQueue(&q, &i);       // 队列不空
  }
  return 1;
}

void PreTraverse(SqBiTree T, int e) {
  // PreOrderTraverse()调用
  VisitFunc(T[e]);              //先调用函数VisitFunc处理根
  if (T[2 * e + 1] != Nil)      // 左子树不空
    PreTraverse(T, 2 * e + 1);  //然后处理左子树
  if (T[2 * e + 2] != Nil)      // 右子树不空
    PreTraverse(T, 2 * e + 2);
}

// 先序遍历T,对每个结点调用函数Visit一次且仅一次。
int PreOrderTraverse(SqBiTree T, int (*Visit)(char)) {
  VisitFunc = Visit;
  if (!BiTreeEmpty(T))  // 树不空
    PreTraverse(T, 0);
  printf("\n");
  return 1;
}

// InOrderTraverse()调用
void InTraverse(SqBiTree T, int e) {
  if (T[2 * e + 1] != Nil)  // 左子树不空
    InTraverse(T, 2 * e + 1);
  VisitFunc(T[e]);
  if (T[2 * e + 2] != Nil)  // 右子树不空
    InTraverse(T, 2 * e + 2);
}

// 中序遍历T,对每个结点调用函数Visit一次且仅一次。
int InOrderTraverse(SqBiTree T, int (*Visit)(char)) {
  VisitFunc = Visit;
  if (!BiTreeEmpty(T))  // 树不空
    InTraverse(T, 0);
  printf("\n");
  return 1;
}

// PostOrderTraverse()调用
void PostTraverse(SqBiTree T, int e) {
  if (T[2 * e + 1] != Nil)  // 左子树不空
    PostTraverse(T, 2 * e + 1);
  if (T[2 * e + 2] != Nil)  // 右子树不空
    PostTraverse(T, 2 * e + 2);
  VisitFunc(T[e]);
}

// 后序遍历T,对每个结点调用函数Visit一次且仅一次。
int PostOrderTraverse(SqBiTree T, int (*Visit)(char)) {
  VisitFunc = Visit;
  if (!BiTreeEmpty(T))  // 树不空
    PostTraverse(T, 0);
  printf("\n");
  return 1;
}

// 层序遍历二叉树
void LevelOrderTraverse(SqBiTree T, int (*Visit)(char)) {
  int i = MAX_TREE_SIZE - 1, j;
  while (T[i] == Nil) i--;         // 找到最后一个非空结点的序号
  for (j = 0; j <= i; j++)         // 从根结点起,按层序遍历二叉树
    if (T[j] != Nil) Visit(T[j]);  // 只遍历非空的结点
  printf("\n");
}

// 逐层、按本层序号输出二叉树
void Print(SqBiTree T) {
  int j, k;
  position p;
  char e;
  for (j = 1; j <= BiTreeDepth(T); j++) {
    printf("第%d层: ", j);
    for (k = 1; k <= pow(2, j - 1); k++) {
      p.level = j;
      p.order = k;
      e = Value(T, p);
      if (e != Nil) printf("%d:%c ", k, e);
    }
    printf("\n");
  }
}

int visit(char e) {
  printf("%c ", e);
  return 0;
}

int main() {
  int i, j;
  position p;
  char e;
  SqBiTree T, s;
  InitBiTree(T);
  CreateBiTree(T);
  printf("建立二叉树后,树空否？%d(1:是 0:否) 树的深度=%d\n", BiTreeEmpty(T),
         BiTreeDepth(T));
  i = Root(T, &e);
  if (i)
    printf("二叉树的根为：%c\n", e);
  else
    printf("树空，无根\n");
  printf("层序遍历二叉树:\n");
  LevelOrderTraverse(T, visit);
  printf("中序遍历二叉树:\n");
  InOrderTraverse(T, visit);
  printf("后序遍历二叉树:\n");
  PostOrderTraverse(T, visit);
  printf("请输入待修改结点的层号 本层序号: ");
  scanf("%d%d%*c", &p.level, &p.order);
  e = Value(T, p);
  printf("待修改结点的原值为%c请输入新值: ", e);
  scanf("%c%*c", &e);
  Assign(T, p, e);
  printf("先序遍历二叉树:\n");
  PreOrderTraverse(T, visit);
  printf("结点%c的双亲为%c,左右孩子分别为", e, Parent(T, e));
  printf("%c,%c,左右兄弟分别为", LeftChild(T, e), RightChild(T, e));
  printf("%c,%c\n", LeftSibling(T, e), RightSibling(T, e));
  InitBiTree(s);
  printf("建立右子树为空的树s:\n");
  CreateBiTree(s);
  printf("树s插到树T中,请输入树T中树s的双亲结点 s为左(0)或右(1)子树: ");
  scanf("%c%d%*c", &e, &j);
  InsertChild(T, e, j, s);
  Print(T);
  printf("删除子树,请输入待删除子树根结点的层号 本层序号 左(0)或右(1)子树: ");
  scanf("%d%d%d%*c", &p.level, &p.order, &j);
  DeleteChild(T, p, j);
  Print(T);
  InitBiTree(T);
  printf("清除二叉树后,树空否？%d(1:是 0:否) 树的深度=%d\n", BiTreeEmpty(T),
         BiTreeDepth(T));
  i = Root(T, &e);
  if (i)
    printf("二叉树的根为：%c\n", e);
  else
    printf("树空，无根\n");
  return 0;
}