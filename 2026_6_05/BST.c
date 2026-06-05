#include"BST.h"
BSTNode* BuyNode(BSTDataType x)
{
    BSTNode* newnode=malloc(sizeof(BSTNode));
    if(newnode==NULL)
    {
        perror("malloc fail");
        exit(1);
    }
    newnode->data=x;
    newnode->left=newnode->right=NULL;
    return newnode;
}

void InOrder(BSTNode* root)
{
    if(root == NULL)
    {
        return;
    }

    InOrder(root->left);
    printf("%d ", root->data);
    InOrder(root->right);
}

bool BSTInsert(BSTNode** proot,BSTDataType x)
{
    if((*proot)==NULL)
    {
        (*proot)=BuyNode(x);
        return true;
    }
    if((*proot)->data>x)
    {
        return BSTInsert(&(*proot)->left,x);
    }
    else if ((*proot)->data<x)
    {
        return BSTInsert(&(*proot)->right,x);
    }
    else
    {
        return false;
    }
}

BSTNode* BSTFind(BSTNode* root,BSTDataType x)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==x)
    {
        return root;
    }
    if(root->data>x)
    {
        return BSTFind(root->left,x);
    }
    else
    {
        return BSTFind(root->right,x);
    }
}

bool BSTErase(BSTNode** proot,BSTDataType x)
{
    assert(proot);
    if((*proot)==NULL)
    {
        return false;
    }
    if((*proot)->data>x)
    {
        return BSTErase(&(*proot)->left,x);
    }
    else if((*proot)->data<x)
    {
        return BSTErase(&(*proot)->right,x);
    }
    else
    {
        BSTNode* del=(*proot);
        if((*proot)->left==NULL)
        {
            (*proot)=(*proot)->right;
            free(del);
            del=NULL;
            return true;
        }
        else if((*proot)->right==NULL)
        {
            (*proot)=(*proot)->left;
            free(del);
            del=NULL;
            return true;
        }
        else
        {
            BSTNode* father=(*proot);
            BSTNode* min=(*proot)->right;
            while(min->left)
            {
                father=min;
                min=min->left;
            }
            del->data=min->data;
            if(father==(*proot))
            {
                father->right=min->right;
            }
            else
            {
                father->left=min->right;
            }
            free(min);
            min=NULL;
            return true;
        }
    }
}