//https://leetcode.cn/problems/two-sum/?envType=problem-list-v2&envId=hash-table
//哈希表练习两数之和
typedef struct HashNode
 {
    int val;
    int key;
    struct HashNode* next;
 } HashNode;
 #define N 10000
 HashNode* buynode(int val,int key)
 {
    HashNode* newnode=malloc(sizeof(HashNode));
    if(newnode==NULL)
    {
        perror("malloc fail");
        exit(1);
    }
    newnode->val=val;
    newnode->key=key;
    newnode->next=NULL;
    return newnode;
 }
 int findhash(int ival,HashNode* table[])
 {
    int index=abs(ival)%N;
    HashNode*cur=table[index];
    while(cur)
    {
        if(cur->val==ival)
        return cur->key;
        else
        cur=cur->next;
    }
    return -1;
 }
 int hash(int n)
 {
    return abs(n)%N;
 }
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    HashNode* table[N];
    for(int i=0;i<N;i++)
    {
        table[i]=NULL;
    }
    for(int i=0;i<numsSize;i++)
    {
        int find=findhash(target-nums[i],table);
        if(find<0)
        {
            HashNode* tmp=buynode(nums[i],i);
            int index=hash(nums[i]);
            tmp->next=table[index];
            table[index]=tmp;
        }
        else
        {
            int* ret=malloc(sizeof(int)*2);
            *returnSize=2;
            ret[0]=find;
            ret[1]=i;
            return ret;
        }
    }
    *returnSize=0;
    return NULL;    
}

//https://leetcode.cn/problems/majority-element/?envType=problem-list-v2&envId=hash-table
//寻找多数元素
int majorityElement(int* nums, int numsSize) {
    int flag=nums[0];
    int count=1;
    for(int i=1;i<numsSize;i++)
    {
        if(flag==nums[i])
        {
            count++;
        }
        else
        {
            if(count==0)
            {
                flag=nums[i];
                count=1;
            }
            count--;
        }
    }
    return flag;
}