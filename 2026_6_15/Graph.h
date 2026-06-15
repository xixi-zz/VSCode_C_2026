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
void BFS(Graph*gh,int src,bool* visited);
void GraphBFS(Graph*gh);
void GraphShortestPath(Graph*gh,int src,int dest);
void DFS(Graph*gh,int src,bool* visited);
void GraphDFS(Graph*gh);













//队列
typedef int QDatatype;
typedef struct QueueNode
{
    QDatatype data;
    struct QueueNode* next;
}QueueNode;
typedef struct Queue
{
    struct QueueNode* head;
    struct QueueNode* tail;
}Queue;


void Init_Queue(Queue*q);
void Push_Queue(Queue* q,QDatatype x);
void Pop_Queue(Queue*q);
bool Empty_Queue(Queue*q);
QDatatype Front_Queue(Queue*q);
QDatatype Back_Queue(Queue*q);
void Destory_Queue(Queue*q);


//栈
typedef int SDatatype;
typedef struct Stack
{
    SDatatype *data;
    int top;
    int capacity;
}Stack;
void Init_Stack(Stack* st);
void Push_Stack(Stack* st,SDatatype x);
void Pop_Stack(Stack* st);
SDatatype Top_Stack(Stack* st);
bool Empty_Stack(Stack* st);
int Size_Stack(Stack* st);
void Destory_Stack(Stack* st);