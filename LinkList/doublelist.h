#ifndef DOUBLELIST_H_INCLUDED
#define DOUBLELIST_H_INCLUDED

//˫������洢�ṹ�Լ���������

typedef int ElemType;

typedef struct DLNode {
    ElemType val;
    struct DLNode *prior;   //ָ��ֱ��ǰ��
    struct DLNode *next;    //ָ��ֱ�Ӻ��
}DLNode, *DLinkList;

//��ʼ��˫��ѭ������
void Init_List(DLinkList &L);

//�ж������Ƿ�Ϊ��
bool isEmpty(DLinkList L);

//����������
int ListLength(DLinkList L);

//�ڵ�i��λ��ǰ���Ԫ��e
bool addElem(DLinkList &L, int i, ElemType e);

//ɾ����i��Ԫ��
bool deleElem(DLinkList &L, int i, ElemType &e);

//���ҵ�i��Ԫ��
void getElem(DLinkList L, int i, ElemType &e);

//չʾ����Ԫ��
void showup(DLinkList L);
#endif // DOUBLELIST_H_INCLUDED
