#ifndef STACKHEAD_H_INCLUDED
#define STACKHEAD_H_INCLUDED

//˳��ջ�Ĵ洢�ṹ�ͻ�������˵��

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

#include "treehead.h"

typedef BiTree SELemType;

typedef struct {
    SELemType *top;      //ջ��ָ��
    SELemType *bottom;   //ջ��ָ��
    int stacksize;      //��ǰ�ѷ���洢�ռ�
} SqStack;

//����һ����ջ
void Init_Stack(SqStack &S);

//����һ��ջ
void Destory_Stack(SqStack &S);

//��ջ��Ϊ��
void Clear_Stack(SqStack &S);

//�ж�ջ�Ƿ�Ϊ��
bool isEmpty(SqStack S);

//����ջ�ĳ���
int Stack_Length(SqStack S);

//����ջ��Ԫ�أ�������ջ
void GetTop(SqStack S, SELemType &e);

//��ջ
void Push(SqStack &S, SELemType e);

//��ջ
void Pop(SqStack &S, SELemType &e);

//��ӡջԪ��
void showup(SqStack S);


#endif // STACKHEAD_H_INCLUDED
