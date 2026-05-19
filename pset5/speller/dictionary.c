// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include<stdio.h>
#include "dictionary.h"
#include<string.h>
#include<stdlib.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

node* buynode(char*s);
// TODO: Choose number of buckets in hash table
const unsigned int N = 676;

// Hash table
node *table[N];
int count_size=0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    //检查是否有错误
    char low_word[LENGTH+1];
    int len=strlen(word);
    for(int i=0;i<len;i++)
    {
        low_word[i]=tolower(word[i]);
    }
    low_word[len]='\0';
    int index=hash(low_word);
    node*pcur=table[index];
    while(pcur!=NULL)
    {
        if(strcmp(pcur->word,low_word)==0)
        {
            return true;
        }
        pcur=pcur->next;

    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    //完成哈希表
 
    int first = 0;
    int second = 0;
    if (isalpha(word[0]))
    {
        first = toupper(word[0]) - 'A';
    }

    if (word[1] != '\0' && isalpha(word[1]))
    {
        second = toupper(word[1]) - 'A';
    }

    return (first * 26 + second) % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    //将字典数据存入哈希表
    for(int i=0;i<N;i++)
    {
        table[i]=NULL;
    }
    count_size = 0;
    FILE* file=fopen(dictionary,"r");
    if(file==NULL)
    {
        return false;
    }
    char word[LENGTH+1];
    while((fscanf(file,"%s",word))!=EOF)
    {
        node* insert=buynode(word);
        if(insert==NULL)
        {
            fclose(file);
            return false;
        }
        int index=hash(insert->word);
        insert->next=table[index];
        table[index]=insert;
        count_size++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    //统计字典个数
    return count_size;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    //释放内存
    for(int i=0;i<N;i++)
    {
        node*pcur=table[i];
        while(pcur!=NULL)
        {
            node* tmp=pcur;
            pcur=pcur->next;
            free(tmp);
        }
        table[i]=NULL;
    }
    return true;
}
node* buynode(char*s)
{
    node* newnode=malloc(sizeof(node));
    if(newnode==NULL)
    {
        return NULL;
    }
    int len = strlen(s);

    for (int i = 0; i < len; i++)

    {

        newnode->word[i] = tolower(s[i]);

    }

    newnode->word[len] = '\0';
    newnode->next=NULL;
    return newnode;
}