//https://leetcode.cn/problems/insert-into-a-binary-search-tree/description/?utm_source=chatgpt.com
//二叉搜索树中的插入操作
typedef struct TreeNode TreeNode;
TreeNode* buynode(int val)
{
    TreeNode* newnode=malloc(sizeof(TreeNode));
    if(newnode==NULL)
    {
        perror("malloc fail");
        exit(1);
    }
    newnode->val=val;
    newnode->left=newnode->right=NULL;
    return newnode;
}
void insert(TreeNode* root,int val)
{
    if(root->val>val&&root->left==NULL)
    {
        root->left=buynode(val);
        return;
    }
    else if(root->val>val)
    {
        insert(root->left,val);
    }
    else if(root->val<val&&root->right==NULL)
    {
        root->right=buynode(val);
        return;
    }
    else if(root->val<val)
    {
        insert(root->right,val);
    }
    else
    {
        return;
    }
}
struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    if(root==NULL)
    {
        root=buynode(val);
        return root;
    }
    insert(root,val);
    return root;
}





//https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/description/?utm_source=chatgpt.com
//二叉搜索树最近的公共祖先
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if(root->val<p->val&&root->val<q->val)
    {
        return lowestCommonAncestor(root->right,p,q);
    }
    else if(root->val>p->val&&root->val>q->val)
    {
        return lowestCommonAncestor(root->left,p,q);
    }
    return root;
}




//https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/description/?utm_source=chatgpt.com
//二叉树最近的公共祖先
typedef struct TreeNode TreeNode;
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if(!root||root==p||root==q)
    {
        return root;
    }
    TreeNode* left=lowestCommonAncestor(root->left,p,q);
    TreeNode* right=lowestCommonAncestor(root->right,p,q);
    //如果同侧只会有一个left或者right如果异侧两个都存在
    if(left&&right)
    {
        return root;
    }
    return left?left:right;
}


//https://leetcode.cn/problems/diameter-of-binary-tree/description/?utm_source=chatgpt.com
//二叉树的直径
typedef struct TreeNode TreeNode;
int height(TreeNode* root,int* max)
{
    if(root==NULL)
    {
        return 0;
    }
    int left=height(root->left,max);
    int right=height(root->right,max);
    if(left+right>*max)
    {
        *max=left+right;
    }
    return left>right?left+1:right+1;
}
int diameterOfBinaryTree(struct TreeNode* root) {
    int max=0;
    height(root,&max);
    return max;
}