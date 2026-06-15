#include "Graph.h"

int main()
{
    Graph g;

    GraphInit(&g, 4);

    AddEdge(&g, 0, 1);
    AddEdge(&g, 0, 2);
    AddEdge(&g, 1, 3);
    AddEdge(&g, 2, 3);

    printf("Graph:\n");
    GraphPrint(&g);

    printf("\nDFS:\n");

    bool* visited1=(bool*)calloc(g.vertexNum,sizeof(bool));

    DFS(&g,0,visited1);

    free(visited1);
    visited1=NULL;

    printf("\n\nBFS:\n");

    bool* visited2=(bool*)calloc(g.vertexNum,sizeof(bool));

    BFS(&g,0,visited2);

    free(visited2);
    visited2=NULL;

    printf("\n");

    GraphShortestPath(&g,0,3);
    GraphDestroy(&g);

    return 0;
}