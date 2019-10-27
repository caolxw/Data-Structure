#ifndef STACKHEAD_H_INCLUDED
#define STACKHEAD_H_INCLUDED

//顺序栈的存储结构和基本操作说明

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

#include "treehead.h"

typedef BiTree SELemType;

typedef struct {
    SELemType *top;      //栈顶指针
    SELemType *bottom;   //栈底指针
    int stacksize;      //当前已分配存储空间
} SqStack;

//构造一个空栈
void Init_Stack(SqStack &S);

//销毁一个栈
void Destory_Stack(SqStack &S);

//把栈置为空
void Clear_Stack(SqStack &S);

//判断栈是否为空
bool isEmpty(SqStack S);

//返回栈的长度
int Stack_Length(SqStack S);

//返回栈顶元素，但不出栈
void GetTop(SqStack S, SELemType &e);

//入栈
void Push(SqStack &S, SELemType e);

//出栈
void Pop(SqStack &S, SELemType &e);

//打印栈元素
void showup(SqStack S);


#endif // STACKHEAD_H_INCLUDED
