#ifndef QUEUEHEAD_H_INCLUDED
#define QUEUEHEAD_H_INCLUDED

#include "treehead.h"

typedef BiTree QElemType;

//�����д洢�ṹ�ͻ�������˵��

typedef BiTree QElemType;

typedef struct QNode{
    QElemType data;
    struct QNode *next;
}QNode, *QueuePtr;

typedef struct {
    QueuePtr fr;        //��ͷָ��
    QueuePtr rear;      //��βָ��
}LinkQueue;

//����ն���
void Init_Queue(LinkQueue &Q);

//���ٶ���
void Destroy_Queue(LinkQueue &Q);

//��ն���
void Clear_Queue(LinkQueue &Q);

//�ж��Ƿ�Ϊ�ն���
bool isEmpty(LinkQueue Q);

//���ض��г���
int Queue_Length(LinkQueue Q);

//���ض�ͷԪ��
void GetHead(LinkQueue Q, QElemType &e);

//�ڶ�β����Ԫ��
void EnQueue(LinkQueue &Q, QElemType e);

//�ڶ�ͷȡ��Ԫ��
void DeQueue(LinkQueue &Q, QElemType &e);

//��ӡ����
void showup(LinkQueue Q);


#endif // QUEUEHEAD_H_INCLUDED
