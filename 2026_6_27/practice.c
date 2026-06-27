//https://leetcode.cn/problems/sum-of-left-leaves/description/?utm_source=chatgpt.com
//左叶子之和
typedef struct TreeNode TreeNode;
int sumOfLeftLeaves(struct TreeNode* root) {
    if(root==NULL)
    {
        return 0;
    }
    int sumleft=0;
    int sumright=0;
    if(root->left)
    {
        TreeNode* left=root->left;
        if((!(left->left))&&(!(left->right)))
        {
            sumleft=left->val;
        }
        else
        {
            sumleft=sumOfLeftLeaves(root->left);
        }
    }
    sumright=sumOfLeftLeaves(root->right);
    return sumleft+sumright;
}



//https://leetcode.cn/problems/path-sum-ii/description/?utm_source=chatgpt.com
//路径总和  
typedef struct TreeNode TreeNode;
int**ret;
int retsize;
int* retColSize;
int* path;
int pathsize;

void dfs(TreeNode* root, int targetSum)
{
    if(root==NULL)
    {
        return;
    }
    path[pathsize++]=root->val;
    targetSum-=root->val;
    if((!(root->left))&&(!(root->right))&&targetSum==0)
    {
        int* tmp=malloc(sizeof(int)*pathsize);
        for(int i=0;i<pathsize;i++)
        {
            tmp[i]=path[i];
        }
        ret[retsize]=tmp;
        retColSize[retsize++]=pathsize;
    }
    dfs(root->left,targetSum);
    dfs(root->right,targetSum);
    pathsize--;
}
int** pathSum(struct TreeNode* root, int targetSum, int* returnSize, int** returnColumnSizes) {
    if(root==NULL)
    {
        *returnSize=0;
        *returnColumnSizes=NULL;
        return NULL;
    }
    ret=malloc(sizeof(int*)*5000);
    retColSize=malloc(sizeof(int)*5000);   
    path=malloc(sizeof(int)*5000);
    retsize=0;
    pathsize=0;
    dfs(root,targetSum);
    *returnSize=retsize;
    *returnColumnSizes=retColSize;
    free(path);
    return ret;
}








//https://leetcode.cn/problems/find-bottom-left-tree-value/description/?utm_source=chatgpt.com
//找树左下角的值
int depth;
int maxdepth;
typedef struct TreeNode TreeNode;
//找高度并返回最底层的最左边的值
void dfs(TreeNode* root,int*BL)
{
    if(root==NULL)
    {
        return;
    }
    depth++;
    dfs(root->left,BL);
    dfs(root->right,BL);
    if(root->left==NULL&&root->right==NULL)
    {
        if(depth>maxdepth)
        {
            maxdepth=depth;
            *BL=root->val;
        }
    }
    depth--;
}
int findBottomLeftValue(struct TreeNode* root) {
    depth=0;
    maxdepth=0;
    int BL=root->val;
    dfs(root,&BL);
    return BL;
}