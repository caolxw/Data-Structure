#include <stdio.h>
#include <stdlib.h>

#include "linklist.h"
#include "linklistimp.cpp"
#include "polylinklist.h"

//������������
void CreatPoly(LinkList &P, int m)
{
    Init_List(P);

    printf("����������ÿһ���ϵ����ָ�����Կո����֡�\n");
    for(int i = 0; i < m; i ++){
        ElemType data;
        scanf("%f %d", &data.c, &data.e);
        bool flag = addElem(P, i + 1, data);
        if(!flag) return;
    }
}

//����һԪ����ʽ
void DestoryPoly(LinkList &P)
{
    while(P){
        LinkList q = P;
        P = P->next;
        free(q);
    }
}

//��ӡ���һԪ����ʽ
void PrintPoly(LinkList P)
{
    int length = PolyLength(P);
    for(int i = 0; i < length - 1; i++){
        ElemType data;
        getElem(P, i+1, data);
        printf("%.2fx^%d + ", data.c, data.e);
    }
    ElemType data;
    getElem(P, length, data);
    printf("%.2fx^%d\n", data.c, data.e);
}

//����һԪ����ʽP�е�����
int PolyLength(LinkList P)
{
    LinkList q = P->next;
    int length = 0;
    while(q){
        length ++;
        q = q->next;
    }
    return length;
}

//����ʽ���
void AddPoly(LinkList Pa, LinkList Pb, LinkList &Pc);

//����ʽ���
void SubtractPoly(LinkList Pa, LinkList Pb, LinkList &Pc);
