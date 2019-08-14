#include <stdio.h>
#include "linkhead.h"
#include "linkqueue.cpp"

int main()
{
    LinkQueue Q;
    Init_Queue(Q);
    EnQueue(Q, 1);
    EnQueue(Q, 2);
    EnQueue(Q, 3);
    showup(Q);
    printf("%d\n", Queue_Length(Q));
    ElemType e;
    DeQueue(Q, e);
    showup(Q);
    Clear_Queue(Q);
    printf("%d\n", Queue_Length(Q));
}
