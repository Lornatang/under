#ifndef ARRAY_H
#define ARRAY_H

// my_vector默认大小
#define MY_VECTOR_DEF_SIZE 10

// 结构体定义
typedef struct {
  int curSize;  // 已用的大小
  int maxSize;  // 数组最大存储大小
  int *data;    // 实际的数据地址
} array;

// 初始化结构体
void InitMyVector(array *vector);

// 追加成员
void AppendMyVector(array *vector, int value);

// 返回指定下标中的数据，如果失败返回-1
int GetMyVector(array *vector, int index);

// 设置指定位置的指为指定数据
void SetMyVector(array *vector, int index, int value);

// 将当前的my_vecotr存储空间直接扩大一倍
void DoubleCapacityMyVector(array *vector);

// 释放资源
void FreeMyVector(array *vector);

#endif  // ARRAY_H