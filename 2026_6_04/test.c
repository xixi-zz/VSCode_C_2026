#include"BinaryTree_v1.h"
void TestTree()
{
    BTNode* n1 = buynode(1);
    BTNode* n2 = buynode(2);
    BTNode* n3 = buynode(3);
    BTNode* n4 = buynode(4);
    BTNode* n5 = buynode(5);

    n1->left = n2;
    n1->right = n3;

    n2->left = n4;
    n2->right = n5;

    printf("PreOrder:\n");
    PreOrder(n1);

    printf("\n\nInOrder:\n");
    InOrder(n1);

    printf("\n\nPostOrder:\n");
    PostOrder(n1);

    printf("\n\nTreeSize:\n");
    printf("%d\n", TreeSize(n1));

    printf("\nTreeLeafSize:\n");
    printf("%d\n", TreeLeafSize(n1));

    printf("\nTreeHeight:\n");
    printf("%d\n", TreeHeight(n1));

    printf("\nTreeFind(5):\n");
    BTNode* ret = TreeFind(n1, 5);

    if(ret)
    {
        printf("%d\n", ret->data);
    }
    else
    {
        printf("Not Found\n");
    }

    printf("\nTreeKLevelSize:\n");
    printf("Level1 = %d\n", TreeKLevelSize(n1, 1));
    printf("Level2 = %d\n", TreeKLevelSize(n1, 2));
    printf("Level3 = %d\n", TreeKLevelSize(n1, 3));
    printf("Level4 = %d\n", TreeKLevelSize(n1, 4));

    printf("\nLevelOrder:\n");
    LevelOrder(n1);

    printf("\n");

    TreeDestroy(n1);
}
int main()
{
    TestTree();

    return 0;
}