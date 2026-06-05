#include"BST.h"
int main()
{
    BSTNode* root = NULL;

    BSTInsert(&root, 5);
    BSTInsert(&root, 3);
    BSTInsert(&root, 8);
    BSTInsert(&root, 1);
    BSTInsert(&root, 4);
    BSTInsert(&root, 6);
    BSTInsert(&root, 9);
    BSTInsert(&root, 7);

    printf("原BST:\n");
    InOrder(root);
    printf("\n\n");

    // 测试Find
    BSTNode* ret = BSTFind(root, 6);

    if(ret)
    {
        printf("找到:%d\n\n", ret->data);
    }
    else
    {
        printf("没找到\n\n");
    }

    // 删除叶子节点
    printf("删除叶子节点9:\n");
    BSTErase(&root, 9);
    InOrder(root);
    printf("\n\n");

    // 删除只有一个孩子的节点
    printf("删除只有一个孩子的节点6:\n");
    BSTErase(&root, 6);
    InOrder(root);
    printf("\n\n");

    // 删除有两个孩子的节点
    printf("删除有两个孩子的节点5:\n");
    BSTErase(&root, 5);
    InOrder(root);
    printf("\n\n");

    return 0;
}