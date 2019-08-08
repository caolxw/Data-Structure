#ifndef DOUBLELIST_H_INCLUDED
#define DOUBLELIST_H_INCLUDED

//双向链表存储结构以及基本操作

typedef int ElemType;

typedef struct DLNode {
    ElemType val;
    struct DLNode *prior;   //指向直接前驱
    struct DLNode *next;    //指向直接后继
}DLNode, *DLinkList;

//初始化双向循环链表
void Init_List(DLinkList &L);

//判断链表是否为空
bool isEmpty(DLinkList L);

//计算链表长度
int ListLength(DLinkList L);

//在第i个位置前添加元素e
bool addElem(DLinkList &L, int i, ElemType e);

//删除第i个元素
bool deleElem(DLinkList &L, int i, ElemType &e);

//查找第i个元素
void getElem(DLinkList L, int i, ElemType &e);

//展示所有元素
void showup(DLinkList L);
#endif // DOUBLELIST_H_INCLUDED
