//https://leetcode.cn/problems/maximum-depth-of-binary-tree/?utm_source=chatgpt.com
//二叉树的最大深度
int maxDepth(struct TreeNode* root) {
    if(root==NULL)
    {
        return 0;
    }
    int leftDepth=maxDepth(root->left);
    int rightDepth=maxDepth(root->right);
    return leftDepth>rightDepth?leftDepth+1:rightDepth+1;   
}



//https://leetcode.cn/problems/same-tree/?utm_source=chatgpt.com
//相同的树
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if(p==NULL||q==NULL)
    {
        return p==q;
    }
    //走到这一步p与q均不为空指针
    if(p->val==q->val)
    {
        bool flagleft=isSameTree(p->left,q->left);
        bool flagright=isSameTree(p->right,q->right);
        return flagleft && flagright;
    }
    else
    {
        return false;
    }

}