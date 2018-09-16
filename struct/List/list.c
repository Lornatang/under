#include "list.h"

int main() {
  seqList *L;
  L = initList();
  insertList(L, 1, 5);
  return 0;
}
