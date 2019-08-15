#ifndef SQHEAD_H_INCLUDED
#define SQHEAD_H_INCLUDED

//ѭ�����д洢�ṹ����������˵��
#define MAXSIZE 5

typedef int ElemType;

typedef struct {
    ElemType *base;     //��ʼ���Ķ�̬����洢�ṹ
    int fr;             //ͷָ��
    int rear;           //βָ��
} SqQueue;

//�����˳�����
void Init_Queue(SqQueue &Q);

//����˳�����
void Destroy_Queue(SqQueue &Q);

//�ÿ�˳�����
void Clear_Queue(SqQueue &Q);

//����˳����еĳ���
int Queue_Length(SqQueue Q);

//�ж��Ƿ�Ϊ�ն���
bool isEmpty(SqQueue Q);

//�����
void EnQueue(SqQueue &Q, ElemType e);

//������
void DeQueue(SqQueue &Q, ElemType &e);

//��ӡ����
void showup(SqQueue Q);

#endif // SQHEAD_H_INCLUDED
