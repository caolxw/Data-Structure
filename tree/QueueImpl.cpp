#include <stdio.h>
#include <stdlib.h>
#include "queuehead.h"

//构造空队列
void Init_Queue(LinkQueue &Q)
{
    Q.fr = (QueuePtr)malloc(sizeof(QNode));
    if(!Q.fr) return;
    Q.rear = Q.fr;
    Q.fr->next = NULL;
    return;
}

//销毁队列
void Destroy_Queue(LinkQueue &Q)
{
    while(Q.fr){
        Q.rear = Q.fr->next;
        free(Q.fr);
        Q.fr = Q.rear;
    }
}

//清空队列
void Clear_Queue(LinkQueue &Q)
{
    while(Q.fr != Q.rear){
        QueuePtr p = Q.fr->next;
        Q.fr = Q.fr->next;
        free(p);
    }
    Q.fr = NULL;
    Q.rear = Q.fr;
}

//判断是否为空队列
bool isEmpty(LinkQueue Q)
{
    if(Q.fr == Q.rear) return true;
    else return false;
}

//返回队列长度
int Queue_Length(LinkQueue Q)
{
    if(isEmpty(Q)) return 0;
    int length = 0;
    while(Q.fr != Q.rear){
        length ++;
        Q.fr = Q.fr->next;
    }
    return length + 1;
}

//返回队头元素
void GetHead(LinkQueue Q, QElemType &e)
{
    if(isEmpty(Q)){
        printf("队列为空，无队头元素\n");
        return;
    }
    e = Q.fr->data;
    return;
}

//在队尾插入元素
void EnQueue(LinkQueue &Q, QElemType e)
{
    QueuePtr p = (QueuePtr) malloc(sizeof(QNode));
    p->data = e;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
}

//在队头取出元素
void DeQueue(LinkQueue &Q, QElemType &e)
{
    if(isEmpty(Q)){
        printf("队列为空，无队头元素\n");
        return;
    }
    QueuePtr p = Q.fr->next;
    Q.fr->next = p->next;
    e = p->data;
    if(Q.rear == p) Q.rear = Q.fr;
    free(p);

}

//打印队列
void showup(LinkQueue Q)
{
    QueuePtr p = Q.fr->next;
    while(p != Q.rear){
        printf("%d ",p->data->data);
        p = p->next;
    }
    printf("%d\n", p->data->data);
}
