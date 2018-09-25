#ifndef TREE_H
#define TREE_H

#define MAXQSIZE 5  // 最大队列长度(对于循环队列，最大队列长度要减1)
#define MAX_TREE_SIZE 100              // 二叉树的最大结点数
typedef char SqBiTree[MAX_TREE_SIZE];  // 0号单元存储根结点

char Nil = ' ';  // 设空为字符型的空格符

typedef struct {
  int level;  //结点的层
  int order;  //本层序号(按满二叉树计算)
} position;

typedef struct {
  int *base;  // 初始化的动态分配存储空间 相当于一个数组
  int front;  // 头指针,若队列不空,指向队列头元素，相当于一个数组下标
  int rear;  // 尾指针,若队列不空,指向队列尾元素的下一个位置
             // 相当于一个数组下标
} SqQueue;

// 构造空二叉树T。因为T是固定数组，不会改变，故不需要&
int InitBiTree(SqBiTree T);

void DestroyBiTree();

// 按层序次序输入二叉树中结点的值(字符型或整型), 构造顺序存储的二叉树T
int CreateBiTree(SqBiTree T);

// 若T为空二叉树,则返回1,否则0
int BiTreeEmpty(SqBiTree T);
//  返回T的深度
int BiTreeDepth(SqBiTree T);

// 当T不空,用e返回T的根,返回1;否则返回0,e无定义
int Root(SqBiTree T, char *e);

// 返回处于位置e(层,本层序号)的结点的值
char Value(SqBiTree T, position e);

// 给处于位置e(层,本层序号)的结点赋新值value
int Assign(SqBiTree T, position e, char value);

// 若e是T的非根结点,则返回它的双亲,否则返回＂空＂
char Parent(SqBiTree T, char e);

// 返回e的左孩子。若e无左孩子,则返回＂空＂
char LeftChild(SqBiTree T, char e);

// 返回e的右孩子。若e无右孩子,则返回＂空＂
char RightChild(SqBiTree T, char e);

// 返回e的左兄弟。若e是T的左孩子或无左兄弟,则返回＂空＂
char LeftSibling(SqBiTree T, char e);

// 返回e的右兄弟。若e是T的右孩子或无右兄弟,则返回＂空＂
char RightSibling(SqBiTree T, char e);

// 把从q的j结点开始的子树移为从T的i结点开始的子树
// InsertChild()用到
void Move(SqBiTree q, int j, SqBiTree T, int i);
// 根据LR为0或1,插入c为T中p结点的左或右子树。p结点的原有左或
// 右子树则成为c的右子树
int InsertChild(SqBiTree T, char p, int LR, SqBiTree c);

// 构造一个空队列Q
int InitQueue(SqQueue *Q);

// 插入元素e为Q的新的队尾元素
int EnQueue(SqQueue *Q, int e);

// 若队列不空,则删除Q的队头元素,用e返回其值,并返回1,否则返回0
int DeQueue(SqQueue *Q, int *e);

// 根据LR为1或0,删除T中p所指结点的左或右子树
int DeleteChild(SqBiTree T, position p, int LR);

int (*VisitFunc)(char);  // 函数变量

void PreTraverse(SqBiTree T, int e);

// 先序遍历T,对每个结点调用函数Visit一次且仅一次。
int PreOrderTraverse(SqBiTree T, int (*Visit)(char));

// InOrderTraverse()调用
void InTraverse(SqBiTree T, int e);

// 中序遍历T,对每个结点调用函数Visit一次且仅一次。
int InOrderTraverse(SqBiTree T, int (*Visit)(char));

// PostOrderTraverse()调用
void PostTraverse(SqBiTree T, int e);

// 后序遍历T,对每个结点调用函数Visit一次且仅一次。
int PostOrderTraverse(SqBiTree T, int (*Visit)(char));

// 层序遍历二叉树
void LevelOrderTraverse(SqBiTree T, int (*Visit)(char));

// 逐层、按本层序号输出二叉树
void Print(SqBiTree T);

int visit(char e);

#endif  // TREE_H