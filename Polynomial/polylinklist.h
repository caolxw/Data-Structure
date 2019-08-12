#ifndef POLYLINKLIST_H_INCLUDED
#define POLYLINKLIST_H_INCLUDED

#include "polyterm.h"
#include "linklist.h"

//建立有序链表
void CreatPoly(LinkList &P, int m);

//销毁一元多项式
void DestoryPoly(LinkList &P);

//打印输出一元多项式
void PrintPoly(LinkList P);

//返回一元多项式P中的项数
int PolyLength(LinkList P);

//多项式相加
void AddPoly(LinkList &Pa, LinkList &Pb, LinkList &Pc);

//多项式相减
void SubtractPoly(LinkList &Pa, LinkList &Pb, LinkList &Pc);
#endif // POLYLINKLIST_H_INCLUDED
