#include <stdio.h>
#include <stdlib.h>
#include "circlelist.h"

//ѭ�������������ʵ��

//������ͷ���ĵ�����
void Init_List(LinkList &L)
{
    L = (LinkList)malloc(sizeof(node));
    if(!L) exit(0);
    L->next = L;
}

//�ж������Ƿ�Ϊ��
bool isEmpty(LinkList L)
{
    if(L->next == L){
        return true;
    }
    return false;
}

//��������ĳ���
int ListLength(LinkList L)
{
    LinkList p = L->next;
    int length = 0;
    while(p != L)
    {
        length ++;
        p = p->next;
    }
    return length;
}

//�ڵ������i��λ��֮ǰ����Ԫ��e
bool addElem(LinkList &L, int i, ElemType e)
{
    LinkList p = L->next;
    int length = ListLength(L);
    if(i > length + 1 || i < 1){
        printf("λ�ô���\n");
        return false;
    }
    int index = i;
    while(i > 1){
        p = p->next;
        i = i - 1;
    }
    LinkList temp = (LinkList)malloc(sizeof(node));
    temp->val = e;
    temp->next = p->next;
    p->next = temp;
    if(index == length + 1){
            //����βָ��λ��
        L = temp;
    }
    return true;
}

//ɾ����i��λ���ϵ�Ԫ��
bool deleElem(LinkList &L, int i, ElemType &e)
{
    LinkList p = L->next;
    int length = ListLength(L);
    if(i > length || i < 1){
        printf("λ�ô���\n");
        return false;
    }
    int j = i;
    while(i > 1){
        p = p->next;
        i = i - 1;
    }
    e = p->next->val;
    LinkList s = p->next;
    p->next = s->next;
    if(j == length){
            //����βָ��λ��
        L = p;
    }

    free(s);
    return true;
}

//���ҵ�i��λ�õ�Ԫ��
bool getElem(LinkList L, int i, ElemType &e)
{
    LinkList p = L->next;
    if(i > ListLength(L) || i < 1){
        printf("λ�ô���\n");
        return false;
    }

    while(i){
        p = p->next;
        i --;
    }
    e = p->val;
    return true;
}

//��ʾȫ��Ԫ��
void showup(LinkList L)
{
    if(isEmpty(L)) return;
    LinkList p = L->next->next;
    while(p != L){
        printf("%d ",p->val);
        p = p->next;
    }
    printf("%d\n",p->val);
}
