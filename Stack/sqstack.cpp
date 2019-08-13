#include <stdio.h>
#include <stdlib.h>
#include "sqhead.h"

//����һ����ջ
void Init_Stack(SqStack &S)
{
    S.bottom = (ELemType *) malloc(STACK_INIT_SIZE * sizeof(ELemType));
    if(!S.bottom){
        printf("��ʼ������ռ�ʧ��\n");
        return;
    }
    S.top = S.bottom;
    S.stacksize = STACK_INIT_SIZE;
    return;
}

//����һ��ջ
void Destory_Stack(SqStack &S)
{
    free(S.bottom);
    S.bottom = NULL;
    S.top = NULL;
    S.stacksize = 0;
}

//��ջ��Ϊ��
void Clear_Stack(SqStack &S)
{
    S.top = S.bottom;
    return;
}

//�ж�ջ�Ƿ�Ϊ��
bool isEmpty(SqStack S){
    if(S.top == S.bottom)
        return true;
    else return false;
}

//����ջ�ĳ���
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

//����ջ��Ԫ�أ�������ջ
void GetTop(SqStack S, ELemType &e)
{
    if(isEmpty(S)){
        printf("ջΪ�գ���ջ��Ԫ��");
        return;
    }else{
        e = *(S.top  - 1);
        return;
    }
}

//��ջ
void Push(SqStack &S, ELemType e)
{
    if(Stack_Length(S) == S.stacksize){
        //ջ�Ĵ洢�ռ��Ѿ����꣬��Ҫ��ջ
        ELemType *temp = (ELemType *)realloc(S.bottom, (S.stacksize + STACKINCREMENT) * sizeof(ELemType));
        if(!temp){
            printf("��ջʧ��\n");
            return;
        }
        S.bottom = temp;
        S.top = S.bottom + S.stacksize;
        S.stacksize += STACKINCREMENT;
    }
    *S.top ++ = e;
    return;
}

//��ջ
void Pop(SqStack &S, ELemType &e)
{
    if(isEmpty(S)){
        printf("ջΪ�գ���ջʧ��\n");
        return;
    }
    e = *(-- S.top);
    return;
}

//��ӡջԪ��
void showup(SqStack S)
{
    while(S.bottom < S.top){
        printf("%d ", *S.bottom);
        S.bottom ++;
    }
    printf("\n");
}
