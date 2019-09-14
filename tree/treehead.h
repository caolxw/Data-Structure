#ifndef TREEHEAD_H_INCLUDED
#define TREEHEAD_H_INCLUDED

/*二叉树的二叉链表存储表示*/
typedef int ElemType;

typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

//构造二叉链表表示二叉树
//要求以先序输入
void CreateBiTree(BiTree &T);

//先序递归遍历二叉树
void PreOrderTree(BiTree T, void (*visit)(ElemType e));

//中序递归遍历二叉树
void InOrderTree(BiTree T, void (*visit)(ElemType e));

//后序递归遍历二叉树
void PostOrderTree(BiTree T, void (*visit)(ElemType e));

//层序递归遍历二叉树
void LevelOrderTree(BiTree T, void (*visit)(ElemType e));

#endif // TREEHEAD_H_INCLUDED
