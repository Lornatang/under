#include "string.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init(str *s, const char *chars)  //初始化串
{
  assert(s != NULL);
  int len = strlen(chars);

  /*if(s->length<len)
  {
      return;
  }*/
  s->length = len;
  for (int i = 0; i < len; i++) {
    s->elem[i] = chars[i];
  }
}

void strCopy(str *s, str *t)  //拷贝串
{
  for (int i = 0; i < t->length; i++) {
    s->elem[i] = t->elem[i];
  }
  s->length = t->length;
}

int getLength(str *s)  //获取串的长度
{
  return s->length;
}

void clear(str *s)  //清空串s
{
  s->length = 0;
}

bool SubStr(str *sub, str *s, int pos, int len)  //空白字符不拷贝
{
  if (pos < 0 || len < 1 || pos >= s->length || pos + len > s->length - 1) {
    return false;
  }
  for (int i = pos; i < pos + len; i++) {
    sub->elem[i - pos] = s->elem[i];
  }
  sub->length = len;
  return true;
}

bool insert(str *s, int pos, str *t)  //在串s的pos位置插入串t
{
  assert(s != NULL);
  assert(t != NULL);
  if (pos < 0 || pos > s->length || pos + t->length > SIZE) {
    return false;
  }
  for (int i = s->length - 1; i >= pos; i--) {
    s->elem[i + t->length] = s->elem[i];
  }
  for (int j = 0; j < t->length; j++) {
    s->elem[j + pos] = t->elem[j];
  }
  s->length += t->length;
  return true;
}
int BF(str *s, str *sub,
       int pos)  //在串s里找第一个串sub，并返回串sub的第一个元素的下标
{
  if (pos < 0 || pos > s->length) {
    return -1;
  }

  int i = pos;
  int j = 0;

  int lens = s->length;
  int lensub = sub->length;

  while (i < lens && j < lensub) {
    if (s->elem[i] == sub->elem[j]) {
      i++;
      j++;
    } else {
      i = i - j + 1;
      j = 0;
    }
  }
  if (j >= lensub) {
    return i - j;
  } else
    return -1;
}

bool deletePos(str *s, int pos, int len)  //从pos位置开始删除len个长度
{
  assert(s != NULL);
  if (pos < 0 || pos + len > s->length || len < 0) {
    return false;
  }
  // for(int i = pos;i<len+pos;i++)
  for (int i = pos; i < s->length - len; i++) {
    s->elem[i] = s->elem[i + len];
  }
  s->length -= len;
  return true;
}

bool del(str *s, int pos, str *t)  //在串中的pos位置开始删除串t
{
  assert(s != NULL);
  assert(t != NULL);
  if (pos < 0 || pos > s->length || t->length > s->length) {
    return false;
  }
  int index = BF(s, t, pos);
  if (index < 0) {
    return false;
  }
  return deletePos(s, index, t->length);
}
bool Replace(str *s, str *t, str *v, int pos)  //用v替换从pos位置开始的第一个t
{
  assert(s != NULL);
  assert(t != NULL);
  assert(v != NULL);

  int index = BF(s, t, pos);
  if (index < 0) {
    return false;
  }
  deletePos(s, index, t->length);
  return insert(s, index, v);
}
bool replace(str *s, str *t, str *v)  //在串s中查找到串t并用串v替换
{
  assert(s != NULL);
  assert(t != NULL);
  assert(v != NULL);

  while (Replace(s, t, v, 0))
    ;
  return true;
}
void dis(str *s)  //打印
{
  for (int i = 0; i < getLength(s); i++) {
    printf("%c", s->elem[i]);
  }
  printf("\n");
}

int main() {
  str s;
  char *s1 = "abcdecdfcd";
  init(&s, s1);
  dis(&s);

  str t;
  char *t1 = "cd";
  init(&t, t1);
  dis(&t);

  str v;
  char *v1 = "zkr";
  init(&v, v1);
  dis(&v);
  replace(&s, &t, &v);
  dis(&s);
  return 0;
}