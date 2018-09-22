#ifndef STRING_H
#define STRING_H

#ifndef MASIZE
#define SIZE 255
#endif  // MAXSIZE
typedef struct {
  char elem[SIZE];  // elem数组用来存放串的元素
  int length;       // 定义一个串长度
} str;

void init(str *s, const char *chars);  // 初始化串
void strCopy(str *s, str *t);          // 拷贝串
int getLength(str *s);                 // 获取串的长度
void clear(str *s);                    // 清空串s
bool insert(str *s, int pos, str *t);  // 在串s的pos位置插入串t
void dis(str *s);                      // 打印串
int BF(str *s, str *sub,
       int pos);  // 在串s里找第一个串sub，并返回串sub的第一个元素的下标
bool deletePos(str *s, int pos,
               int len);  // 在串中的pos位置开始删除len长度个元素
bool del(str *s, int pos, str *t);  // 在串中的pos位置开始删除串t
bool replace(str *s, str *t, str *v, int pos);  // 用v替换从pos位置开始的第一个t
bool repIaceAll(str *s, str *t, str *v);  // 在串s中查找到串t并用串v替换

#endif  // STRING_H