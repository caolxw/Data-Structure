#include <stdio.h>
#include <stdlib.h>
#include "sqhead.h"

//构造一个空栈
void Init_Stack(SqStack &S)
{
    S.bottom = (ELemType *) malloc(STACK_INIT_SIZE * sizeof(ELemType));
    if(!S.bottom){
        printf("初始化分配空间失败\n");
        return;
    }
    S.top = S.bottom;
    S.stacksize = STACK_INIT_SIZE;
    return;
}

//销毁一个栈
void Destory_Stack(SqStack &S)
{
    free(S.bottom);
    S.bottom = NULL;
    S.top = NULL;
    S.stacksize = 0;
}

//把栈置为空
void Clear_Stack(SqStack &S)
{
    S.top = S.bottom;
    return;
}

//判断栈是否为空
bool isEmpty(SqStack S){
    if(S.top == S.bottom)
        return true;
    else return false;
}

//返回栈的长度
int Stack_Length(SqStack S)
{
    if(isEmpty(S)){
        return 0;
    }else{
        int length = 0;
        ELemType *temp = S.top;
        while(temp != S.bottom){
            length ++;
            temp --;
        }
        return length;
    }
}

//返回栈顶元素，但不出栈
void GetTop(SqStack S, ELemType &e)
{
    if(isEmpty(S)){
        printf("栈为空，无栈顶元素");
        return;
    }else{
        e = *(S.top  - 1);
        return;
    }
}

//入栈
void Push(SqStack &S, ELemType e)
{
    if(Stack_Length(S) == S.stacksize){
        //栈的存储空间已经用完，需要括栈
        ELemType *temp = (ELemType *)realloc(S.bottom, (S.stacksize + STACKINCREMENT) * sizeof(ELemType));
        if(!temp){
            printf("括栈失败\n");
            return;
        }
        S.bottom = temp;
        S.top = S.bottom + S.stacksize;
        S.stacksize += STACKINCREMENT;
    }
    *S.top ++ = e;
    return;
}

//出栈
void Pop(SqStack &S, ELemType &e)
{
    if(isEmpty(S)){
        printf("栈为空，出栈失败\n");
        return;
    }
    e = *(-- S.top);
    return;
}

//打印栈元素
void showup(SqStack S)
{
    while(S.bottom < S.top){
        printf("%d ", *S.bottom);
        S.bottom ++;
    }
    printf("\n");
}
