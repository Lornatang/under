#include "array.h"
#include <stdio.h>
#include <stdlib.h>

// 初始化
void InitMyVector(array *vector) {
  // 数据初始化
  vector->curSize = 0;
  vector->maxSize = MY_VECTOR_DEF_SIZE;

  // 开辟存储实际数据的空间
  vector->data = (int *)malloc(sizeof(int) * vector->maxSize);
}

// 追加值
void AppendMyVector(array *vector, int value) {
  // 空间不够了需要增大
  DoubleCapacityMyVector(vector);
  // 添加新的数据到数组尾
  vector->data[vector->curSize++] = value;
}

// 获的值
int GetMyVector(array *vector, int index) {
  // 输入的数据如果小于0或者是大余数组最大存储值时，直接退出程序，因为数据不合法
  if (index >= vector->curSize || index < 0) {
    exit(1);
  }  // 如果输入的是一个合法的数据那么返回对应的数据
  return vector->data[index];
}

// 设置值
void SetMyVector(array *vector, int index, int value) {
  // 用0作为默认值来他填充数组
  while (index >= vector->curSize) {
    AppendMyVector(vector, 0);
  }

  vector->data[index] = value;
}

// 扩大空间
void DoubleCapacityMyVector(array *vector) {
  if (vector->curSize >= vector->maxSize) {
    // 扩大数组大小为当前的两倍
    vector->maxSize *= 2;
    vector->data = (int *)realloc(vector->data, sizeof(int) * vector->maxSize);
  }
}

//释放空间
void FreeMyVector(array *vector) { free(vector->data); }

int main() {
  // 声明vector对象
  array vector;
  int i;
  // 初始化vector对象
  InitMyVector(&vector);

  // 随便初始化点数据
  for (i = 0; i < 200; i++) {
    AppendMyVector(&vector, i);
  }

  // 测试用，在第200位置设置1，200之前的数据如果为空自动填充为0，当前程序就是200-299为0
  SetMyVector(&vector, 300, 1);
  // 测试用，取指定位置的数据
  printf("%d\n", GetMyVector(&vector, 6));
  // 测试用，输出每一个成员
  for (i = 0; i < vector.curSize; i++) {
    printf("%d %d\n", i, GetMyVector(&vector, i));
  }
  // 使用完之后要释放，不然会有内存泄露
  FreeMyVector(&vector);

  return 0;
  return 0;
}
