#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
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