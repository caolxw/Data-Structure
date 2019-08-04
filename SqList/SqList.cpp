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

//˳����Ƿ�Ϊ��
bool isEmpty(SqList L){
    return L.length == 0 ? true : false;
}

//��ָ��λ��֮ǰ���Ԫ��
bool addElem(SqList &L, int i, ElemType e){
    if(i < 1 || i > L.length + 1) {
            //i������Χ
        printf("λ�ô���\n");
        return false;
    }
    if(L.length == L.listsize){
        //˳���λ�ò���
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

//ɾ��ָ��λ��Ԫ��
ElemType deleteElemByIndex(SqList &L, int i){
    if(i < 1 || i > L.length){
        printf("����λ��\n");
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

//ɾ��ָ��Ԫ��
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

//����Ԫ��λ��
int selectIndex(SqList L, ElemType e){
    for(int i = 0; i < L.listsize; i ++){
        if(L.elem[i] == e){
            return i + 1;
        }
    }
}

//����ָ��λ�õ�Ԫ��
ElemType selectElem(SqList L, int i){
    return i < 1 || i > L.length +1 ? -1 : L.elem[i-1];
}

//��ʾ˳���ȫ��Ԫ��
void showup(SqList L){
    for(int i = 0; i < L.length; i ++){
        printf("%d ", L.elem[i]);
    }
    printf("\n");
}
