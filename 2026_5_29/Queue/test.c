#include"Queue.h"
void test_queue()
{
    Queue q;
    Init_Queue(&q);

    Push_Queue(&q, 1);
    Push_Queue(&q, 2);
    Push_Queue(&q, 3);

    printf("front:%d\n", Front_Queue(&q));
    printf("back:%d\n", Back_Queue(&q));

    Pop_Queue(&q);
    printf("front:%d\n", Front_Queue(&q));

    Push_Queue(&q, 4);
    printf("back:%d\n", Back_Queue(&q));

    while (!Empty_Queue(&q))
    {
        printf("%d ", Front_Queue(&q));
        Pop_Queue(&q);
    }

    printf("\n");

    Destory_Queue(&q);
}
int main()
{
    test_queue();
    return 0;
}