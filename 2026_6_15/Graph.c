#include"Graph.h"


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

void BFS(Graph*gh,int src,bool* visited)
{
    assert(gh);
    Queue q;
    Init_Queue(&q);
    Push_Queue(&q,src);
    visited[src]=true;
    while(!(Empty_Queue(&q)))
    {
        int vertex=Front_Queue(&q);
        Pop_Queue(&q);
        printf("%d ",vertex);
        EdgeNode* pcur=gh->adjlist[vertex];
        while(pcur)
        {
            if(!(visited[pcur->dest]))
            {
                Push_Queue(&q,pcur->dest);
                visited[pcur->dest]=true;
            }
            pcur=pcur->next;
        }
    }
}

void GraphBFS(Graph*gh)
{
    assert(gh);
    bool* visited=(bool*)calloc(gh->vertexNum,sizeof(bool));
    if(visited==NULL)
    {
        perror("calloc fail");
        exit(1);
    }
    for(int i=0;i<gh->vertexNum;i++)
    {
        if(!(visited[i]))
        {
            BFS(gh,i,visited);
        }
    }
    free(visited);
    visited=NULL;
}

void GraphShortestPath(Graph*gh,int src,int dest)
{
    assert(gh);
    int parents[gh->vertexNum];
    for(int i=0;i<gh->vertexNum;i++)
    {
        parents[i]=-1;
    }
    bool* visited=(bool*)calloc(gh->vertexNum,sizeof(bool));
    if(visited==NULL)
    {
        perror("calloc fail");
        exit(1);
    }
    Queue q;
    Init_Queue(&q);
    Push_Queue(&q,src);
    visited[src]=true;
    while(!(Empty_Queue(&q)))
    {
        int vertex=Front_Queue(&q);
        Pop_Queue(&q);
        EdgeNode* pcur=gh->adjlist[vertex];
        if(vertex==dest)
        {
            int pre=dest;
            int count=-1;
            Stack st;
            Init_Stack(&st);
            while(pre!=-1)
            {
                Push_Stack(&st,pre);
                pre=parents[pre];
                count++;
            }
            printf("最短路径为:");
            while(!(Empty_Stack(&st)))
            {
                int top=Top_Stack(&st);
                Pop_Stack(&st);
                printf("%d-",top);
            }
            printf("\n");
            printf("最短路径距离为%d\n",count);
            free(visited);
            visited=NULL;
            return;
        }
        while(pcur)
        {
            if(!(visited[pcur->dest]))
            {
                Push_Queue(&q,pcur->dest);
                parents[pcur->dest]=vertex;
                visited[pcur->dest]=true;
            }
            pcur=pcur->next;
        }
    }
    free(visited);
    visited=NULL;
}

void DFS(Graph* gh,int src,bool* visited)
{
    assert(gh);
    if(visited[src])
    {
        return;
    }
    visited[src]=true;
    printf("%d ",src);
    EdgeNode* pcur=gh->adjlist[src];
    while(pcur)
    {
        if(!(visited[pcur->dest]))
        {
            DFS(gh,pcur->dest,visited);
        }
        pcur=pcur->next;
    }
}

void GraphDFS(Graph*gh)
{
    assert(gh);
    bool* visited=(bool*)calloc(gh->vertexNum,sizeof(bool));
    if(visited==NULL)
    {
        perror("calloc fail");
        exit(1);
    }
    for(int i=0;i<gh->vertexNum;i++)
    {
        if(!(visited[i]))
        {
            DFS(gh,i,visited);
        }
    }
    free(visited);
    visited=NULL;
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












QueueNode* QBuyNode(QDatatype x)
{
    QueueNode*newnode=(QueueNode*)malloc(sizeof(QueueNode));
    if(newnode==NULL)
    {
        perror("malloc fail");
        exit(1);
    }
    newnode->data=x;
    newnode->next=NULL;
    return newnode;
}
bool Empty_Queue(Queue*q)
{
    return q->head==NULL;
}
void Init_Queue(Queue*q)
{
    assert(q);
    q->head=q->tail=NULL;
}
void Push_Queue(Queue*q,QDatatype x)
{
    assert(q);
    if(q->head==NULL)
    {
        q->head=q->tail=QBuyNode(x);
        return;
    }
    q->tail->next=QBuyNode(x);
    q->tail=q->tail->next;//尾插
}
void Pop_Queue(Queue*q)
{
    assert(q);
    assert(!(Empty_Queue(q)));
    QueueNode* del=q->head;
    if(q->head==q->tail)
        q->head=q->tail=NULL;
    else
        q->head=q->head->next;
    free(del);
    del=NULL;
}
QDatatype Front_Queue(Queue*q)
{
    assert(q);
    assert(!(Empty_Queue(q)));
    return q->head->data;
}
QDatatype Back_Queue(Queue*q)
{
    assert(q);
    assert(!(Empty_Queue(q)));
    return q->tail->data;
}
void Destory_Queue(Queue*q)
{
    assert(q);
    // 第一种    
    while(!(Empty_Queue(q)))
    {
        Pop_Queue(q);
    }
}





void Init_Stack(Stack* st)
{
    assert(st);
    st->capacity=4;
    st->top=0;
    st->data=malloc(sizeof(SDatatype)*st->capacity);
    if(st->data==NULL)
    {
        perror("malloc fail");
        exit(1);
    }
}
bool Empty_Stack(Stack* st)
{
    assert(st);
    return st->top==0;
}
void Push_Stack(Stack* st,SDatatype x)
{
    assert(st);
    if(st->top==st->capacity)
    {
        int newcapacity=st->capacity*2;
        SDatatype*tmp=realloc(st->data,sizeof(SDatatype)*newcapacity);
        if(tmp==NULL)
        {
            perror("realloc fail");
            exit(1);
        }
        st->capacity=newcapacity;
        st->data=tmp;
    }
    st->data[st->top]=x;
    st->top++;
}
void Pop_Stack(Stack* st)
{
    assert(st);
    assert(!(Empty_Stack(st)));
    st->top--;
}

SDatatype Top_Stack(Stack* st)
{
    assert(st);
    assert(!(Empty_Stack(st)));
    return st->data[st->top-1];
}
int Size_Stack(Stack*st)
{
    assert(st);
    return st->top;
}
void Destory_Stack(Stack* st)
{
    assert(st);
    free(st->data);
    st->data=NULL;
    st->capacity=st->top=0;
}