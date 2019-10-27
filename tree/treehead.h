#ifndef TREEHEAD_H_INCLUDED
#define TREEHEAD_H_INCLUDED

/*�������Ķ�������洢��ʾ*/
typedef int ElemType;

typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

//������������ʾ������
//Ҫ������������
void CreateBiTree(BiTree &T);

//����ݹ����������
void PreOrderTree(BiTree T, void (*visit)(ElemType e));

//����ݹ����������
void InOrderTree(BiTree T, void (*visit)(ElemType e));

//����ݹ����������
void PostOrderTree(BiTree T, void (*visit)(ElemType e));

//ǰ��ǵݹ�ױ���������
void PreOrderTree_norecursive(BiTree T, void(*visit)(ElemType e));

//����ǵݹ����������
void InOrderTree_norecursive(BiTree T, void (*visit)(ElemType e));

//����ǵݹ����������
void PostOrderTree_norecursive(BiTree T, void (*visit)(ElemType e));

//�������������
void LevelOrderTree(BiTree T, void (*visit)(ElemType e));

#endif // TREEHEAD_H_INCLUDED
