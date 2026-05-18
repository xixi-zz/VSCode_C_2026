#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct node
    {
        char word[46];
        struct node*next;
    }node;
node* buynode(char*s);
int hash(node* insert);
int main()
{
    node* table[26];
    for(int i=0;i<26;i++)
    {
        table[i]=NULL;
    }
    node* apple=buynode("apple");
    apple->next = table[hash(apple)];
    table[hash(apple)] = apple;
    node* ant=buynode("ant");
    ant->next=table[hash(ant)];
    table[hash(ant)]=ant;
    node* banana=buynode("banana");
    banana->next = table[hash(banana)];
    table[hash(banana)] = banana;
    node* book=buynode("book");
    book->next=table[hash(book)];
    table[hash(book)]=book;
    node* pcur=table[1];
    while(pcur!=NULL)
    {
        printf("%s\n",pcur->word);
        pcur=pcur->next;
    }

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
int hash(node* insert)
{
    return toupper(insert->word[0])-'A';
}