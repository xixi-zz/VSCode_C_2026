//算法练习之重复标记
//找到所有数组中消失的数字
//https://leetcode.cn/problems/find-all-numbers-disappeared-in-an-array/?envType=problem-list-v2&envId=shujujiegouyusuanfa-xianxingqiantan-shuzu-ii
int* findDisapperNumbers(int* nums, int numsSize,int* returnSize)
{
    for(int i=0;i<numsSize;i++)
    {
        int x=(nums[i]-1)%numsSize;
        if(nums[x]<=numsSize)
        {
            nums[x]+=numsSize;
        }
    }
    *returnSize=0;
    int* ans=(int*)malloc(sizeof(int)*numsSize);
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]<=numsSize)
        ans[*returnSize++]=i+1;
    }
    return ans;
}
//变式练习：找到所有数组中重复的数字
int* findRepeatNumbers(int* nums, int numsSize, int* returnSize) {
  *returnSize=0;
  int* ans=(int*)malloc(sizeof(int)*numsSize);
  for(int i=0;i<numsSize;i++)
  {
    int x=(nums[i]-1)%numsSize;
    if(nums[x]>numsSize)
    {
        ans[(*returnSize)++]=x+1;
    }
    else
    {
        nums[x]+=numsSize;
    }
  }
  return ans;
}