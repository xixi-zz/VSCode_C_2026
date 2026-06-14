#include"Graph_DFS.h"


EdgeNode* BuyNode(int dest)
{
    EdgeNode* newnode=(EdgeNode*)malloc(sizeof(EdgeNode));
    if(newnode==NULL)
    {
        perror("malloc fail");
        exit(1);
    }
    newnode->dest=dest;
    newnode->next=NULL;
    return newnode;
}

void GraphPrint(Graph*gh)
{
    assert(gh);
    for(int i=0;i<gh->vertexNum;i++)
    {
        printf("[%d]:",i);
        EdgeNode* pcur=gh->adjlist[i];
        while(pcur)
        {
            printf("%d->",pcur->dest);
            pcur=pcur->next;
        }
        printf("\n");
    }
}

void GraphInit(Graph* gh,int InitvertexNum)
{
    assert(gh);
    gh->adjlist=(EdgeNode**)malloc(sizeof(EdgeNode*)*InitvertexNum);
    if(gh->adjlist==NULL)
    {
        perror("malloc fail");
        exit(1);
    }
    gh->vertexNum=InitvertexNum;
    for(int i=0;i<gh->vertexNum;i++)
    {
        gh->adjlist[i]=NULL;
    }
}

void AddEdge(Graph* gh,int src, int dest)
{
    assert(gh);
    EdgeNode*srcnode=BuyNode(dest);
    srcnode->next=gh->adjlist[src];
    gh->adjlist[src]=srcnode;
    EdgeNode*destnode=BuyNode(src);
    destnode->next=gh->adjlist[dest];
    gh->adjlist[dest]=destnode;
}

void DFS(Graph* gh,int v,bool* visited)
{
    if(visited[v])
    {
        return;
    }
    visited[v]=true;
    printf("%d ",v);
    EdgeNode* pcur=gh->adjlist[v];
    while(pcur)
    {
        if(!(visited[pcur->dest]))
        {
            DFS(gh,pcur->dest,visited);
        }
        pcur=pcur->next;
    }
}
void GraphDestroy(Graph* gh)
{
    assert(gh);
    for(int i=0;i<gh->vertexNum;i++)
    {
        EdgeNode* pcur=gh->adjlist[i];
        while(pcur)
        {
            EdgeNode* del=pcur;
            pcur=del->next;
            free(del);
        }
    }
    gh->vertexNum=0;
    free(gh->adjlist);
    gh->adjlist=NULL;
}