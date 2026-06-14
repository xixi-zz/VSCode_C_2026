#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>


typedef struct EdgeNode
{
    int dest;
    struct EdgeNode* next;
}EdgeNode;

// typedef int VDatatype;
// typedef struct Vertexs
// {
//     VDatatype data;
// }Vertexs;

typedef struct Graph
{
    EdgeNode** adjlist;
    // Vertexs* vertexs;
    int vertexNum;
}Graph;

void GraphPrint(Graph*gh);
void GraphInit(Graph* gh,int InitVertexNum);
void AddEdge(Graph* gh,int src, int dest);
void GraphDestroy(Graph* gh);
void DFS(Graph*gh,int v,bool* visited);