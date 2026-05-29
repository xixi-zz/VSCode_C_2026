#include"Queue.h"
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
        // QueueNode*del=q->head;
        // if(q->head==q->tail)
        // q->head=q->tail=NULL;
        // else
        // q->head=q->head->next;
        // free(del);
        // del=NULL;
        //或者
        Pop_Queue(q);
    }
    //第二种 
    // while(q->head)
    // {
    //     QueueNode* del=q->head;
    //     if(q->head==q->tail)
    //     q->head=q->tail=NULL;
    //     else
    //     q->head=q->head->next;
    //     free(del);
    //     del=NULL;
    // }
    //第三种
    // while(q->head!=q->tail)
    // {
    //     QueueNode*del=q->head;
    //     q->head=q->head->next;
    //     free(del);
    //     del=NULL;
    // }
    // QueueNode* del=q->head;
    // q->head=q->tail=NULL;
    // free(del);
    // del=NULL;
}