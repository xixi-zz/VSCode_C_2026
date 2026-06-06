#include"Heap.h"
void HeapInit(Heap* hp)
{
    assert(hp);
    hp->capacity=4;
    hp->data=malloc(sizeof(HPDataType)*hp->capacity);
    if(hp->data==NULL)
    {
        perror("malloc fail");
        exit(1);
    }
    hp->size=0;
}
void Swap(int*a,int*b)
{
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
void AdjustUp(HPDataType* data, int child)
{
    int parent=(child-1)/2;
    while(child>0&&data[parent]<data[child])
    {  
        Swap(&data[child],&data[parent]);
        child=parent;
        parent=(child-1)/2;
    }
}
void HeapPush(Heap* hp, HPDataType x)
{
    assert(hp);
    if(hp->size==hp->capacity)
    {
        int newcapacity=hp->capacity*2;
        HPDataType* tmp=realloc(hp->data,sizeof(HPDataType)*newcapacity);
        if(tmp==NULL)
        {
            perror("realloc fail");
            exit(1);
        }
        hp->data=tmp;
        hp->capacity=newcapacity;
    }
    hp->data[hp->size]=x;
    AdjustUp(hp->data,hp->size);
    hp->size++;
}
bool HeapEmpty(Heap* hp)
{
    assert(hp);
    return hp->size==0;
}
HPDataType HeapTop(Heap* hp)
{
    assert(hp);
    assert(!(HeapEmpty(hp)));
    return hp->data[0];
}
void AdjustDown(HPDataType* data,int size,int parent)
{
    int child=parent*2+1;
    while(child<size)
    {
        if(child+1<size&&data[child]<data[child+1])
        {
            child++;
        }
        if(data[child]>data[parent])
        {
            Swap(&data[child],&data[parent]);
            parent=child;
            child=parent*2+1;
        }
        else
        {
            break;
        }
    }
}
void HeapPop(Heap* hp)
{
    assert(hp);
    assert(!(HeapEmpty(hp)));
    Swap(&hp->data[0],&hp->data[hp->size-1]);
    hp->size--;
    AdjustDown(hp->data,hp->size,0);
}
int HeapSize(Heap* hp)
{
    assert(hp);
    return hp->size;
}
void HeapPrint(Heap* hp)
{
    assert(hp);
    for(int i=0;i<hp->size;i++)
    {
        printf("%d ",hp->data[i]);
    }
    printf("\n");
}
void HeapDestroy(Heap* hp)
{
    assert(hp);
    free(hp->data);
    hp->data=NULL;
    hp->size=hp->capacity=0;
}