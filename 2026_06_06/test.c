#include"Heap.h"
void CreateHeap(HPDataType* data,int size)
{
    for(int i=(size-2)/2;i>=0;i--)
    {
        AdjustDown(data,size,i);
    }
}
void HeapSort(HPDataType* data,int size)
{
    CreateHeap(data,size);
    int end=size-1;
    while(end>0)
    {
        Swap(&data[0],&data[end]);
        AdjustDown(data,end,0);
        end--;
    }
}
int main()
{
    int a[] = {27,15,19,18,28,34,65,49,25,37};
    Heap hp;
    HeapInit(&hp);
    for(int i = 0; i < sizeof(a)/sizeof(a[0]); i++)
    {
        HeapPush(&hp, a[i]);
    }
    while(!HeapEmpty(&hp))
    {
        printf("%d ",HeapTop(&hp));
        HeapPop(&hp);
    }
    printf("\n");
    HeapDestroy(&hp);
    return 0;
}