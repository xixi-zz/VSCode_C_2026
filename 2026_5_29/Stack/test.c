#include"Stack.h"
void Print_Stack(Stack* st)
{
    for(int i=0;i<st->top;i++)
    {
        printf("%d ",st->data[i]);
    }
    printf("\n");
}
void test01()
{
    Stack s1;
    Init_Stack(&s1);
    Push_Stack(&s1,1);
    Push_Stack(&s1,2);
    Push_Stack(&s1,3);
    Push_Stack(&s1,4);
    Print_Stack(&s1);
    Push_Stack(&s1,5);
    Print_Stack(&s1);
    Pop_Stack(&s1);
    Print_Stack(&s1);
    Pop_Stack(&s1);
    Print_Stack(&s1);
    Pop_Stack(&s1);
    Print_Stack(&s1);
    Pop_Stack(&s1);
    Print_Stack(&s1);
    Pop_Stack(&s1);
    Print_Stack(&s1);
    Pop_Stack(&s1);
    Destory_Stack(&s1);
}
int main()
{
    test01();
    return 0;
}