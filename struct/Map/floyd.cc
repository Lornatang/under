#include <iostream>
using namespace std;

#define MAXEDGE 20
#define MAXVEX 20
#define INFINITY 65535

typedef struct {
  int vexs[MAXVEX];
  int arc[MAXVEX][MAXVEX];
  int numVertexes, numEdges;
} MGraph;

typedef int Patharc[MAXVEX][MAXVEX];
typedef int ShortPathTable[MAXVEX][MAXVEX];

/* 构建图 */
void CreateMGraph(MGraph *G) {
  int i, j;

  /* printf("请输入边数和顶点数:"); */
  G->numEdges = 16;
  G->numVertexes = 9;

  for (i = 0; i < G->numVertexes; i++) /* 初始化图 */
  {
    G->vexs[i] = i;
  }

  for (i = 0; i < G->numVertexes; i++) /* 初始化图 */
  {
    for (j = 0; j < G->numVertexes; j++) {
      if (i == j)
        G->arc[i][j] = 0;
      else
        G->arc[i][j] = G->arc[j][i] = INFINITY;
    }
  }

  G->arc[0][1] = 1;
  G->arc[0][2] = 5;
  G->arc[1][2] = 3;
  G->arc[1][3] = 7;
  G->arc[1][4] = 5;

  G->arc[2][4] = 1;
  G->arc[2][5] = 7;
  G->arc[3][4] = 2;
  G->arc[3][6] = 3;
  G->arc[4][5] = 3;

  G->arc[4][6] = 6;
  G->arc[4][7] = 9;
  G->arc[5][7] = 5;
  G->arc[6][7] = 2;
  G->arc[6][8] = 7;

  G->arc[7][8] = 4;

  for (i = 0; i < G->numVertexes; i++) {
    for (j = i; j < G->numVertexes; j++) {
      G->arc[j][i] = G->arc[i][j];
    }
  }
}
/* Floyd算法，求网图G中各顶点v到其余顶点w的最短路径P[v][w]及带权长度D[v][w]。 */
void ShortestPath_Floyd(MGraph MG, Patharc P, ShortPathTable D) {
  int v, w, k;
  for (v = 0; v < MG.numVertexes; v++) /* 初始化D与P */
  {
    for (w = 0; w < MG.numVertexes; w++) {
      D[v][w] = MG.arc[v][w]; /* D[v][w]值即为对应点间的权值 */
      P[v][w] = w;            /* 初始化P */
    }
  }

  for (k = 0; k < MG.numVertexes; k++) {
    for (v = 0; v < MG.numVertexes; v++) {
      for (w = 0; w < MG.numVertexes; w++) {
        /* 如果经过下标为k顶点路径比原两点间路径更短 */
        if (D[v][w] > D[v][k] + D[k][w]) {
          /* 将当前两点间权值设为更小的一个 */
          D[v][w] = D[v][k] + D[k][w];
          P[v][w] = P[v][k]; /* 路径设置为经过下标为k的顶点 */
        }
      }
    }
  }
}

int main(void) {
  int v, w, k;
  MGraph MG;
  Patharc P;
  ShortPathTable D;
  CreateMGraph(&MG);
  ShortestPath_Floyd(MG, P, D);

  cout << "各顶点间最短路径如下: " << endl;

  for (v = 0; v < MG.numVertexes; v++) {
    for (w = v + 1; w < MG.numVertexes; w++) {
      cout << "v" << v << "--"
           << "v" << w << " weight: " << D[v][w] << " Path: " << v << ' ';
      k = P[v][w];
      while (k != w) {
        cout << "-> " << k << " ";
        k = P[k][w];
      }
      cout << "-> " << w << endl;
    }
    cout << endl;
  }

  return 0;
}