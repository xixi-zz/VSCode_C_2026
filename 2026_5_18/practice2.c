#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    typedef struct node
    {
        char word[46];
        struct node*next;
    }node;
    node* newnode=malloc(sizeof(node));
    if(newnode==NULL)
    {
        return 1;
    }
    strcpy(newnode->word,"hello");
    newnode->next=NULL;
    printf("%s\n",newnode->word);
    free(newnode);
    return 0;
}