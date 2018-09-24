#include "matrix.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief 创建一个大小为 sizeM x sizeN 稀疏矩阵
 *
 * @return 返回创建的稀疏矩阵的指针
 */
TMatrix *CreateEmptyTMatrix(int sizeM, int sizeN) {
  ///不接受大小为0的稀疏矩阵
  assert(sizeM > 0 && sizeN > 0);

  TMatrix *pMat = (TMatrix *)malloc(sizeof(TMatrix));
  pMat->tup = NULL;
  pMat->row = sizeM;
  pMat->col = sizeN;
  pMat->unul = 0;

  return pMat;
}

/**
 * @brief 从二维数组中创建稀疏矩阵
 *
 * @param pArr2D 一个ElemType型二维数组
 * @param sizeM 二维数组的行数
 * @param sizeN 二维数组的列数
 *
 * @return 返回创建的稀疏矩阵的指针
 */
TMatrix *CreateTMatirxFrom2DArray(void *pArr2D, int sizeM, int sizeN) {
  ///不接受大小为0的稀疏矩阵
  assert(sizeM > 0 && sizeN > 0);

  TMatrix *pMat = (TMatrix *)malloc(sizeof(TMatrix));

  ///初始化稀疏矩阵行数、列数
  pMat->row = sizeM;
  pMat->col = sizeN;

  ///第一趟遍历, 统计非零元素个数
  int m = 0, n = 0;
  for (m = 0; m < sizeM; ++m)
    for (n = 0; n < sizeN; ++n)
      if (((int *)pArr2D)[sizeM * m + n] != 0) ++pMat->unul;

  ///申请合适长度的三元组类型的线性表
  pMat->tup = (TTuple *)calloc(pMat->unul, sizeof(TTuple));

  ///第二趟遍历, 存储二维矩阵中的非零元素
  int nPos = 0;
  for (m = 0; m < sizeM; ++m)
    for (n = 0; n < sizeN; ++n)
      if (((int *)pArr2D)[sizeM * m + n] != 0) {
        pMat->tup[nPos].m = m;
        pMat->tup[nPos].n = n;
        pMat->tup[nPos].elm = ((int *)pArr2D)[sizeM * m + n];
        ++nPos;
      }

  return pMat;
}

/**
 * @brief 销毁稀疏矩阵
 *
 * @param pMat 指向待销毁的稀疏矩阵
 */
void DestroyTMatrix(TMatrix *pMat) {
  free(pMat->tup);
  free(pMat);

  pMat = NULL;
}

/**
 * @brief 定位元素下标 m, n 在稀疏矩阵中出现的位置
 *
 * @param pMat 指向待定位元素的稀疏矩阵
 * @param m 元素行下标
 * @param n 元素列下标
 *
 * @return 若存在, 返回该下标组在稀疏矩阵中出现的位置, 否则返回 error
 *
 * @note 元素位置由 0 计起
 */
int ElemLocate(const TMatrix *const pMat, int m, int n) {
  int i = 0;
  for (i = 0; i < pMat->unul; ++i) {
    if (pMat->tup[i].m == m && pMat->tup[i].n == n) return i;
  }

  return error;
}

/**‘
 * @brief 输出稀疏矩阵
 *
 * @param pMat 指向待输出的稀疏矩阵
 *
 * @return void
 */
void DisplayTMatrix(const TMatrix *const pMat) {
  int m = 0, n = 0, pos = 0;
  for (m = 0; m < pMat->row; ++m) {
    for (n = 0; n < pMat->col; ++n) {
      pos = ElemLocate(pMat, m, n);
      if (pos != error)
        printf("%d ", pMat->tup[pos].elm);
      else
        printf("%d ", 0);
    }
    putchar('\n');
  }
}

/**
 * @brief 获取稀疏矩阵所占用的空间大小(字节)
 *
 * @param pMat 指向待获取占用空间的稀疏矩阵
 *
 * @return 返回该矩阵所占用的空间的大小
 */
int GetTMatrixSize(const TMatrix *const pMat) {
  return pMat->unul * sizeof(TTuple);
}

/**
 * @brief 将元素添加到稀疏矩阵的 m, n 位置
 *
 * @param pMat 指向待添加元素的稀疏矩阵
 * @param elm 待添加的元素
 * @param m 元素所在的行数
 * @param n 元素所在的列数
 *
 * @return 返回添加后稀疏矩阵中非 0 元素的个数
 */
int AppendElem(TMatrix *const pMat, int elm, int m, int n) {
  ///断言下标合法
  assert(m >= 0 && m < pMat->row && n >= 0 && n < pMat->col);

  ///断言元素值合法(不接受元素值为0的元素)
  assert(elm != 0);

  ///测试下标是否存在
  int i = 0, pos = 0;
  pos = ElemLocate(pMat, m, n);
  if (pos != error) {  ///下标已存在, 覆盖原值
    pMat->tup[pos].elm = elm;
    return pMat->unul;
  }

  ///新添加
  pMat->tup = (TTuple *)realloc(pMat->tup, sizeof(TTuple) * (pMat->unul + 1));
  pMat->tup[pMat->unul].m = m;
  pMat->tup[pMat->unul].n = n;
  pMat->tup[pMat->unul].elm = elm;

  return ++pMat->unul;
}

/**
 * @brief 删除稀疏矩阵中下标 m, n 指向的元素
 *
 * @param pMat 指向待删除元素的稀疏矩阵
 * @param m 元素行下标
 * @param n 元素列下标
 *
 * @param 若元素存在, 则返回删除后稀疏矩阵中非 0 元素个数, 否则返回NPOS
 */
int DeleteElem(TMatrix *const pMat, int m, int n) {
  ///使用断言确保下标合法
  assert(m >= 0 && m < pMat->row && n >= 0 && n < pMat->col);

  int pos = ElemLocate(pMat, m, n);

  ///该元素是否存在
  if (pos == error) return error;

  ///删除该位置上的元素以及记录
  for (pos = pos; pos < pMat->unul - 1; ++pos) {
    pMat->tup[pos].m = pMat->tup[pos + 1].m;
    pMat->tup[pos].n = pMat->tup[pos + 1].n;
    pMat->tup[pos].elm = pMat->tup[pos + 1].elm;
  }

  ///缩小内容占用
  pMat->tup = (TTuple *)realloc(pMat->tup, sizeof(TTuple) * (pMat->unul - 1));

  return --pMat->unul;
}

/**
 * @brief 将源稀疏矩阵复制到目标稀疏矩阵中
 *
 * @param pMatDest 指向目标稀疏矩阵
 * @param pMatSrc 指向源稀疏矩阵
 *
 * @return 返回复制成功后目标稀疏矩阵中的非0元素数量
 */
int TMatrixCopy(TMatrix *const pMatDest, TMatrix *const pMatSrc) {
  if (pMatDest->tup) free(pMatDest->tup);

  ///源稀疏矩是否为空
  if (pMatSrc->tup) {  //不为空, 复制矩阵
    pMatDest->tup =
        (TTuple *)calloc(pMatSrc->unul, sizeof(TTuple) * pMatSrc->unul);
    assert(pMatDest->tup);
    memcpy(pMatDest->tup, pMatSrc->tup, sizeof(TTuple) * pMatSrc->unul);
  } else
    pMatDest->tup = NULL;

  pMatDest->row = pMatSrc->row;
  pMatDest->col = pMatSrc->col;
  pMatDest->unul = pMatSrc->unul;

  return pMatDest->unul;
}

/**
 * @brief 从稀疏矩阵中获取下标为 m, n 元素的值
 *
 * @param pMat 指向待获取元素的稀疏矩阵
 * @param m 元素所在位置的行下标
 * @param n 元素所在位置的列下标
 * @param pElm 接收数据元素的指针
 *
 * @return 返回该元素在稀疏矩阵中的位置
 *
 * @note 位置由 0 计起
 */
int Value(const TMatrix *const pMat, int m, int n, int *pElm) {
  ///使用断言确保下标合法
  assert(m >= 0 && m < pMat->row && n >= 0 && n < pMat->col);

  int pos = ElemLocate(pMat, m, n);
  if (pos != error) {
    *pElm = pMat->tup[pos].elm;
    return pos;
  } else {
    *pElm = 0;
    return error;
  }
}

/**
 * @brief 对稀疏矩阵中的每个元素依次执行 func 函数
 *
 * @param pMat 指向待处理的稀疏矩阵
 * @param func 回调函数
 *
 * @return void
 */
void ForEach(const TMatrix *const pMat, void (*func)(int *pElm)) {
  int m = 0, n = 0, pos = 0, t = 0;

  for (m = 0; m < pMat->row; ++m)
    for (n = 0; n < pMat->col; ++n) {
      pos = ElemLocate(pMat, m, n);

      if (pos != error)
        func(&pMat->tup[pos].elm);
      else
        func(&t);
    }
}

///测试

/**
 * @brief ForEach的回调函数, 若元素为 0 则输出'x', 否则正常输出
 */
void display(int *pElm) {
  if (*pElm == 0)
    putchar('x');
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
  TMatrix *pMat = CreateTMatirxFrom2DArray(arrMat, 15, 15);
  printf("稀疏矩阵占用空间大小: %d (byte)\n", GetTMatrixSize(pMat));

  ///测试 CreateEmptyTMatrix
  ///创建一个 5 x 5 大小的稀疏矩阵
  TMatrix *pMat2 = CreateEmptyTMatrix(5, 5);

  ///测试 TMatrixCopy
  ///将 pMat 复制到 pMat2
  TMatrixCopy(pMat2, pMat);

  ///测试 DisplayTMatrix
  printf("输出稀疏矩阵 pMat2:\n");
  DisplayTMatrix(pMat2);

  ///测试 AppendElem
  printf("将 0, 0 处元素置为 1.\n");
  AppendElem(pMat2, 1, 0, 0);

  ///测试 DeleteElem
  printf("删除 0, 1 处的元素.\n");
  DeleteElem(pMat2, 0, 1);

  ///输出 pMat2
  printf("输出稀疏矩阵 pMat2:\n");
  DisplayTMatrix(pMat2);

  ///测试 Value
  int a = -1;
  Value(pMat2, 10, 8, &a);
  printf("位置 10, 8 处的元素为: %d\n", a);

  ///测试 ForEach
  printf("将稀疏矩阵中值为0的元素用x代替并全部输出:\n");
  ForEach(pMat2, display);

  ///销毁稀疏矩阵
  DestroyTMatrix(pMat);
  DestroyTMatrix(pMat2);

  return 0;
}