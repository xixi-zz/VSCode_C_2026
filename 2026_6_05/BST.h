#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef int BSTDataType;
typedef struct BSTNode
{
    BSTDataType data;
    struct BSTNode* left;
    struct BSTNode* right;
}BSTNode;


BSTNode* BuyNode(BSTDataType x);
void InOrder(BSTNode* root);
bool BSTInsert(BSTNode** proot,BSTDataType x);
BSTNode* BSTFind(BSTNode* root,BSTDataType x);
bool BSTErase(BSTNode** proot,BSTDataType x);