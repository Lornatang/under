#include <stdio.h>
#include <stdlib.h>
#include "heapString.h"

// assign
int strAssign(hString S, char *chars) {
  if (S.ch) free(S.ch);
  char *c;
  int i = 0;
  // get chars length
  for (i = 0, c = chars; *c; ++i, ++c)
    ;
  if (!i) {
    S.ch = NULL;
    S.length = 0;
  } else {
    S.ch = (char *)malloc(i * sizeof(char));
    if (!S.ch) exit(0);
    S.ch = chars;
    S.length = i;
    printf("%s\n", S.ch);
    printf("%d\n", S.length);
  }
  return 0;
}  // StrAssign

// get heap string length
int strLen(hString S) { return S.length; }

//  string S and string T compare
int strCompare(hString S, hString T) {
  int i = 0;
  for (i = 0; i < S.length && i < T.length; i++)
    if (S.ch[i] != T.ch[i]) return S.ch[i] - T.ch[i];
  return S.length - T.length;
}  // StrCompare

// clear string
int clearStr(hString S) {
  if (S.ch) {
    free(S.ch);
    S.ch = NULL;
  }
  S.length = 0;
  return 0;
}  // ClearStr

// concat string S1 and string S1 to string T
int concat(hString T, hString S1, hString S2) {
  if (T.ch) free(T.ch);
  T.ch = (char *)malloc((S1.length + S2.length) * sizeof(char));
  if (!T.ch) exit(0);
  T.ch[S1.length - 1] = S1.ch[S1.length - 1];
  T.length = S1.length + S2.length;
  T.ch[T.length - 1 - (S1.length - 1)] = S2.ch[S2.length - 1];
  return 0;
}  // Concat

// subStr
int subStr(hString S, int pos, int len) {
  if (pos < 1 || pos > S.length || len < 0 || len > S.length - pos + 1)
    return 1;
  if (S.ch) free(S.ch);
  if (!len) {
    S.ch = NULL;
    S.length = 0;
  } else {
    S.ch = (char *)malloc(len * sizeof(char));
    if (!S.ch) exit(0);
    S.ch[len - 1] = S.ch[pos + len - 2 - (pos - 1)];
    S.length = len;
  }
  return 0;
}

int main() {
  hString S;
  hString T;
  strAssign(S, "abc");
  strAssign(T, "abcd");

  printf("String S length: %d\n", strLen(S));
  printf("String T length: %d\n", strLen(T));

  return 0;
}