#include <stdio.h>
#include <stdlib.h>

#include "linklist.h"
#include "linklistimp.cpp"
#include "polylinklist.h"

//建立有序链表
void CreatPoly(LinkList &P, int m)
{
    Init_List(P);

    printf("请依次输入每一项的系数和指数，以空格区分。\n");
    for(int i = 0; i < m; i ++){
        ElemType data;
        scanf("%f %d", &data.c, &data.e);
        bool flag = addElem(P, i + 1, data);
        if(!flag) return;
    }
}

//销毁一元多项式
void DestoryPoly(LinkList &P)
{
    while(P){
        LinkList q = P;
        P = P->next;
        free(q);
    }
}

//打印输出一元多项式
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

//返回一元多项式P中的项数
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

//多项式相加
void AddPoly(LinkList Pa, LinkList Pb, LinkList &Pc);

//多项式相减
void SubtractPoly(LinkList Pa, LinkList Pb, LinkList &Pc);
