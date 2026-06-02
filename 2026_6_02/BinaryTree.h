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
}BTNode;

BTNode* buynode(BTDataType x);
void PreOrder(BTNode* root);
void InOrder(BTNode* root);
void PostOrder(BTNode* root);
int TreeSize(BTNode* root);      // 节点个数
int TreeLeafSize(BTNode* root);  // 叶子节点个数
int TreeHeight(BTNode* root);    // 树高度
