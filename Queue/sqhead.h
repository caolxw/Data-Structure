#ifndef SQHEAD_H_INCLUDED
#define SQHEAD_H_INCLUDED

//循环队列存储结构及基本操作说明
#define MAXSIZE 5

typedef int ElemType;

typedef struct {
    ElemType *base;     //初始化的动态分配存储结构
    int fr;             //头指针
    int rear;           //尾指针
} SqQueue;

//构造空顺序队列
void Init_Queue(SqQueue &Q);

//销毁顺序队列
void Destroy_Queue(SqQueue &Q);

//置空顺序队列
void Clear_Queue(SqQueue &Q);

//返回顺序队列的长度
int Queue_Length(SqQueue Q);

//判断是否为空队列
bool isEmpty(SqQueue Q);

//入队列
void EnQueue(SqQueue &Q, ElemType e);

//出队列
void DeQueue(SqQueue &Q, ElemType &e);

//打印队列
void showup(SqQueue Q);

#endif // SQHEAD_H_INCLUDED
