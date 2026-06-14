#include"Graph.h"

void test01()
{
    Graph g;
    GraphInit(&g, 4);

    AddEdge(&g, 0, 1);
    AddEdge(&g, 0, 2);
    AddEdge(&g, 1, 3);
    AddEdge(&g, 2, 3);

    GraphPrint(&g);

    printf("DFS:");
    bool* visited = (bool*)calloc(g.vertexNum, sizeof(bool));
    DFS(&g, 0, visited);
    printf("\n");

    free(visited);
    visited = NULL;

    GraphDestroy(&g);
}

int main()
{
    test01();
    return 0;
}