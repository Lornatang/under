#include "bank.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initqueue(linkqueue &q) {
  q.front = q.rear = (person)malloc(sizeof(pnode));
  if (!q.front || !q.rear) exit(0);
  q.front->next = NULL;
  q.length = 0;
}

void enterqueue(linkqueue &q, int number, int time) {
  person p;
  p = (person)malloc(sizeof(person));
  if (!p) exit(0);
  q.length++;
  p->number = number;
  p->cometime = time;
  p->next = NULL;
  q.rear->next = p;
  q.rear = p;
}

void popqueue(linkqueue &q) {
  person p;
  if (q.front == q.rear) {
    return;
  }
  p = q.front->next;
  q.front->next = p->next;
  q.length--;
  if (q.rear == p) {
    q.front = q.rear;
  }
}

int getmin(linkqueue q[]) {
  int temp = q[1].length;
  int j = 1;
  for (int i = 2; i <= 4; i++) {
    if (q[i].length < temp) {
      temp = q[i].length;
      j = i;
    }
  }
  return j;
}

int getmax(linkqueue q[]) {
  int temp = q[1].length;
  int j = 1;
  for (int i = 2; i <= 4; i++) {
    if (q[i].length > temp) {
      temp = q[i].length;
      j = i;
    }
  }
  return j;
}

void Customer_Come() {
  printf("客户选队并排队\n\n");
  printf("输入客户编号:");
  scanf("%d", &number);
  printf("输入当前时间:");
  scanf("%d", &time);
  printf("\n");

  printf("%d号顾客来到%d号窗口\n", number, getmin(q));
  enterqueue(q[getmin(q)], number, time);
}
void Customer_Leave() {
  printf("客户离队:\n\n");
  printf("输入要离队的客户编号: ");
  scanf("%d", &number);
  printf("输入当前时间:  ");
  scanf("%d", &time);

  for (int i = 1; i <= 4; i++) {
    if (q[i].front->next->number == number) {
      sum += time - q[i].front->next->cometime;
      printf("%d号客户办理完成业务从%d号窗口离开\n", number, i);
      popqueue(q[i]);
      flag = 0;
    }
  }
  if (flag) printf("编号错误请重新输入\n");
}

void Adjust_Queue(linkqueue q[]) {
  int m = getmin(q);
  int n = getmax(q);
  person x, y;
  x = (person)malloc(sizeof(pnode));
  y = (person)malloc(sizeof(pnode));
  x = q[n].rear;
  enterqueue(q[m], x->number, x->cometime);
  y = q[n].front;
  while (y->next != q[n].rear) y->next = y->next->next;
  q[n].rear = y;
  free(y->next);
  q[n].length--;
  q[m].length++;
}

void Close_Door() {
  printf("下班时间到，工作结束。\n");
  printf("今天共接待了%d位客户\n", cnt);
  printf("每位客户平均逗留时间为%.2f\n", (float)sum / cnt);
}

void welcome() {
  printf("    **************************   *************************\n");
  printf("    *   模拟银行排队系统  *   *  请输入号码选择功能 *\n");
  printf("    **************************   *************************\n");
  printf("     当前一号队列人数：%3d                 \n", q[1].length);
  printf("                     1  客户选队并排队  \n");
  printf("     当前二号队列人数：%3d                 \n", q[2].length);
  printf("                     2   客户离队    \n");
  printf("     当前三号队列人数：%3d                 \n", q[3].length);
  printf("                     3   退出系统    \n");
  printf("     当前四号队列人数：%3d                 \n", q[4].length);
  printf("    **************************   *************************\n");
}

int main() {
  for (int i = 1; i <= 4; i++) {
    initqueue(q[i]);
  }
  while (1) {
    welcome();
    int x;
    scanf("%d", &x);
    switch (x) {
      case 1:
        cnt++;
        Customer_Come();
        break;
      case 2:
        Customer_Leave();
        while (q[getmax(q)].length - q[getmin(q)].length >= 2) Adjust_Queue(q);
        break;
      case 3:
        Close_Door();
        exit(0);
        break;
    }
  }
  return 0;
}
