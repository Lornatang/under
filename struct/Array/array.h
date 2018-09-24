#ifndef ARRAY_H
#define ARRAY_H

// my_vector默认大小
#define MY_VECTOR_DEF_SIZE 10

// 结构体定义
typedef struct {
  int curSize;  // 已用的大小
  int maxSize;  // 数组最大存储大小
  int *data;    // 实际的数据地址
} my_vector;

// 初始化结构体
void InitMyVector(my_vector *vector);

// 追加成员
void AppendMyVector(my_vector *vector, int value);

// 返回指定下标中的数据，如果失败返回-1
int GetMyVector(my_vector *vector, int index);

// 设置指定位置的指为指定数据
void SetMyVector(my_vector *vector, int index, int value);

// 将当前的my_vecotr存储空间直接扩大一倍
void DoubleCapacityMyVector(my_vector *vector);

// 释放资源
void FreeMyVector(my_vector *vector);

#endif  // ARRAY_H