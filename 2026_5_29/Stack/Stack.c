#include"Stack.h"
void Init_Stack(Stack* st)
{
    assert(st);
    st->capacity=4;
    st->top=0;
    st->data=malloc(sizeof(SDatatype)*st->capacity);
    if(st->data==NULL)
    {
        perror("malloc fail");
        exit(1);
    }
}
bool Empty_Stack(Stack* st)
{
    assert(st);
    return st->top==0;
}
void Push_Stack(Stack* st,SDatatype x)
{
    assert(st);
    if(st->top==st->capacity)
    {
        int newcapacity=st->capacity*2;
        SDatatype*tmp=realloc(st->data,sizeof(SDatatype)*newcapacity);
        if(tmp==NULL)
        {
            perror("realloc fail");
            exit(1);
        }
        st->capacity=newcapacity;
        st->data=tmp;
    }
    st->data[st->top]=x;
    st->top++;
}
void Pop_Stack(Stack* st)
{
    assert(st);
    assert(!(Empty_Stack(st)));
    st->top--;
}

SDatatype Top_Stack(Stack* st)
{
    assert(st);
    assert(!(Empty_Stack(st)));
    return st->data[st->top-1];
}
int Size_Stack(Stack*st)
{
    assert(st);
    return st->top;
}
void Destory_Stack(Stack* st)
{
    assert(st);
    free(st->data);
    st->data=NULL;
    st->capacity=st->top=0;
}