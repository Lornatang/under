#include "linklist.h"

int main() {
  linkList list, start;
  int i;
  int x;

  printf("请输入单链表的数据：");
  list = linkListCreateT();
  for (start = list->next; start != NULL; start = start->next)
    printf("%d ", start->data);
  printf("\n");

  // printf("请输入插入数据的位置：");
  // scanf("%d", &i);
  // printf("请输入插入数据的值：");
  // scanf("%d", &x);
  // linkListCreateT();

  // for (start = list->next; start != NULL; start = start->next)
  //   printf("%d ", start->data);
  // printf("\n");

  // printf("请输入要删除的元素的值：");
  // scanf("%d", &x);
  // linkListDel(list, x);
  // for (start = list->next; start != NULL; start = start->next)
  //   printf("%d ", start->data);
  int length = getLength(list);
  printf("Length: %d", length);
  printf("\n");

  return 0;
}