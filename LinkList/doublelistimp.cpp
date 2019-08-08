#include <stdio.h>
#include <stdlib.h>

/*
双向循环链表基本操作实现代码
*/
#include "doublelist.h"

//初始化双向循环链表
void Init_List(DLinkList &L)
{
    L = (DLinkList) malloc(sizeof(DLNode));
    if(!L) exit(0);
    L ->prior = L;
    L ->next = L;
}

//判断链表是否为空
bool isEmpty(DLinkList L)
{
    if(L->next == L) return true;
    return false;
}

//计算链表长度
int ListLength(DLinkList L)
{
    int length = 0;
    if(!isEmpty(L)){
       DLinkList p = L->next;
       while(p != L){
            length ++;
            p = p->next;
       }
    }
    return length;
}

//在第i个位置前添加元素e
bool addElem(DLinkList &L, int i, ElemType e)
{
    if(i > ListLength(L) + 1 || i < 1 ){
        printf("位置错误\n");
        return false;
    }
    DLinkList s = (DLinkList) malloc(sizeof(DLNode));
    if(!s) return false;
    s->val = e;
    DLinkList p = L;
    while(i > 1){
        p = p->next;
        i --;
    }
    s->next = p->next;
    s->prior = p;
    p->next->prior = s;
    p->next = s;
    return true;
}

//删除第i个元素
bool deleElem(DLinkList &L, int i, ElemType &e)
{
    if(i > ListLength(L) + 1 || i < 1 ){
        printf("位置错误\n");
        return false;
    }
    DLinkList p = L;
    while(i > 1){
        p = p->next;
        i --;
    }
    DLinkList q = p->next;
    q->next->prior = p;
    p->next = q->next;
    e = q->val;
    free(q);
    return true;
}

//查找第i个元素
void getElem(DLinkList L, int i, ElemType &e)
{
    if(i > ListLength(L) + 1 || i < 1 ){
        printf("位置错误\n");
        return;
    }
    DLinkList p = L;
    while(i){
        p = p->next;
        i --;
    }
    e = p->val;
}

//展示所有元素
void showup(DLinkList L)
{
    DLinkList p = L->next;
    while(p != L){
        printf("%d ",p->val);
        p = p->next;
    }
    printf("\n");
}
