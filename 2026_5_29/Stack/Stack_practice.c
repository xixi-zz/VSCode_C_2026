#include"Stack.h"
//https://leetcode.cn/problems/valid-parentheses/description/?utm_source=chatgpt.com
//有效的括号    
bool isValid(char* s) {
    int len=strlen(s);
    if(len%2!=0)
    return false;
    Stack s1;
    Init_Stack(&s1);
    for(int i=0;i<len;i++)
    {
        if(s[i]=='{'||s[i]=='['||s[i]=='(')
        {
            Push_Stack(&s1,s[i]);
        }
        else
        {
            if(Empty_Stack(&s1))
            {
                Destory_Stack(&s1);
                return false;
            }
            char top=Top_Stack(&s1);
            if(top=='{'&&s[i]=='}'||
            top=='['&&s[i]==']'||
            top=='('&&s[i]==')')
            {
                Pop_Stack(&s1);
            }
            else
            {
                return false;
            }
        }
    }
    if(!(Empty_Stack(&s1)))
    {
        Destory_Stack(&s1);
        return false;
    }
    Destory_Stack(&s1);
    return true;
}



//https://leetcode.cn/problems/min-stack/?utm_source=chatgpt.com
//最小栈 
typedef int SDatatype;
typedef struct MinStack{
    SDatatype *data;
    SDatatype *mindata;
    int top;
    int capacity;
} MinStack;

MinStack* minStackCreate() {
    MinStack* obj=malloc(sizeof(MinStack));
    obj->capacity=4;
    obj->top=0;
    obj->data=malloc(sizeof(SDatatype)*obj->capacity);
    obj->mindata=malloc(sizeof(SDatatype)*obj->capacity);
    if(obj->data==NULL||obj->mindata==NULL)
    {
        perror("malloc fail");
        exit(1);
    }
    return obj;
}

bool minStackEmpty(MinStack*obj)
{
    assert(obj);
    return obj->top==0;
}
void minStackPush(MinStack* obj, int val) {
    assert(obj);
    if(obj->top==obj->capacity)
    {
        int newcapacity=obj->capacity*2;
        SDatatype*tmp=realloc(obj->data,sizeof(SDatatype)*newcapacity);
        if(tmp==NULL)
        {
            perror("realloc fail");
            exit(1);
        }
        obj->data=tmp;
        obj->capacity=newcapacity;
        SDatatype* mintmp=realloc(obj->mindata,sizeof(SDatatype)*newcapacity);
        if(mintmp==NULL)
        {
            perror("realloc fail");
            exit(1);
        }
        obj->mindata=mintmp;
    }
    if(obj->top==0)
    obj->mindata[obj->top]=val;
    else if(obj->mindata[obj->top-1]>val)
    obj->mindata[obj->top]=val;
    else
    obj->mindata[obj->top]=obj->mindata[obj->top-1];
    
    obj->data[obj->top++]=val;
}

void minStackPop(MinStack* obj) {
    assert(obj);
    assert(!(minStackEmpty(obj)));
    obj->top--;
}

int minStackTop(MinStack* obj) {
    assert(obj);
    assert(!(minStackEmpty(obj)));
    return obj->data[obj->top-1];
}

int minStackGetMin(MinStack* obj) {
    assert(obj);
    assert(!(minStackEmpty(obj)));
    return obj->mindata[obj->top-1];
}

void minStackFree(MinStack* obj) {
    assert(obj);
    free(obj->data);
    obj->data=NULL;
    obj->top=obj->capacity=0;
    free(obj->mindata);
    obj->mindata=NULL;
    free(obj);
    obj=NULL;
}
