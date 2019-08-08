#ifndef CIRCLELIST_H_INCLUDED
#define CIRCLELIST_H_INCLUDED

/*
循环链表存储结构和基本操作（带头结点）
设立尾指针，而非头指针。
*/
typedef int ElemType;

typedef struct SLNode
{
    ElemType val;
    struct SLNode *next;
}node, *LinkList;

//创建带头结点的单链表
void Init_List(LinkList &L);

//判断链表是否为空
bool isEmpty(LinkList L);

//返回链表的长度
int ListLength(LinkList L);

//在单链表第i个位置之前插入元素e
bool addElem(LinkList &L, int i, ElemType e);

//删除第i个位置上的元素
bool deleElem(LinkList &L, int i, ElemType &e);

//查找第i个位置的元素
bool getElem(LinkList L, int i, ElemType &e);

//显示全部元素
void showup(LinkList L);

//找到位置对饮的索引
int getIndex(LinkList L, LinkList p);

#endif // CIRCLELIST_H_INCLUDED
