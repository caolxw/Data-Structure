#include <stdio.h>
#include <stdlib.h>
#include "circlelist.h"

//循环链表基本操作实现

//创建带头结点的单链表
void Init_List(LinkList &L)
{
    L = (LinkList)malloc(sizeof(node));
    if(!L) exit(0);
    L->next = L;
}

//判断链表是否为空
bool isEmpty(LinkList L)
{
    if(L->next == L){
        return true;
    }
    return false;
}

//返回链表的长度
int ListLength(LinkList L)
{
    LinkList p = L->next;
    int length = 0;
    while(p != L)
    {
        length ++;
        p = p->next;
    }
    return length;
}

//在单链表第i个位置之前插入元素e
bool addElem(LinkList &L, int i, ElemType e)
{
    LinkList p = L->next;
    int length = ListLength(L);
    if(i > length + 1 || i < 1){
        printf("位置错误\n");
        return false;
    }
    int index = i;
    while(i > 1){
        p = p->next;
        i = i - 1;
    }
    LinkList temp = (LinkList)malloc(sizeof(node));
    temp->val = e;
    temp->next = p->next;
    p->next = temp;
    if(index == length + 1){
            //更新尾指针位置
        L = temp;
    }
    return true;
}

//删除第i个位置上的元素
bool deleElem(LinkList &L, int i, ElemType &e)
{
    LinkList p = L->next;
    int length = ListLength(L);
    if(i > length || i < 1){
        printf("位置错误\n");
        return false;
    }
    int j = i;
    while(i > 1){
        p = p->next;
        i = i - 1;
    }
    e = p->next->val;
    LinkList s = p->next;
    p->next = s->next;
    if(j == length){
            //更新尾指针位置
        L = p;
    }

    free(s);
    return true;
}

//查找第i个位置的元素
bool getElem(LinkList L, int i, ElemType &e)
{
    LinkList p = L->next;
    if(i > ListLength(L) || i < 1){
        printf("位置错误\n");
        return false;
    }

    while(i){
        p = p->next;
        i --;
    }
    e = p->val;
    return true;
}

//显示全部元素
void showup(LinkList L)
{
    if(isEmpty(L)) return;
    LinkList p = L->next->next;
    while(p != L){
        printf("%d ",p->val);
        p = p->next;
    }
    printf("%d\n",p->val);
}
