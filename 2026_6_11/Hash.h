#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef int HDataType;
typedef struct HashNode
{
    HDataType data;
    struct HashNode* next;
}HashNode;

typedef struct HashTable
{
    HashNode** table;
    int capacity;
    int size;
}HashTable;


void HashPrint(HashTable* ht);
void HashInit(HashTable* ht);
void HashInsert(HashTable* ht,HDataType x);
double LoadFactor(HashTable* ht);
HashNode* HashFind(HashTable* ht,HDataType x);
bool HashErase(HashTable* ht,HDataType x);
void HashDestroy(HashTable* ht);