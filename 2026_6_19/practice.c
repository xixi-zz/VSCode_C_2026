//https://leetcode.cn/problems/symmetric-tree/
//对称二叉树
typedef struct TreeNode TreeNode;
bool isMirror(TreeNode*p,TreeNode*q)
{
    if(p==NULL||q==NULL)
    {
        return p==q;
    }
    if(p->val==q->val)
    {
        bool flagL=isMirror(p->left,q->right);
        bool flagR=isMirror(p->right,q->left);
        return flagL&&flagR;
    }
    else
    {
        return false;
    }
}
bool isSymmetric(struct TreeNode* root) {
    if(root==NULL)
    {
        return true;
    }
    return isMirror(root->left,root->right);
}




//https://leetcode.cn/problems/invert-binary-tree/
//翻转二叉树
typedef struct TreeNode TreeNode;
struct TreeNode* invertTree(struct TreeNode* root) {
    if(root==NULL)
    {
        return root;
    }
    invertTree(root->left);
    invertTree(root->right);
    TreeNode* tmp=root->left;
    root->left=root->right;
    root->right=tmp;
    return root;

}





//https://leetcode.cn/problems/balanced-binary-tree/?utm_source=chatgpt.com
//平衡二叉树    
typedef struct TreeNode TreeNode;
int height(TreeNode*root)
{
    if(root==NULL)
    {
        return 0;
    }
    int left=height(root->left);
    if(left==-1)
    {
        return -1;
    }
    int right=height(root->right);
    if(right==-1)
    {
        return -1;
    }
    if(abs(left-right)>1)
    {
        return -1;
    }
    return (left>right?left:right)+1;
}
bool isBalanced(struct TreeNode* root) {
    if(root==NULL)
    {
        return true;
    }
    return height(root)!=-1;
}




//https://leetcode.cn/problems/minimum-depth-of-binary-tree/description/?utm_source=chatgpt.com
//二叉树的最小深度  
typedef struct TreeNode TreeNode;
int minDepth(struct TreeNode* root) {
    if(root==NULL)
    {
        return 0;
    }
    if(root->left==NULL&&root->right==NULL)
    {
        return 1;
    }
    //走到这一步为非叶子结点(要么有两个孩子要么只有一个)
    if(root->left==NULL)
    {
        return minDepth(root->right)+1;
    }
    if(root->right==NULL)
    {
        return minDepth(root->left)+1;
    }
    int minDepthL=minDepth(root->left);
    int minDepthR=minDepth(root->right);
    return (minDepthL<minDepthR?minDepthL:minDepthR)+1;
}



//https://leetcode.cn/problems/path-sum/
//路径总和
typedef struct TreeNode TreeNode;
bool hasPathSum(struct TreeNode* root, int targetSum) {
    if(root==NULL)
    {
        return false;
    }
    if(root->left==NULL&&root->right==NULL)
    {
        return targetSum-root->val==0;
    }
    return hasPathSum(root->left,targetSum-root->val)||hasPathSum(root->right,targetSum-root->val);
}