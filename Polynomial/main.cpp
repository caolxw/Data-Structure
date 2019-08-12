#include <stdio.h>
#include "polylinklist.cpp"

int main(){
    int m;
    printf("第一个多项式的项数为：\n");
    scanf("%d",&m);
    LinkList P1;
    CreatPoly(P1, m);
    printf("第二个多项式的项数为：\n");
    scanf("%d", &m);
    LinkList P2;
    CreatPoly(P2, m);
    printf("创建的多项式为：\n");
    PrintPoly(P1);
    PrintPoly(P2);
    LinkList P3;
    SubtractPoly(P1, P2, P3);
    printf("多项式相减的结果为：\n");
    PrintPoly(P3);
}
