#include"Hash.h"

HashNode* BuyNode(HDataType x)
{
    HashNode* newnode=(HashNode*)malloc(sizeof(HashNode));
    if(newnode==NULL)
    {
        perror("malloc fail");
        exit(1);
    }
    newnode->data=x;
    newnode->next=NULL;
    return newnode;
}
void HashPrint(HashTable* ht)
{
    for(int i=0;i<ht->capacity;i++)
    {
        HashNode* pcur=ht->table[i];
        printf("[%d]:",i);
        while(pcur)
        {
            printf("%d->",pcur->data);
            pcur=pcur->next;
        }
        printf("\n");
    }
}
void HashInit(HashTable* ht)
{
    assert(ht);
    ht->capacity=10;
    ht->size=0;
    ht->table=malloc(sizeof(HashNode*)*ht->capacity);
    if(ht->table==NULL)
    {
        perror("malloc fail");
        exit(1);
    }
    for(int i=0;i<ht->capacity;i++)
    {
        ht->table[i]=NULL;
    }
}

void HashInsert(HashTable* ht,HDataType x)
{
    assert(ht);
    int index=abs(x)%ht->capacity;
    HashNode* newnode=BuyNode(x);
    newnode->next=ht->table[index];
    ht->table[index]=newnode;
    ht->size++;
}

double LoadFactor(HashTable* ht)
{
    return (double)ht->size / ht->capacity;
}

bool CheckHash(HashTable* ht)
{
    return LoadFactor(ht)>0.7;
}

HashNode* HashFind(HashTable* ht,HDataType x)
{
    assert(ht);
    int index=abs(x)%ht->capacity;
    HashNode* pcur=ht->table[index];
    while(pcur)
    {
        if(pcur->data==x)
        {
            return pcur;
        }
        pcur=pcur->next;
    }
    return NULL;
}

bool HashErase(HashTable* ht,HDataType x)
{
    assert(ht);
    int index=abs(x)%ht->capacity;
    HashNode* head=ht->table[index];
    HashNode* pcur=head;
    if(head==NULL)
    {
        return false;
    }
    if(head->data==x)
    {
        HashNode* del=head;
        ht->table[index]=head->next;
        free(del);
        del=NULL;
        ht->size--;
        return true;
    }
    while(pcur->next)
    {
        if(pcur->next->data==x)
        {
            HashNode* del=pcur->next;
            pcur->next=del->next;
            free(del);
            del=NULL;
            ht->size--;
            return true;
        }
        pcur=pcur->next;
    }
    return false;
}

void HashDestroy(HashTable* ht)
{
    if((ht)==NULL)
    {
        return;
    }
    for(int i=0;i<ht->capacity;i++)
    {
        if(ht->table[i]!=NULL)
        {
            HashNode* pcur=ht->table[i];
            while(pcur)
            {
                HashNode* del=pcur;
                pcur=pcur->next;
                free(del);
                del=NULL;
            }
        }
        ht->table[i] = NULL;
    }
    ht->capacity=ht->size=0;
    free(ht->table);
    ht->table=NULL;
}
