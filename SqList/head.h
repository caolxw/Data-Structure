/*
˳���ͷ�ļ�
*/

#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

#define LIST_INIT_SIZE 100
#define LISTADD 10

typedef int ElemType;

typedef struct SqList {
    ElemType *elem;
    int length;
    int listsize;
};

//˳����ʼ��
bool Init_list(SqList &L);

//˳����Ƿ�Ϊ��
bool isEmpty(SqList L);

//��ָ��λ�����Ԫ��
bool addElem(SqList &L, int i, ElemType e);

//ɾ��ָ��λ��Ԫ��
ElemType deleteElemByIndex(SqList &L, int i);

//ɾ��ָ��Ԫ��
ElemType deleteElemByData(SqList &L, ElemType e);

//����Ԫ��λ��
int selectIndex(SqList L, ElemType e);

//����ָ��λ�õ�Ԫ��
ElemType selectElem(SqList L, int i);

//��ʾ˳���ȫ��Ԫ��
void showup(SqList L);

#endif // HEAD_H_INCLUDED
