#include <stdio.h>
#include <stdlib.h>

#include "TreeImpl.cpp"

int main()
{
    BiTree T;
    CreateBiTree(T);
    PreOrderTree(T, PrintElement);
    printf("\n");
    InOrderTree(T, PrintElement);
    printf("\n");
    PostOrderTree(T, PrintElement);
    printf("\n");
    PreOrderTree_norecursive(T, PrintElement);
    printf("\n");
    InOrderTree_norecursive(T, PrintElement);
    printf("\n");
    PostOrderTree_norecursive(T, PrintElement);
    printf("\n");
    LevelOrderTree(T, PrintElement);
}
