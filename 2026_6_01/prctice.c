//https://leetcode.cn/problems/implement-queue-using-stacks/description/
//用栈实现队列
typedef int SDatatype;
typedef struct Stack
{
    SDatatype *data;
    int top;
    int capacity;
}Stack;
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


typedef struct {
    Stack s1;
    Stack s2;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* obj=malloc(sizeof(MyQueue));
    if(obj==NULL)
    {
        perror("malloc fail");
        exit(1);
    }
    Init_Stack(&obj->s1);
    Init_Stack(&obj->s2);
    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
   Push_Stack(&obj->s1,x);
}

int myQueuePop(MyQueue* obj) {
    if(!(Empty_Stack(&obj->s2)))
    {
        int top=Top_Stack(&obj->s2);
        Pop_Stack(&obj->s2);
        return top;
    }
    else
    {
        while(!(Empty_Stack(&obj->s1)))
        {
            int top=Top_Stack(&obj->s1);
            Push_Stack(&obj->s2,top);
            Pop_Stack(&obj->s1);
        }
        int top=Top_Stack(&obj->s2);
        Pop_Stack(&obj->s2);
        return top;
    }
}

int myQueuePeek(MyQueue* obj) {
    if(!(Empty_Stack(&obj->s2)))
    {
        return Top_Stack(&obj->s2);
    }
    else
    {
        while(!(Empty_Stack(&obj->s1)))
        {
            int top=Top_Stack(&obj->s1);
            Push_Stack(&obj->s2,top);
            Pop_Stack(&obj->s1);
        }
        return Top_Stack(&obj->s2);
    }
}

bool myQueueEmpty(MyQueue* obj) {
    return Empty_Stack(&obj->s1)&&Empty_Stack(&obj->s2);
}

void myQueueFree(MyQueue* obj) {
    Destory_Stack(&obj->s1);
    Destory_Stack(&obj->s2);
    free(obj);
    obj=NULL;
}





//https://leetcode.cn/problems/implement-stack-using-queues/
//用队列实现栈
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
QueueNode* BuyNode(QDatatype x)
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
        q->head=q->tail=BuyNode(x);
        return;
    }
    q->tail->next=BuyNode(x);
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

typedef struct {
    Queue*q1;
    Queue*q2;
} MyStack;


MyStack* myStackCreate() {
    MyStack* obj=malloc(sizeof(MyStack));
    if(obj==NULL)
    {
        perror("malloc fail");
        exit(1);
    }
    obj->q1=malloc(sizeof(Queue));
    if(obj->q1==NULL)
    {
        perror("malloc fail");
        exit(1);
    }
    obj->q2=malloc(sizeof(Queue));
    if(obj->q2==NULL)
    {
        perror("malloc fail");
        exit(1);
    }
    Init_Queue(obj->q1);
    Init_Queue(obj->q2);
    return obj;
}

void myStackPush(MyStack* obj, int x) {
    if(Empty_Queue(obj->q1)&&Empty_Queue(obj->q2))
    {
        Push_Queue(obj->q1,x);
    }
    else if (!(Empty_Queue(obj->q1)))
    {
        Push_Queue(obj->q1,x);
    }
    else
    {
        Push_Queue(obj->q2,x);
    }
}

int myStackPop(MyStack* obj) {
    if(!(Empty_Queue(obj->q1)))
    {
        while(obj->q1->head!=obj->q1->tail)
        {
            int top=Front_Queue(obj->q1);
            Push_Queue(obj->q2,top);
            Pop_Queue(obj->q1);
            
        }
        int top=Front_Queue(obj->q1);
        Pop_Queue(obj->q1);
        return top;
    }
    else
    {
        while(obj->q2->head!=obj->q2->tail)
        {
            int top=Front_Queue(obj->q2);
            Push_Queue(obj->q1,top);
            Pop_Queue(obj->q2);
        }
        int top=Front_Queue(obj->q2);
        Pop_Queue(obj->q2);
        return top;
    }
}

int myStackTop(MyStack* obj) {
    if(!(Empty_Queue(obj->q1)))
    {
        return Back_Queue(obj->q1);
    }
    else
    {
        return Back_Queue(obj->q2);
    }
}

bool myStackEmpty(MyStack* obj) {
    return Empty_Queue(obj->q1)&&Empty_Queue(obj->q2);
}

void myStackFree(MyStack* obj) {
    Destory_Queue(obj->q1);
    free(obj->q1);
    obj->q1=NULL;
    Destory_Queue(obj->q2);
    free(obj->q2);
    obj->q2=NULL;
    free(obj);
    obj=NULL;
}