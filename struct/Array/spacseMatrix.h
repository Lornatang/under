#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H

#ifndef FLAG
#define FLAG
#define true 1
#define false 0
#define error -1
#endif  // FLAG

typedef struct {
  int row;  // 行下标
  int col;  // 列下标
  int elm;  // 该下标所保存的元素
} tuple;    // 三元组结构

typedef struct {
  tuple *tup;  //三元组顺序表
  int row;     // 矩阵行数
  int col;     // 矩阵列数
  int unul;    // 非 0 元素个数
} matrix;      // 稀疏矩阵结构

// 稀疏矩阵方法声明
matrix *init(int row, int col);  // 创建一个大小为 row x col 稀疏矩阵
matrix *CreateTMatirxFrom2DArray(void *p, int row,
                                 int col);  // 从二维数组中创建稀疏矩阵
void DestroyTMatrix(matrix *pMat);          // 销毁稀疏矩阵
int ElemLocate(matrix *pMat, int row,
               int col);  // 定位矩阵下标 row, col 在稀疏矩阵中的存储位置
void DisplayTMatrix(matrix *pMat);  // 输出稀疏矩阵
int GetTMatrixSize(matrix *pMat);  ///输出稀疏矩阵 pMat 所占用的空间大小(字节)
int AppendElem(matrix *pMat, int elm, int row,
               int col);  // 将元素 elm 添加到稀疏矩阵 row, col 位置
int DeleteElem(matrix *pMat, int row,
               int col);  // 删除稀疏矩阵中 row, col 下标指向的元素
int TMatrixCopy(matrix *pMatDest,
                matrix *pMatSrc);  // 将稀疏矩阵 pMatSrc 复制到 pMatDest
int Value(matrix *pMat, int row, int col,
          int *pElm);  // 从稀疏矩阵中取下标为 row, col 元素的值
void ForEach(matrix *pMat,
             void (*func)(int *pElm));  // 对矩阵中的每个元素依次执行 func 函数

#endif  // SPARSEMATRIX_H