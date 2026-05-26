//https://leetcode.cn/problems/reverse-linked-list/description/
//反转链表
typedef struct ListNode ListNode;
struct ListNode* reverseList(struct ListNode* head) {
    ListNode*pcur=head;
    ListNode*next=head;
    ListNode*newhead=NULL;
    while(pcur)
    {
        next=next->next;
        pcur->next=newhead;
        newhead=pcur;
        pcur=next;
    }
    return newhead;
}