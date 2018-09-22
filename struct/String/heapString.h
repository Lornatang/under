#ifndef HEAP_STRING_H
#define HEAP_STRING_H

typedef struct {
  char *ch;
  int length;
} hString;

int strAssign(hString &S);

#endif  // HEAP_STRING_H