#include <stdio.h>
#include <stdlib.h>

#include "linklist.h"

//单链表基本操作实现

//创建带头结点的单链表
void Init_List(LinkList &L)
{
    L = (LinkList)malloc(sizeof(node));
    if(!L) exit(0);
    L->next = NULL;
}

//在单链表第i个位置之前插入元素e
bool addElem(LinkList &L, int i, ElemType e)
{
    LinkList p = L;
    int j;
    for(j = 0; j < i - 1; j ++)
        p = p->next;

    if(!p || j > i - 1)
    {
        printf("i错误");
        return false;
    }
    LinkList temp = (LinkList)malloc(sizeof(node));
    temp->val = e;
    temp->next = p->next;
    p->next = temp;
    return true;
}

//删除第i个位置上的元素
bool deleElem(LinkList &L, int i, ElemType &e)
{
    LinkList p = L;
    int j;
    for(j = 0; j < i - 1; j ++)
        p = p->next;
    if(!p || j > i -1 )
    {
        printf("i错误");
        return false;
    }
    e = p->next->val;
    LinkList s = p->next;
    p->next = s->next;
    free(s);
    return true;
}

//查找第i个位置的元素
bool getElem(LinkList L, int i, ElemType &e)
{
    LinkList p = L->next;
    int j;
    for(j = 1; j < i; j ++){
        p = p->next;
    }
    if(!p || j > i){
        printf("i错误");
        return false;
    }
    e = p->val;
    return true;
}

//显示全部元素
void showup(LinkList L)
{
    LinkList p = L->next;
    while(p){
        printf("%d ",p->val);
        p = p->next;
    }
    printf("\n");
}

//返回满足cmp的元素的索引
int getIndex(LinkList L, ElemType e, int (* compare)(ElemType, ElemType))
{
    LinkList p = L->next;
    int i = 1;
    while(p){
        if(compare(e, p->val) == 0) return i;
        i ++;
        p = p->next;
    }
    return i;
}
