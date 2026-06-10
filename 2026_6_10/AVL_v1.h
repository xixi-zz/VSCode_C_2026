#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef int BTDataType;
typedef struct BinaryTreeNode
{
    BTDataType data;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
    int hight;
}BTNode;

void PreOrder(BTNode* root);
void InOrder(BTNode* root);
void RotateR(BTNode** proot);
void RotateL(BTNode** proot);
void RotateRL(BTNode** proot);
void RotateLR(BTNode** proot);
void AVLInsert(BTNode** proot,BTDataType x);

