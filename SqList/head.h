/*
顺序表头文件
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

//顺序表初始化
bool Init_list(SqList &L);

//顺序表是否为空
bool isEmpty(SqList L);

//在指定位置添加元素
bool addElem(SqList &L, int i, ElemType e);

//删除指定位置元素
ElemType deleteElemByIndex(SqList &L, int i);

//删除指定元素
ElemType deleteElemByData(SqList &L, ElemType e);

//查找元素位置
int selectIndex(SqList L, ElemType e);

//查找指定位置的元素
ElemType selectElem(SqList L, int i);

//显示顺序表全部元素
void showup(SqList L);

#endif // HEAD_H_INCLUDED
