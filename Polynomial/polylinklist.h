#ifndef POLYLINKLIST_H_INCLUDED
#define POLYLINKLIST_H_INCLUDED

#include "polyterm.h"
#include "linklist.h"

//������������
void CreatPoly(LinkList &P, int m);

//����һԪ����ʽ
void DestoryPoly(LinkList &P);

//��ӡ���һԪ����ʽ
void PrintPoly(LinkList P);

//����һԪ����ʽP�е�����
int PolyLength(LinkList P);

//����ʽ���
void AddPoly(LinkList &Pa, LinkList &Pb, LinkList &Pc);

//����ʽ���
void SubtractPoly(LinkList &Pa, LinkList &Pb, LinkList &Pc);
#endif // POLYLINKLIST_H_INCLUDED
