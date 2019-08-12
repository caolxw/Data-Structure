#include <stdio.h>
#include <stdlib.h>

#include "linklist.h"
#include "linklistimp.cpp"
#include "polylinklist.h"

//�ȽϺ���
int cmp(ElemType a, ElemType b)
{
    if(a.e > b.e){
        return 1;
    }else if(a.e < b.e){
        return -1;
    }else{
        if(a.c > b.c) return 1;
        else if(a.c < b.c) return -1;
        else return 0;
    }
}

//������������
void CreatPoly(LinkList &P, int m)
{
    Init_List(P);

    printf("����������ÿһ���ϵ����ָ�����Կո����֡�\n");
    for(int i = 0; i < m; i ++){
        ElemType data;
        scanf("%f %d", &data.c, &data.e);
        int index = getIndex(P, data, cmp);
        if(index <= PolyLength(P)){
            LinkList q = P;
            while(index -- ) q = q->next;
            q->val.c += data.c;
            continue;
        }
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
void AddPoly(LinkList &Pa, LinkList &Pb, LinkList &Pc)
{
    LinkList qa = Pa->next;
    LinkList qb = Pb->next;
    Init_List(Pc);
    LinkList qc = Pc;
    while(qa && qc){
        ElemType dataa = qa->val;
        ElemType datab = qb->val;

        if(dataa.e > datab.e){
            qc->next = qa;
            qa = qa->next;
        }else if(dataa.e < datab.e){
            qc->next = qb;
            qb = qb->next;
        }else{
            dataa.c += datab.c;
            if(dataa.c == 0){
                LinkList s = qa;
                qa = qa->next;
                free(s);
                s = qb;
                qb = qb->next;
                free(s);
                continue;
            }
            qa->val.c = dataa.c;
            qc->next = qa;
            LinkList s = qb;
            qb = qb->next;
            qa = qa->next;
            free(s);
        }
        qc = qc->next;
    }
    if(qa){
      qc->next = qa;
    }
    if(qb){
        qc->next = qb;
    }
}

//����ʽ���(Pa - Pb = Pc)
void SubtractPoly(LinkList &Pa, LinkList &Pb, LinkList &Pc)
{
    LinkList q = Pb->next;
    while(q){
        q->val.c *= -1;
        q = q->next;
    }
    AddPoly(Pa, Pb, Pc);
}



