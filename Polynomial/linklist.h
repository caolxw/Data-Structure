#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED

#include "polyterm.h"
typedef struct SLNode
{
    ElemType val;
    struct SLNode *next;
}node, *LinkList;

//������ͷ���ĵ�����
void Init_List(LinkList &L);

//�ڵ������i��λ��֮ǰ����Ԫ��e
bool addElem(LinkList &L, int i, ElemType e);

//ɾ����i��λ���ϵ�Ԫ��
bool deleElem(LinkList &L, int i, ElemType &e);

//���ҵ�i��λ�õ�Ԫ��
bool getElem(LinkList L, int i, ElemType &e);

//��ʾȫ��Ԫ��
void showup(LinkList L);

//�ϲ���������������ݼ���
void MergeList(LinkList &L1, LinkList &L2, LinkList &L3);

//��������cmp��Ԫ�ص�����
int getIndex(LinkList L, ElemType e, int (* compare)(ElemType, ElemType));

#endif // LINKLIST_H_INCLUDED
