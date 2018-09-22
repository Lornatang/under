#include <stdio.h>
#include <stdlib.h>
#include "heapString.h"

// assign
int strAssign(hString *S, char *chars) {
  if(S->ch)
}

// get heap string length
int strlen(hString S);

//  string S and string T compare
int strCompare(hString S, hString T);

// clear string
int clearStr(hString *S);

// concat string S1 and string S1 to string T
int concat(hString T, hString S1, hString S2);

// subStr
int subStr(hString S, int pos, int len);