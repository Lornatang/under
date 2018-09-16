#include "cycle.h"

pNode create() {
  int i, length = 0, data = 0;
  pNode L = NULL;
  pNode end = NULL;

  L = (pNode)malloc(sizeof(node));

  if (L == NULL) {
    printf("space error!.\n");
    exit(0);
  }
  L->data = 0;
  L->next = L;
  end = L;

  printf("Length: ");
  scanf("%d", &length);

  for (i = 1; i < length; i++) {
    pNode p = (pNode)malloc(sizeof(node));
  }
  return L;
}