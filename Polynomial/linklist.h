#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED

#include "polyterm.h"
typedef struct SLNode
{
    ElemType val;
    struct SLNode *next;
}node, *LinkList;

//创建带头结点的单链表
void Init_List(LinkList &L);

//在单链表第i个位置之前插入元素e
bool addElem(LinkList &L, int i, ElemType e);

//删除第i个位置上的元素
bool deleElem(LinkList &L, int i, ElemType &e);

//查找第i个位置的元素
bool getElem(LinkList L, int i, ElemType &e);

//显示全部元素
void showup(LinkList L);

//合并两个链表并保持其递减性
void MergeList(LinkList &L1, LinkList &L2, LinkList &L3);

//返回满足cmp的元素的索引
int getIndex(LinkList L, ElemType e, int (* compare)(ElemType, ElemType));

#endif // LINKLIST_H_INCLUDED
