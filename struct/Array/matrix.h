#ifndef MATRIX_H
#define MATRIX_H

#ifndef FLAG
#define FLAG
#define true 1
#define false 0
#define error -1
#endif  // FLAG

typedef struct {
  int m;    ///行下标
  int n;    ///列下标
  int elm;  ///该下标所保存的元素
} TTuple;   ///三元组结构

typedef struct {
  TTuple *tup;  ///三元组顺序表
  int row;      ///矩阵行数
  int col;      ///矩阵列数
  int unul;     ///非 0 元素个数
} TMatrix;      ///稀疏矩阵结构

///稀疏矩阵方法声明
TMatrix *init(int sizeM, int sizeN);  ///创建一个大小为 sizeM x sizeN 稀疏矩阵
TMatrix *CreateTMatirxFrom2DArray(void *pArr2D, int sizeM,
                                  int sizeN);  ///从二维数组中创建稀疏矩阵
void DestroyTMatrix(TMatrix *pMat);            ///销毁稀疏矩阵
int ElemLocate(TMatrix *pMat, int m,
               int n);  ///定位矩阵下标 m, n 在稀疏矩阵中的存储位置
void DisplayTMatrix(TMatrix *pMat);  ///输出稀疏矩阵
int GetTMatrixSize(TMatrix *pMat);  ///输出稀疏矩阵 pMat 所占用的空间大小(字节)
int AppendElem(TMatrix *pMat, int elm, int m,
               int n);  ///将元素 elm 添加到稀疏矩阵 m, n 位置
int DeleteElem(TMatrix *pMat, int m,
               int n);  ///删除稀疏矩阵中 m, n 下标指向的元素
int TMatrixCopy(TMatrix *pMatDest,
                TMatrix *pMatSrc);  ///将稀疏矩阵 pMatSrc 复制到 pMatDest
int Value(TMatrix *pMat, int m, int n,
          int *pElm);  ///从稀疏矩阵中取下标为 m, n 元素的值
void ForEach(TMatrix *pMat,
             void (*func)(int *pElm));  ///对矩阵中的每个元素依次执行 func 函数

#endif  // MATRIX_H