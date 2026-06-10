#include"AVL_v1.h"
void test01()
{
    BTNode* root=NULL;
    AVLInsert(&root,15);
    PreOrder(root);
    printf("第%d次\n",1);
    AVLInsert(&root,30);
    PreOrder(root);
    printf("第%d次\n",2);
    AVLInsert(&root,20);
    PreOrder(root);
    printf("第%d次\n",3);
    AVLInsert(&root,10);
    PreOrder(root);
    printf("第%d次\n",4);
    AVLInsert(&root,40);
    PreOrder(root);
    printf("第%d次\n",5);
    AVLInsert(&root,35);
    PreOrder(root);
    printf("第%d次\n",6);

}
int main()
{
    test01();
    return 0;
}