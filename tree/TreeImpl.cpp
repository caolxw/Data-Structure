#include <stdio.h>
#include <stdlib.h>

#include "treehead.h"

void PrintElement(ElemType e){
    printf("%d", e);
    return;
}

//构造二叉链表表示二叉树
//要求以先序输入
void CreateBiTree(BiTree &T)
{
    ElemType e;
    scanf("%d ", &e);
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

//层序遍历二叉树
void LevelOrderTree(BiTree T, void (*visit)(ElemType e));
