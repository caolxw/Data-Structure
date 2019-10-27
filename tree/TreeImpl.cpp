#include <stdio.h>
#include <stdlib.h>

#include "treehead.h"
#include "StackImpl.cpp"
#include "QueueImpl.cpp"

void PrintElement(ElemType e){
    printf("%d", e);
    return;
}

//构造二叉链表表示二叉树
//要求以先序输入
void CreateBiTree(BiTree &T)
{
    ElemType e;
    scanf("%d", &e);
    if(e == -1) {
        T = NULL;
        return;
    }
    if(!(T = (BiTNode *)malloc(sizeof(BiTNode)))) {
        printf("初始化失败！\n");
        return;
    }
    T->data = e;
    CreateBiTree(T->lchild);
    CreateBiTree(T->rchild);
}

//先序递归遍历二叉树
void PreOrderTree(BiTree T, void (*visit)(ElemType e))
{
    if(T){
        visit(T->data);
        PreOrderTree(T->lchild, visit);
        PreOrderTree(T->rchild, visit);
    }else return;
}

//中序递归遍历二叉树
void InOrderTree(BiTree T, void (*visit)(ElemType e))
{
    if(T){
        InOrderTree(T ->lchild, visit);
        visit(T ->data);
        InOrderTree(T ->rchild, visit);
    }else return;
}

//后序递归遍历二叉树
void PostOrderTree(BiTree T, void (*visit)(ElemType e))
{
    if(T){
        PostOrderTree(T ->lchild, visit);
        PostOrderTree(T ->rchild, visit);
        visit(T ->data);
    }else return;
}

//前序非递归白遍历二叉树
void PreOrderTree_norecursive(BiTree T, void(*visit)(ElemType e))
{
    if(T == NULL) return;
    BiTree p = T;
    SqStack q;
    Init_Stack(q);
    while(!isEmpty(q) || p){
        while(p){
            visit(p ->data);
            Push(q, p);
            p = p->lchild;
        }
        if(!isEmpty(q)){
            Pop(q, p);
            p = p ->rchild;
        }
    }
    Destory_Stack(q);
}

//中序非递归遍历二叉树
void InOrderTree_norecursive(BiTree T, void (*visit)(ElemType e))
{
    if(T == NULL) return;
    BiTree p = T;
    SqStack s;
    Init_Stack(s);
    while(!isEmpty(s) || p){
        while(p){
            Push(s, p);
            p = p ->lchild;
        }
        if(!isEmpty(s)){
            Pop(s, p);
            visit(p ->data);
            p = p ->rchild;
        }
    }
    Destory_Stack(s);
}

//后序非递归遍历二叉树
void PostOrderTree_norecursive(BiTree T, void (*visit)(ElemType e))
{
    if(T == NULL) return;
    BiTree p = T;
    BiTree pre; //记录上一个被访问的结点
    SqStack s;
    Init_Stack(s);

    Push(s, p);
    while(!isEmpty(s)){
        GetTop(s, p);

        //1.左右子树均为空
        //2.左右子树均被访问过
        if((p->lchild == NULL && p->rchild == NULL) || ((pre == p ->lchild || pre == p ->rchild)&& pre)){
            Pop(s, p);
            visit(p->data);
            pre = p;
        }
        else{
            if(p->rchild){
                Push(s, p->rchild);
            }
            if(p ->lchild){
                Push(s, p->lchild);
            }
        }

    }
    Destory_Stack(s);
}

//层序遍历二叉树
void LevelOrderTree(BiTree T, void (*visit)(ElemType e))
{
    if(T == NULL) return;
    LinkQueue q;
    Init_Queue(q);
    BiTree p = T;

    EnQueue(q, p);
    while(!isEmpty(q)){
        DeQueue(q, p);
        if(p ->lchild){
            EnQueue(q, p->lchild);
        }
        if(p ->rchild){
            EnQueue(q, p->rchild);
        }
        visit(p->data);
    }
}
