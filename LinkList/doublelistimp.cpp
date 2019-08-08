#include <stdio.h>
#include <stdlib.h>

/*
˫��ѭ�������������ʵ�ִ���
*/
#include "doublelist.h"

//��ʼ��˫��ѭ������
void Init_List(DLinkList &L)
{
    L = (DLinkList) malloc(sizeof(DLNode));
    if(!L) exit(0);
    L ->prior = L;
    L ->next = L;
}

//�ж������Ƿ�Ϊ��
bool isEmpty(DLinkList L)
{
    if(L->next == L) return true;
    return false;
}

//����������
int ListLength(DLinkList L)
{
    int length = 0;
    if(!isEmpty(L)){
       DLinkList p = L->next;
       while(p != L){
            length ++;
            p = p->next;
       }
    }
    return length;
}

//�ڵ�i��λ��ǰ���Ԫ��e
bool addElem(DLinkList &L, int i, ElemType e)
{
    if(i > ListLength(L) + 1 || i < 1 ){
        printf("λ�ô���\n");
        return false;
    }
    DLinkList s = (DLinkList) malloc(sizeof(DLNode));
    if(!s) return false;
    s->val = e;
    DLinkList p = L;
    while(i > 1){
        p = p->next;
        i --;
    }
    s->next = p->next;
    s->prior = p;
    p->next->prior = s;
    p->next = s;
    return true;
}

//ɾ����i��Ԫ��
bool deleElem(DLinkList &L, int i, ElemType &e)
{
    if(i > ListLength(L) + 1 || i < 1 ){
        printf("λ�ô���\n");
        return false;
    }
    DLinkList p = L;
    while(i > 1){
        p = p->next;
        i --;
    }
    DLinkList q = p->next;
    q->next->prior = p;
    p->next = q->next;
    e = q->val;
    free(q);
    return true;
}

//���ҵ�i��Ԫ��
void getElem(DLinkList L, int i, ElemType &e)
{
    if(i > ListLength(L) + 1 || i < 1 ){
        printf("λ�ô���\n");
        return;
    }
    DLinkList p = L;
    while(i){
        p = p->next;
        i --;
    }
    e = p->val;
}

//չʾ����Ԫ��
void showup(DLinkList L)
{
    DLinkList p = L->next;
    while(p != L){
        printf("%d ",p->val);
        p = p->next;
    }
    printf("\n");
}
