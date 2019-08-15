#include <stdio.h>
/*
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
*/

#include "sqhead.h"
#include "sqqueue.cpp"

int main()
{
    SqQueue Q;
    Init_Queue(Q);
    EnQueue(Q, 1);
    EnQueue(Q, 2);
    EnQueue(Q, 3);
    EnQueue(Q, 4);
    EnQueue(Q, 5);
    EnQueue(Q, 6);
    showup(Q);
    int i;
    DeQueue(Q,i);
    showup(Q);
    Clear_Queue(Q);
    EnQueue(Q,5);
    showup(Q);
}
