#include "generaTable.h"
#include <stdio.h>
#include <stdlib.h>

// 1、建立广义表
//假定广义表的元素类型ElemType为字符类型char，每个单元素的值被限定为英文字母，
//输入格式为： (a,(#),b,(d,(e)));
//整个表最后以分号作为结束符，#表示空表
//建立广义表需要进行子表递归和后继表递归
void CreateGList_char(gNode** GL) {
  char ch;
  scanf("%c", &ch);
  if (ch == '#')  //若输入为空格，则置表头指针为空
    *GL = NULL;
  else if (ch == '(')  //若输入为左括号则建立由*GL所指向的子表结点并递归构造子表
  {
    *GL = (gNode*)malloc(sizeof(gNode));
    (*GL)->tag = 1;
    CreateGList_char(&((*GL)->sublist));  //递归
  } else {  //若输入为字符则建立由*GL所指向的单元素结点
    *GL = (gNode*)malloc(sizeof(gNode));
    (*GL)->tag = 0;
    (*GL)->data = ch;
  }
  scanf("%c", &ch);  //此处读入的字符必为逗号、括号或分号
  if (*GL == NULL)
    ;                  //若*GL为空，什么都不做
  else if (ch == ',')  //若输入为逗号则递归构造后续表
    CreateGList_char(&((*GL)->next));  //递归
  else if (ch == ')' ||
           ch == ';')  //若输入为右括号或分号则置*GL的后继指针域为空
    (*GL)->next = NULL;
}

// 2、打印输出广义表
//打印输出上面的广义表同样需要递归子表和递归后继表
void PrintfGList_char(gNode* GL) {
  if (GL->tag == 1) {  //表结点的处理情况
    printf("%c", '(');        //先输出左括号，作为开始符号
    if (GL->sublist == NULL)  //若子表为空
      printf("%c", '#');
    else
      PrintfGList_char(GL->sublist);  //递归
    printf("%c", ')');  //当一个子表输出结束后，输出一个右括号终止符
  } else                //单元素结点的处理情况
    printf("%c", GL->data);
  if (GL->next != NULL)  //若结点还有后继表，则递归输出
  {
    printf("%c", ',');           //先输出逗号分隔符
    PrintfGList_char(GL->next);  //递归
  }
}

// 3、求广义表的长度
//广义表中，同一层次的每个结点是通过next域链接起来的，所以可把它看做是由next域链接起来的单链表。
//这样求广义表的长度就是求单链表的长度
//如单链表非空，其长度等于1加其后继单链表的长度，若单链表为空，则长度为0，这是递归的终止条件
int LenthGList(gNode* GL) {
  if (GL != NULL)
    return 1 + LenthGList(GL->next);
  else
    return 0;
}

// 4、求广义表的深度
//广义表深度的递归定义是它等于所有子表中的最大深度加1，若一个表为空或仅由单元素组成，则深度为1
int DepthGList(gNode* GL) {
  int max = 0;  //所有子表中最大深度，初始值为0
  while (GL != NULL) {
    if (GL->tag == 1) {
      int dep = DepthGList(
          GL->sublist);  //递归调用求出一个子表的深度，用dep表示任一子表的深度
      if (dep > max) max = dep;  //让max始终为同一层所求过的子表中深度的最大值
    }
    GL = GL->next;  //使GL指向同一层的下一个结点
  }
  return max + 1;  //返回表的深度
}

//主函数
int main() {
  gNode* gl;
  printf("输入一个广义表，输入格式为： (a,(#),b,(d,(e))); \n");
  CreateGList_char(&gl);
  printf("输出广义表：\n");
  PrintfGList_char(gl);
  printf("\n");
  printf("广义表的长度为：");
  printf("%d\n", LenthGList(gl->sublist));
  printf("广义表的深度为：");
  printf("%d\n", DepthGList(gl->sublist));
}