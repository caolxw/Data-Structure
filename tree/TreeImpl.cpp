#include <stdio.h>
#include <stdlib.h>

#include "treehead.h"
#include "StackImpl.cpp"
#include "QueueImpl.cpp"

void PrintElement(ElemType e){
    printf("%d", e);
    return;
}

//������������ʾ������
//Ҫ������������
void CreateBiTree(BiTree &T)
{
    ElemType e;
    scanf("%d", &e);
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

//ǰ��ǵݹ�ױ���������
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

//����ǵݹ����������
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

//����ǵݹ����������
void PostOrderTree_norecursive(BiTree T, void (*visit)(ElemType e))
{
    if(T == NULL) return;
    BiTree p = T;
    BiTree pre; //��¼��һ�������ʵĽ��
    SqStack s;
    Init_Stack(s);

    Push(s, p);
    while(!isEmpty(s)){
        GetTop(s, p);

        //1.����������Ϊ��
        //2.���������������ʹ�
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

//�������������
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
