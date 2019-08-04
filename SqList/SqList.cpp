#include <stdio.h>
#include <stdlib.h>
#include <head.h>

bool Init_list(SqList &L){
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if(!L.elem) return false;
    else{
        L.length = 0;
        L.listsize = LIST_INIT_SIZE;
        return true;
    }
}

//顺序表是否为空
bool isEmpty(SqList L){
    return L.length == 0 ? true : false;
}

//在指定位置之前添加元素
bool addElem(SqList &L, int i, ElemType e){
    if(i < 1 || i > L.length + 1) {
            //i超出范围
        printf("位置错误\n");
        return false;
    }
    if(L.length == L.listsize){
        //顺序表位置不够
        ElemType *temp = (ElemType *)realloc(L.elem, (L.listsize + LISTADD) * sizeof(ElemType));
        if(!temp) return false;
        L.elem = temp;
        L.listsize += LISTADD;
    }

    for(int j = L.length; j >= i; j --){
        L.elem[j] = L.elem[j - 1];
    }
    L.elem[i - 1] = e;
/*
    ElemType *q = &(L.elem[i - 1]);
    for(ElemType *p = &(L.elem[L.length - 1]); p >= q; p --){
        *(p+1) = *p;
    }
    *q = e;
    */
    L.length ++;
    return true;

}

//删除指定位置元素
ElemType deleteElemByIndex(SqList &L, int i){
    if(i < 1 || i > L.length){
        printf("错误位置\n");
        exit(0);
    }else{
        ElemType e = L.elem[i - 1];
        while(i < L.length){
            L.elem[i - 1] = L.elem[i];
        }
        L.length --;
        return e;
    }

}

//删除指定元素
int deleteElemByData(SqList &L, ElemType e){
    for(int i = 0; i < L.listsize; i ++){
        if(L.elem[i] == e){
            int temp = i;
            while(temp < L.length){
                L.elem[temp] = L.elem[++temp];
            }

            L.length --;
            return i + 1;
        }
    }
    return -1;
}

//查找元素位置
int selectIndex(SqList L, ElemType e){
    for(int i = 0; i < L.listsize; i ++){
        if(L.elem[i] == e){
            return i + 1;
        }
    }
}

//查找指定位置的元素
ElemType selectElem(SqList L, int i){
    return i < 1 || i > L.length +1 ? -1 : L.elem[i-1];
}

//显示顺序表全部元素
void showup(SqList L){
    for(int i = 0; i < L.length; i ++){
        printf("%d ", L.elem[i]);
    }
    printf("\n");
}
