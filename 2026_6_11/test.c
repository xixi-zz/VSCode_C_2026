#include"Hash.h"
void test01()
{
    HashTable ht;

    HashInit(&ht);

    HashInsert(&ht,15);
    HashInsert(&ht,25);
    HashInsert(&ht,35);
    HashInsert(&ht,12);
    HashInsert(&ht,22);

    HashPrint(&ht);

    HashErase(&ht,35);
    HashPrint(&ht);

    HashErase(&ht,25);
    HashPrint(&ht);

    HashErase(&ht,15);
    HashPrint(&ht);

    HashDestroy(&ht);
}
int main()
{
    test01();
    return 0;
}