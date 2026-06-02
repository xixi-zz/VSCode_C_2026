#include "Binarytree.h"

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
}

int main()
{
    TestTree();

    return 0;
}