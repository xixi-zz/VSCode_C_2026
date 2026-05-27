#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int LDataType;
typedef struct ListNode
{
    LDataType data;
    struct ListNode* next;
    
}ListNode;

void PushFront_List(ListNode* ls,LDataType x);
void PushBack_List(ListNode* ls,LDataType x);
void PopFront_List(ListNode* ls);
void PopBack_List(ListNode* ls);
ListNode* Find_List(ListNode* ls,LDataType x);
void Print_List(ListNode*ls);
void Destory_List(ListNode* ls);