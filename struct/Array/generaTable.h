#ifndef GENERATABLE_H
#define GENERATABLE_H

typedef struct Node {
  int tag;  //标志域
  union {
    char data;             //值域
    struct Node* sublist;  //子表的表头指针域
  };
  struct Node* next;  //指向后继结点的指针域
} gNode;

// 1、建立广义表
void CreateGList_char(gNode** GL);

// 2、打印输出广义表
void PrintfGList_char(gNode* GL);

// 3、求广义表的长度
int LenthGList(gNode* GL);

// 4、求广义表的深度
int DepthGList(gNode* GL);

#endif  // GENERATABLE_H