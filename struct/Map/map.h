#ifndef MAP_H
#define MAP_H
#define MAX_VER_NUM 50
typedef char VertexType;
typedef enum { DG, UDG } GraphType;
typedef struct {
  VertexType vexs[MAX_VER_NUM];        //顶点向量
  int arcs[MAX_VER_NUM][MAX_VER_NUM];  //邻接矩阵
  int vexnum, arcnum;                  //图的当前顶点数和弧数
  GraphType type;                      //图的种类标志
} MGraph;

#endif  // MAP_H