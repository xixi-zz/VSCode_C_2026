#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef int SDatatype;
typedef struct Stack
{
    SDatatype *data;
    int top;
    int capacity;
}Stack;
void Init_Stack(Stack* st);
void Push_Stack(Stack* st,SDatatype x);
void Pop_Stack(Stack* st);
SDatatype Top_Stack(Stack* st);
bool Empty_Stack(Stack* st);
int Size_Stack(Stack* st);
void Destory_Stack(Stack* st);