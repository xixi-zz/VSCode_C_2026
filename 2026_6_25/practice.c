//https://leetcode.cn/problems/binary-tree-right-side-view/description/?utm_source=chatgpt.com
//二叉树的右视图
int* rightSideView(struct TreeNode* root, int* returnSize) {
    if(root==NULL)
    {
        *returnSize=0;
        return NULL;
    }
    Queue q;
    Init_Queue(&q);
    Push_Queue(&q,root);
    int* ret=malloc(sizeof(int)*100);
    if(ret==NULL)
    {
        perror("malloc fail");
        exit(1);
    }
    int level=0;
    while(!(Empty_Queue(&q)))
    {
        int size=q.size;
        TreeNode* top;
        for(int i=0;i<size;i++)
        {
            top=Front_Queue(&q);
            Pop_Queue(&q);
            if(top->left)
            {
                Push_Queue(&q,top->left);
            }
            if(top->right)
            {
                Push_Queue(&q,top->right);
            }
        }
        ret[level]=top->val;
        level++;
    }
    *returnSize=level;
    return ret;
}





//https://leetcode.cn/problems/binary-tree-level-order-traversal/description/?utm_source=chatgpt.com
//二叉树的层序遍历
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
   if(root==NULL)
   {
    *returnSize=0;
    *returnColumnSizes=NULL;
    return NULL;
   }
   int **ret=malloc(sizeof(int*)*2000);
   *returnColumnSizes=malloc(sizeof(int*)*2000);
   int level=0;
   Queue q;
   Init_Queue(&q);
   Push_Queue(&q,root);
   while(!(Empty_Queue(&q)))
   {
    int size=q.size;
    ret[level]=malloc(sizeof(int)*size);
    (*returnColumnSizes)[level]=size;
    for(int i=0;i<size;i++)
    {
        TreeNode* top=Front_Queue(&q);
        Pop_Queue(&q);
        ret[level][i]=top->val;
        if(top->left!=NULL)
        {
            Push_Queue(&q,top->left);
        }
        if(top->right!=NULL)
        {
            Push_Queue(&q,top->right);
        }
    }
    level++;
   }
   *returnSize=level;
   return ret;
}




//https://leetcode.cn/problems/average-of-levels-in-binary-tree/description/
//二叉树的层平均值
double* averageOfLevels(struct TreeNode* root, int* returnSize) {
    int level=0;
    *returnSize=level;
    if(root==NULL)
    {
        return NULL;
    }
    double*ret=malloc(sizeof(double)*10000);
    Queue q;
    Init_Queue(&q);
    Push_Queue(&q,root);
    while(!(Empty_Queue(&q)))
    {
        int size=q.size;
        double sum=0.0;
        for(int i=0;i<size;i++)
        {
            TreeNode* top=Front_Queue(&q);
            Pop_Queue(&q);
            sum+=top->val;
            if(top->left)
            {
                Push_Queue(&q,top->left);
            }
            if(top->right)
            {
                Push_Queue(&q,top->right);
            }
        }
        ret[level]=sum/size;
        level++;
    }
    *returnSize=level;
    return ret;
}



//https://leetcode.cn/problems/search-in-a-binary-search-tree/description/?utm_source=chatgpt.com
//二叉搜索树中的搜索    
struct TreeNode* searchBST(struct TreeNode* root, int val) {
    if(root==NULL)
    {
        return NULL;
    }
    if(root->val==val)
    {
        return root;
    }
    if(root->val>val)
    {
        return searchBST(root->left,val);
    }
    else
    {
        return searchBST(root->right,val);
    }
}







//https://leetcode.cn/problems/minimum-absolute-difference-in-bst/description/?utm_source=chatgpt.com
//二叉搜索树的绝对最小值
typedef struct TreeNode TreeNode;
void inorder(TreeNode* root,int* pre,int* min)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left,pre,min);
    if(*pre==-1)
    {
        *pre=root->val;
    }
    else
    {
        int differ=root->val-*pre;
        if(differ<*min)
        *min=differ;
        *pre=root->val;
    }
    inorder(root->right,pre,min);
}
int getMinimumDifference(struct TreeNode* root) {
   int min=100000;
   int pre=-1;
   inorder(root,&pre,&min);
   return min;
}






//https://leetcode.cn/problems/validate-binary-search-tree/description/?utm_source=chatgpt.com
//验证二叉搜索树
typedef struct TreeNode TreeNode;
bool inorder(TreeNode* root,TreeNode** pre)
{
    if(root==NULL)
    {
        return true;
    }
    if(!inorder(root->left,pre))
    {
        return false;
    }
    if(*pre==NULL)
    {
        *pre=root;
    }
    else
    {
        if(root->val<=(*pre)->val)
        {
            return false;
        }
        *pre=root;
    }
    if(!(inorder(root->right,pre)))
    {
        return false;
    }
    return true;
}
bool isValidBST(struct TreeNode* root) {
    TreeNode* pre=NULL;
    return inorder(root,&pre);
}