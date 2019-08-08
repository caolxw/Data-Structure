#include <stdio.h>
/*
#include "singlelist.h"
#include "singleListimp.cpp"

int main()
{
    LinkList head;
    Init_List(head);
    addElem(head, 1, 1);
    addElem(head, 2, 2);
    addElem(head, 1, 3);
    showup(head);
    ElemType e;
    deleElem(head, 2, e);
    //printf("%d\n", e);
    //showup(head);
    //getElem(head, 2, e);
    //printf("%d\n", e);

    LinkList l;
    Init_List(l);
    addElem(l, 1, 4);
    addElem(l, 2, 1);
    MergeList(head, l, head);
    showup(head);
}
*/

/*
#include "circlelist.h"
#include "circlelistimp.cpp"

int main(){
    LinkList l;
    int e;
    Init_List(l);
    //printf("%d\n", ListLength(l));
    addElem(l, 1, 2);
    addElem(l, 1, 3);
    addElem(l, 3, 4);
    addElem(l, 3, 5);
    addElem(l, 4, 6);
    //printf("%d\n",ListLength(l));
    showup(l);

    deleElem(l, 1, e);
    printf("删除了%d元素，现在剩下%d个元素\n", e, ListLength(l));
    showup(l);
    deleElem(l, 4, e);
    printf("删除了%d元素，现在剩下%d个元素\n", e, ListLength(l));
    showup(l);

    getElem(l, 2, e);
    printf("第2个元素是：%d\n", e);
}
*/

/*
#include "doublelist.h"
#include "doublelistimp.cpp"

int main(){
    DLinkList l;
    Init_List(l);
    addElem(l, 1, 1);
    addElem(l, 2, 3);
    addElem(l, 1, 4);
    addElem(l, ListLength(l), 0);
    showup(l);
    int e;
    deleElem(l, 2, e);
    printf("删除了%d元素，现在剩下%d个元素\n", e, ListLength(l));
    showup(l);
    getElem(l, 2, e);
    printf("第2个元素是：%d\n", e);
}
*/

#include "josephus.cpp"

int main(){
    josephus(5, 2, 3);
}
