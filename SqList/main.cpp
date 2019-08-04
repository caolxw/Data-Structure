#include <stdio.h>
#include "head.h"
#include "SqList.cpp"

int main()
{
    SqList l;
    Init_list(l);
    addElem(l, 1, 1);
    addElem(l, 1, 2);
    addElem(l, 2, 3);
    showup(l);
    deleteElemByData(l, 2);
    showup(l);
}
