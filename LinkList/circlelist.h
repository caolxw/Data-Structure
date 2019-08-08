#ifndef CIRCLELIST_H_INCLUDED
#define CIRCLELIST_H_INCLUDED

/*
ѭ������洢�ṹ�ͻ�����������ͷ��㣩
����βָ�룬����ͷָ�롣
*/
typedef int ElemType;

typedef struct SLNode
{
    ElemType val;
    struct SLNode *next;
}node, *LinkList;

//������ͷ���ĵ�����
void Init_List(LinkList &L);

//�ж������Ƿ�Ϊ��
bool isEmpty(LinkList L);

//��������ĳ���
int ListLength(LinkList L);

//�ڵ������i��λ��֮ǰ����Ԫ��e
bool addElem(LinkList &L, int i, ElemType e);

//ɾ����i��λ���ϵ�Ԫ��
bool deleElem(LinkList &L, int i, ElemType &e);

//���ҵ�i��λ�õ�Ԫ��
bool getElem(LinkList L, int i, ElemType &e);

//��ʾȫ��Ԫ��
void showup(LinkList L);

//�ҵ�λ�ö���������
int getIndex(LinkList L, LinkList p);

#endif // CIRCLELIST_H_INCLUDED
