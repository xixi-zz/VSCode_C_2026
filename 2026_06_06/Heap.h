#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef int HPDataType;

typedef struct Heap
{
    HPDataType* data;
    int size;
    int capacity;
}Heap;
void HeapInit(Heap* hp);
void Swap(int*a,int*b);
void HeapPush(Heap* hp, HPDataType x);
void AdjustUp(HPDataType* data, int child);
void HeapPrint(Heap* hp);
void AdjustDown(HPDataType* data,int size,int parent);
void HeapPop(Heap* hp);
HPDataType HeapTop(Heap* hp);
bool HeapEmpty(Heap* hp);
int HeapSize(Heap* hp);
void HeapDestroy(Heap* hp);
