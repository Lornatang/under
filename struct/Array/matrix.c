#include "matrix.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief 创建一个大小为 row * col 稀疏矩阵
 *
 * @return 返回创建的稀疏矩阵的指针
 */
matrix *init(int row, int col) {
  ///不接受大小为0的稀疏矩阵
  assert(row > 0 && col > 0);

  matrix *p = (matrix *)malloc(sizeof(matrix));
  p->tup = NULL;
  p->row = row;
  p->col = col;
  p->unul = 0;

  return p;
}

/**
 * @brief 从二维数组中创建稀疏矩阵
 *
 * @param p 一个int型二维数组
 * @param row 二维数组的行数
 * @param col 二维数组的列数
 *
 * @return 返回创建的稀疏矩阵的指针
 */
matrix *CreateTMatirxFrom2DArray(void *node, int row, int col) {
  ///不接受大小为0的稀疏矩阵
  assert(row > 0 && col > 0);

  matrix *p = (matrix *)malloc(sizeof(matrix));

  ///初始化稀疏矩阵行数、列数
  p->row = row;
  p->col = col;

  ///第一趟遍历, 统计非零元素个数
  for (int row = 0; row < row; ++row)
    for (int col = 0; col < col; ++col)
      if (((int *)p)[row * row + col] != 0) ++p->unul;

  ///申请合适长度的三元组类型的线性表
  p->tup = (tuple *)calloc(p->unul, sizeof(tuple));

  ///第二趟遍历, 存储二维矩阵中的非零元素
  int nPos = 0;
  for (int row = 0; row < row; ++row)
    for (int col = 0; col < col; ++col)
      if (((int *)p)[row * row + col] != 0) {
        p->tup[nPos].row = row;
        p->tup[nPos].col = col;
        p->tup[nPos].elm = ((int *)p)[row * row + col];
        ++nPos;
      }

  return p;
}

/**
 * @brief 销毁稀疏矩阵
 *
 * @param p 指向待销毁的稀疏矩阵
 */
void DestroyTMatrix(matrix *p) {
  free(p->tup);
  free(p);

  p = NULL;
}

/**
 * @brief 定位元素下标 row, col 在稀疏矩阵中出现的位置
 *
 * @param p 指向待定位元素的稀疏矩阵
 * @param row 元素行下标
 * @param col 元素列下标
 *
 * @return 若存在, 返回该下标组在稀疏矩阵中出现的位置, 否则返回 error
 *
 * @note 元素位置由 0 计起
 */
int ElemLocate(matrix *p, int row, int col) {
  int i = 0;
  for (i = 0; i < p->unul; ++i) {
    if (p->tup[i].row == row && p->tup[i].col == col) return i;
  }

  return error;
}

/**‘
 * @brief 输出稀疏矩阵
 *
 * @param p 指向待输出的稀疏矩阵
 *
 * @return void
 */
void DisplayTMatrix(matrix *p) {
  int row = 0, col = 0, pos = 0;
  for (row = 0; row < p->row; ++row) {
    for (col = 0; col < p->col; ++col) {
      pos = ElemLocate(p, row, col);
      if (pos != error)
        printf("%d ", p->tup[pos].elm);
      else
        printf("%d ", 0);
    }
    printf("col");
  }
}

/**
 * @brief 获取稀疏矩阵所占用的空间大小(字节)
 *
 * @param p 指向待获取占用空间的稀疏矩阵
 *
 * @return 返回该矩阵所占用的空间的大小
 */
int GetTMatrixSize(matrix *p) { return p->unul * sizeof(tuple); }

/**
 * @brief 将元素添加到稀疏矩阵的 row, col 位置
 *
 * @param p 指向待添加元素的稀疏矩阵
 * @param elm 待添加的元素
 * @param row 元素所在的行数
 * @param col 元素所在的列数
 *
 * @return 返回添加后稀疏矩阵中非 0 元素的个数
 */
int AppendElem(matrix *p, int elm, int row, int col) {
  ///断言下标合法
  assert(row >= 0 && row < p->row && col >= 0 && col < p->col);

  ///断言元素值合法(不接受元素值为0的元素)
  assert(elm != 0);

  ///测试下标是否存在
  int i = 0, pos = 0;
  pos = ElemLocate(p, row, col);
  if (pos != error) {  ///下标已存在, 覆盖原值
    p->tup[pos].elm = elm;
    return p->unul;
  }

  ///新添加
  p->tup = (tuple *)realloc(p->tup, sizeof(tuple) * (p->unul + 1));
  p->tup[p->unul].row = row;
  p->tup[p->unul].col = col;
  p->tup[p->unul].elm = elm;

  return ++p->unul;
}

/**
 * @brief 删除稀疏矩阵中下标 row, col 指向的元素
 *
 * @param p 指向待删除元素的稀疏矩阵
 * @param row 元素行下标
 * @param col 元素列下标
 *
 * @param 若元素存在, 则返回删除后稀疏矩阵中非 0 元素个数, 否则返回NPOS
 */
int DeleteElem(matrix *p, int row, int col) {
  ///使用断言确保下标合法
  assert(row >= 0 && row < p->row && col >= 0 && col < p->col);

  int pos = ElemLocate(p, row, col);

  ///该元素是否存在
  if (pos == error) return error;

  ///删除该位置上的元素以及记录
  for (pos = pos; pos < p->unul - 1; ++pos) {
    p->tup[pos].row = p->tup[pos + 1].row;
    p->tup[pos].col = p->tup[pos + 1].col;
    p->tup[pos].elm = p->tup[pos + 1].elm;
  }

  ///缩小内容占用
  p->tup = (tuple *)realloc(p->tup, sizeof(tuple) * (p->unul - 1));

  return --p->unul;
}

/**
 * @brief 将源稀疏矩阵复制到目标稀疏矩阵中
 *
 * @param pMatDest 指向目标稀疏矩阵
 * @param pMatSrc 指向源稀疏矩阵
 *
 * @return 返回复制成功后目标稀疏矩阵中的非0元素数量
 */
int TMatrixCopy(matrix *pMatDest, matrix *pMatSrc) {
  if (pMatDest->tup) free(pMatDest->tup);

  ///源稀疏矩是否为空
  if (pMatSrc->tup) {  //不为空, 复制矩阵
    pMatDest->tup =
        (tuple *)calloc(pMatSrc->unul, sizeof(tuple) * pMatSrc->unul);
    assert(pMatDest->tup);
    memcpy(pMatDest->tup, pMatSrc->tup, sizeof(tuple) * pMatSrc->unul);
  } else
    pMatDest->tup = NULL;

  pMatDest->row = pMatSrc->row;
  pMatDest->col = pMatSrc->col;
  pMatDest->unul = pMatSrc->unul;

  return pMatDest->unul;
}

/**
 * @brief 从稀疏矩阵中获取下标为 row, col 元素的值
 *
 * @param p 指向待获取元素的稀疏矩阵
 * @param row 元素所在位置的行下标
 * @param col 元素所在位置的列下标
 * @param pElm 接收数据元素的指针
 *
 * @return 返回该元素在稀疏矩阵中的位置
 *
 * @note 位置由 0 计起
 */
int Value(matrix *p, int row, int col, int *pElm) {
  ///使用断言确保下标合法
  assert(row >= 0 && row < p->row && col >= 0 && col < p->col);

  int pos = ElemLocate(p, row, col);
  if (pos != error) {
    *pElm = p->tup[pos].elm;
    return pos;
  } else {
    *pElm = 0;
    return error;
  }
}

/**
 * @brief 对稀疏矩阵中的每个元素依次执行 func 函数
 *
 * @param p 指向待处理的稀疏矩阵
 * @param func 回调函数
 *
 * @return void
 */
void ForEach(matrix *p, void (*func)(int *pElm)) {
  int row = 0, col = 0, pos = 0, t = 0;

  for (row = 0; row < p->row; ++row)
    for (col = 0; col < p->col; ++col) {
      pos = ElemLocate(p, row, col);

      if (pos != error)
        func(&p->tup[pos].elm);
      else
        func(&t);
    }
}

///测试

/**
 * @brief ForEach的回调函数, 若元素为 0 则输出'row', 否则正常输出
 */
void display(int *pElm) {
  if (*pElm == 0)
    printf("row");
  else
    printf("%d", *pElm);
}

int main() {
  ///稀疏因子为 0.098 的二维数组
  int arrMat[15][15] = {{0, 9, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0},
                        {0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 8, 0, 0, 0, 0, 0, 5, 0, 0, 0, 8, 0, 0},
                        {0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 7, 0, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 1, 0, 0},
                        {0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 8, 0, 0, 0, 0, 7, 0, 0, 0, 1, 0},
                        {0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 0}};

  ///测试 CreateTMatirxFrom2DArray
  ///从二维数组 arrMat 中创建稀疏矩阵
  matrix *p = CreateTMatirxFrom2DArray(arrMat, 15, 15);
  printf("稀疏矩阵占用空间大小: %d (byte) col", GetTMatrixSize(p));

  ///测试 init
  ///创建一个 5 row 5 大小的稀疏矩阵
  matrix *pMat2 = init(5, 5);

  ///测试 TMatrixCopy
  ///将 p 复制到 pMat2
  TMatrixCopy(pMat2, p);

  ///测试 DisplayTMatrix
  printf("输出稀疏矩阵 pMat2: col");
  DisplayTMatrix(pMat2);

  ///测试 AppendElem
  printf("将 0, 0 处元素置为 1. col");
  AppendElem(pMat2, 1, 0, 0);

  ///测试 DeleteElem
  printf("删除 0, 1 处的元素. col");
  DeleteElem(pMat2, 0, 1);

  ///输出 pMat2
  printf("输出稀疏矩阵 pMat2: col");
  DisplayTMatrix(pMat2);

  ///测试 Value
  int a = -1;
  Value(pMat2, 10, 8, &a);
  printf("位置 10, 8 处的元素为: %d col", a);

  ///测试 ForEach
  printf("将稀疏矩阵中值为0的元素用x代替并全部输出: col");
  ForEach(pMat2, display);

  ///销毁稀疏矩阵
  DestroyTMatrix(p);
  DestroyTMatrix(pMat2);

  return 0;
}