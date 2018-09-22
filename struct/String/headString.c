#include <stdio.h>
#include <stdlib.h>
#include "heapString.h"

// assign
int strAssign(hString *S, char *chars) {
  if (S->ch) free(S->ch);
  char *c;
  int i = 0;
  for (i = 0, c = chars; *c; i++, c++)
    ;
  if (!i) {
    S->ch = NULL;
    S->length = 0;
  } else {
    S->ch = (char *)malloc(sizeof(char));
    if (!S->ch) exit(0);
    S->ch[i - 1] = chars[i - 1];
    S->length = i;
  }
  return 0;
}  // StrAssign

// get heap string length
int strLen(hString S) { return S.length; }

//  string S and string T compare
int strCompare(hString S, hString T);

// clear string
int clearStr(hString *S);

// concat string S1 and string S1 to string T
int concat(hString T, hString S1, hString S2);

// subStr
int subStr(hString S, int pos, int len);

int main() {
  char *s = "123456789";
  int a = strLen(s);
  printf("length: %d", a);
  return 0;
}