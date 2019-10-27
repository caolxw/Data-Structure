#include <stdio.h>
#include <stdlib.h>
#include "queuehead.h"

//����ն���
void Init_Queue(LinkQueue &Q)
{
    Q.fr = (QueuePtr)malloc(sizeof(QNode));
    if(!Q.fr) return;
    Q.rear = Q.fr;
    Q.fr->next = NULL;
    return;
}

//���ٶ���
void Destroy_Queue(LinkQueue &Q)
{
    while(Q.fr){
        Q.rear = Q.fr->next;
        free(Q.fr);
        Q.fr = Q.rear;
    }
}

//��ն���
void Clear_Queue(LinkQueue &Q)
{
    while(Q.fr != Q.rear){
        QueuePtr p = Q.fr->next;
        Q.fr = Q.fr->next;
        free(p);
    }
    Q.fr = NULL;
    Q.rear = Q.fr;
}

//�ж��Ƿ�Ϊ�ն���
bool isEmpty(LinkQueue Q)
{
    if(Q.fr == Q.rear) return true;
    else return false;
}

//���ض��г���
int Queue_Length(LinkQueue Q)
{
    if(isEmpty(Q)) return 0;
    int length = 0;
    while(Q.fr != Q.rear){
        length ++;
        Q.fr = Q.fr->next;
    }
    return length + 1;
}

//���ض�ͷԪ��
void GetHead(LinkQueue Q, QElemType &e)
{
    if(isEmpty(Q)){
        printf("����Ϊ�գ��޶�ͷԪ��\n");
        return;
    }
    e = Q.fr->data;
    return;
}

//�ڶ�β����Ԫ��
void EnQueue(LinkQueue &Q, QElemType e)
{
    QueuePtr p = (QueuePtr) malloc(sizeof(QNode));
    p->data = e;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
}

//�ڶ�ͷȡ��Ԫ��
void DeQueue(LinkQueue &Q, QElemType &e)
{
    if(isEmpty(Q)){
        printf("����Ϊ�գ��޶�ͷԪ��\n");
        return;
    }
    QueuePtr p = Q.fr->next;
    Q.fr->next = p->next;
    e = p->data;
    if(Q.rear == p) Q.rear = Q.fr;
    free(p);

}

//��ӡ����
void showup(LinkQueue Q)
{
    QueuePtr p = Q.fr->next;
    while(p != Q.rear){
        printf("%d ",p->data->data);
        p = p->next;
    }
    printf("%d\n", p->data->data);
}
