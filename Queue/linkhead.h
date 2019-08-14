#ifndef LINKHEAD_H_INCLUDED
#define LINKHEAD_H_INCLUDED

//链队列存储结构和基本操作说明

typedef int ElemType;

typedef struct QNode{
    ElemType data;
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
void GetHead(LinkQueue Q, ElemType &e);

//在队尾插入元素
void EnQueue(LinkQueue &Q, ElemType e);

//在队头取出元素
void DeQueue(LinkQueue &Q, ElemType &e);

//打印队列
void showup(LinkQueue Q);

#endif // LINKHEAD_H_INCLUDED
