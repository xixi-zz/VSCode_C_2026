#include"Binarytree.h"
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