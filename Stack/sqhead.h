#ifndef SQHEAD_H_INCLUDED
#define SQHEAD_H_INCLUDED

//˳��ջ�Ĵ洢�ṹ�ͻ�������˵��

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef int ELemType;

typedef struct {
    ELemType *top;      //ջ��ָ��
    ELemType *bottom;   //ջ��ָ��
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
void GetTop(SqStack S, ELemType &e);

//��ջ
void Push(SqStack &S, ELemType e);

//��ջ
void Pop(SqStack &S, ELemType &e);

//��ӡջԪ��
void showup(SqStack S);

#endif // SQHEAD_H_INCLUDED
