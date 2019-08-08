/*
Լɪ������������
��֪n���ˣ��Ա��1��2��3...n�ֱ��ʾ��Χ����һ��Բ����Χ���ӱ��Ϊk���˿�ʼ����������m���Ǹ��˳��У�������һ�����ִ�1��ʼ����������m���Ǹ����ֳ��У����˹����ظ���ȥ��ֱ��Բ����Χ����ȫ�����С�

Լɪ���������£�
1��һȺ��Χ��һ������ ��״���磺N��
2����ĳ����ſ�ʼ�������磺K��
3������ĳ�������磺M����ʱ�򣬴��˳��У���һ�������±���
4��һֱѭ����ֱ�������˳��У�Լɪ�򻷽���
*/
#include <stdio.h>
#include "circlelist.h"
#include "circlelistimp.cpp"

//����ѭ�����������Լɪ��
void josephus(int n, int k, int m)
{
    if(k > n){
        printf("k ���ܱ� n ��\n");
        return;
    }
    if(m > n){
        printf("m ���ܱ� n ��\n");
        return;
    }

    LinkList L;
    Init_List(L);   //��ʼ������
    //�����������Ԫ��
    for(int i = 0; i < n; i ++){
        addElem(L, i+1, i+1);
    }
    showup(L);

    //��λ��k��Ԫ��
    LinkList p = L->next;
    while(k --){
        p = p->next;
    }

    while(ListLength(L) > 1){

        for(int i = 1; i < m; ){
            p = p->next;
            if(p == L->next) continue;  //pָ��ͷ���ʱû������
            i ++;
        }
        int index = getIndex(L, p);
        p = p->next;
        int e;
        deleElem(L, index, e);
        printf("%d\n",e);
        showup(L);
    }

    printf("%d\nԼɪ�򻷽���\n", L->val);
    return;
}
