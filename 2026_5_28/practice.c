//https://leetcode.cn/problems/remove-nth-node-from-end-of-list/description/?utm_source=chatgpt.com
//删除链表倒数第N个节点
typedef struct ListNode ListNode;
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    ListNode dummy;
    dummy.next=head;
    ListNode*slow=&dummy;
    ListNode*fast=&dummy;
    for(int i=0;i<n;i++)
    {
        fast=fast->next;
    }
    while(fast->next)
    {
        fast=fast->next;
        slow=slow->next;
    }
    ListNode*del=slow->next;
    slow->next=del->next;
    free(del);
    del=NULL;
    return dummy.next;
}

//https://leetcode.cn/problems/linked-list-cycle/submissions/727765398/?utm_source=chatgpt.com
//环形链表
typedef struct ListNode ListNode;
bool hasCycle(struct ListNode *head) {
    ListNode*slow=head;
    ListNode*fast=head;
    while(fast&&fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            return true;
        }
    }
    return false;
}


//https://leetcode.cn/problems/linked-list-cycle-ii/description/?utm_source=chatgpt.com
//环形链表II    
typedef struct ListNode ListNode;
struct ListNode *detectCycle(struct ListNode *head) {
    ListNode*slow=head;
    ListNode*fast=head;
    while(fast&&fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)//证明有环
        {
            slow=head;
            while(slow!=fast)
            {
                slow=slow->next;
                fast=fast->next;
            }
            return slow;
        }
    }
    return NULL;
}


//https://leetcode.cn/problems/intersection-of-two-linked-lists/?utm_source=chatgpt.com
//相交链表
typedef struct ListNode ListNode;
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    ListNode*pcur=headA;
    int distance=0;
    while(pcur)
    {
        distance++;
        pcur=pcur->next;
    }
    pcur=headB;
    while(pcur)
    {
        distance--;
        pcur=pcur->next;
    }
    ListNode*slow;
    ListNode*fast;
    if(distance>0)
    {
        fast=headA;
        slow=headB;
        for(int i=0;i<distance;i++)
        {
            fast=fast->next;
        }
    }
    else
    {
        fast=headB;
        slow=headA;
        for(int i=0;i<abs(distance);i++)
        {
            fast=fast->next;
        }
    }
    while(slow)
    {
        if(slow==fast)
        {
            return slow;
        }
        slow=slow->next;
        fast=fast->next;
    }
    return NULL;
}