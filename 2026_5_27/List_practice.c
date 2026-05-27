//https://leetcode.cn/problems/middle-of-the-linked-list/description/
//返回中间结点
typedef struct ListNode ListNode;
struct ListNode* middleNode(struct ListNode* head) {
    ListNode*slow=head;
    ListNode*fast=head;
    while(fast&&fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}


//https://leetcode.cn/problems/remove-linked-list-elements/
//删除链表元素
typedef struct ListNode ListNode;
ListNode* buynode(int ival)
{
    ListNode* newnode=malloc(sizeof(ListNode));
    if(newnode==NULL)
    {
        return NULL;
    }
    newnode->val=ival;
    newnode->next=NULL;
    return newnode;
}
struct ListNode* removeElements(struct ListNode* head, int val) {
    ListNode*ptail=NULL;
    ListNode dummy;
    dummy.next=NULL;
    ListNode*pcur=head;
    while(pcur)
    {
        if(pcur->val!=val)
        {
            ListNode*tmp=buynode(pcur->val);
            if(ptail==NULL)
            {
                ptail=tmp;
                dummy.next=ptail;
            }
            else
            {
                ptail->next=tmp;
                ptail=ptail->next;
            }
        }
        pcur=pcur->next;
    }
    pcur=head;
    while(pcur)
    {
        ListNode*tmp=pcur;
        pcur=pcur->next;
        free(tmp);
        tmp=NULL;
    }
    return dummy.next;
}