#ifndef LINKHEAD_H_INCLUDED
#define LINKHEAD_H_INCLUDED

//�����д洢�ṹ�ͻ�������˵��

typedef int ElemType;

typedef struct QNode{
    ElemType data;
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
void GetHead(LinkQueue Q, ElemType &e);

//�ڶ�β����Ԫ��
void EnQueue(LinkQueue &Q, ElemType e);

//�ڶ�ͷȡ��Ԫ��
void DeQueue(LinkQueue &Q, ElemType &e);

//��ӡ����
void showup(LinkQueue Q);

#endif // LINKHEAD_H_INCLUDED
