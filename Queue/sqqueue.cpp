#include <stdio.h>
#include <stdlib.h>
#include "sqhead.h"

//构造空顺序队列
void Init_Queue(SqQueue &Q)
{
    Q.base = (ElemType *)malloc(MAXSIZE * sizeof(ElemType));
    if(!Q.base){
        printf("分配空间失败\n");
        return;
    }
    Q.fr = Q.rear = 0;
    return;
}

//销毁顺序队列
void Destroy_Queue(SqQueue &Q)
{
    while(Q.rear != Q.fr){
        free(&Q.base[Q.fr]);
        Q.fr = (Q.fr + 1) % MAXSIZE;
    }
}

//置空顺序队列
void Clear_Queue(SqQueue &Q)
{
    Q.fr = Q.rear = 0;
}

//返回顺序队列的长度
int Queue_Length(SqQueue Q)
{
    return (Q.rear - Q.fr + MAXSIZE) % MAXSIZE;
}

//判断是否为空队列
bool isEmpty(SqQueue Q)
{
    if(Queue_Length(Q) == 0)
        return true;
    else
        return false;
}

//入队列
void EnQueue(SqQueue &Q, ElemType e)
{
    if((Q.rear + 1) % MAXSIZE == Q.fr){
        printf("队列已满\n");
        return;
    }
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAXSIZE;
    return;
}

//出队列
void DeQueue(SqQueue &Q, ElemType &e)
{
    if(isEmpty(Q)){
        printf("队列为空\n");
        return;
    }
    e = Q.base[Q.fr];
    Q.fr = (Q.fr + 1) % MAXSIZE;
    return;
}

//打印队列
void showup(SqQueue Q)
{
    while(Q.fr != Q.rear){
        printf("%d ", Q.base[Q.fr]);
        Q.fr = (Q.fr + 1) % MAXSIZE;
    }
    printf("\n");
}
