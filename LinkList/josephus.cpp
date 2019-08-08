/*
约瑟夫环问题描述：
已知n个人（以编号1，2，3...n分别表示）围坐在一张圆桌周围。从编号为k的人开始报数，数到m的那个人出列；他的下一个人又从1开始报数，数到m的那个人又出列；依此规律重复下去，直到圆桌周围的人全部出列。

约瑟夫环运作如下：
1、一群人围在一起坐成 环状（如：N）
2、从某个编号开始报数（如：K）
3、数到某个数（如：M）的时候，此人出列，下一个人重新报数
4、一直循环，直到所有人出列，约瑟夫环结束
*/
#include <stdio.h>
#include "circlelist.h"
#include "circlelistimp.cpp"

//采用循环单链表完成约瑟夫环
void josephus(int n, int k, int m)
{
    if(k > n){
        printf("k 不能比 n 大\n");
        return;
    }
    if(m > n){
        printf("m 不能比 n 大\n");
        return;
    }

    LinkList L;
    Init_List(L);   //初始化链表
    //向链表中添加元素
    for(int i = 0; i < n; i ++){
        addElem(L, i+1, i+1);
    }
    showup(L);

    //定位第k个元素
    LinkList p = L->next;
    while(k --){
        p = p->next;
    }

    while(ListLength(L) > 1){

        for(int i = 1; i < m; ){
            p = p->next;
            if(p == L->next) continue;  //p指向头结点时没有数据
            i ++;
        }
        int index = getIndex(L, p);
        p = p->next;
        int e;
        deleElem(L, index, e);
        printf("%d\n",e);
        showup(L);
    }

    printf("%d\n约瑟夫环结束\n", L->val);
    return;
}
