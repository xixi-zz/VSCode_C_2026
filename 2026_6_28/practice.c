//https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/?utm_source=chatgpt.com
//用前序和中序遍历构造二叉树
typedef struct TreeNode TreeNode;
TreeNode* buynode(int x)
{
    TreeNode*newnode=malloc(sizeof(TreeNode));
    if(newnode==NULL)
    {
        perror("malloc fail");
        exit(1);
    }
    newnode->left=NULL;
    newnode->right=NULL;
    newnode->val=x;
    return newnode;
}
TreeNode* build(int* preorder,int preL,int preR,int* inorder,int inL,int inR)
{
    if(preL>preR)
    {
        return NULL;
    }
    TreeNode*root=buynode(preorder[preL]);
    int k=inL;
    while(inorder[k]!=preorder[preL])
    {
        k++;
    }
    int leftsize=k-inL;
    root->left=build(preorder,preL+1,preL+leftsize,inorder,inL,k-1);
    root->right=build(preorder,preL+leftsize+1,preR,inorder,k+1,inR);
    return root;
}
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    int preL=0;
    int preR=preorderSize-1;
    int inL=0;
    int inR=inorderSize-1;
    return build(preorder,preL,preR,inorder,inL,inR);
}







//https://leetcode.cn/problems/binary-tree-maximum-path-sum/description/?utm_source=chatgpt.com
//二叉树中的最大路径和
typedef struct TreeNode TreeNode;
int max;
int dfs(TreeNode* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int left=dfs(root->left);
    int right=dfs(root->right);
    int cmp=left>right?left:right;
    if(root->val>max)
    {
        max=root->val;
    }
    if(root->val+cmp>max)
    {
        max=root->val+cmp;
    }
    if(root->val+left+right>max)
    {
        max=root->val+left+right;
    }
    return root->val>root->val+cmp?root->val:root->val+cmp;
}
int maxPathSum(struct TreeNode* root) {
    max=-1001;
    dfs(root);
    return max;
}