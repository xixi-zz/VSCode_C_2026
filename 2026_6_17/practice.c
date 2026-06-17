//https://leetcode.cn/problems/rotting-oranges/?utm_source=chatgpt.com
//腐烂的橘子
const int dx[4]={-1,0,0,1};
const int dy[4]={0,-1,1,0};

int n,m;

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
    int size;
}Queue;
void Init_Queue(Queue*q);
void Push_Queue(Queue* q,QDatatype x);
void Pop_Queue(Queue*q);
bool Empty_Queue(Queue*q);
QDatatype Front_Queue(Queue*q);
QDatatype Back_Queue(Queue*q);
void Destory_Queue(Queue*q);




int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    n=gridSize;
    m=gridColSize[0];
    Queue q;
    Init_Queue(&q);
    int minites=0;
    int refresh=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==2)
            {
                Push_Queue(&q,i*m+j);
            }
            else if(grid[i][j]==1)
            {
                refresh++;
            }
        }
    }
    int size=q.size;
    while(!(Empty_Queue(&q))&&refresh>0)
    {
        for(int i=0;i<size;i++)
        {
            int top=Front_Queue(&q);
            int x=top/m;
            int y=top%m;
            Pop_Queue(&q);
            for(int i=0;i<4;i++)
            {
                int kx=x+dx[i];
                int ky=y+dy[i];
                if(kx>=0&&kx<n&&ky>=0&&ky<m&&grid[kx][ky]==1)
                {
                    Push_Queue(&q,kx*m+ky);
                    grid[kx][ky]=2;
                    refresh--;
                }
            }
        }
        minites++;
        size=q.size;
    }
    if(refresh>0)
    {
        return -1;
    }
    return minites;
}
