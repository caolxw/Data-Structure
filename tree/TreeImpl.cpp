#include <stdio.h>
#include <stdlib.h>

#include "treehead.h"

void PrintElement(ElemType e){
    printf("%d", e);
    return;
}

//������������ʾ������
//Ҫ������������
void CreateBiTree(BiTree &T)
{
    ElemType e;
    scanf("%d ", &e);
    if(e == -1) {
        T = NULL;
        return;
    }
    if(!(T = (BiTNode *)malloc(sizeof(BiTNode)))) {
        printf("��ʼ��ʧ�ܣ�\n");
        return;
    }
    T->data = e;
    CreateBiTree(T->lchild);
    CreateBiTree(T->rchild);
}

//����ݹ����������
void PreOrderTree(BiTree T, void (*visit)(ElemType e))
{
    if(T){
        visit(T->data);
        PreOrderTree(T->lchild, visit);
        PreOrderTree(T->rchild, visit);
    }else return;
}

//����ݹ����������
void InOrderTree(BiTree T, void (*visit)(ElemType e))
{
    if(T){
        InOrderTree(T ->lchild, visit);
        visit(T ->data);
        InOrderTree(T ->rchild, visit);
    }else return;
}

//����ݹ����������
void PostOrderTree(BiTree T, void (*visit)(ElemType e))
{
    if(T){
        PostOrderTree(T ->lchild, visit);
        PostOrderTree(T ->rchild, visit);
        visit(T ->data);
    }else return;
}

//�������������
void LevelOrderTree(BiTree T, void (*visit)(ElemType e));
