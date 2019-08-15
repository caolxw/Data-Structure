#include <stdio.h>
#include <stdlib.h>
#include "sqhead.h"

//�����˳�����
void Init_Queue(SqQueue &Q)
{
    Q.base = (ElemType *)malloc(MAXSIZE * sizeof(ElemType));
    if(!Q.base){
        printf("����ռ�ʧ��\n");
        return;
    }
    Q.fr = Q.rear = 0;
    return;
}

//����˳�����
void Destroy_Queue(SqQueue &Q)
{
    while(Q.rear != Q.fr){
        free(&Q.base[Q.fr]);
        Q.fr = (Q.fr + 1) % MAXSIZE;
    }
}

//�ÿ�˳�����
void Clear_Queue(SqQueue &Q)
{
    Q.fr = Q.rear = 0;
}

//����˳����еĳ���
int Queue_Length(SqQueue Q)
{
    return (Q.rear - Q.fr + MAXSIZE) % MAXSIZE;
}

//�ж��Ƿ�Ϊ�ն���
bool isEmpty(SqQueue Q)
{
    if(Queue_Length(Q) == 0)
        return true;
    else
        return false;
}

//�����
void EnQueue(SqQueue &Q, ElemType e)
{
    if((Q.rear + 1) % MAXSIZE == Q.fr){
        printf("��������\n");
        return;
    }
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAXSIZE;
    return;
}

//������
void DeQueue(SqQueue &Q, ElemType &e)
{
    if(isEmpty(Q)){
        printf("����Ϊ��\n");
        return;
    }
    e = Q.base[Q.fr];
    Q.fr = (Q.fr + 1) % MAXSIZE;
    return;
}

//��ӡ����
void showup(SqQueue Q)
{
    while(Q.fr != Q.rear){
        printf("%d ", Q.base[Q.fr]);
        Q.fr = (Q.fr + 1) % MAXSIZE;
    }
    printf("\n");
}
