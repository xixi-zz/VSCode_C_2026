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

typedef BTNode* QDatatype;
typedef struct QueueNode
{
    QDatatype data;
    struct QueueNode* next;
}QueueNode;
typedef struct Queue
{
    struct QueueNode* head;
    struct QueueNode* tail;
}Queue;
void Init_Queue(Queue*q);
void Push_Queue(Queue* q,QDatatype x);
void Pop_Queue(Queue*q);
bool Empty_Queue(Queue*q);
QDatatype Front_Queue(Queue*q);
QDatatype Back_Queue(Queue*q);
void Destory_Queue(Queue*q);

BTNode* buynode(BTDataType x);
void PreOrder(BTNode* root);//先序遍历      
void InOrder(BTNode* root);//中序遍历
void PostOrder(BTNode* root);//后序遍历 
int TreeSize(BTNode* root);      // 节点个数
int TreeLeafSize(BTNode* root);  // 叶子节点个数
int TreeHeight(BTNode* root);    // 树高度
BTNode* TreeFind(BTNode* root, BTDataType x);//查找
void TreeDestroy(BTNode* root);//销毁
int TreeKLevelSize(BTNode* root, int k);//第k层节点个数
void LevelOrder(BTNode* root);//层序遍历
bool TreeEqual(BTNode* root1, BTNode* root2);//判断两棵树是否相等;