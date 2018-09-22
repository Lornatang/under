#ifndef BANK_H
#define BANK_H
typedef struct pnode {
  int number;
  int cometime;
  int leavetime;
  struct pnode *next;
} * person;
typedef struct node {
  person front;
  person rear;
  int length;
} linkqueue;
linkqueue q[5];
int number, time;
int flag = 1;
int cnt = 0;  //当日客流量
int sum = 0;  //当日客户排队总时间

void initqueue(linkqueue &q);
void enterqueue(linkqueue &q, int number, int time);
void popqueue(linkqueue &q);
int getmin(linkqueue q[]);
int getmax(linkqueue q[]);

void Customer_Come();
void Customer_Leave();
void Adjust_Queue(linkqueue q[]);
void Close_Door();
void welcome();
#endif  // BANK_H