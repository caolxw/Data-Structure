#include <stdio.h>
#include <stdlib.h>

#include "linklist.h"

//�������������ʵ��

//������ͷ���ĵ�����
void Init_List(LinkList &L)
{
    L = (LinkList)malloc(sizeof(node));
    if(!L) exit(0);
    L->next = NULL;
}

//�ڵ������i��λ��֮ǰ����Ԫ��e
bool addElem(LinkList &L, int i, ElemType e)
{
    LinkList p = L;
    int j;
    for(j = 0; j < i - 1; j ++)
        p = p->next;

    if(!p || j > i - 1)
    {
        printf("i����");
        return false;
    }
    LinkList temp = (LinkList)malloc(sizeof(node));
    temp->val = e;
    temp->next = p->next;
    p->next = temp;
    return true;
}

//ɾ����i��λ���ϵ�Ԫ��
bool deleElem(LinkList &L, int i, ElemType &e)
{
    LinkList p = L;
    int j;
    for(j = 0; j < i - 1; j ++)
        p = p->next;
    if(!p || j > i -1 )
    {
        printf("i����");
        return false;
    }
    e = p->next->val;
    LinkList s = p->next;
    p->next = s->next;
    free(s);
    return true;
}

//���ҵ�i��λ�õ�Ԫ��
bool getElem(LinkList L, int i, ElemType &e)
{
    LinkList p = L->next;
    int j;
    for(j = 1; j < i; j ++){
        p = p->next;
    }
    if(!p || j > i){
        printf("i����");
        return false;
    }
    e = p->val;
    return true;
}

//��ʾȫ��Ԫ��
void showup(LinkList L)
{
    LinkList p = L->next;
    while(p){
        printf("%d ",p->val);
        p = p->next;
    }
    printf("\n");
}
