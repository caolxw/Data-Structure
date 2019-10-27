#ifndef QUEUEHEAD_H_INCLUDED
#define QUEUEHEAD_H_INCLUDED

#include "treehead.h"

typedef BiTree QElemType;

//链队列存储结构和基本操作说明

typedef BiTree QElemType;

typedef struct QNode{
    QElemType data;
    struct QNode *next;
}QNode, *QueuePtr;

typedef struct {
    QueuePtr fr;        //队头指针
    QueuePtr rear;      //队尾指针
}LinkQueue;

//构造空队列
void Init_Queue(LinkQueue &Q);

//销毁队列
void Destroy_Queue(LinkQueue &Q);

//清空队列
void Clear_Queue(LinkQueue &Q);

//判断是否为空队列
bool isEmpty(LinkQueue Q);

//返回队列长度
int Queue_Length(LinkQueue Q);

//返回队头元素
void GetHead(LinkQueue Q, QElemType &e);

//在队尾插入元素
void EnQueue(LinkQueue &Q, QElemType e);

//在队头取出元素
void DeQueue(LinkQueue &Q, QElemType &e);

//打印队列
void showup(LinkQueue Q);


#endif // QUEUEHEAD_H_INCLUDED
