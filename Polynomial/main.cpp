#include <stdio.h>
#include "polylinklist.cpp"

int main(){
    int m;
    printf("��һ������ʽ������Ϊ��\n");
    scanf("%d",&m);
    LinkList P1;
    CreatPoly(P1, m);
    printf("�ڶ�������ʽ������Ϊ��\n");
    scanf("%d", &m);
    LinkList P2;
    CreatPoly(P2, m);
    printf("�����Ķ���ʽΪ��\n");
    PrintPoly(P1);
    PrintPoly(P2);
    LinkList P3;
    SubtractPoly(P1, P2, P3);
    printf("����ʽ����Ľ��Ϊ��\n");
    PrintPoly(P3);
}
