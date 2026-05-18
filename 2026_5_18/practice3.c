#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
    {
        char word[46];
        struct node*next;
    }node;
node* buynode(char*s);
int main()
{
    node*apple=buynode("apple");
    node*banana=buynode("banana");
    banana->next=apple;
    node*phead=banana;
    while(phead!=NULL)
    {
        printf("%s\n",phead->word);
        phead=phead->next;
    }
    free(banana);
    free(apple);
    return 0;
}
node* buynode(char*s)
{
    node*newnode=malloc(sizeof(node));
    if(newnode==NULL)
    {
        return NULL;
    }
    strcpy(newnode->word,s);
    newnode->next=NULL;
    return newnode;
}