#include"List.h"
ListNode*buynode(LDataType x)
{
    ListNode*newnode=(ListNode*)malloc(sizeof(ListNode));
    if(newnode==NULL)
    {
        perror("malloc fail");
        exit(1);
    }
    newnode->data=x;
    newnode->next=NULL;
    return newnode;
}
void Print_List(ListNode* ls)
{
    ListNode*pcur=ls->next;
    while(pcur)
    {
        printf("%d ",pcur->data);
        pcur=pcur->next;
    }
    printf("\n");
}
void PushFront_List(ListNode* ls,LDataType x)
{
    assert(ls);
    ListNode* newnode=buynode(x);
    if(ls->next==NULL)
    {
        ls->next=newnode;
    }
    else
    {
        ListNode*next=ls->next;
        ls->next=newnode;
        newnode->next=next;
    }
}
void PushBack_List(ListNode* ls,LDataType x)
{
    assert(ls);
    ListNode* newnode=buynode(x);
    if(ls->next==NULL)
    {
        ls->next=newnode;
    }
    else
    {
        ListNode* ptail=ls->next;
        while(ptail->next)
        {
            ptail=ptail->next;
        }
        ptail->next=newnode;
        ptail=ptail->next;
        }
}
void PopFront_List(ListNode* ls)
{
    assert(ls);
    assert(ls->next);
    //只有一个节点 
    if(ls->next->next==NULL)
    {
        free(ls->next);
        ls->next=NULL;
    }
    else
    {
        ListNode*next=ls->next->next;
        ListNode*del=ls->next;
        free(del);
        del=NULL;
        ls->next=next;
    }
}
void PopBack_List(ListNode*ls)
{
    assert(ls);
    assert(ls->next);
    if(ls->next->next==NULL)
    {
        free(ls->next);
        ls->next=NULL;
    }
    else
    {
        ListNode* ptail=ls->next;
        while(ptail->next->next)
        {
            ptail=ptail->next;
        }
        ListNode*end=ptail;
        ptail=ptail->next;
        end->next=NULL;
        free(ptail);
        ptail=NULL;
    }
}
ListNode* Find_List(ListNode*ls,LDataType x)
{
    assert(ls);
    ListNode*pcur=ls->next;
    while(pcur)
    {
        if(pcur->data==x)
        {
            return pcur;
        }
        pcur=pcur->next;
    }
    return NULL;
}
void Destory_List(ListNode*ls)
{
    assert(ls);
    ListNode*pcur=ls->next;
    while(pcur)
    {
        ListNode*del=pcur;
        pcur=pcur->next;
        free(del);
        del=NULL;
    }
    ls->next=NULL;
}
