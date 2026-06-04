#include"BinaryTree_v1.h"
BTNode* buynode(BTDataType x)
{
    BTNode* newnode=malloc(sizeof(BTNode));
    if(newnode==NULL)
    {
        perror("malloc fail");
        exit(1);
    }
    newnode->data=x;
    newnode->left=newnode->right=NULL;
    return newnode;
}
void PreOrder(BTNode* root)
{
    if(root==NULL)
    {
        return;
    }
    printf("%d ",root->data);
    PreOrder(root->left);
    PreOrder(root->right);
}

void InOrder(BTNode* root)
{
    if(root==NULL)
    {
        return;
    }
    InOrder(root->left);
    printf("%d ",root->data);
    InOrder(root->right);
}

void PostOrder(BTNode* root)
{
    if(root==NULL)
    {
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%d ",root->data);
}

int TreeSize(BTNode* root)
{
    int LeftSize=0;
    int RightSize=0;
    if(root==NULL)
    {
        return 0;
    }
    LeftSize=TreeSize(root->left);
    RightSize=TreeSize(root->right);
    return LeftSize+RightSize+1;
}
int TreeLeafSize(BTNode* root)
{
    if(root==NULL)
    {
        return 0;
    }
    if((root->left==NULL)&&(root->right==NULL))
    {
        return 1;
    }
    int LeftLeaf=TreeLeafSize(root->left);
    int RightLeaf=TreeLeafSize(root->right);
    return RightLeaf+LeftLeaf;
}

int TreeHeight(BTNode* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int LeftHeight=TreeHeight(root->left)+1;
    int RightHeight=TreeHeight(root->right)+1;
    return LeftHeight>RightHeight?LeftHeight:RightHeight;
}


BTNode* TreeFind(BTNode* root, BTDataType x)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==x)
    {
        return root;
    }
    BTNode*Left=TreeFind(root->left,x);
    if(Left)
    {
        return Left;
    }
    BTNode*Right=TreeFind(root->right,x);
    if(Right)
    {
        return Right;
    }
    return NULL;
}
void TreeDestroy(BTNode* root)
{
    if(root==NULL)
    {
        return;
    }
    TreeDestroy(root->left);
    TreeDestroy(root->right);
    free(root);
}
int TreeKLevelSize(BTNode* root, int k)
{
    if(root==NULL)
    {
        return 0;
    }
    if(k<1)
    {
        return 0;
    }
    if(k==1)
    {
        return 1;
    }
    int LeftK=TreeKLevelSize(root->left,k-1);
    int RightK=TreeKLevelSize(root->right,k-1);
    return LeftK+RightK;
}
void LevelOrder(BTNode* root)
{
    if(root==NULL)
    {
        return;
    }
    Queue qt;
    Init_Queue(&qt);
    Push_Queue(&qt,root);
    while(!(Empty_Queue(&qt)))
    {
        BTNode*top=Front_Queue(&qt);
        Pop_Queue(&qt);
        printf("%d ",top->data);
       
        if(top->left)
        {
            Push_Queue(&qt,top->left);
        }
        if(top->right)
        {
            Push_Queue(&qt,top->right);
        }
    }
    Destory_Queue(&qt);
}

bool TreeEqual(BTNode* root1, BTNode* root2)
{
    if(root1==NULL&&root2==NULL)
    {
        return true;
    }
    if(root1==NULL||root2==NULL)
    {
        return false;
    }
    return root1->data==root2->data
    &&TreeEqual(root1->left,root2->left)
    &&TreeEqual(root1->right,root2->right);
}