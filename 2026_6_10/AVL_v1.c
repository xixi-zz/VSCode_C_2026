#include"AVL_v1.h"
BTNode* BuyNode(BTDataType x)
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
int Height(BTNode* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int leftheight=1+Height(root->left);
    int rightheight=1+Height(root->right);
    return leftheight>rightheight?leftheight:rightheight;
}

int Balance(BTNode* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return Height(root->left)-Height(root->right);
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
    if(root == NULL)
    {
        return;
    }

    InOrder(root->left);
    printf("%d ", root->data);
    InOrder(root->right);
}

void RotateR(BTNode** proot)
{
    assert(proot);
    assert((*proot));
    assert((*proot)->left);
    BTNode* left=(*proot)->left;
    (*proot)->left=left->right;
    left->right=(*proot);
    (*proot)=left;
}

void RotateL(BTNode** proot)
{
    assert(proot);
    assert((*proot));
    assert((*proot)->right);
    BTNode* right=(*proot)->right;
    (*proot)->right=right->left;
    right->left=(*proot);
    (*proot)=right;
}

void RotateRL(BTNode** proot)
{
    assert(proot);
    assert((*proot));
    assert((*proot)->right);
    RotateR(&(*proot)->right);
    RotateL(proot);
}

void RotateLR(BTNode** proot)
{
    assert(proot);
    assert((*proot));
    assert((*proot)->left);
    RotateL(&(*proot)->left);
    RotateR(proot);
}

void AVLInsert(BTNode** proot,BTDataType x)
{
    assert(proot);
    if((*proot)==NULL)
    {
        *proot=BuyNode(x);
        return;
    }
    if((*proot)->data>x)
    {
        AVLInsert(&(*proot)->left,x);
    }
    else if((*proot)->data<x)
    {
        AVLInsert(&(*proot)->right,x);
    }
    else
    {
        return;
    }
    //更新平衡因子
    int balance=Balance((*proot));
    //插入完后检查平衡因子
    if(balance>1)
    {
        int leftbalance=Balance((*proot)->left);
        if(leftbalance>=0)//LL
        {
            RotateR(proot);
        }
        else
        {
            RotateLR(proot);
        }
    }
    else if(balance<-1)
    {
        int rightbalance=Balance((*proot)->right);
        if(rightbalance<=0)//RR
        {
            RotateL(proot);
        }
       else
       {
            RotateRL(proot);
       }
    }
}